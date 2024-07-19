/*
 * Lcd_Interface.h
 *
 *  Created on: Apr 6, 2024
 *      Author: 20102
 */

#include"../../../Common/StdType.h"

#include "../../../MCAL/GPIO/Header/GPIO_Interface.h"

#include "Lcd_Config.h"
#include "Lcd_Private.h"

#ifndef HAL_LCD_HEADER_LCD_INTERFACE_H_
#define HAL_LCD_HEADER_LCD_INTERFACE_H_

void Lcd_Init(void);
void Lcd_SendCommand(u8 Command);
void Lcd_SendData(u8 Data);
void Lcd_SendString(const u8* Text);
void Lcd_ClrScreenFnc(void);
void Lcd_GoToXY_DDRAM(u8 X_Pos,u8 Y_Pos);
void Lcd_SendSpecialChar(u8* Arr,u8 BlockNo,u8 X_Pos,u8 Y_Pos);
void Lcd_SendNumber(s128 Num);


//u8   Lcd_ReadData();

#endif /* HAL_LCD_HEADER_LCD_INTERFACE_H_ */
