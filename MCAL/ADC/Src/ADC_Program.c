/*
 * ADC_Program.c
 *
 *  Created on: May 10, 2024
 *      Author: 20102
 */


#include "../Header/ADC_Interface.h"


void ADC_Update_Channel(const u8 Channel)
{
	if(Channel>NO_AUTO_TRIGGER_CONTROLED_CONVERSION || Channel<FREE_RUN)
	{
		return ;
	}

	//Set mux channel
	ADCMUX_REG.BYTE= (ADCMUX_REG.BYTE & AdcMuxMask) | (Channel & ADC_CHANNEL_MASK);

}

void ADC_Init(const ADC_Config *CONFIG)
{
	ADCSRA_REG.Bits.ADIE=0;//disable interrupt

	//Normal data read -----> right adjust
	ADCMUX_REG.Bits.ADLAR=0;

	//AREF
	ADCMUX_REG.BYTE = (ADCMUX_REG.BYTE & ADC_REFRENCE_VOLT_MASK) | ( ((CONFIG->REFRENCE_VOLT)&0x03)<<6);

	//Set mux channel
	ADCMUX_REG.BYTE= (ADCMUX_REG.BYTE & AdcMuxMask) | ( (CONFIG->Channel) & ADC_CHANNEL_MASK);

	if((CONFIG->TRIGGER) == NO_AUTO_TRIGGER_CONTROLED_CONVERSION)
	{

		ADCSRA_REG.Bits.ADATE=0;

		ADCSPIOR = (ADCSPIOR&ADC_TRIGGER_MASK) | 0;
	}
	else
	{
		ADCSRA_REG.Bits.ADATE=1;

		ADCSPIOR = (ADCSPIOR&ADC_TRIGGER_MASK) | (CONFIG->TRIGGER)<<5;
	}

	//Prescaler Divide for adc clock
	ADCSRA_REG.BYTE=(ADCSRA_REG.BYTE&ADCCSRAmask)|( (CONFIG->PRE_SCALE)&prescalemask);

	//Enable ADC
	ADCSRA_REG.Bits.ADEN=1;
}
/*                            DESCRIPTION
 *
 * using polling the MC waits until the conversion is done.
 *
 * where it firstly choose the channel then
 */
u16 ADC_Get_DigitalValue()
{
	/*configuring the port direction as input*/
	/*the used mode or channel must be set as input before using */

	//Start conversion
	//ADCSRA_REG.Bits.ADSC=1;

	do
	{
		/*nothing*/
	}while(ADCSRA_REG.Bits.ADIF==0);

	//Set flag to 0
	ADCSRA_REG.Bits.ADIF=1;

	return ADCData;
}
