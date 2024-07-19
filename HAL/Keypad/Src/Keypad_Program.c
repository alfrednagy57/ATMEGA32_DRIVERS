/*
 * Keypad_Program.c
 *
 *  Created on: Apr 19, 2024
 *      Author: 20102
 */

#include<util/delay.h>

#include "../../../MCAL/GPIO/Header/GPIO_Interface.h"

#include "../Header/Keypad_Interface.h"


static u8 Keypad [Keypad_Row][Keypad_Col]={
		{
		 '1','2','3','/'
		},
		{
		 '4','5','6','*'
		},
		{
		 '7','8','9','+'
		},
		{
		 'c','0','=','-'

		}
};


void Keypad_Init(void)
{
	//Direction
	// R3 R2 R1 R0 C3 C2 C1 C0
	// 7  6  5  4  3  2   1  0
	// 0  0  0  0  1  1   1  1
	GPIO_SetDirectionForGroup(Keypad_Group,Keypad_TypeConnection);
    GPIO_SetOutputForGroup(Keypad_Group,Keypad_TypeSetup);
}

u8 Keypad_ReadBtnValue(void)
{
	u8 BtnState=0;
	u8 BtnValue=0;

	for (u8 C=0;C<Keypad_Col;C++)
	{
		GPIO_SetOutputForPin(Keypad_Group,C,GPIO_Low);
		for(u8 R=0;R<Keypad_Row;R++)
		{
			BtnState=GPIO_ReadValueForPin(Keypad_Group,R+4);
			if(BtnState == Pressed)
			{
				GPIO_SetOutputForPin(Keypad_Group,C,GPIO_High);
				BtnValue = Keypad[R][C];
				return BtnValue;
			}
		}
		//C as high
		GPIO_SetOutputForPin(Keypad_Group,C,GPIO_High);
	}
	return 'n';
}
