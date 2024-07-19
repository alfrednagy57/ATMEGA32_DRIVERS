/*
 * EXTI_Program.c
 *
 *  Created on: Apr 26, 2024
 *      Author: 20102
 */

#include "../../GPIO/Header/GPIO_Interface.h"
#include "../Header/EXTI_INTERFACE.h"
#include "../Header/EXTI_PRIVATE.h"


static void  (*GInt0)(void)=null;
static void  (*GInt1)(void)=null;
static void  (*GInt2)(void)=null;

void EXTI_Init0(const INT0_INT1_Sense_Control SenseControl)
{
	GPIO_SetDirectionForPin(INT_0_1_GROUP_ID,INT_0_PIN_ID,INT_STATE);//set to input

	if(SenseControl == Low_Level)
	{
		MCUCR_REG.Bits.ISC01 = 0;
		MCUCR_REG.Bits.ISC00 = 0;
	}
	else if(SenseControl == Any_Logic_Change)
	{
		MCUCR_REG.Bits.ISC01 = 0;
		MCUCR_REG.Bits.ISC00 = 1;
	}
	else if(SenseControl == Falling_Edge)
	{
		MCUCR_REG.Bits.ISC01 = 1;
		MCUCR_REG.Bits.ISC00 = 0;

	}
	else if(SenseControl == Rising_Edge)
	{
		MCUCR_REG.Bits.ISC01 = 1;
		MCUCR_REG.Bits.ISC00 = 1;
	}

	GICR_REG.Bits.INT0 = 1;//enable interrupt request
}


void EXTI_Init1(const INT0_INT1_Sense_Control SenseControl)
{

	GPIO_SetDirectionForPin(INT_0_1_GROUP_ID,INT_1_PIN_ID,INT_STATE);

	if(SenseControl == Low_Level)
	{
		MCUCR_REG.Bits.ISC11 = 0;
		MCUCR_REG.Bits.ISC10 = 0;
	}
	else if(SenseControl == Any_Logic_Change)
	{
		MCUCR_REG.Bits.ISC11 = 0;
		MCUCR_REG.Bits.ISC10 = 1;
	}
	else if(SenseControl == Falling_Edge)
	{
		MCUCR_REG.Bits.ISC11 = 1;
		MCUCR_REG.Bits.ISC10 = 0;

	}
	else if(SenseControl == Rising_Edge)
	{
		MCUCR_REG.Bits.ISC11 = 1;
		MCUCR_REG.Bits.ISC10 = 1;
	}

	GICR_REG.Bits.INT1 = 1;//enable interrupt request
}


void EXTI_Init2(const INT2_Sense_Control SenseControl)
{
	GPIO_SetDirectionForPin(INT_2_GROUP_ID,INT_2_PIN_ID,INT_STATE);

	if(SenseControl == Falling_Edge_2)
	{
		MCUCSR_REG.Bits.ISC2 = 0;
	}
	else if(SenseControl == Rising_Edge_2)
	{
		MCUCSR_REG.Bits.ISC2 = 1;
	}

	GICR_REG.Bits.INT2 = 1;//enable interrupt request
}


void EXTI_UPDATE_SENSE_0(const u8 SenseControl)
{
	if(SenseControl == Low_Level)
	{
		MCUCR_REG.Bits.ISC01 = 0;
		MCUCR_REG.Bits.ISC00 = 0;
	}
	else if(SenseControl == Any_Logic_Change)
	{
		MCUCR_REG.Bits.ISC01 = 0;
		MCUCR_REG.Bits.ISC00 = 1;
	}
	else if(SenseControl == Falling_Edge)
	{
		MCUCR_REG.Bits.ISC01 = 1;
		MCUCR_REG.Bits.ISC00 = 0;

	}
	else if(SenseControl == Rising_Edge)
	{
		MCUCR_REG.Bits.ISC01 = 1;
		MCUCR_REG.Bits.ISC00 = 1;
	}
}


void EXTI_UPDATE_SENSE_1(const u8 SenseControl)
{
	if(SenseControl == Low_Level)
	{
		MCUCR_REG.Bits.ISC11 = 0;
		MCUCR_REG.Bits.ISC10 = 0;
	}
	else if(SenseControl == Any_Logic_Change)
	{
		MCUCR_REG.Bits.ISC11 = 0;
		MCUCR_REG.Bits.ISC10 = 1;
	}
	else if(SenseControl == Falling_Edge)
	{
		MCUCR_REG.Bits.ISC11 = 1;
		MCUCR_REG.Bits.ISC10 = 0;

	}
	else if(SenseControl == Rising_Edge)
	{
		MCUCR_REG.Bits.ISC11 = 1;
		MCUCR_REG.Bits.ISC10 = 1;
	}

}


void EXTI_UPDATE_SENSE_2(const u8 SenseControl)
{
	if(SenseControl == Falling_Edge_2)
	{
		MCUCSR_REG.Bits.ISC2 = 0;
	}
	else if(SenseControl == Rising_Edge_2)
	{
		MCUCSR_REG.Bits.ISC2 = 1;
	}
}


void EXTI_Disable_Interrupt_0()
{
	GICR_REG.Bits.INT0 = 0;//enable interrupt request
}
void EXTI_Disable_Interrupt_1()
{
	GICR_REG.Bits.INT1 = 0;//enable interrupt request
}
void EXTI_Disable_Interrupt_2()
{
	GICR_REG.Bits.INT2 = 0;//enable interrupt request
}


void __vector_1()
{
	if(GInt0!=null)
	{
		GInt0();
	}
}
void __vector_2()
{
	if(GInt1!=null)
	{
		GInt1();
	}
}
void __vector_3()
{
	if(GInt2!=null)
	{
		GInt2();
	}
}

void EXTO_CallBackInt0(void(*pf) (void))
{
	if(pf!=null)
	{
		GInt0=pf;
	}
}
void EXTO_CallBackInt1(void(*pf) (void))
{
	if(pf!=null)
	{
		GInt1=pf;
	}
}
void EXTO_CallBackInt2(void (*pf)(void))
{
	if(pf!=null)
	{
		GInt2=pf;
	}
}
