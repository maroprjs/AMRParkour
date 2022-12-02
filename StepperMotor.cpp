/*
 * StepperMotor.cpp
 *
 *  Created on: 10 Apr 2022
 *      Author: pionet
 */

#include "StepperMotor.h"


StepperMotor::StepperMotor(uint8_t pulsePin, uint8_t dirPin, uint8_t enPin) {
	_pulsePin = pulsePin;
	_dirPin = dirPin;
	_enPin = enPin;
	_stepsToMove = 0;
	_turnRequested = false;
	_timeToMove = 0;

}

void StepperMotor::begin(){
	  pinMode(_pulsePin,OUTPUT);
	  pinMode(_dirPin,OUTPUT);
	  pinMode(_enPin,OUTPUT);
	  digitalWrite(_enPin,HIGH);
	  digitalWrite(_pulsePin,LOW);
	  digitalWrite(_dirPin,HIGH);
}


void StepperMotor::loop(){
  if(_turnRequested == true){
	  _turnRequested = turning();
  }
}


void StepperMotor::turnRight(uint16_t steps){

  _stepsToMove = steps;
  enableRightTurn();
  _timeToMove = micros();
  _turnRequested = true;
}


void StepperMotor::turnLeft(uint16_t steps){

  _stepsToMove = steps; //TODO: check if this is even number
  enableLeftTurn();
  _timeToMove = micros();
  _turnRequested = true;
}

void StepperMotor::enableRightTurn(){
	  digitalWrite(_enPin,LOW); //ENABLE IS ACTIVE LOW
	  digitalWrite(_pulsePin,LOW);
	  digitalWrite(_dirPin,HIGH);
}

void StepperMotor::enableLeftTurn(){
	  digitalWrite(_enPin,LOW); //ENABLE IS ACTIVE LOW
	  digitalWrite(_pulsePin,LOW);
	  digitalWrite(_dirPin,LOW);
}

void StepperMotor::disable(){
	digitalWrite(_enPin,HIGH); //DISABLE STEPPER
}

void StepperMotor::oneStep(){
	digitalWrite(_pulsePin,!digitalRead(_pulsePin));
    delayMicroseconds(STEPTIME);
    digitalWrite(_pulsePin,!digitalRead(_pulsePin));
}

/*
 * returns false when _stepsToMove equals zero, hence motor has moved to requested position
 * -will be initiated by public turnRight/Left(steps) method
 */
bool StepperMotor::turning(){
	bool isItTurning = false;

	/*
	unsigned long currentTime = micros();

	if (currentTime >= _timeToMove)
	if (_stepsToMove > 0){
		isItTurning = true;
		Serial.print(_stepsToMove);
		digitalWrite(_pulsePin,!digitalRead(_pulsePin));
		_stepsToMove--;
		if (_stepsToMove <= 0){
			digitalWrite(_enPin,HIGH); //DISABLE STEPPER
			isItTurning = false;

		}else{
			_timeToMove = currentTime + STEPTIME;
		}
	}*/
	for(int i=0;i<_stepsToMove *2 ;i++){
		digitalWrite(_pulsePin,!digitalRead(_pulsePin));
	    delayMicroseconds(STEPTIME);
	};
	digitalWrite(_enPin,HIGH); //DISABLE STEPPER
	return isItTurning;

}





StepperMotor::~StepperMotor() {
	// TODO Auto-generated destructor stub
}

