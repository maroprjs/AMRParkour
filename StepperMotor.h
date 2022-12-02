/*
 * StepperMotor.h
 *
 *  Created on: 10 Apr 2022
 *      Author: pionet
 */

#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include "Arduino.h"
#define STEPTIME 250*4*3 //in [us]

class StepperMotor {
public:
	StepperMotor(uint8_t pulsePin, uint8_t dirPin, uint8_t enPin);
	void begin();
	void loop();
	void turnRight(uint16_t steps);
	void turnLeft(uint16_t steps);
	void enableRightTurn();
	void enableLeftTurn();
	void disable();
	void oneStep();
	bool isTurning() {return (_stepsToMove > 0);}
	virtual ~StepperMotor();
private:
	bool turning();
	uint8_t _pulsePin;
	uint8_t _dirPin;
	uint8_t _enPin;
	uint16_t _stepsToMove;
	bool _turnRequested;
	unsigned long _timeToMove;
};

#endif /* STEPPERMOTOR_H_ */
