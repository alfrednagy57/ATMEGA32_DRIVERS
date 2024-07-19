/*
 * Calc.c
 *
 *  Created on: Apr 20, 2024
 *      Author: 20102
 */

#include "../../HAL/Calc/Calc.h"

#include <util/delay.h>
#include <stdlib.h>
#include <avr/io.h>


static u8 X_Pos=0;

static u8 Y_Pos=0;

static u8 BtnVal = 0;

static u8 i =0;

static u8 Buff[33]={0};// each number is 2 places in lcd

static u8 num1[3] = {0};

static u8 op='+';

static s8 Sign=1;

static u8 Coui=0;

static s16 Second = 0;

static s32 Res = 0;


void Calc_Op(u8 *Eq)
{
	i=0;
	if(Eq[i] == '+' || Eq[i] == '-')//sign
	{
		Sign=Eq[i];
		i++;
	}

	while(Eq[i] >= '0' && Eq[i] <= '9')//Num
	{
		num1[Coui]=Eq[i];
		i++;
		Coui++;
	}

	if(Sign =='-')
	{
		Sign=-1;
	}
	else if(Sign=='+')
	{
		Sign=1;
	}

	Res = atoi(num1);
	Res *=Sign;

	if(Eq[i] == '+' || Eq[i] == '-'||Eq[i]=='*'||Eq[i]=='/')//operation
	{
		op=Eq[i];
		i++;
	}
	//got the first num and operation


	while(Eq[i]!='\0')
	{

		Coui=0;

		if((Eq[i] == '+' || Eq[i] == '-')&&Eq[i]!='\0')//sign
		{
			Sign=Eq[i];
			i++;
		}

		while((Eq[i] >= '0' && Eq[i] <= '9')&&Eq[i]!='\0')//Num
		{
			num1[Coui]=Eq[i];
			Coui++;
			i++;
		}

		if(Sign =='-')
		{
			Sign=-1;
		}
		else if(Sign=='+')
		{
			Sign=1;
		}

		Second= atoi(num1);

		Second*=Sign;

		switch (op)
		{
		case '+':
			Res +=Second;
			break;
		case '-':
			Res -=Second;
			break;
		case '*':
			Res *=Second;
			break;
		case '/':
			Res /=Second;
			break;
		}

		if((Eq[i] == '+' || Eq[i] == '-'||Eq[i]=='*'||Eq[i]=='/')&&Eq[i]!='\0')//Operation
		{
			op=Eq[i];
			i++;
		}
	}

	itoa(Res,Eq,10);
	Lcd_ClrScreenFnc();
	Lcd_SendString("Answer is : ");
	Lcd_GoToXY_DDRAM(0,1);
	Lcd_SendString(Eq);

}
void Calc()
{

	Lcd_Init();

	Keypad_Init();

	while(1)
	{
		BtnVal=Keypad_ReadBtnValue();//return ASCII code

		if(BtnVal == 'c')
		{
			Lcd_ClrScreenFnc();

			X_Pos=0;
			Y_Pos=0;

			i=0;

		}
		else if(BtnVal == 'n')
		{
			/*nothing*/
		}
		else if(BtnVal != '=')
		{

			Buff[i] =BtnVal;

			Lcd_GoToXY_DDRAM(X_Pos,Y_Pos);
			Lcd_SendData(BtnVal);
			X_Pos++;

			if(X_Pos>15)
			{
				X_Pos=0;

				Y_Pos++;

				if(Y_Pos>1)
				{
					Y_Pos=0;
				}
			}
			_delay_ms(300);//debouncing
			i++;
		}
		else
		{
			Buff[i]='\0';
			i++;
			Calc_Op(Buff);
			i=0;
		}
	}
}



//	while(1)
//	{
//		BtnVal=Keypad_ReadBtnValue();//return ASCII code
//
//		if(BtnVal == 'c')
//		{
//			Lcd_ClrScreenFnc();
//			X_Pos=0;
//			Y_Pos=0;
//		}
//		else if(BtnVal == 'n'||BtnVal == '=')
//		{
//			/*nothing*/
//		}
//		else if(BtnVal == '+'||BtnVal == '-'||BtnVal == '*'||BtnVal == '/')
//		{
//			u8 Operation = BtnVal;
//			while(1)
//			{
//				BtnVal=Keypad_ReadBtnValue();
//
//				if(BtnVal == 'c')
//				{
//					Lcd_ClrScreenFnc();
//					X_Pos=0;
//					Y_Pos=0;
//				}
//				else if(BtnVal == 'n')
//				{
//					/*nothing*/
//				}
//				else if(BtnVal!='=')
//				{
//					keypadVal2=BtnVal;
//
//					Lcd_GoToXY_DDRAM(X_Pos,Y_Pos);
//					Lcd_SendData(keypadVal2);
//					X_Pos++;
//					if(X_Pos>15)
//					{
//						X_Pos=0;
//
//						Y_Pos++;
//
//						if(Y_Pos>1)
//							{
//								Y_Pos=0;
//							}
//					}
//					_delay_ms(300);//debouncing
//				}
//				else
//				{
//					keypadVal  -='0';
//					keypadVal2 -='0';
//					switch (Operation)
//					{
//						case '+' :
//							Res=keypadVal+keypadVal2;
//						break;
//						case '-':
//							Res=keypadVal-keypadVal2;
//						break;
//						case '*':
//							Res=keypadVal*keypadVal2;
//						break;
//						case '/':
//							Res=keypadVal/keypadVal2;
//						break;
//					}
//					Lcd_ClrScreenFnc();
//
//					Lcd_GoToXY_DDRAM(0,0);
//
//					itoa(Res,Buff,10);
//					u8 i=0;
//					while(Buff[i]!='\0')
//					{
//						Lcd_SendData(Buff[i]);
//						i++;
//					}
//					break;
//				}
//
//			}
//		}
//		else
//		{
//			keypadVal=BtnVal;
//
//			Lcd_GoToXY_DDRAM(X_Pos,Y_Pos);
//			Lcd_SendData(keypadVal);
//			X_Pos++;
//			if(X_Pos>15)
//			{
//				X_Pos=0;
//
//				Y_Pos++;
//
//				if(Y_Pos>1)
//					{
//						Y_Pos=0;
//					}
//			}
//			_delay_ms(300);//debouncing
//
//
//		}
//	}
