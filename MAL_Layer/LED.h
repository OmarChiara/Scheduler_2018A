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

#define FAN_50 (GPIO_WritePinOutput(GPIOB, 0U,1U))
#define FAN_50_OFF (GPIO_WritePinOutput(GPIOB, 0U,0U))

#define FAN_100 (GPIO_WritePinOutput(GPIOB, 1U, 1u))
#define FAN_100_OFF (GPIO_WritePinOutput(GPIOB, 1U,0u))

#define HEAT_50 (GPIO_WritePinOutput(GPIOB, 2U,1U))
#define HEAT_50_OFF (GPIO_WritePinOutput(GPIOB, 2U,0U))

#define HEAT_100 (GPIO_WritePinOutput(GPIOB, 3U,1U))
#define HEAT_100_OFF (GPIO_WritePinOutput(GPIOB, 3U,0U))


void Led_On();
void Led_Off();
void Fan_Half();
void Fan_Full();
void Heat_Half();
void Heat_Full();


#endif /* LED_H_ */
