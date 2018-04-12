/*
 * app_PWM.c
 *
 *  Created on: Apr 10, 2018
 *      Author: Misael
 */


#include "stdtypedef.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_tpm.h"
#include "app_PWM.h"

/******************************************
 * Variables
 ******************************************/
T_UBYTE rub_PWMDutyCycle = 0u;



void app_PWM_IncreaseDutyCycle(void);
void app_PWM_DecreaseDutyCycle(void);
/******************************************
 * Code
 ******************************************/

/***********************************************
 * Function Name: app_PWM_Init
 * Description: TBD
 ***********************************************/
void app_PWM_Init(void)
{
	tpm_config_t ls_TPMConfig;
	port_pin_config_t ls_PortConfig;
	tpm_chnl_pwm_signal_param_t ls_PWMParam;

	/* Enable Clock */
	//CLOCK_EnableClock(kCLOCK_Tpm2); //FOR LED RED
	CLOCK_SetTpmClock(1);

	/* PWM PIN Config */
	ls_PortConfig.mux = kPORT_MuxAlt3; //For PTB19, ALT3 is TPM2_CH1
	ls_PortConfig.pullSelect = kPORT_PullUp;

	PORT_SetPinConfig(PORTB, 19u, &ls_PortConfig);

	/* Get Default Config */
	TPM_GetDefaultConfig(&ls_TPMConfig);

	TPM_Init(TPM2, &ls_TPMConfig);

	/* PWM Setup */
	ls_PWMParam.chnlNumber = kTPM_Chnl_1;
	ls_PWMParam.dutyCyclePercent = rub_PWMDutyCycle;
	ls_PWMParam.level = kTPM_LowTrue;
	TPM_SetupPwm(TPM2, &ls_PWMParam, 1u, kTPM_CenterAlignedPwm, 24000u, CLOCK_GetFreq(kCLOCK_PllFllSelClk));

	/* Start PWM Timer */
	TPM_StartTimer(TPM2, kTPM_SystemClock);
}

/***********************************************
 * Function Name: app_PWM_SetValue
 * Description: TBD
 ***********************************************/
void app_PWM_SetValue(T_UBYTE lub_Duty)
{
	/* Update duty cycle */
	TPM_UpdatePwmDutycycle(TPM2, kTPM_Chnl_1, kTPM_CenterAlignedPwm, lub_Duty);
}

/***********************************************
 * Function Name: app_PWM_Task
 * Description: TBD
 ***********************************************/
void app_PWM_Task50(void)
{
	app_PWM_SetValue(5);
}

void app_PWM_Task100(void)
{
	app_PWM_SetValue(10);
}


