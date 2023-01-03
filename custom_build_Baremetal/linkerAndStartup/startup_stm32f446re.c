/******************************************************************************
*****     	CUSTOM STARTUP FILE  									      *****
******************************************************************************/
/*!
***     \file       startup_stm32f446re.c
***
***     \author     Aditya
***
***
***     \brief      custom startup file to enable successful system startup
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

/*------ module includes --------*/

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/

extern uint32_t _estack;

/*=============================================================================
=======                       PRIVATE FUNCTION DECLARATIONS             =======
=============================================================================*/
void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler           (void)__attribute__((weak,alias("Default_Handler")));
void HardFault_Handler     (void)__attribute__((weak,alias("Default_Handler")));
void MemManage_Handler     (void)__attribute__((weak,alias("Default_Handler")));
void BusFault_Handler      (void)__attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler    (void)__attribute__((weak,alias("Default_Handler")));
void SVCall_Handler        (void)__attribute__((weak,alias("Default_Handler")));
void DebugMonitor_Handler  (void)__attribute__((weak,alias("Default_Handler")));
void PendSV_Handler        (void)__attribute__((weak,alias("Default_Handler")));
void Systick_Handler       (void)__attribute__((weak,alias("Default_Handler")));
void WWDG_Handler          (void)__attribute__((weak,alias("Default_Handler")));
void PVD_Handler           (void)__attribute__((weak,alias("Default_Handler")));
void TAMPSTAMP_Handler     (void)__attribute__((weak,alias("Default_Handler")));
void RTCWKUP_Handler       (void)__attribute__((weak,alias("Default_Handler")));
void FLASH_Handler         (void)__attribute__((weak,alias("Default_Handler")));
void RCC_Handler           (void)__attribute__((weak,alias("Default_Handler")));
void EXTI0_Handler         (void)__attribute__((weak,alias("Default_Handler")));
void EXTI1_Handler         (void)__attribute__((weak,alias("Default_Handler")));
void EXTI2_Handler         (void)__attribute__((weak,alias("Default_Handler")));
void EXTI3_Handler         (void)__attribute__((weak,alias("Default_Handler")));
void EXTI4_Handler         (void)__attribute__((weak,alias("Default_Handler")));
void DMA1Stream0_Handler   (void)__attribute__((weak,alias("Default_Handler")));
void DMA1Stream1_Handler   (void)__attribute__((weak,alias("Default_Handler")));
void DMA1Stream2_Handler   (void)__attribute__((weak,alias("Default_Handler")));
void DMA1Stream3_Handler   (void)__attribute__((weak,alias("Default_Handler")));
void DMA1Stream4_Handler   (void)__attribute__((weak,alias("Default_Handler")));
void DMA1Stream5_Handler   (void)__attribute__((weak,alias("Default_Handler")));
void DMA1Stream6_Handler   (void)__attribute__((weak,alias("Default_Handler")));
void ADC_Handler           (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_TX_Handler       (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_RX0_Handler      (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_RX1_Handler      (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_SCE_Handler      (void)__attribute__((weak,alias("Default_Handler")));
void EXTI9_5_Handler       (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_TIM9_Handler (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_UP_TIM10_Handler (void)__attribute__((weak,alias("Default_Handler")));
void TIM1TRG_COMTIM11_Handler (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_CC_Handler       (void)__attribute__((weak,alias("Default_Handler")));
void TIM2IRQ_Handler       (void)__attribute__((weak,alias("Default_Handler")));
void TIM3IRQ_Handler       (void)__attribute__((weak,alias("Default_Handler")));
void TIM4IRQ_Handler       (void)__attribute__((weak,alias("Default_Handler")));
void I2C1_EVIRQ_Handler    (void)__attribute__((weak,alias("Default_Handler")));
void I2C1_ERIRQ_Handler    (void)__attribute__((weak,alias("Default_Handler")));
void I2C2_EVIRQ_Handler    (void)__attribute__((weak,alias("Default_Handler")));
void I2C2_ERIRQ_Handler    (void)__attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler       (void)__attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler       (void)__attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler  (void)__attribute__((weak,alias("Default_Handler")));
void RTC_Alarm_IRQHandler  (void)__attribute__((weak,alias("Default_Handler")));
void OTG_FSWKUP_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler      (void)__attribute__((weak,alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void TIM8_CC_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void DMA1Stream7_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void FMC_IRQHandler         (void)__attribute__((weak,alias("Default_Handler")));
void SDIO_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void TIM5_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void SPI3_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void USART4_IRQHandler      (void)__attribute__((weak,alias("Default_Handler")));
void USART5_IRQHandler      (void)__attribute__((weak,alias("Default_Handler")));
void TIM6_DAC_IRQHandler    (void)__attribute__((weak,alias("Default_Handler")));
void TIM7_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void CAN2_TX_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void CAN2_RX0_IRQHandler    (void)__attribute__((weak,alias("Default_Handler")));
void CAN2_RX1_IRQHandler    (void)__attribute__((weak,alias("Default_Handler")));
void CAN2_SCE_IRQHandler    (void)__attribute__((weak,alias("Default_Handler")));
void OTG_FS_IRQHandler      (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream6_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream7_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void USART6_IRQHandler      (void)__attribute__((weak,alias("Default_Handler")));
void I2C3_EV_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void I2C3_ER_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler  (void)__attribute__((weak,alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));
void OTG_HS_IRQHandler      (void)__attribute__((weak,alias("Default_Handler")));
void DCMI_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void FPU_IRQHandler         (void)__attribute__((weak,alias("Default_Handler")));
void SPI4_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void SAI1_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void SAI2_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void QuadSPI_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void HDMI_CEC_IRQHandler    (void)__attribute__((weak,alias("Default_Handler")));
void SPDIF_Rx_IRQHandler    (void)__attribute__((weak,alias("Default_Handler")));
void FMPI2C1_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void FMPI2C1_ER_IRQHandler  (void)__attribute__((weak,alias("Default_Handler")));
/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/
/* The following array is placed in the isr_vector_tbl section and it contains the interrupt handlers*/

/* NOTE:
   The content of the vector table must be placed exactly the way shown in the reference manual 
   of the microcontroller.
*/

uint32_t vector_tbl[] __attribute__((section(".isr_vector_tbl")))={
	
	(uint32_t)&_estack,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
	0,
	0,
	0,
	0,/* Reserved*/
	(uint32_t)&SVCall_Handler,
	(uint32_t)&DebugMonitor_Handler,
	0,
	(uint32_t)&PendSV_Handler,
	(uint32_t)&Systick_Handler,
	(uint32_t)&WWDG_Handler,
	(uint32_t)&PVD_Handler,
	(uint32_t)&TAMPSTAMP_Handler,
	(uint32_t)&RTCWKUP_Handler,
	(uint32_t)&FLASH_Handler,
	(uint32_t)&RCC_Handler,
	(uint32_t)&EXTI0_Handler,
	(uint32_t)&EXTI1_Handler,
	(uint32_t)&EXTI2_Handler,
	(uint32_t)&EXTI3_Handler,
	(uint32_t)&EXTI4_Handler,
	(uint32_t)&DMA1Stream0_Handler,
	(uint32_t)&DMA1Stream1_Handler,
	(uint32_t)&DMA1Stream2_Handler,
	(uint32_t)&DMA1Stream3_Handler,
	(uint32_t)&DMA1Stream4_Handler,
	(uint32_t)&DMA1Stream5_Handler,
	(uint32_t)&DMA1Stream6_Handler,
    (uint32_t)&ADC_Handler,
	(uint32_t)&CAN1_TX_Handler,
	(uint32_t)&CAN1_RX0_Handler,
	(uint32_t)&CAN1_RX1_Handler,
	(uint32_t)&CAN1_SCE_Handler,
	(uint32_t)&EXTI9_5_Handler,
	(uint32_t)&TIM1_BRK_TIM9_Handler,
	(uint32_t)&TIM1_UP_TIM10_Handler,
	(uint32_t)&TIM1TRG_COMTIM11_Handler,
	(uint32_t)&TIM1_CC_Handler,
	(uint32_t)&TIM2IRQ_Handler,
	(uint32_t)&TIM3IRQ_Handler,
	(uint32_t)&TIM4IRQ_Handler,
	(uint32_t)&I2C1_EVIRQ_Handler,
	(uint32_t)&I2C1_ERIRQ_Handler,
	(uint32_t)&I2C2_EVIRQ_Handler,
	(uint32_t)&I2C2_ERIRQ_Handler,
	(uint32_t)&SPI1_IRQHandler,
	(uint32_t)&SPI2_IRQHandler,
	(uint32_t)&USART1_IRQHandler,
	(uint32_t)&USART2_IRQHandler,
	(uint32_t)&USART3_IRQHandler,
	(uint32_t)&EXTI15_10_IRQHandler,
	(uint32_t)&OTG_FSWKUP_IRQHandler,
	(uint32_t)&TIM8_BRK_TIM12_IRQHandler,
	(uint32_t)&TIM8_UP_TIM13_IRQHandler,
	(uint32_t)&TIM8_TRG_COM_TIM14_IRQHandler,
	(uint32_t)&TIM8_CC_IRQHandler,
	(uint32_t)&DMA1Stream7_IRQHandler,
	(uint32_t)&FMC_IRQHandler,
	(uint32_t)&SDIO_IRQHandler,
	(uint32_t)&TIM5_IRQHandler,
	(uint32_t)&SPI3_IRQHandler,
	(uint32_t)&USART4_IRQHandler,
	(uint32_t)&USART5_IRQHandler,
	(uint32_t)&TIM6_DAC_IRQHandler,
	(uint32_t)&TIM7_IRQHandler,
	(uint32_t)&DMA2_Stream0_IRQHandler,
	(uint32_t)&DMA2_Stream1_IRQHandler,
	(uint32_t)&DMA2_Stream2_IRQHandler,
	(uint32_t)&DMA2_Stream3_IRQHandler,
	(uint32_t)&DMA2_Stream4_IRQHandler,
	0,
	0,
	(uint32_t)&CAN2_TX_IRQHandler,
	(uint32_t)&CAN2_RX0_IRQHandler,
	(uint32_t)&CAN2_RX1_IRQHandler,
	(uint32_t)&CAN2_SCE_IRQHandler,
	(uint32_t)&OTG_FS_IRQHandler,
	(uint32_t)&DMA2_Stream5_IRQHandler,
	(uint32_t)&DMA2_Stream6_IRQHandler,
	(uint32_t)&DMA2_Stream7_IRQHandler,
	(uint32_t)&USART6_IRQHandler,
	(uint32_t)&I2C3_EV_IRQHandler,
	(uint32_t)&I2C3_ER_IRQHandler,
	(uint32_t)&OTG_HS_EP1_OUT_IRQHandler,
	(uint32_t)&OTG_HS_EP1_IN_IRQHandler,
	(uint32_t)&OTG_HS_WKUP_IRQHandler,
	(uint32_t)&OTG_HS_IRQHandler,
	(uint32_t)&DCMI_IRQHandler,
	0,
	0,
	(uint32_t)&FPU_IRQHandler,
	0,
	0,
	(uint32_t)&SPI4_IRQHandler,
	0,
	0,
	(uint32_t)&SAI1_IRQHandler,
	0,
	0,
	0,
	(uint32_t)&SAI2_IRQHandler,
	(uint32_t)&QuadSPI_IRQHandler,
	(uint32_t)&HDMI_CEC_IRQHandler,
	(uint32_t)&SPDIF_Rx_IRQHandler,
	(uint32_t)&FMPI2C1_IRQHandler,
	(uint32_t)&FMPI2C1_ER_IRQHandler,
};

/*=============================================================================
=======                              METHODS                            =======
=============================================================================*/

/*---------------------------------------------------------------------------*/
/*     FUNCTION: reset_Handler()
 */

/*!    \brief    First function to be executed on system startup
 *
 *
 *     \param    void
 *    
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *     Startup File: Execute startup relevant code.
 *//*------------------------------------------------------------------------*/
void Reset_Handler(void)
{
	/* NOTE
	   One of the tasks of reset handler would be to copy the .data section from flash to SRAM 
	   In order to pinpoint the actual address of the .data section in the flash memory; linker symbols 
	   are used
	*/
	
	
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: default_Handler()
 */

/*!    \brief    Default Handler to be executed for any weak alias
 *
 *
 *     \param    void
 *    
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *     Loop continuously as it handles interrupts and system exceptions; other than system reset.
 
 *//*------------------------------------------------------------------------*/
void Default_Handler(void)
{
	while(1){/* Do Nothing */}
}