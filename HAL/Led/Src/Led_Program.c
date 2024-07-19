/*
 * Led_Program.c
 *
 *  Created on: Apr 6, 2024
 *      Author: 20102
 */



#include <util/delay.h>

#include "../../../MCAL/GPIO/Header/GPIO_Interface.h"
#include"../Header/Led_Interface.h"

/*Init*/

void Led_InitForPin(u8 GroupName,u8 PinNumber)
{
	GPIO_SetDirectionForPin(GroupName,PinNumber,1);
}
void Led_InitForGroup(u8 GroupName)
{
	GPIO_SetDirectionForGroup(GroupName,0xFF);
}

void Led_Change_State_Pin(u8 GroupName,u8 PinNumber,u8 State)
{
	GPIO_SetOutputForPin(GroupName,PinNumber,State);
}
void Led_Change_State_Group(u8 GroupName,u8 State)
{
	GPIO_SetOutputForGroup(GroupName,State);
}

/*Leds Tog*/

void Led_TogForPin(u8 GroupName,u8 PinNumber)
{
	GPIO_TogOutputForPin(GroupName,PinNumber);
}


void Led_TogForGroup(u8 GroupName)
{
	GPIO_TogOutputForGroup(GroupName);
}
