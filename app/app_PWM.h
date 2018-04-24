/*
 * app_PWM.h
 *
 *  Created on: Apr 10, 2018
 *      Author: Misael
 */

#ifndef APP_PWM_H_
#define APP_PWM_H_

#include "stdtypedef.h"



void app_PWM_Init(void);
void app_PWM_Init2(void);
void app_PWM_SetValue(T_UBYTE lub_Duty);
void app_PWM_Task(void);
void app_HEAT100(void);
void app_HEAT50(void);
void app_HEATOFF(void);
void app_FAN100(void);
void app_FAN50(void);
void app_FANOFF(void);;


#endif /* APP_PWM_H_ */
