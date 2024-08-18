/*
 * Lcd_Config.h
 *
 *  Created on: Apr 6, 2024
 *      Author: 20102
 */

#include "../../../MCAL/GPIO/Header/GPIO_Interface.h"

#ifndef HAL_LCD_HEADER_LCD_CONFIG_H_
#define HAL_LCD_HEADER_LCD_CONFIG_H_

#define Lcd_ControlGroup GPIO_GroupA_ID
#define Lcd_DataGroup    GPIO_GroupB_ID

#define Lcd_RS  GPIO_PIN0
#define Lcd_E   GPIO_PIN1

#define LCD_BITS_MODE LCD_DATA_BITS_4

#endif /* HAL_LCD_HEADER_LCD_CONFIG_H_ */
