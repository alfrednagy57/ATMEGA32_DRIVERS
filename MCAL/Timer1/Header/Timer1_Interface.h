/*
 * Timer_Interface.h
 *
 *  Created on: May 18, 2024
 *      Author: 20102
 */

#include"Timer1_Register.h"

#ifndef MCAL_TIMER1_HEADER_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_HEADER_TIMER1_INTERFACE_H_

void Timer1_Init(const CONFIG_TYPE_Timer1 * CONFIG);
void Timer1_SetCompareVal_A(const u16 CompareVAL_A);
void Timer1_SetCompareVal_B(const u16 CompareVAL_B);
void Timer1_SetICR1(const u16 ICR1_Top);
void Timer1_SetTCNT1(const u16 TCNT1_Top);

void Timer1_deInit(void);

void Timer1_setCallBack_OV(void (*a_ptr)(void));
void Timer1_setCallBack_CM_B(void (*a_ptr)(void));
void Timer1_setCallBack_CM_A(void (*a_ptr)(void));

void __vector_9 () __attribute__((signal));//Timer1 OV
void __vector_8 () __attribute__((signal));//Timer1 CM_B
void __vector_7 () __attribute__((signal));//Timer1 CM_A

#endif /* MCAL_TIMER1_HEADER_TIMER1_INTERFACE_H_ */
