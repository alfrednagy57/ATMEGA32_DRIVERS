/*
 * GIE.c
 *
 *  Created on: Jul 14, 2024
 *      Author: 20102
 */


#include "GIE_Private.h"
#include "GIE.h"

void GIE_Enable()
{
	SREG_REG.Bits.GIE_Enable=1;
}
void GIE_Disable()
{
	SREG_REG.Bits.GIE_Enable=0;
}
