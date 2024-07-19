/*
 * StepperMotor_Program.c
 *
 *  Created on: Apr 20, 2024
 *      Author: 20102
 */

#include "../Header/StepperMotor_Intrface.h"
#include <util/delay.h>


void Stepper_Init(u8 GroupName,u8 PinNum0,u8 PinNum2,u8 PinNum3,u8 PinNum4)
{
	GPIO_SetDirectionForPin(GroupName,PinNum0,GPIO_Output);
	GPIO_SetDirectionForPin(GroupName,PinNum3,GPIO_Output);
	GPIO_SetDirectionForPin(GroupName,PinNum3,GPIO_Output);
	GPIO_SetDirectionForPin(GroupName,PinNum4,GPIO_Output);
}

void Stepper_RotateWithAngle(u8 GroupName,u8 PinNum0,u8 PinNum2,u8 PinNum3,u8 PinNum4,u16 Angle)
{
	Angle/=(0.17578);
	Angle/=4;
	while(Angle--)
	{
		GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_High);
		GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
		_delay_ms(2);

		GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_High);
		_delay_ms(2);

		GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_High);
		GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
		_delay_ms(2);

		GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_High);
		GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
		GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
		_delay_ms(2);
	}
}
void Stepper_RotateWithAngleWithClock(u8 GroupName,u8 PinNum0,u8 PinNum2,u8 PinNum3,u8 PinNum4,u16 Angle,u8 Clock)
{
	Angle/=(0.17578);//divide by 0.17578 to get number of iterations of the full step (big trs)
	Angle/=4;//divide by four to do a single step
	if(Clock==StepCW)
	{
		while(Angle--)
		{

			GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_High);
			GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
			_delay_ms(2);

			GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_High);
			GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
			_delay_ms(2);

			GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_High);
			GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
			_delay_ms(2);

			GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_High);
			_delay_ms(2);
		}
	}
	else if(Clock==StepUCW)
	{
		while(Angle--)
		{

			GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_High);
			_delay_ms(2);


			GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_High);
			GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
			_delay_ms(2);


			GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_High);
			GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
			_delay_ms(2);

			GPIO_SetOutputForPin(GroupName,PinNum0,GPIO_High);
			GPIO_SetOutputForPin(GroupName,PinNum2,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum3,GPIO_Low);
			GPIO_SetOutputForPin(GroupName,PinNum4,GPIO_Low);
			_delay_ms(2);
		}
	}
}
