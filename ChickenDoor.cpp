/*
 * ChickenDoor.cpp
 *
 *  Created on: 1 Sep 2021
 *      Author: Nokia
 */

#include "ChickenDoor.h"
#include "Defines.h"

ChickenDoor::ChickenDoor() {

	_stepperMotor1 = new StepperMotor(PULSE_PIN1, DIR_PIN1, EN_PIN1);
	_stepperMotor2 = new StepperMotor(PULSE_PIN2, DIR_PIN2, EN_PIN2);
	//_doorIsOpen = false;
	//_forwardSenseState = false;
	//_reverseSenseState = true;
	_doorState = CLOSED;
	_doorStateLastChecked = 0;
	//_transitionCount = 0;
	//_previousDoorState = CLOSING;
	//_doorCmdLastChecked = 0;
	//_requestedDoorState = CLOSED;
	_inTransition = false;


}

void ChickenDoor::begin() {

   _doorStateLastChecked = millis();
   //_doorCmdLastChecked = millis();
   pinMode( CONTROLLINO_R5, OUTPUT);
}

void ChickenDoor::loop() {
	//_stepperMotor1->loop();
	//_stepperMotor2->loop();
	if (_inTransition == true){
		//if (millis() >= _doorStateLastChecked + DOOR_STATE_SENSE_INTERVAL){
			for(int i=DEG_90;i>0 ;i--){
				_stepperMotor1->oneStep();
				_stepperMotor2->oneStep();
			    delayMicroseconds(STEPTIME);
			};
			_stepperMotor1->disable();
			_stepperMotor2->disable();
			if (_doorState == OPENING){
					_doorState = OPEN;
			}
			if (_doorState == CLOSING){
					_doorState = CLOSED;

			}
			digitalWrite(CONTROLLINO_R5,LOW);
			_inTransition = false;
			_doorStateLastChecked = millis();
	}
}


void ChickenDoor::open() {
	//_stepperMotor1->turnRight(DEG_90);
	//_stepperMotor2->turnLeft(DEG_90);
	//_doorState = OPENING; TODO: make proper transition
	_stepperMotor1->enableRightTurn();
	_stepperMotor2->enableLeftTurn();
	_doorState = OPENING;
	_inTransition = true;
	digitalWrite(CONTROLLINO_R5,HIGH);

}

void ChickenDoor::close() {
	//_stepperMotor1->turnLeft(DEG_90);
	//_stepperMotor2->turnRight(DEG_90);
	//_doorState = CLOSING; TODO: make proper transition
	_stepperMotor2->enableRightTurn();
	_stepperMotor1->enableLeftTurn();
	_doorState = CLOSING;
	_inTransition = true;
	digitalWrite(CONTROLLINO_R5,HIGH);

}



ChickenDoor::~ChickenDoor() {
	// TODO Auto-generated destructor stub
}

