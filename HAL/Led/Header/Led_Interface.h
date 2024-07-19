/*
 * Led_Interface.h
 *
 *  Created on: Apr 6, 2024
 *      Author: 20102
 */

#include"../../../Common/StdType.h"
#include"Led_Private.h"

#ifndef HAL_LED_HEADER_LED_INTERFACE_H_
#define HAL_LED_HEADER_LED_INTERFACE_H_


/*Init*/

void Led_InitForPin(u8 GroupName,u8 PinNumber);
void Led_InitForGroup(u8 GroupName);

void Led_Change_State_Pin(u8 GroupName,u8 PinNumber,u8 State);
void Led_Change_State_Group(u8 GroupName,u8 State);

/*Leds toggle*/
void Led_TogForPin(u8 GroupName,u8 PinNumber);
void Led_TogForGroup(u8 GroupName);

#endif /* HAL_LED_HEADER_LED_INTERFACE_H_ */
