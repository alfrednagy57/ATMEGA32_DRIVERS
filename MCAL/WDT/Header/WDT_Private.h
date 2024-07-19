/*
 * WDT_Private.h
 *
 *  Created on: Jul 14, 2024
 *      Author: 20102
 */

#include "../../../Common/StdType.h"

#ifndef MCAL_WDT_HEADER_WDT_PRIVATE_H_
#define MCAL_WDT_HEADER_WDT_PRIVATE_H_

typedef union
{
	u8 BYTE;
	struct
	{
		u8 PORF   : 1;
		u8 EXTRF  : 1;
		u8 BORF   : 1;
		u8 WDRF   : 1;
		u8 JTRF   : 1;
		u8 UNUSED : 3;
	}Bits;
}Type_WDT_MCUCSR;

typedef union
{
	u8 BYTE;
	struct
	{
		u8 WDP0   : 1;
		u8 WDP1   : 1;
		u8 WDP2   : 1;
		u8 WDE    : 1;
		u8 WDTOE  : 1;
		u8 UNUSED : 3;
	}Bits;
}Type_WDT_WDTCR;

typedef enum
{
	__16_3_MS,
	__32_5_MS,
	__65_MS,
	__0_13_S,
	__0_26_S,
	__0_52_S,
	__1_S,
	__2_1_S

}Type_PreScale;

#define WDTCR_MASK 0xE7
#define TURN_OFF_CODE_MASK 0x18

#define WDT_SET_CLOCK 0xF8
#define WDT_PRSCALE_MASK 0x07

#endif /* MCAL_WDT_HEADER_WDT_PRIVATE_H_ */
