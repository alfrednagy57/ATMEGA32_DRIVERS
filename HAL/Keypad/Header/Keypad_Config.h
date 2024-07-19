/*
 * Keypad_Config.h
 *
 *  Created on: Apr 19, 2024
 *      Author: 20102
 */

#include "../../../Mcal/GPIO/Header/GPIO_Private.h"

#ifndef HAL_KEYPAD_HEADER_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_HEADER_KEYPAD_CONFIG_H_

#define Keypad_Row 4
#define Keypad_Col 4

// R3 R2 R1 R0 C3 C2 C1 C0
// 7  6  5  4  3  2   1  0

#define Keypad_Group          GPIO_GroupA_ID
#define Keypad_TypeConnection 0x0f
#define Keypad_TypeSetup      0xff

#endif /* HAL_KEYPAD_HEADER_KEYPAD_CONFIG_H_ */
