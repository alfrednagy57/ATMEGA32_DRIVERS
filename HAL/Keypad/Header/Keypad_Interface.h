/*
 * Keypad_Interface.h
 *
 *  Created on: Apr 19, 2024
 *      Author: 20102
 */

#include "../../../Common/Stdtype.h"

#include "Keypad_Private.h"
#include "Keypad_Config.h"

#ifndef HAL_KEYPAD_HEADER_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_HEADER_KEYPAD_INTERFACE_H_

void Keypad_Init(void);
u8   Keypad_ReadBtnValue(void);

#endif /* HAL_KEYPAD_HEADER_KEYPAD_INTERFACE_H_ */
