
/**
 *  @file		AMRParkour.ino
 *
 *  @author		maro
 *  @date		mm/dd/yyyy
 *  @version	x.y
 *
 *  @brief 		Main
 *
 *  @section DESCRIPTION
 *
 *  Instantiation and control of objects.
 *  Door and SignalLight control for AMR Robot Parkour
 *
 */


/////////// Includes /////////////////
#include "Arduino.h"
#include "Controllino.h"
#include "Modem.h"
#include "ChickenDoor.h"
#include "Defines.h"
#include "SignalLight.h"
#include "ParkourUI.h"

/*************************************************************
 * modem - local MMI represented by serial interface, WebUI by server IP and port
 */
IPAddress udpServerIP(UDP_SERVER_IP);
uint16_t udpServerPort = UDP_SERVER_PORT;
IPAddress controllinoIP(OWN_IP);

Modem modem(&Serial, udpServerIP, udpServerPort, controllinoIP);

/*************************************************************
 * Chicken door
 *
 */

//ChickenDoor class pin definitions in Defines.h

ChickenDoor chickenDoor;

/*************************************************************
 * signal
 *
 */
SignalLight signal; //pins defined in Defines.h

/*************************************************************
 * Parkou UI - local MMI represented by serial interface, WebUI by server IP and port
 *
 */
ParkourUI parkourUI(&modem, &chickenDoor, &signal);

void setup()
{
	Serial.begin(9600);
	modem.begin();
	chickenDoor.begin();
	parkourUI.begin();
}

// The loop function is called in an endless loop
void loop()
{
	modem.loop();
	chickenDoor.loop();
	parkourUI.loop();
}
