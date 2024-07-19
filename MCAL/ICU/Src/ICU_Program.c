/*
 * ICU_Program.c
 *
 *  Created on: Jun 19, 2024
 *      Author: 20102
 */

#include "../Header/ICU_Interface.h"
#include "../../../Common/BitMath.h"
#include "../../SREG/GIE.h"

static void (*G_PointerToFnc)(void)=NULL;

void ICU_setCallBack(void (*a_ptr)(void))
{
	if(a_ptr!=NULL)
	{
		G_PointerToFnc=a_ptr;
	}
}

void ICU_Init(ICU_ClockType Clock,ICU_EdgeType Edge)
{
	GIE_Enable();

	/* Initial Values for Timer1 */
	TCNT1_REG = 0;
	ICR1_REG  = 0;
	Timer1_OCR1B=0;
	Timer1_OCR1A=0;


	//set edge
	TCCR1B_REG.BYTE = (TCCR1B_REG.BYTE & TCCR1B_EDGE_SELECT_MASK) | (Edge<<6);

	/* Enable the Input Capture interrupt*/
	TIMSK_REG.Bits.TICIE1=1;

	/*disable force ouput compare*/
	TCCR1A_REG.Bits.FOC1A=0;
	TCCR1A_REG.Bits.FOC1B=0;

	/*disconnect oc1a / oc1b pins*/
	TCCR1A_REG.Bits.COM1A0=0;
	TCCR1A_REG.Bits.COM1A1=0;

	TCCR1A_REG.Bits.COM1B0=0;
	TCCR1A_REG.Bits.COM1B1=0;

	//set wave generating
	//	13 12 11 10
	//	0  0  0   0   ---->  normal mode
	TCCR1B_REG.Bits.WGM13=0;
	TCCR1B_REG.Bits.WGM12=0;
	TCCR1A_REG.Bits.WGM11=0;
	TCCR1A_REG.Bits.WGM10=0;

	//set clock
	TCCR1B_REG.BYTE = (TCCR1B_REG.BYTE & ICU_CLK_MASK) | (Clock);

	//set the icp pin to input
	//pin 6 port d
	ClrBit(DIO_DDRD_ICU,DDR_PIN6);
}

void ICU_setEdgeType(ICU_EdgeType edgeType)
{
	//set edge
	TCCR1B_REG.BYTE = (TCCR1B_REG.BYTE & TCCR1B_EDGE_SELECT_MASK) | (edgeType << 6);
}
u16 ICU_getInputCaptureValue(void)
{
	return ICR1_REG;
}
void ICU_clearTimerValue(void)
{
	TCNT1_REG = ICR1_REG = 0;
}
void ICU_deInit(void)
{
    TIMSK_REG.Bits.TICIE1=0;
	TCCR1B_REG.BYTE = (TCCR1B_REG.BYTE & ICU_CLK_MASK) | 0 ;
	 GIE_Disable();
}

void __vector_6()
{
	if(G_PointerToFnc!=NULL)
	{
		G_PointerToFnc();
	}
}
