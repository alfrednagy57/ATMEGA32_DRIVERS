/*
 * Timer_Program.c
 *
 *  Created on: May 18, 2024
 *      Author: 20102
 */

#include "../Header/Timer1_Interface.h"
#include "../../SREG/GIE.h"

static void (* G_Ptr_OV)(void)=NULL;
static void (* G_Ptr_CM_B)(void)=NULL;
static void (* G_Ptr_CM_A)(void)=NULL;

void Timer1_Init(const CONFIG_TYPE_Timer1 * CONFIG)
{
	//set wave generating
	TCCR1A_REG.Bits.WGM10= 0;
	TCCR1A_REG.Bits.WGM11= 1;

	TCCR1B_REG.Bits.WGM12= 1;
	TCCR1B_REG.Bits.WGM13= 1;

	//configuring FOC1 A-B
	/*foc must be = 1 if the desired pin is operating as non_pwm*/
	TCCR1A_REG.Bits.FOC1A=0;
	TCCR1A_REG.Bits.FOC1B=0;

	//Set ICR
	ICR1_REG=CONFIG->Timer1_ICR1_REG;

	//set compare Val
	Timer1_OCR1A=CONFIG->Timer1_OCR1A_VAL;
	Timer1_OCR1B=CONFIG->Timer1_OCR1B_VAL;

	//set TCNT VAL
	TCNT1_REG=CONFIG->Timer1_TCNT1_VAL;

	//config coma
	TCCR1A_REG.Bits.COM1A0 = 0;
	TCCR1A_REG.Bits.COM1A1 = 0;

	//config comb
	TCCR1A_REG.Bits.COM1B0 = 0;
	TCCR1A_REG.Bits.COM1B1 = 1;


	/*INTERRUPT*/
	TIMSK_REG.Bits.OCIE1A = TIMSK_REG.Bits.OCIE1B = TIMSK_REG.Bits.TOIE1 = 0;

	//start timer clock
	TCCR1B_REG.BYTE = (TCCR1B_REG.BYTE&TCRR1_Mask)|(CONFIG->CLK);

}
void Timer1_SetCompareVal_A(const u16 CompareVAL_A)
{
	//set compare Val
	Timer1_OCR1A=CompareVAL_A;

}
void Timer1_SetCompareVal_B(const u16 CompareVAL_B)
{
	//set compare Val
	Timer1_OCR1B=CompareVAL_B;
}
void Timer1_SetICR1(const u16 ICR1_Top)
{
	//Set ICR
	ICR1_REG=ICR1_Top;
}

void Timer1_SetTCNT1(const u16 TCNT1_Top)
{
	TCNT1_REG=TCNT1_Top;
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
