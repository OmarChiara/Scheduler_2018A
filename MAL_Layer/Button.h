/*
 * Button.h
 *
 *  Created on: Mar 22, 2018
 *      Author: Misael
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#define BUTTON_ON (GPIO_ReadPinInput(GPIOB, LED_BUTTON)==FALSE)
#include "GPIO.h"
#include "fsl_gpio.h"




void Button_Pressed();

#endif /* BUTTON_H_ */
