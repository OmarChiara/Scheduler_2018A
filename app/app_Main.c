/*
 * app_Main.c
 *
 *  Created on: Apr 12, 2018
 *      Author: Misael
 */

/*

#include "app_ADC.h"
#include "LED.h"
#include "app_Main.h"


static T_UWORD ruw_SafeCount;
static T_UWORD ruw_SafeMode=0;



void app_Main_Task(void)
{
//Starts in standard mode
if (ruw_SafeMode!=1)
{
	app_ADC_Task();
//Heat at 100%, if it remains 30s, then safemode is on
	if ((ruw_ADCValue >= LOW_MAX_DANGER_LIMITDOWN) && (ruw_ADCValue <= HIGH_MAX_DANGER_LIMITDOWN))
			{
			HEAT_50_OFF;
			HEAT_100;
			FAN_50_OFF;
			FAN_100_OFF;
		    APP_LED_OFF;
		    	//Safe mode counter, after 30 seconds, it activates itself
		    	if(ruw_SafeCount>= 1500)
		    		{
		    			ruw_SafeMode=1;
		    		}
		    		else
		    		{
		    			ruw_SafeCount++;
		    		}
			}

//Heat at 50%
	else if ((ruw_ADCValue >= LOW_MIN_DANGER_LIMITDOWN) && (ruw_ADCValue <= HIGH_MIN_DANGER_LIMITDOWN))
		{
		HEAT_100_OFF;
		HEAT_50;
		FAN_50_OFF;
		FAN_100_OFF;
	    APP_LED_OFF;
	    ruw_SafeCount=0;
		}

//Regular temperature, Green led as indicator
	else if ((ruw_ADCValue >= MIN_SAFE_LIMIT) && (ruw_ADCValue <= MAX_SAFE_LIMIT))
	{
	HEAT_50_OFF;
	HEAT_100_OFF;
	FAN_50_OFF;
	FAN_100_OFF;
    APP_LED_ON;
    ruw_SafeCount=0;
	}
//FAN at 50%
	else if ((ruw_ADCValue >= LOW_MIN_DANGER_LIMITUP) && (ruw_ADCValue <= HIGH_MIN_DANGER_LIMITUP))
	{
	HEAT_50_OFF;
	HEAT_100_OFF;
	FAN_100_OFF;
	APP_LED_OFF;

	FAN_50;
	ruw_SafeCount=0;

	}
//FAN at 100% if it remains 30 seconds in this way, safe mode is activated
	else if ((ruw_ADCValue >= LOW_MAX_DANGER_LIMITUP) && (ruw_ADCValue <= HIGH_MAX_DANGER_LIMITUP))
	{
    FAN_50_OFF;
	HEAT_50_OFF;
	HEAT_100_OFF;
	FAN_100_OFF;
	APP_LED_OFF;
	FAN_100;

//safemode counter, after 30 seconds it activates itself
		if(ruw_SafeCount>= 1500)
		{
			ruw_SafeMode=1;
		}
		else
		{
			ruw_SafeCount++;
		}
	}
}


//Safe mode, only ADc module is working at 200ms
else if(ruw_SafeMode !=0)
	{
	HEAT_50_OFF;
	HEAT_100_OFF;
	FAN_50_OFF;
	APP_LED_ON;
	FAN_100_OFF;

    app_ADC200 (); //ADC at 200ms

    //if ADC comes back at low risk temperature then standard mode is activated
    	if(((ruw_ADCValue > LOW_MIN_DANGER_LIMITDOWN) && (ruw_ADCValue < HIGH_MIN_DANGER_LIMITDOWN)) | ((ruw_ADCValue > LOW_MIN_DANGER_LIMITUP) && (ruw_ADCValue < HIGH_MIN_DANGER_LIMITUP)))
    	{
    		ruw_SafeMode=0;
    	}

	}

}

*/
