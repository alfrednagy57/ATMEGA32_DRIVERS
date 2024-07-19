/*
 * ICU_Private.h
 *
 *  Created on: Jun 19, 2024
 *      Author: 20102
 */

#include "../../../Common/StdType.h"

#ifndef MCAL_ICU_HEADER_ICU_PRIVATE_H_
#define MCAL_ICU_HEADER_ICU_PRIVATE_H_

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

	NO_CLOCK,
	F_CPU_CLOCK,
	F_CPU_8,
	F_CPU_64,
	F_CPU_256,
	F_CPU_1024,
	EXTERNAL_CLK_ON_FALLING_EDGE,
	EXTERNAL_CLK_ON_RISING_EDGE

} ICU_ClockType;

typedef enum
{

	FALLING,
	RAISING

} ICU_EdgeType;

#define TCCR1B_EDGE_SELECT_MASK  0xBF
#define ICU_CLK_MASK  0xF8
#endif /* MCAL_ICU_HEADER_ICU_PRIVATE_H_ */
