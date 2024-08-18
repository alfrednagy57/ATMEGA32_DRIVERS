/*
 * Lcd_Program.c
 *
 *  Created on: Apr 6, 2024
 *      Author: 20102
 */


#include<stdlib.h>
#include <util/delay.h>

#include "../../../Common/BitMath.H"

#include"../Header/Lcd_Interface.h"

void Lcd_Init(void)
{
	GPIO_SetDirectionForPin(Lcd_ControlGroup,Lcd_RS,Lcd_HighForPin);
	GPIO_SetDirectionForPin(Lcd_ControlGroup,Lcd_E,Lcd_HighForPin);
	//  GPIO_SetDirectionForPin(Lcd_ControlGroup,Lcd_On,Lcd_HighForPin);
	//	GPIO_SetDirectionForPin(Lcd_ControlGroup,Lcd_RW,Lcd_HighForPin);
	_delay_ms(20);

#if LCD_BITS_MODE  == LCD_DATA_BITS_8

	GPIO_SetDirectionForGroup(Lcd_DataGroup,Lcd_HighForGroup);

#elif LCD_BITS_MODE  == LCD_DATA_BITS_4

	GPIO_SetDirectionForPin(Lcd_DataGroup,GPIO_PIN4,GPIO_Output);
	GPIO_SetDirectionForPin(Lcd_DataGroup,GPIO_PIN5,GPIO_Output);
	GPIO_SetDirectionForPin(Lcd_DataGroup,GPIO_PIN6,GPIO_Output);
	GPIO_SetDirectionForPin(Lcd_DataGroup,GPIO_PIN7,GPIO_Output);

#endif

#if LCD_BITS_MODE  == LCD_DATA_BITS_8//8 bit mode

	Lcd_SendCommand(Lcd_58_2Lines8BitsMode);

#elif LCD_BITS_MODE  == LCD_DATA_BITS_4//4 bit mode

	/*Wait for more than 30 ms*/
	_delay_ms(30);

	Lcd_SendCommand(LCD_2LINES_4BitsMode_INIT1);
	Lcd_SendCommand(LCD_2LINES_4BitsMode_INIT2);

	Lcd_SendCommand(Lcd_58_2Lines4BitsMode);

#endif
	Lcd_SendCommand(Lcd_DisplayONCursorOFF8Bit);	/* cursor off */
	Lcd_SendCommand(Lcd_ClrScreenCommand);

}


void Lcd_SendCommand(u8 Command)
{
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_RS,Lcd_Low);//Command
	_delay_ms(1);
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_HighForPin);
	_delay_ms(1);

#if LCD_BITS_MODE  == LCD_DATA_BITS_8

	GPIO_SetOutputForGroup(Lcd_DataGroup,Command);
	_delay_ms(1);
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_Low);
	_delay_ms(1);
#elif LCD_BITS_MODE  == LCD_DATA_BITS_4
	GPIO_SetOutputForGroup(Lcd_DataGroup,Command & 0xF0);
	_delay_ms(1);	/* delay for processing Tdsw = 100ns */
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_Low);
	_delay_ms(1);
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_HighForPin);
	_delay_ms(1);

	GPIO_SetOutputForGroup(Lcd_DataGroup,(Command&0x0F)<<4);
	_delay_ms(1);	/* delay for processing Tdsw = 100ns */
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_Low);
	_delay_ms(1);

#endif

}


void Lcd_SendData(u8 Data)
{
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_RS,Lcd_HighForPin);//DATA
	_delay_ms(1);
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_HighForPin);
	_delay_ms(1);
#if LCD_BITS_MODE  == LCD_DATA_BITS_8

	GPIO_SetOutputForGroup(Lcd_DataGroup,Data);
	_delay_ms(1);
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_Low);
	_delay_ms(1);

#elif LCD_BITS_MODE  == LCD_DATA_BITS_4

	GPIO_SetOutputForGroup(Lcd_DataGroup,Data & 0xF0);

	_delay_ms(1);	/* delay for processing Tdsw = 100ns */
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_Low);
	_delay_ms(1);
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_HighForPin);
	_delay_ms(1);

	GPIO_SetOutputForGroup(Lcd_DataGroup,(Data&0x0F)<<4);

	_delay_ms(1);	/* delay for processing Tdsw = 100ns */
	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_Low);
	_delay_ms(1);

#endif

}
//u8  Lcd_ReadData()
//{
//	//Select RS
//	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_RS,Lcd_HighForPin);//Data
//	//RW
//	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_RW,Lcd_HighForPin);//Read
//	//E
//	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_HighForPin);
//	//Data
//	u8* Data=GPIO_ReadValueForGroup(Lcd_DataGroup);
//	//E
//	GPIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,Lcd_Low);
//	return Data;
//}

void Lcd_ClrScreenFnc(void)
{
	/*Clear display*/
	Lcd_SendCommand(Lcd_ClrScreenCommand);
}

void Lcd_SendString(const u8* Text)
{
	u8 Cou=0;
	while(Text[Cou]!='\0')
	{
		Lcd_SendData(Text[Cou]);
		Cou++;
	}
}


void Lcd_GoToXY_DDRAM(u8 X_Pos,u8 Y_Pos)
{
	Sol(Y_Pos,6);
	Lcd_SendCommand(X_Pos+Y_Pos+128);
}


void Lcd_SendSpecialChar(u8* Arr,u8 BlockNo,u8 X_Pos,u8 Y_Pos)
{
	BlockNo*=8;//Calculate CGRAM Address
	Lcd_SendCommand(BlockNo+0x40);
	for(u8 Cou=0;Cou<8;Cou++)
	{
		Lcd_SendData(Arr[Cou]);//Write on CGRAM
	}
	Lcd_GoToXY_DDRAM(X_Pos,Y_Pos);//Re-Point to DDRAM
	Lcd_SendData(BlockNo);//Address of the user defined Char
}
void Lcd_SendNumber(s128 Copy_u32_Num)
{
	u8 buff[16];
	itoa(Copy_u32_Num,buff,Radix_Dec);
	Lcd_SendString(buff);
}
