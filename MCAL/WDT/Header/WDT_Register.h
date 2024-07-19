/*
 * WDT_Register.h
 *
 *  Created on: Jul 14, 2024
 *      Author: 20102
 */

#include "WDT_Private.h"

#ifndef MCAL_WDT_HEADER_WDT_REGISTER_H_
#define MCAL_WDT_HEADER_WDT_REGISTER_H_

#define  WDTCR_REG  (*(volatile Type_WDT_WDTCR *const)0x41)
#define  MCUCSR_REG (*(volatile Type_WDT_MCUCSR *const)0x54)

#endif /* MCAL_WDT_HEADER_WDT_REGISTER_H_ */
