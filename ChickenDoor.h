/*
 * ChickenDoor.h
 *
 *  Created on: 1 Sep 2021
 *      Author: Nokia
 */

#ifndef CHICKENDOOR_H_
#define CHICKENDOOR_H_
#include "Arduino.h"
#include "StepperMotor.h"

#define DOOR_STATE_SENSE_INTERVAL 50 //ms
//#define TRANSITION_TO_OPEN_COUNTER_UPPER_LIMIT 150 //measured count is 180
//#define TRANSITION_TO_OPEN_COUNTER_LOWER_LIMIT 30 //normally initialized to 0
//#define CMD_CHECK_INTERVAL 500 //check if requested from mmi to open or close the door
//#define MAX_TIME_TO_OPEN 30000
//#define MAX_TIME_TO_CLOSE 30000

class ChickenDoor {



	//enum DoorActivity{
	//	NONE,
	//	UP,
	//	DOWN
	//};

public:
	enum DoorState:unsigned int{
			CLOSED,
			OPEN,
			OPENING,
			CLOSING,
			STOPPED
	};

public:
	ChickenDoor();
	void begin();
	void loop();
	void open();
	void close();
	StepperMotor* motor1(){return _stepperMotor1;};
	StepperMotor* motor2(){return _stepperMotor2;};
	//bool isOpen(){ return _doorIsOpen; };
	unsigned int getDoorState(){ return _doorState; };
	virtual ~ChickenDoor();
	//bool _forwardSenseState;
	//bool _reverseSenseState;
	//int16_t _transitionCount;

private:
	//void updateDoorState(DoorActivity);
	//void openDoor();
	//void closeDoor();
private:
	StepperMotor* _stepperMotor1;
	StepperMotor* _stepperMotor2;
	//bool _doorIsOpen;
	DoorState _doorState;
	//DoorState _previousDoorState;
	//DoorState _requestedDoorState;
	uint32_t _doorStateLastChecked;
	//uint32_t _doorCmdLastChecked;
	bool _inTransition;
	//uint32_t _openingStart;


};

#endif /* CHICKENDOOR_H_ */
