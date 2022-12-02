/*
 * ParkourUI.h
 *
 *  Created on: 1 Sep 2021
 *      Author: Nokia
 */

#ifndef PARKOURUI_H_
#define PARKOURUI_H_
#include "ChickenDoor.h"
#include "Modem.h"
#include "SignalLight.h"

#define PUBLISH_TIME_INTERVAL_MS 1000
#define PUBLISH_MSG_ID 1

class ParkourUI {
public:
	ParkourUI(Modem * modem, ChickenDoor * chickenDoor, SignalLight * signal);
	void begin();
	void loop();
	bool serialMMI(char command);
	virtual ~ParkourUI();

private:
	void publishStatus();
private:
	Modem * _modem;
	ChickenDoor * _chickenDoor;
	SignalLight * _signal;
	uint32_t _elapsedPublishTime;
	uint32_t _publishInterval;
	char* _rxMsg;
	char* _txMsg;
};

#endif /* PARKOURUI_H_ */
