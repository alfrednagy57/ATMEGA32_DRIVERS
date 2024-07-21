/*
 * WDT_Program.c
 *
 *  Created on: Jul 14, 2024
 *      Author: 20102
 */


#include "../Header/WDT_Interface.h"

void WDT_Enable()
{
	// wdt reset flag it is setted when a wdt reset occurs
    MCUCSR_REG.Bits.WDRF = 1;
	//set bit wde in wdtcr register
	WDTCR_REG.Bits.WDE=1;
}
void WDT_Disable()
{
	WDTCR_REG.BYTE=(WDTCR_REG.BYTE&WDTCR_MASK)|(TURN_OFF_CODE_MASK);
	WDTCR_REG.BYTE=0;
}
void WDT_Sleep(const Type_PreScale Time)
{
	WDTCR_REG.BYTE=(WDTCR_REG.BYTE&WDT_SET_CLOCK)|(Time&WDT_PRSCALE_MASK);
}

