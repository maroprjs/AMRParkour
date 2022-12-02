/*
 * SignalLight.cpp
 *
 *  Created on: 10 Sep 2021
 *      Author: Nokia
 */

#include "SignalLight.h"
#include "Defines.h"

SignalLight::SignalLight() {
	_pin = CONTROLLINO_DO1;
	_lightIsOn = false;
	_lastStateChange = 0;

}
void SignalLight::begin(){
	_lastStateChange = millis();
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);

}

void SignalLight::loop(){

	if (millis() > _lastStateChange + FLICKER_INTERVAL){

		if (_lightIsOn){
			digitalWrite(_pin, !digitalRead(_pin));
		}else{
			digitalWrite(_pin, LOW);
		};

		_lastStateChange = millis();
	}

}

SignalLight::~SignalLight() {
	// TODO Auto-generated destructor stub
}

