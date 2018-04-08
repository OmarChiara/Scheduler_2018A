/*
 * LED.c
 *
 *  Created on: Mar 22, 2018
 *      Author: Misael
 */
#include "LED.h"

void Led_On()
{
	APP_LED_ON;
}

void Led_Off()
{
	APP_LED_OFF;
}

void Fan_Half()
{
	FAN_50;
}

void Fan_Full()
{
	FAN_100;
}

void Heat_Half()
{
	HEAT_50;
}
void Heat_Full()
{
	HEAT_100;
}
