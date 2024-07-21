/*
 * Timer0_Interface.h
 *
 *  Created on: May 17, 2024
 *      Author: 20102
 */

#include "Timer0_Register.h"

#ifndef MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_

void Timer0_Init(const TIMER0_Config *CONFIG);

void Timer0_CallBackFnc_OV(const void(*pf)(void));

void Timer0_CallBackFnc_CM(const void(*pf)(void));

void __vector_10() __attribute__((signal));

void __vector_11() __attribute__((signal));

void Timer0_UpdateDutyCycle(const TIMER0_Compare_Type OutputMode,const u8 DutyCycle);

#endif /* MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_ */
