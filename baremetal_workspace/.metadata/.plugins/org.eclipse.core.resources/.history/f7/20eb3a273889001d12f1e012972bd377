/******************************************************************************
*****     															      *****
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
/*------ project includes --------*/

/*------ module includes --------*/

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/

#define PERIPHERAL_BASE                        (0x40000000UL)
#define AHB1PERIPHERAL_OFFSET                  (0x00020000UL)
#define AHB1PERIPHERAL_BASE                    (PERIPHERAL_BASE + AHB1PERIPHERAL_OFFSET)
#define GPIOA_OFFSET                           (0x0000U)
#define GPIOAPERIPHERAL_BASE                   (AHB1PERIPHERAL_BASE + GPIOA_OFFSET)
#define RCC_OFFSET                             (0x3800UL)
#define RCCPERIPHERAL_BASE                     (AHB1PERIPHERAL_BASE + RCC_OFFSET)
#define AHB1ENR_OFFSET                         (0x30UL)
#define RCC_AHB1ENR                            (*(volatile unsigned int *)(RCCPERIPHERAL_BASE + AHB1ENR_OFFSET))
/* Use this MACRO to enable clock access to GPIOA in RCCAHB1ENR bit 0 */
#define GPIOAEN                                (1U<<0)
#define GPIOMODER_OFFSET                       (0x00U)
#define GPIOA_MODER                            (*(volatile unsigned int *)(GPIOAPERIPHERAL_BASE + GPIOMODER_OFFSET))
#define GPIOAODR_OFFSET                        (0x14UL)
#define GPIOA_ODR                              (*(volatile unsigned int *)(GPIOAPERIPHERAL_BASE + GPIOAODR_OFFSET))
#define PIN5                                   (1U<<5)
#define LED_PIN                                PIN5

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
	/* Set clock access to GPIOA to trigger LED */
	RCC_AHB1ENR |= GPIOAEN;
    /* Set the GPIOA Pin mode using the mode register */
	GPIOA_MODER |= (1U<<10);
	GPIOA_MODER &= ~(1U<<11);

	while(1)
	{
		/* Set the respective pin to high */
		//GPIOA_ODR |= LED_PIN;

		/* Toggle the LED by XORing */
		GPIOA_ODR ^= LED_PIN;
		/* generate an artificial delay in order to view toggling */
		for(int i= 0 ; i< 1000000 ; i ++ ) {}

	}

	return 0;
}


