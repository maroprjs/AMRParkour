/*
 * SignalLight.h
 *
 *  Created on: 10 Sep 2021
 *      Author: Nokia
 */

#ifndef SIGNALLIGHT_H_
#define SIGNALLIGHT_H_
#include "Arduino.h"

#define FLICKER_INTERVAL 500

class SignalLight {
public:
	SignalLight();
	void begin();
	void loop();
	void on() {_lightIsOn = true; };
	void off(){_lightIsOn = false; };;
	virtual ~SignalLight();
private:
	uint8_t _pin;
	bool _lightIsOn;
	uint32_t _lastStateChange;

};

#endif /* SIGNALLIGHT_H_ */
