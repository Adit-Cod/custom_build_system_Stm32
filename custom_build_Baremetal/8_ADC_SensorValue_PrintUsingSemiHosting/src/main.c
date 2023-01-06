/******************************************************************************
*****     	BARE METAL USING STRUCT									      *****
******************************************************************************/
/*!
***     \file       main.c
***
***     \author     Aditya
***
***
***     \brief      main control module for intended execution
***     \par        File_description
***
***
***
*\n*/
/*****************************************************************************/


/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/

/*------ standard includes -------*/
#include "Stdio.h"
#include "string.h"
#include "stdint.h"
/*------ project includes --------*/
#include "stm32f446xx.h"
#include "ADC_Driver.h"
/*------ module includes --------*/

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/


/* Use this MACRO to enable clock access to GPIOA in RCCAHB1ENR bit 0 */
#define GPIOAEN                                (1U<<0)
#define PIN5                                   (1U<<5)
#define LED_PIN                                PIN5
#define __IO                                   volatile

extern void initialise_monitor_handles(void);
uint32_t ADC_data_ui32;

/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/


/*=============================================================================
=======                       PRIVATE FUNCTION DECLARATIONS             =======
=============================================================================*/

/*=============================================================================
=======                              METHODS                            =======
=============================================================================*/

int main()
{
	initialise_monitor_handles();
	/* Set clock access to GPIOA to trigger LED */
	RCC->AHB1ENR |= GPIOAEN;
    /* Set the GPIOA Pin mode using the mode register */
    GPIOA->MODER |= (1U<<10);
    GPIOA->MODER &= ~(1U<<11);
    PA1_ADC_Init();
 
	while(1)
	{
		Start_ADC_Conversion();
		ADC_data_ui32 = ADC_Read();
		printf("ADC VAL= %d\n",(int)ADC_data_ui32);
		/* Toggle the LED by XORing */
		GPIOA->ODR ^= LED_PIN;
		/* generate an artificial delay in order to view toggling */
		for(int i= 0 ; i< 900000 ; i ++ ) {}
	}
	return 0;
}


