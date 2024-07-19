/*
 * Timer_Interface.h
 *
 *  Created on: May 18, 2024
 *      Author: 20102
 */

#ifndef MCAL_TIMER1_HEADER_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_HEADER_TIMER1_INTERFACE_H_

#include"Timer1_Register.h"

void Timer1_Init(CONFIG_TYPE * CONFIG);
void Timer1_SetCompareVal_A(u16 CompareVAL_A);
void Timer1_SetCompareVal_B(u16 CompareVAL_B);
void Timer1_SetTop(u16 ICR_Top);
void Timer1_deInit(void);

void Timer1_setCallBack_OV(void (*a_ptr)(void));
void Timer1_setCallBack_CM_B(void (*a_ptr)(void));
void Timer1_setCallBack_CM_A(void (*a_ptr)(void));

void __vector_9 () __attribute__((signal));//Timer1 OV
void __vector_8 () __attribute__((signal));//Timer1 CM_B
void __vector_7 () __attribute__((signal));//Timer1 CM_A

#endif /* MCAL_TIMER1_HEADER_TIMER1_INTERFACE_H_ */
