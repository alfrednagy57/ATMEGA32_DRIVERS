/*
 * ADC_Interface.h
 *
 *  Created on: May 10, 2024
 *      Author: 20102
 */

#include"ADC_Register.h"

#ifndef MCAL_ADC_HEADER_ADC_INTERFACE_H_
#define MCAL_ADC_HEADER_ADC_INTERFACE_H_

void ADC_Init(const ADC_Config *CONFIG);
u16 ADC_Get_DigitalValue(u8 Channel);


#endif /* MCAL_ADC_HEADER_ADC_INTERFACE_H_ */
