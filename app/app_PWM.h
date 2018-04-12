/*
 * app_PWM.h
 *
 *  Created on: Apr 10, 2018
 *      Author: Misael
 */

#ifndef APP_PWM_H_
#define APP_PWM_H_

#include "stdtypedef.h"



extern void app_PWM_Init(void);
extern void app_PWM_SetValue(T_UBYTE lub_Duty);
extern void app_PWM_Task50(void);
extern void app_PWM_Task100(void);


#endif /* APP_PWM_H_ */
