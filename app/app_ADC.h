/*
 * app_ADC.h
 *
 *  Created on: Apr 5, 2018
 *      Author: Misael
 */

#ifndef APP_ADC_H_
#define APP_ADC_H_
#include "stdtypedef.h"

extern T_UWORD ruw_ADCValue;

extern void app_ADC_Init(void);
extern void app_ADC_Task(void);
extern void app_ADC200 (void);
extern void app_Main_Task(void);

#endif /* APP_ADC_H_ */
