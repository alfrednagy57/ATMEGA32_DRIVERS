/*
 * Servo.c
 *
 *  Created on: Jul 3, 2024
 *      Author: 20102
 */

#include "../../../MCAL/Timer1/Header/Timer1_Interface.h"

#include "../../../MCAL/GPIO/Header/GPIO_Interface.h"

#include"../Header/Servo_Interface.h"

void Servo_Init()
{
	GPIO_SetDirectionForPin(GPIO_GroupD_ID, GPIO_PIN4, GPIO_Output);//oco1B

	/*timer1 must be in icr mode */
	CONFIG_TYPE_Timer1 CONFIG={0,0,0,20000,F_CPU_8_T1,
			OC1_A_B_DISCONNECTED,
			CLEAR_OC1_A_B_NON_INVERTING_PWM_MODE,
			Fast_ICR1_TOP};

	Timer1_Init(&CONFIG);
}


void Servo_SetAngle(f32 Angle)
{
	// Calculate the compare value based on the angle
	// 0 degrees corresponds to 750 ticks (1ms)
	// 180 degrees corresponds to 2500 ticks (2ms)
	//9.72222 =1750 / 180

	Angle=Angle*9.722222222+750;
	//Ideal servo  ---- > proteus equation
	//Angle=Angle*5.555555556+999;

	// Set the compare value
	Timer1_SetCompareVal_A((u16)Angle);
}
