/*
 * Timer_Private.h
 *
 *  Created on: May 18, 2024
 *      Author: 20102
 */

#include"../../../Common/StdType.h"

#ifndef MCAL_TIMER1_HEADER_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_HEADER_TIMER1_PRIVATE_H_

/*TCCR1A*/
typedef union
{
	u8 BYTE;
	struct
	{
		u8 WGM10  : 1;
		u8 WGM11  : 1;
		u8 FOC1B  : 1;
		u8 FOC1A  : 1;
		u8 COM1B0 : 1;
		u8 COM1B1 : 1;
		u8 COM1A0 : 1;
		u8 COM1A1 : 1;
	}Bits;
}Type_TCCR1A_REG;

typedef union
{
	u8 BYTE;
	struct
	{
		u8 CS10     : 1;
		u8 CS11     : 1;
		u8 CS12     : 1;
		u8 WGM12    : 1;
		u8 WGM13    : 1;
		u8 UNUSED_1 : 1;// must be always zero
		u8 ICES1    : 1;
		u8 ICNC1    : 1;
	}Bits;
}Type_TCCR1B_REG;

typedef union
{
	u8 BYTE;
	struct
	{
		u8 UNUSED_1    : 1;
		u8 UNUSED_2    : 1;
		u8 TOIE1       : 1;
		u8 OCIE1B      : 1;
		u8 OCIE1A      : 1;
		u8 TICIE1      : 1;
		u8 UNUSED_3    : 1;
		u8 UNUSED_4    : 1;
	}Bits;
}Type_TIMSK_REG;

typedef union
{
	u8 BYTE;
	struct
	{
		u8 UNUSED_1     : 1;
		u8 UNUSED_2     : 1;
		u8 TOV1         : 1;
		u8 OCF1B        : 1;
		u8 OCF1A        : 1;
		u8 ICF1         : 1;
		u8 UNUSED_3     : 1;
		u8 UNUSED_4     : 1;
	}Bits;
}Type_TIFR_REG;

typedef enum
{
	OC1_A_B_DISCONNECTED,
	TOGGLE_OC1_A_B_NORMAL_OPERATION_OC1_A_B_DISCONNECTED_WGM_15_FAST_9_14_PHASE_PWM,
	CLEAR_OC1_A_B_NON_INVERTING_PWM_MODE,
	SET_OC1_A_B_NON_INVERTING_PWM_MODE
}Type_COM1_A_B_0_1;

typedef enum
{
	Normal,
	__8_BITS_PHASE,
	__9_BITS_PHASE,
	__10_BITS_PHASE,
	CTC,
	__8_BITS_FAST,
	__9_BITS_FAST,
	__10_BITS_FAST,
	PHASE_FREQ_CORRECT_ICR1_TOP,
	PHASE_FREQ_CORRECT_OCR1A_TOP,
	PHASE_CORRECT_ICR1_TOP,
	PHASE_CORRECT_OCR1A_TOP,
	CTC_ICR1_TOP,
	Reserved,
	Fast_ICR1_TOP,
	Fast_OCR1A_TOP

}WAVE_GENERATION_MODES;

typedef enum
{

	NO_CLOCK_T1,
	F_CPU_CLOCK_T1,
	F_CPU_8_T1,
	F_CPU_64_T1,
	F_CPU_256_T1,
	F_CPU_1024_T1,
	EXTERNAL_CLK_ON_FALLING_EDGE_T1,
	EXTERNAL_CLK_ON_RISING_EDGE_T1

} TIMER1_ClockType;
typedef enum
{
	NO_INTERRUPT,
	OCIE_1_A,
	OCIE_1_B,
	TOIE_1,
	WITH_INTERRUPT
}TYPE_Interrupt;
typedef struct
{
	u8 FOC1A_STATE;
	u8 FOC1B_STATE;

	u16 PRE_VALUE_TCNT1;
	u16 PRE_VALUE_ICR1;
	u16 PRE_VALUE_OCR1B;
	u16 PRE_VALUE_OCR1A;

	TIMER1_ClockType CLK;
	WAVE_GENERATION_MODES WGM;
	Type_COM1_A_B_0_1 COM_A;
	Type_COM1_A_B_0_1 COM_B;
	TYPE_Interrupt INTERRUPT;

}CONFIG_TYPE;

#define PreScaleMask  0x07
#define TCRR1_Mask    0xF8

#define TCCR1A_CLK_MASK 0xFC
#define TCCR1B_CLK_MASK 0xE7

#define TCCR1A_COMA_MASK 0x3F
#define TCCR1A_COMB_MASK 0xCF

#define WCM_10_11_MASK   0x03
#define WCM_12_13_MASK   0x0C

#endif /* MCAL_TIMER1_HEADER_TIMER1_PRIVATE_H_ */
