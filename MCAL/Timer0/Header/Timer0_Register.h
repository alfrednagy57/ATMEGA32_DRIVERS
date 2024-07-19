/*
 * Timer0_Register.h
 *
 *  Created on: May 17, 2024
 *      Author: 20102
 */

#ifndef MCAL_TIMER0_HEADER_TIMER0_REGISTER_H_
#define MCAL_TIMER0_HEADER_TIMER0_REGISTER_H_

#include "../../../Common/StdType.h"
#include "Timer0_Private.h"

#define Timer0_TCCR0_REG  (*(volatile Timer0_TCCR0_Type * const)0x53)

#define Timer0_TIMSK_REG  (*(volatile Timer0_TIMSK_Type *const)0x59)

#define Timer0_TIFR_REG   (*(volatile Timer0_TIFR_Type* const )0x58)

#define Timer0_TCNT0_REG  (*(volatile u8 * const)0x52)

#define Timer0_OCR0_REG   (*(volatile u8 * const)0x5C)

#endif /* MCAL_TIMER0_HEADER_TIMER0_REGISTER_H_ */
