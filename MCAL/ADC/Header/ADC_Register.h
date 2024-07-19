/*
 * ADC_Register.h
 *
 *  Created on: May 10, 2024
 *      Author: 20102
 */

#include "ADC_Private.h"

#ifndef MCAL_ADC_HEADER_ADC_REGISTER_H_
#define MCAL_ADC_HEADER_ADC_REGISTER_H_

#define ADCMUX_REG   (*(volatile Type_ADC_MUX_REG * const)0x27)
#define ADCSRA_REG   (*(volatile Type_ADCSRA_REG * const)0x26)
//#define ADCH    *((volatile u8 *)0x25)
//#define ADCL    *((volatile u8 *)0x24)
#define ADCData  	 (*(volatile u16 * const)0x24)
#define ADCSPIOR     (*(volatile u8 * const)0x50)

#endif /* MCAL_ADC_HEADER_ADC_REGISTER_H_ */
