/*
 * app_Main.c
 *
 *  Created on: Apr 12, 2018
 *      Author: Misael
 */



#include "app_ADC.h"
#include "LED.h"
#include "app_Main.h"
#include "app_PWM.h"


static T_UWORD ruw_SafeCount;
static T_UWORD ruw_SafeMode=0;
static T_UWORD ruw_TempInput;



void Temp_Normal(void)
{
	app_FANOFF();
	app_HEATOFF();
    APP_LED_ON;
    ruw_SafeCount=0; //Temp_Req_12

}

void Fan_50(void)
{

	app_FAN50();
	app_HEATOFF();
	APP_LED_OFF;
	ruw_SafeCount=0; //Temp_Req_12
}

void Heat_50(void)
{
	app_FANOFF();
	app_HEAT50();
	APP_LED_OFF;
	ruw_SafeCount=0; //Temp_Req_12
}

void Fan_100(void)

{
	app_FAN100();
	app_HEATOFF();
	APP_LED_OFF;

//safemode counter, after 30 seconds it activates itself
	if(ruw_SafeCount>= 15000)
	{
		ruw_SafeMode=1;

	}
	else
	{
		ruw_SafeCount++;
	}
}

void Heat_100(void)
{
	app_FANOFF();
	app_HEAT100();
	APP_LED_OFF;
			    	//Safe mode counter, after 30 seconds, it activates itself
			    	if(ruw_SafeCount>= 15000)
			    		{
			    			ruw_SafeMode=1;
			    		}
			    		else
			    		{
			    			ruw_SafeCount++;
			    		}

}

void app_CheckInputState(void)
{

	//Heat at 100%, if it remains 30s, then safemode is on
		if (HEAT_100)
				{
			ruw_TempInput=HEAT_100_CASE;
				}

	//Heat at 50%
		else if (HEAT_50)
			{
			ruw_TempInput=HEAT_50_CASE;
			}

	//Regular temperature, Green led as indicator
		else if (TEMP_NORMAL)
		{
			ruw_TempInput=TEMP_NORMAL_CASE;
		}
	//FAN at 50%
		else if (FAN_50)
		{
			ruw_TempInput=FAN_50_CASE;

		}



	//FAN at 100% if it remains 30 seconds in this way, safe mode is activated
		else if (FAN_100)
		{
			ruw_TempInput=FAN_100_CASE;
		}

		else
		{
			//Do nothing
		}


}

void app_NormalModeTask(void)
{
	app_ADC_Task();
	app_CheckInputState();

	switch (ruw_TempInput)
	{
	case HEAT_100_CASE: //Temp_15,16
		Heat_100();
		break;
	case HEAT_50_CASE: //Temp_Req_13,14
		Heat_50();
		break;
	case TEMP_NORMAL_CASE: //Temp_Req_2
		Temp_Normal();
		break;
	case FAN_50_CASE:  //Temp_Req_3,4
		Fan_50();
		break;
	case FAN_100_CASE: //Temp_Req_5,6
		Fan_100();
		break;


	}

}

void app_SafeModeTask(void) //Temp_Req_7,17
{
	app_PinsAsInput(); //Temp_Req_8

    app_ADC200 (); //Temp_Req_9,10 | ADC at 200ms

    //if ADC comes back at low risk temperature then standard mode is activated
    	if((HEAT_50) | (FAN_50)) //Temp_Req_11
    	{
    		GPIO_Init();
    	    app_PWM_Init();
    	    app_PWM_Init2();

    		ruw_SafeMode=0;
    	}

	}

/*  */
void app_Main_Task(void)
{

switch(ruw_SafeMode)
{

case NORMAL_MODE_CASE:
app_NormalModeTask();
break;

case SAFE_MODE_CASE:
app_SafeModeTask();
break;

}

}
