/*
 * ConveyorDefines.h
 *
 *  Created on: 29 Jan 2022
 *      Author: pionet
 */

#ifndef DEFINES_H_
#define DEFINES_H_
//#include "Arduino.h"
#include "Controllino.h"


//chicken door
#define DEG_90 1600 //in [steps]
#define PULSE_PIN1	CONTROLLINO_DO4
#define DIR_PIN1	CONTROLLINO_DO3
#define EN_PIN1		CONTROLLINO_DO2
#define PULSE_PIN2	CONTROLLINO_DO7
#define DIR_PIN2	CONTROLLINO_DO6
#define EN_PIN2		CONTROLLINO_DO5


//infrared sensor
//#define IR_SENSOR_PIN	CONTROLLINO_IN0

//signallight
#define SIGNAL_PIN CONTROLLINO_DO1

//IP related
//#define OWN_IP 			192, 168, 0, 88
//#define OWN_IP 			10, 200, 20, 88
#define OWN_IP			192, 168, 1, 60
//#define UDP_SERVER_IP 	192, 168, 0, 186 //application server f�r e.g. GUI to send status information
#define UDP_SERVER_IP 	10, 200, 20, 233 //application server f�r e.g. GUI to send status information
#define UDP_SERVER_PORT	5555
#define MAC_ADDRESS 	{ 0xDE, 0xAD, 0xBE, 0xEF, 0xCA, 0xFE }
#define LOCAL_UDP_PORT 	3333



#endif /* DEFINES_H_ */
