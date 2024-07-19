/*
 * GIE_Register.h
 *
 *  Created on: Jul 14, 2024
 *      Author: 20102
 */

#include "../../Common/StdType.h"

#ifndef MCAL_SREG_GIE_PRIVATE_H_
#define MCAL_SREG_GIE_PRIVATE_H_

typedef union
{
	u8 BYTE;

	struct
	{
		u8 Carry_Flag:1;
		u8 Zero_Flag:1;
		u8 Negative_Flag:1;
		u8 TWO_COMP_Flag:1;
		u8 Sign_Flag:1;
		u8 Half_Carry_Flag:1;
		u8 Copy_Storage_Flag:1;
		u8 GIE_Enable:1;
	}Bits;

}Type_Status_Register;

#define SREG_REG (*(volatile Type_Status_Register * const)0x5F)


#endif /* MCAL_SREG_GIE_PRIVATE_H_ */
