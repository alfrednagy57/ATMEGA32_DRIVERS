///*
// * HC_Program.c
//
// *
// *  Created on: Jun 27, 2024
// *      Author: 20102
// */

#include <util/delay.h>

#include "../Header/HC_Interface.h"

#include "../../../MCAL/ICU/Header/ICU_Interface.h"

#include "../../../HAL/Lcd/Header/Lcd_Interface.h"


static u8  g_edgeCount =  0;
static u16 g_echoTime  =  0;




void DisMain()
{

	u16 distance = 0;

	Lcd_Init();

	Ultrasonic_init();

	Lcd_SendString("Distance=    cm");

	while (1)
	{

		distance = Ultrasonic_readDistance();

		Lcd_GoToXY_DDRAM(10,0);

		Lcd_SendNumber(distance);

		if (distance < 100)
		{
			Lcd_SendData(' ');
		}

		else if (distance < 10)
		{
			Lcd_SendData(' ');
		}
	}
}


void Ultrasonic_init(void)
{
	GPIO_SetDirectionForPin(TRI_GROUP_ID,TRI_PIN,GPIO_Output);

	ICU_Init(F_CPU_8,RAISING);

	ICU_setCallBack(Ultrasonic_edgeProcessing);
}


void Ultrasonic_Trigger(void)
{
	GPIO_SetOutputForPin(TRI_GROUP_ID,TRI_PIN,GPIO_High);

	_delay_ms(TRI_DELAY);

	GPIO_SetOutputForPin(TRI_GROUP_ID,TRI_PIN,GPIO_Low);
}


u16 Ultrasonic_readDistance(void)
{
	u16 distance;

	Ultrasonic_Trigger();

	distance = (g_echoTime /58.8);

	return distance;
}

void Ultrasonic_edgeProcessing(void)
{
	if(g_edgeCount==0)
	{
		ICU_clearTimerValue();

		ICU_setEdgeType(FALLING);

		g_edgeCount++;
	}
	else if(g_edgeCount==1)
	{
		g_echoTime = ICU_getInputCaptureValue();

		ICU_setEdgeType(RAISING);

		g_edgeCount=0;
	}
}
