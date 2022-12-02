/*
 * ParkourUI.cpp
 *
 *  Created on: 1 Sep 2021
 *      Author: Nokia
 */

#include "ParkourUI.h"

ParkourUI::ParkourUI(Modem * modem, ChickenDoor * chickenDoor, SignalLight * signal) {
	_modem = modem;
	_chickenDoor = chickenDoor;
	_elapsedPublishTime = 0;
	_publishInterval = PUBLISH_TIME_INTERVAL_MS;
	_rxMsg = new char[UDP_TX_PACKET_MAX_SIZE];
	_txMsg = new char[UDP_TX_PACKET_MAX_SIZE];
	_signal = signal;
}

void ParkourUI::begin() {
	_elapsedPublishTime = millis();
}
void ParkourUI::loop() {
	if (_modem->msgArrived()){
		_modem->readMsg(_rxMsg);
		//Serial.println(_rxMsg);
		serialMMI(_rxMsg[0]);
	}
	while(_modem->mmiPort()->available()){
		char cmd = _modem->mmiPort()->read();
		_modem->mmiPort()->flush();
		serialMMI(cmd);
	}
	publishStatus();
}

bool ParkourUI::serialMMI(char command){
	bool retVal = false;
	_modem->mmiPort()->print(command);
	switch (command){
	case 'o':{
			_modem->mmiPort()->println(" - open chicken door");
			_chickenDoor->open();
		}
		retVal = true;
		break;
	case 'c':{
			_modem->mmiPort()->println(" - close chicken door");
			_chickenDoor->close();
		}
		retVal = true;
		break;
	case 'r':{
			_modem->mmiPort()->println(" - stepper motors reverse");
			_chickenDoor->motor1()->turnRight(DEG_90);
			_chickenDoor->motor2()->turnLeft(DEG_90);
		}
		retVal = true;
		break;
	case 'f':{
			_modem->mmiPort()->println(" - stepper motors forward");
			_chickenDoor->motor1()->turnLeft(DEG_90);
			_chickenDoor->motor2()->turnRight(DEG_90);
		}
		retVal = true;
		break;
	case '1':{
			_modem->mmiPort()->println(" - stepper motor1 right turn");
			_chickenDoor->motor1()->turnRight(DEG_90);
		}
		retVal = true;
		break;
	case '2':{
			_modem->mmiPort()->println(" - stepper motor2 right turn");
			_chickenDoor->motor2()->turnRight(DEG_90);
		}
		retVal = true;
		break;
	case '3':{
			_modem->mmiPort()->println(" - stepper motor1 left turn");
			_chickenDoor->motor1()->turnLeft(DEG_90);
		}
		retVal = true;
		break;
	case '4':{
			_modem->mmiPort()->println(" - stepper motor2 left turn");
			_chickenDoor->motor2()->turnLeft(DEG_90);
		}
		retVal = true;
		break;
	}
	return retVal;
}

/*
 * this must be called in loop function
 *
 * protocol fields:
 *   <message ID>,<door state on(1)/off(0)>
 */
void ParkourUI::publishStatus(){

	if (millis() >= (_elapsedPublishTime + _publishInterval)){
		//build message
		sprintf((char*)_txMsg,"%u,%u", (unsigned int)PUBLISH_MSG_ID, \
				                            (unsigned int)_chickenDoor->getDoorState());
		_modem->sendUdpMsg(_txMsg);
		Serial.print("Controller state <f><r>: ");
		Serial.print(" door state: ");Serial.println(_chickenDoor->getDoorState());
		if ((_chickenDoor->getDoorState() == ChickenDoor::CLOSING) || (_chickenDoor->getDoorState() == ChickenDoor::OPENING)){
			_signal->on();
		}else{
			_signal->off();
		}
		_elapsedPublishTime = millis();
	}
}


ParkourUI::~ParkourUI() {
	// TODO Auto-generated destructor stub
}

