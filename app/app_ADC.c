/*
 * app_ADC.c
 *
 *  Created on: Apr 5, 2018
 *      Author: Misael
 */


#include "stdtypedef.h"
#include "fsl_adc16.h"
#include "app_ADC.h"
#include "app_Main.c"
#include "LED.h"

 /******************************************
 * Private Macros
 ******************************************/
#define APP_ADC_CHANNEL 		0u
#define APP_ADC_CHANNEL_GROUP 	0u

 /******************************************
 * Private Typedef
 ******************************************/

 /******************************************
 * Public Const
 ******************************************/

 /******************************************
 * Private Const
 ******************************************/

 /******************************************
 * Public Variables
 ******************************************/

 /******************************************
 * Private Variables
 ******************************************/
static T_UWORD ruw_ADCValue = 0u;
static T_UBYTE rub_ConversionInProgressFlag = FALSE;
T_UWORD ruw_SafeCount;
T_UWORD ruw_SafeMode;
T_UBYTE ruw_ADC200;
 /******************************************
 * Private Prototypes
 ******************************************/
static void app_ADC_Trigger(void);
static T_UBYTE app_ADC_IsConversionCompleted(void);
static T_UWORD app_ADC_GetValue(void);

 /******************************************
 * Code
 ******************************************/

/***********************************************
 * Function Name: app_ADC_Init
 * Description: TBD
 ***********************************************/
void app_ADC_Init(void)
{
	adc16_config_t ls_ADCConfig;

	//Initialize structure with default values
	ADC16_GetDefaultConfig(&ls_ADCConfig);

	//Init ADC Module
	ADC16_Init(ADC0, &ls_ADCConfig);

	//Disable Hardware Trigger
	ADC16_EnableHardwareTrigger(ADC0, FALSE); /* Make sure the software trigger is used. */

	//Perform Autocalibration
	(void)ADC16_DoAutoCalibration(ADC0);
}

/***********************************************
 * Function Name: app_ADC_Trigger
 * Description: TBD
 ***********************************************/
static void app_ADC_Trigger(void)
{
	adc16_channel_config_t ls_ChannelConfig;

	//Channel Selection
	ls_ChannelConfig.channelNumber = APP_ADC_CHANNEL;

	//Disable Interrupt when Conversion is completed
	ls_ChannelConfig.enableInterruptOnConversionCompleted = FALSE;

	//Disable Differential Conversion
	ls_ChannelConfig.enableDifferentialConversion = FALSE;

	ADC16_SetChannelConfig(ADC0, APP_ADC_CHANNEL_GROUP, &ls_ChannelConfig);
}

/***********************************************
 * Function Name: app_ADC_IsConversionCompleted
 * Description: TBD
 ***********************************************/
static T_UBYTE app_ADC_IsConversionCompleted(void)
{
	T_UBYTE lub_Return;

	lub_Return = FALSE;

	//Check if Conversion was completed
	if(kADC16_ChannelConversionDoneFlag &
			ADC16_GetChannelStatusFlags(ADC0, APP_ADC_CHANNEL_GROUP))
	{
		//Conversion Completed
		lub_Return = TRUE;
	}
	else
	{
		//Conversion not completed
		lub_Return = FALSE;
	}

	return lub_Return;
}

/***********************************************
 * Function Name: app_ADC_GetValue
 * Description: TBD
 ***********************************************/
extern T_UWORD app_ADC_GetValue(void)
{
	//Return Last Conversion Value
	return ADC16_GetChannelConversionValue(ADC0, APP_ADC_CHANNEL_GROUP);
}

/***********************************************
 * Function Name: app_ADC_Task
 * Description: TBD
 ***********************************************/
void app_ADC_Task(void)
{
	//Check if a conversion is in progress
	if(TRUE == rub_ConversionInProgressFlag)
	{
		//Check if Conversion was completed
		if(TRUE == app_ADC_IsConversionCompleted())
		{
			//Store the ADC Value
			ruw_ADCValue = app_ADC_GetValue();

			//Clear conversion in progress flag
			rub_ConversionInProgressFlag = FALSE;
		}
		else
		{
			/* Do nothing */
		}
	}
	else
	{
		//Trigger the ADC Conversion
		app_ADC_Trigger();

		//Set Conversion in progress flag
		rub_ConversionInProgressFlag = TRUE;
	}


}

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
		HEAT_50_OFF;
		HEAT_100;
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
	HEAT_50_OFF;
	HEAT_50_OFF;
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
	HEAT_50_OFF;
	FAN_100_OFF;
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


//ADC Working at 200ms

void app_ADC200 (void)
{
	if (ruw_ADC200 >= 20)
	{
		app_ADC_Task();
		ruw_ADC200=0;
	}

	else
	{
		ruw_ADC200++;
	}

}
