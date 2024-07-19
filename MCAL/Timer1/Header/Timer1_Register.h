/*
 * Timer_Register.h
 *
 *  Created on: May 18, 2024
 *      Author: 20102
 */

#include "Timer1_Private.h"

#ifndef MCAL_TIMER1_HEADER_TIMER1_REGISTER_H_
#define MCAL_TIMER1_HEADER_TIMER1_REGISTER_H_

#define TCCR1A_REG     (*(volatile Type_TCCR1A_REG * const)0x4F)

/*Timer/Counter1 Control Register B – TCCR1B*/
#define TCCR1B_REG     (*(volatile Type_TCCR1B_REG * const)0x4E)

// Timer Counter Interrupt Mask
#define TIMSK_REG      (*(volatile Type_TIMSK_REG * const)0x59)

//timer counter interrupt flag Register
#define TIFR_REG	   (*(volatile Type_TIFR_REG * const)0x58)

/*Counter overflow*/
#define TCNT1_REG      (*(volatile u16 *const)0x4C)

/* Input Capture Register 1 - ICR1*/
#define  ICR1_REG	   (*(volatile u16 *const)0x46)

#define Timer1_OCR1B   (*(volatile u16 *const)0x48)
#define Timer1_OCR1A   (*(volatile u16 *const)0x4A)

#endif /* MCAL_TIMER1_HEADER_TIMER1_REGISTER_H_ */
