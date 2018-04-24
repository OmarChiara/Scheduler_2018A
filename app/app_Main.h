/*
 * app_Main.h
 *
 *  Created on: Apr 8, 2018
 *      Author: Misael
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

#define NORMAL_MODE_CASE 0U
#define SAFE_MODE_CASE   1U

#define HEAT_100_CASE 0U
#define HEAT_50_CASE 1U
#define TEMP_NORMAL_CASE 2U
#define FAN_50_CASE 3U
#define FAN_100_CASE 4U

#define HEAT_100 (ruw_ADCValue >= LOW_MAX_DANGER_LIMITDOWN) && (ruw_ADCValue <= HIGH_MAX_DANGER_LIMITDOWN)
#define HEAT_50 (ruw_ADCValue >= LOW_MIN_DANGER_LIMITDOWN) && (ruw_ADCValue <= HIGH_MIN_DANGER_LIMITDOWN)
#define TEMP_NORMAL (ruw_ADCValue >= MIN_SAFE_LIMIT) && (ruw_ADCValue <= MAX_SAFE_LIMIT)
#define FAN_50 (ruw_ADCValue >= LOW_MIN_DANGER_LIMITUP) && (ruw_ADCValue <= HIGH_MIN_DANGER_LIMITUP)
#define FAN_100 (ruw_ADCValue >= LOW_MAX_DANGER_LIMITUP) && (ruw_ADCValue <= HIGH_MAX_DANGER_LIMITUP)

//Temp_Req_18,19
#define LOW_MAX_DANGER_LIMITDOWN 0U
#define HIGH_MAX_DANGER_LIMITDOWN 749U

#define LOW_MIN_DANGER_LIMITDOWN 750U
#define HIGH_MIN_DANGER_LIMITDOWN 1499U

#define MIN_SAFE_LIMIT 1500U
#define MAX_SAFE_LIMIT 2000U

#define LOW_MIN_DANGER_LIMITUP  2001U
#define HIGH_MIN_DANGER_LIMITUP 3000U

#define LOW_MAX_DANGER_LIMITUP  3001U
#define HIGH_MAX_DANGER_LIMITUP 4100U

extern void Fan_100(void);
extern void Fan_50(void);
extern void Heat_100(void);
extern void Heat_50(void);
extern void Temp_Normal(void);
extern void app_Main_Task(void);

#endif /* APP_MAIN_H_ */
