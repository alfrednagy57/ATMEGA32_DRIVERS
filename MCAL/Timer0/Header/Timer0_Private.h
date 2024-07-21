/*
 * Timer0_Private.h
 *
 *  Created on: May 17, 2024
 *      Author: 20102
 */

#include "../../../Common/StdType.h"
#include "../../GPIO/Header/GPIO_Register.h"

#ifndef MCAL_TIMER0_HEADER_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_HEADER_TIMER0_PRIVATE_H_

typedef union
{
	u8 Byte;
	struct
	{
		u8 CS00:1;
		u8 CS01:1;
		u8 CS02:1;
		u8 WGM01:1;
		u8 COM00:1;
		u8 COM01:1;
		u8 WGM00:1;
		u8 FOC0:1;
	}Bits;
}Timer0_TCCR0_Type;


typedef union
{
	u8 _2Bits ;
	struct
	{
		u8 TOIE0:1;
		u8 OCIE0:1;
		u8 UNUSED_6:6;
	}Bits;
}Timer0_TIMSK_Type;


typedef enum
{
	Off,
	NoScale,
	Over8,
	Over64,
	Over256,
	Over1024,
	ExternelOnFallingEdge,
	ExternalOnRisingEdge

}Timer0_PreScale;

typedef enum
{
	Normal_Timer0,
	Phase_Correct_Timer0,
	CTC_Timer0,
	FastPWM_Timer0
}Timer0_Operation_Modes;

typedef enum
{
	NORMAL_MODE_OC0_DISCONNECTED,
	CTC_TOGGLE__PWM_RESERVED,
	CTC_CLEAR__PWM_NON_INVERTING,
	CTC_SET__PWM_INVERTING
} TIMER0_Compare_Type;

typedef union
{
	u8 _2Bits;
	struct
	{
		u8 TOV0:1;
		u8 OCF0:1;
		u8 UNUSED_6:6;
	}Bits;
}Timer0_TIFR_Type;

typedef struct
{
	u8 initial_value;
	u8 compare_value; /* for CTC mode only */
	Timer0_Operation_Modes mode;
	Timer0_PreScale prescaler;
	TIMER0_Compare_Type outputMode;

} TIMER0_Config;

/*SFIOR*/
#define PSR10 0



#define OC0_PORTID      DIO_DDRB//b
#define OC0_PINID 		3

#define TCCR0_MASK  		  0xF8
#define PreScale_MASK		  0x07

#define NonInverting          1
#define Inverting             2

#endif /* MCAL_TIMER0_HEADER_TIMER0_PRIVATE_H_ */
