/*
 * ADC_Driver.h
 *
 *  Created on: Jan 6, 2023
 *      Author: User
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <stdint.h>

void PA1_ADC_Init(void);
void Start_ADC_Conversion(void);
uint32_t ADC_Read(void);
#endif /* ADC_DRIVER_H_ */
