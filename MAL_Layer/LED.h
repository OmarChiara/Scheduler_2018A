/*
 * LED.h
 *
 *  Created on: Mar 22, 2018
 *      Author: Misael
 */

#ifndef LED_H_
#define LED_H_

#include "GPIO.h"
#include "fsl_gpio.h"

#define LED_IS_ON 0U
#define LED_IS_OFF 1U

#define APP_LED_ON (GPIO_WritePinOutput(GPIOB, APP_LED,LED_IS_ON))
#define APP_LED_OFF (GPIO_WritePinOutput(GPIOB, APP_LED,LED_IS_OFF))



void Led_On();
void Led_Off();



#endif /* LED_H_ */
