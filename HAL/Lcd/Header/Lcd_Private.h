/*
 * Lcd_Private.h
 *
 *  Created on: Apr 6, 2024
 *      Author: 20102
 */

#ifndef HAL_LCD_HEADER_LCD_PRIVATE_H_
#define HAL_LCD_HEADER_LCD_PRIVATE_H_

#define Lcd_Low 0x00
#define Lcd_HighForGroup 0xFF
#define Lcd_HighForPin   0x01
#define Lcd_HighForGroup4Bit 0xF0

//code to do clear screen function
#define Lcd_ClrScreenCommand    0x01

//return to original position
#define Lcd_ReturnHome   0x02

/*Configuration part*/
#define Lcd_58_2Lines8BitsMode 0x38

#define Lcd_58_2Lines4BitsMode 0x28

#define LCD_2LINES_4BitsMode_INIT1 0x33
#define LCD_2LINES_4BitsMode_INIT2 0x32

#define Lcd_DisplayONCursorOFF8Bit 0x0C
#define Lcd_DisplayONCursorON_NoBlinking8Bit 0x0E
#define Lcd_DisplayONCursorON_Blinking8Bit 0x0F

#define Lcd_DisplayONCursorOFF4Bit 0xC0
#define Lcd_DisplayONCursorON_NoBlinking4Bit 0xE0
#define Lcd_DisplayONCursorON_Blinking4Bit 0xF0

#define Lcd_DisplayNoShift8Bit 0x06
#define Lcd_DisplayNoShift4Bit 0x40

#define LCD_SET_CURSOR_LOCATION 0x80

#define LCD_DATA_BITS_4		4
#define LCD_DATA_BITS_8		8


#endif /* HAL_LCD_HEADER_LCD_PRIVATE_H_ */
