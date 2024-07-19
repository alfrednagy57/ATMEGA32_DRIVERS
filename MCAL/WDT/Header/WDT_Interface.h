/*
 * WDT_Interface.h
 *
 *  Created on: Jul 14, 2024
 *      Author: 20102
 */

#include "../Header/WDT_Register.h"
#include "../Header/WDT_Private.h"

#ifndef MCAL_WDT_HEADER_WDT_INTERFACE_H_
#define MCAL_WDT_HEADER_WDT_INTERFACE_H_

void WDT_Enable();

void WDT_Disable();

void WDT_Sleep(Type_PreScale Time);

#endif /* MCAL_WDT_HEADER_WDT_INTERFACE_H_ */
