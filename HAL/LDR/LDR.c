/*
 * LDR.c
 *
 *  Created on: May 15, 2024
 *      Author: 20102
 */

#include "../../HAL/LDR/LDR.h"

#include <util/delay.h>

#include "../../Common/BitMath.H"

#include "../../MCAL/GPIO/Header/GPIO_Interface.h"
#include"../../MCAL/ADC/Header/ADC_Interface.h"
#include"../../HAL/Lcd/Header/Lcd_Interface.h"
#include"../../HAL/Led/Header/Led_Interface.h"



void LDR_Main()
{
	ADC_Config CONFIG= {NO_AUTO_TRIGGER_CONTROLED_CONVERSION,AVCC_With_External_CAP,DIV_8};

	Lcd_Init();

	Led_InitForGroup(2);

	GPIO_SetDirectionForPin(GPIO_GroupA_ID,0,0);//set pin 0 group a to input ----> to recieve the analog volt

	ADC_Init(&CONFIG);

	u16 LDR_Val=0;

	while(1)
	{
		Led_Change_State_Group(2,0x00);

		Lcd_ClrScreenFnc();

		LDR_Val= ADC_Get_DigitalValue(0);

		Lcd_SendNumber(LDR_Val);

		if(LDR_Val<128&&LDR_Val>0)
		{
			Led_Change_State_Group(2,0x01);
		}
		else if(LDR_Val<256&&LDR_Val>128)
		{
			Led_Change_State_Group(2,0x03);
		}
		else if(LDR_Val<384&&LDR_Val>256)
		{
			Led_Change_State_Group(2,0x07);
		}
		else if(LDR_Val<512&&LDR_Val>384)
		{
			Led_Change_State_Group(2,0x0F);
		}
		else if(LDR_Val<640&&LDR_Val>512)
		{
			Led_Change_State_Group(2,0x1F);
		}
		else if(LDR_Val<768&&LDR_Val>640)
		{
			Led_Change_State_Group(2,0x3F);
		}
		else if(LDR_Val<896&&LDR_Val>768)
		{
			Led_Change_State_Group(2,0x7F);
		}
		else if(LDR_Val<1024&&LDR_Val>896)
		{
			Led_Change_State_Group(2,0xFF);
		}
		else
		{
			Lcd_ClrScreenFnc();
			Lcd_SendString("higher than 1024");
			Led_Change_State_Group(2,0x00);
		}
		_delay_ms(5000);
	}
}
