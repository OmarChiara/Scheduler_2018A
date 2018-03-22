/*
 * BUTTON_LED.c
 *
 *  Created on: Mar 22, 2018
 *      Author: Misael
 */

#include "BUTTON_LED.h"

void app_button()
{
	if (BUTTON_ON)
	{
		Led_On();

	}

	else
	{
		Led_Off();
	}
}
