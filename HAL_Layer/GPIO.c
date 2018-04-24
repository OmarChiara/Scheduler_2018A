/*
 * GPIO.c
 *
 *  Created on: Mar 22, 2018
 *      Author: Misael
 */


#include "fsl_gpio.h"
#include "GPIO.h"
#include "fsl_port.h"
#include "stdtypedef.h"

void GPIO_Init(void)

{
	//ENABLE PORTB CLOCK
	CLOCK_EnableClock(kCLOCK_PortB);

/*	//SET BUTTON PORT AS GPIO
	port_pin_config_t ls_portb_mux;


	    	ls_portb_mux.mux = kPORT_MuxAsGpio;
	    	ls_portb_mux.pullSelect = kPORT_PullUp;


	    	PORT_SetPinConfig(PORTB,LED_BUTTON, &ls_portb_mux);
	    	//SET BUTTON PORT AS INPUT
	    	gpio_pin_config_t ls_portbcfg;

	    	ls_portbcfg.pinDirection = kGPIO_DigitalInput;
	    	ls_portbcfg.outputLogic= 0u;

	    	GPIO_PinInit(GPIOB, LED_BUTTON,&ls_portbcfg); */

	    	//SET LED PORT AS GPIO

	    	port_pin_config_t ls_LedMode1PinMux;
	        ls_LedMode1PinMux.mux = kPORT_MuxAsGpio;
	      //  ls_LedMode1PinMux.pullSelect = kPORT_PullUp;




	        PORT_SetPinConfig(PORTB,APP_LED, &ls_LedMode1PinMux);
	    	gpio_pin_config_t ls_LedMode1PinCfg;
	    	//SET LED PORT AS OUTPUT
	    	ls_LedMode1PinCfg.pinDirection = kGPIO_DigitalOutput;
	    	ls_LedMode1PinCfg.outputLogic= FALSE;
	    	//PIN Initialization


	    	GPIO_PinInit(GPIOB, APP_LED,&ls_LedMode1PinCfg);

}

void app_PinsAsInput (void)
{



	port_pin_config_t ls_LedMode1PinMux;
    ls_LedMode1PinMux.mux = kPORT_PinDisabledOrAnalog;


	PORT_SetPinConfig(PORTB,0u, &ls_LedMode1PinMux);
	PORT_SetPinConfig(PORTB,1u, &ls_LedMode1PinMux);
	PORT_SetPinConfig(PORTB,2u, &ls_LedMode1PinMux);
	PORT_SetPinConfig(PORTB,3u, &ls_LedMode1PinMux);
    PORT_SetPinConfig(PORTB,APP_LED, &ls_LedMode1PinMux);

}
