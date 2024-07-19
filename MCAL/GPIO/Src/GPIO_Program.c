/*
 * GPIO_Program.c
 *
 *  Created on: Apr 5, 2024
 *      Author: 20102
 */

#include "../../../Common/StdType.h"
#include "../../../Common/BitMath.h"

#include "../Header/GPIO_Interface.h"
#include "../Header/GPIO_Private.h"
#include "../Header/GPIO_Register.h"
/*Direction*/

void GPIO_SetDirectionForPin(u8 GroupName,u8 PinNumber,u8 DirectionState)
{
	if(GroupName<=GPIO_GroupD_ID &&GroupName>=GPIO_GroupA_ID)
	{
		if(PinNumber>=GPIO_PIN0&&PinNumber<= GPIO_PIN7)
		{
			if(GPIO_Input==DirectionState)
			{
				switch(GroupName)
				{
				case GPIO_GroupA_ID:
					ClrBit(GPIO_DDRA_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupB_ID:
					ClrBit(GPIO_DDRB_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupC_ID:
					ClrBit(GPIO_DDRC_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupD_ID:
					ClrBit(GPIO_DDRD_REG.BYTE,PinNumber);
					break;
				}
			}
			else if(GPIO_Output==DirectionState)
			{
				switch(GroupName)
				{
				case GPIO_GroupA_ID:
					SetBit(GPIO_DDRA_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupB_ID:
					SetBit(GPIO_DDRB_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupC_ID:
					SetBit(GPIO_DDRC_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupD_ID:
					SetBit(GPIO_DDRD_REG.BYTE,PinNumber);
					break;
				}
			}
		}
	}
}


void GPIO_SetDirectionForGroup(u8 GroupName,u8 Direction)
{
	if(GroupName<=GPIO_GroupD_ID &&GroupName>=GPIO_GroupA_ID )
	{
		switch(GroupName)
		{
		case GPIO_GroupA_ID:
			GPIO_DDRA_REG.BYTE=Direction;
			break;
		case GPIO_GroupB_ID:
			GPIO_DDRB_REG.BYTE=Direction;
			break;
		case GPIO_GroupC_ID:
			GPIO_DDRC_REG.BYTE=Direction;
			break;
		case GPIO_GroupD_ID:
			GPIO_DDRD_REG.BYTE=Direction;
			break;
		}

	}
}

/*Output*/

void GPIO_SetOutputForPin(u8 GroupName,u8 PinNumber,u8 OutputState)
{
	if(GroupName<=GPIO_GroupD_ID &&GroupName>=GPIO_GroupA_ID)
	{
		if(PinNumber>=GPIO_PIN0&&PinNumber<= GPIO_PIN7)
		{
			if(GPIO_Low==OutputState)
			{
				switch(GroupName)
				{
				case GPIO_GroupA_ID:
					ClrBit(GPIO_PORTA_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupB_ID:
					ClrBit(GPIO_PORTB_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupC_ID:
					ClrBit(GPIO_PORTC_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupD_ID:
					ClrBit(GPIO_PORTD_REG.BYTE,PinNumber);
					break;
				}
			}
			else if(GPIO_High==OutputState)
			{
				switch(GroupName)
				{
				case GPIO_GroupA_ID:
					SetBit(GPIO_PORTA_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupB_ID:
					SetBit(GPIO_PORTB_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupC_ID:
					SetBit(GPIO_PORTC_REG.BYTE,PinNumber);
					break;
				case GPIO_GroupD_ID:
					SetBit(GPIO_PORTD_REG.BYTE,PinNumber);
					break;
				}
			}
		}
	}
}


void GPIO_SetOutputForGroup(u8 GroupName,u8 Output)
{
	if(GroupName<=GPIO_GroupD_ID &&GroupName>=GPIO_GroupA_ID )
	{
		switch(GroupName)
		{
		case GPIO_GroupA_ID:
			GPIO_PORTA_REG.BYTE=Output;
			break;
		case GPIO_GroupB_ID:
			GPIO_PORTB_REG.BYTE=Output;
			break;
		case GPIO_GroupC_ID:
			GPIO_PORTC_REG.BYTE=Output;
			break;
		case GPIO_GroupD_ID:
			GPIO_PORTD_REG.BYTE=Output;
			break;
		}
	}
}


void GPIO_TogOutputForPin(u8 GroupName,u8 PinNumber)
{
	if(GroupName<=GPIO_GroupD_ID &&GroupName>=GPIO_GroupA_ID )
	{
		if(PinNumber>=GPIO_PIN0&&PinNumber<= GPIO_PIN7)
		{
			switch(GroupName)
			{
			case GPIO_GroupA_ID:
				TogBit(GPIO_PORTA_REG.BYTE,PinNumber);
				break;
			case GPIO_GroupB_ID:
				TogBit(GPIO_PORTB_REG.BYTE,PinNumber);
				break;
			case GPIO_GroupC_ID:
				TogBit(GPIO_PORTC_REG.BYTE,PinNumber);
				break;
			case GPIO_GroupD_ID:
				TogBit(GPIO_PORTD_REG.BYTE,PinNumber);
				break;
			}
		}
	}
}

void GPIO_TogOutputForGroup(u8 GroupName)
{
	if(GroupName<=GPIO_GroupD_ID &&GroupName>=GPIO_GroupA_ID )
	{
		switch(GroupName)
		{
		case GPIO_GroupA_ID:
			TogGroup(GPIO_PORTA_REG.BYTE,HIGH_GROUP);
			break;
		case GPIO_GroupB_ID:
			TogGroup(GPIO_PORTB_REG.BYTE,HIGH_GROUP);
			break;
		case GPIO_GroupC_ID:
			TogGroup(GPIO_PORTC_REG.BYTE,HIGH_GROUP);
			break;
		case GPIO_GroupD_ID:
			TogGroup(GPIO_PORTD_REG.BYTE,HIGH_GROUP);
			break;
		}
	}
}


/*Read*/

u8 GPIO_ReadValueForPin(u8 GroupName,u8 PinNumber)
{
	u8 Res=0;
	if(GroupName<=GPIO_GroupD_ID &&GroupName>=GPIO_GroupA_ID )
	{
		switch(GroupName)
		{
		case GPIO_GroupA_ID:
			Res= ReadBit(GPIO_PINA_REG.BYTE,PinNumber);
			break;
		case GPIO_GroupB_ID:
			Res= ReadBit(GPIO_PINB_REG.BYTE,PinNumber);
			break;
		case GPIO_GroupC_ID:
			Res= ReadBit(GPIO_PINC_REG.BYTE,PinNumber);
			break;
		case GPIO_GroupD_ID:
			Res= ReadBit(GPIO_PIND_REG.BYTE,PinNumber);
			break;
		}
	}
	return Res;
}


u8 GPIO_ReadValueForGroup(u8 GroupName)
{
	u8 Res=0;
	if(GroupName<=GPIO_GroupD_ID &&GroupName>=GPIO_GroupA_ID )
	{
		switch(GroupName)
		{
		case GPIO_GroupA_ID:
			Res= GPIO_PINA_REG.BYTE;
			break;
		case GPIO_GroupB_ID:
			Res= GPIO_PINB_REG.BYTE;
			break;
		case GPIO_GroupC_ID:
			Res= GPIO_PINC_REG.BYTE;
			break;
		case GPIO_GroupD_ID:
			Res= GPIO_PIND_REG.BYTE;
			break;
		}
	}
	return Res;
}
