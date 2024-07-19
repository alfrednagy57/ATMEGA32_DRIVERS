/*
 * Timer_Program.c
 *
 *  Created on: May 18, 2024
 *      Author: 20102
 */

#include"../Header/Timer1_Interface.h"

static void (* G_Ptr_OV)(void)=NULL;
static void (* G_Ptr_CM_B)(void)=NULL;
static void (* G_Ptr_CM_A)(void)=NULL;

void Timer1_Init(CONFIG_TYPE * CONFIG)
{
	//set wave generating
	//	13 12 11 10
	//	1  1  1   0
	TCCR1A_REG.BYTE= (TCCR1A_REG.BYTE & TCCR1A_CLK_MASK) | ((CONFIG->WGM)& WCM_10_11_MASK) ;
	TCCR1B_REG.BYTE= (TCCR1B_REG.BYTE &TCCR1B_CLK_MASK) | ((CONFIG->WGM)& WCM_12_13_MASK) ;

	//configuring FOC1 A-B
	TCCR1A_REG.Bits.FOC1A=CONFIG->FOC1A_STATE;
	TCCR1A_REG.Bits.FOC1B=CONFIG->FOC1B_STATE;

	//Set ICR
	ICR1_REG=CONFIG->PRE_VALUE_ICR1;

	//set compare Val
	Timer1_OCR1A=CONFIG->PRE_VALUE_OCR1A;
	Timer1_OCR1B=CONFIG->PRE_VALUE_OCR1B;

	//set TCNT VAL
	TCNT1_REG=CONFIG->PRE_VALUE_TCNT1;

	//config coma
	TCCR1A_REG.BYTE=(TCCR1A_REG.BYTE & TCCR1A_COMA_MASK ) | (CONFIG->COM_A);
	//config comb
	TCCR1A_REG.BYTE=(TCCR1A_REG.BYTE & TCCR1A_COMB_MASK ) | (CONFIG->COM_B);

	/*INTERRUPT*/
	switch(CONFIG->INTERRUPT)
	{
	case NO_INTERRUPT:

		TIMSK_REG.Bits.OCIE1A = TIMSK_REG.Bits.OCIE1B = TIMSK_REG.Bits.TOIE1 = 0;
		break;
	case OCIE_1_A:

		TIMSK_REG.Bits.OCIE1A=1;
		break;
	case OCIE_1_B:

		TIMSK_REG.Bits.OCIE1B=1;
		break;
	case TOIE_1:

		TIMSK_REG.Bits.TOIE1=1;
		break;
	case WITH_INTERRUPT:

		TIMSK_REG.Bits.OCIE1A = TIMSK_REG.Bits.OCIE1B = TIMSK_REG.Bits.TOIE1 = 1;
		break;
	}
	//start timer clock
	TCCR1B_REG.BYTE = (TCCR1B_REG.BYTE&TCRR1_Mask)|(CONFIG->CLK);

}
void Timer1_SetCompareVal(u16 CompareVAL_A)
{
	//set compare Val
	Timer1_OCR1A=CompareVAL_A;

}
void Timer1_SetCompareVal_B(u16 CompareVAL_B)
{
	//set compare Val
	Timer1_OCR1B=CompareVAL_B;
}
void Timer1_SetTop(u16 ICR_Top)
{
	//Set ICR
	ICR1_REG=ICR_Top;
}

void Timer1_deInit(void)
{
	/* Clear All Timer1 Registers */
	TCCR1A_REG.BYTE = TCCR1B_REG.BYTE = TCNT1_REG = Timer1_OCR1A = Timer1_OCR1B = 0;

	/* Disable the Output Compare A match and Overflow interrupt */
	TIMSK_REG.Bits.OCIE1A = 0;
	TIMSK_REG.Bits.TOIE1 = 0;

	/* Reset the global pointer value */
	G_Ptr_OV = NULL;
	G_Ptr_CM_B=NULL;
	G_Ptr_CM_A=NULL;
}

void Timer1_setCallBack_OV(void (*a_ptr)(void))
{
	G_Ptr_OV=a_ptr;
}

void Timer1_setCallBack_CM_B(void (*a_ptr)(void))
{
	G_Ptr_CM_B=a_ptr;
}

void Timer1_setCallBack_CM_A(void (*a_ptr)(void))
{
	G_Ptr_CM_A=a_ptr;
}

void __vector_9 ()//Timer1 OV
{
	if(G_Ptr_OV!=NULL)
	{
		G_Ptr_OV();
	}
}

void __vector_8 ()//Timer1 CM_B
{
	if(G_Ptr_OV!=NULL)
	{
		G_Ptr_CM_B();
	}
}

void __vector_7 () //Timer1 CM_A
{
	if(G_Ptr_OV!=NULL)
	{
		G_Ptr_CM_A();
	}
}
