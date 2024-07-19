/*
 * Temp.c
 *
 *  Created on: May 15, 2024
 *      Author: 20102
 */

#include <util/delay.h>
#include<stdlib.h>

#include "../../MCAL/GPIO/Header/GPIO_Interface.h"
#include"../../MCAL/ADC/Header/ADC_Interface.h"
#include"../../HAL/Lcd/Header/Lcd_Interface.h"


#include"Temp.h"

void tempMain()
{
	ADC_Config CONFIG= {NO_AUTO_TRIGGER_CONTROLED_CONVERSION,AREF_Pin_INTERNAL_VREF_OFF,DIV_8};

	GPIO_SetDirectionForPin(GPIO_GroupA_ID,0,0);//set pin 0 group a to input ----> to recieve the analog volt

	Lcd_Init();

	ADC_Init(&CONFIG);

	u16 DigitalVal=0;

	u16 MiliVol   =0;

	u8 Buff[3]  ;

	u8 Temp=0;

	while (1)
	{
		DigitalVal = ADC_Get_DigitalValue(0); // Get the digital value from ADC channel 0

		MiliVol = (((u64)DigitalVal) * (5000ul)) / 1024ul; // Convert digital value to millivolts
		Temp = MiliVol / 10; // Convert millivolts to Celsius (10mV per degree Celsius for LM35)


		itoa(Temp, Buff, Radix_Dec); // Convert temperature to string
		Lcd_GoToXY_DDRAM(0, 0);
		Lcd_SendString("T:");
		Lcd_SendString(Buff); // Display temperature on LCD
		Lcd_SendString("C");  // Display the unit

		_delay_ms(2000); // Wait for 2 seconds
	}
}
