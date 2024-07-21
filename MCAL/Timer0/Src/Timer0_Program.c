/*
 ============================================================================
 Name        : Timer0_Program.c
 Module Name : TIMER0
 Author      : Alfred Nagy
 Date        : 15 July 2024
 Description : Source file for the AVR TIMER0 driver
 ============================================================================
 */
#include "../Header/Timer0_Interface.h"
#include "../../../Common/BitMath.H"
#include "../../../Common/StdType.h"

static void (*GP_OV)(void )=NULL;
static void (*GP_CM)(void )=NULL;

void Timer0_Init(const TIMER0_Config *CONFIG)
{
//	SetBit(OC0_PORTID,OC0_PINID);

	Timer0_TCNT0_REG=CONFIG->initial_value;

	Timer0_OCR0_REG=CONFIG->compare_value;

	if(CONFIG->mode==Normal_Timer0)
	{
		Timer0_TCCR0_REG.Bits.FOC0=1;
		Timer0_TCCR0_REG.Bits.WGM00=0;
		Timer0_TCCR0_REG.Bits.WGM01=0;
	}
	if(CONFIG->mode==Phase_Correct_Timer0)
	{
		Timer0_TCCR0_REG.Bits.FOC0=0;
		Timer0_TCCR0_REG.Bits.WGM00=1;
		Timer0_TCCR0_REG.Bits.WGM01=0;
	}
	if(CONFIG->mode== CTC_Timer0)
	{
		Timer0_TCCR0_REG.Bits.FOC0=1;
		Timer0_TCCR0_REG.Bits.WGM00=0;
		Timer0_TCCR0_REG.Bits.WGM01=1;
	}
    if (CONFIG->mode==FastPWM_Timer0)
	{
		Timer0_TCCR0_REG.Bits.FOC0=0;
		Timer0_TCCR0_REG.Bits.WGM00=1;
		Timer0_TCCR0_REG.Bits.WGM01=1;
	}

	if(CONFIG->outputMode==NORMAL_MODE_OC0_DISCONNECTED)
	{
		Timer0_TCCR0_REG.Bits.COM00=0;
		Timer0_TCCR0_REG.Bits.COM01=0;
	}
	if(CONFIG->outputMode==CTC_TOGGLE__PWM_RESERVED)
	{
		Timer0_TCCR0_REG.Bits.COM00=1;
		Timer0_TCCR0_REG.Bits.COM01=0;
	}
	if(CONFIG->outputMode==CTC_CLEAR__PWM_NON_INVERTING)
	{
		Timer0_TCCR0_REG.Bits.COM00=0;
		Timer0_TCCR0_REG.Bits.COM01=1;
	}
	if(CONFIG->outputMode==CTC_SET__PWM_INVERTING)
	{
		Timer0_TCCR0_REG.Bits.COM00=1;
		Timer0_TCCR0_REG.Bits.COM01=1;
	}

	Timer0_TCCR0_REG.Byte=(Timer0_TCCR0_REG.Byte & TCCR0_MASK) | (CONFIG->prescaler);

	/* Disable Timer/Counter0 Output Compare Match interrupt */
	Timer0_TIMSK_REG.Bits.OCIE0 = 0;

	/* Disable Timer/Counter0 Overflow Interrupt */
	Timer0_TIMSK_REG.Bits.TOIE0 = 0;
}
void Timer0_UpdateDutyCycle(const TIMER0_Compare_Type OutputMode,const u8 DutyCycle)
{
	if(OutputMode==CTC_CLEAR__PWM_NON_INVERTING)
	{
		Timer0_OCR0_REG=(u8)(((u16)(1-DutyCycle)*255)/100);
	}
	else if(OutputMode==CTC_SET__PWM_INVERTING)
	{
		Timer0_OCR0_REG=(u8)((u16)(DutyCycle*255)/100);
	}
}
void Timer0_CallBackFnc_OV(const void(*pf)(void))
{
	if(pf!=NULL)
	{
		GP_OV=pf;
	}
}

void Timer0_CallBackFnc_CM(const void(*pf)(void))
{
	if(pf!=NULL)
	{
		GP_OV=pf;
	}
}

void __vector_10()
{
	//CM
	if(GP_CM!=NULL)
	{
		GP_CM();
	}
}

void __vector_11()
{
	if(GP_OV!=NULL)
	{
		GP_OV();
	}
}

