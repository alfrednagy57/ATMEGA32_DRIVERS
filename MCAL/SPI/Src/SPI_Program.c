/*
 * SPI_Program.c
 *
 *  Created on: Jun 21, 2024
 *      Author: 20102
 */

#include "../Header/SPI_Interface.h"
#include "../../GPIO/Header/GPIO_Interface.h"
//to set another master and de-activate a master write zero on ss pin.
//note : if ss pin is configured as input in master.
void SPI_Init(SPI_CONFIG *CONFIG)
{
	if(CONFIG->SPI_ROLE==MASTER)
	{
		GPIO_SetDirectionForPin(SPI_GROUP_ID,SPI_SS_PIN_NUM,GPIO_Input);//set ss as input
		GPIO_SetOutputForPin(SPI_GROUP_ID,SPI_SS_PIN_NUM,GPIO_High);// configure pull up resistors

		GPIO_SetDirectionForPin(SPI_GROUP_ID,SPI_MOSI_PIN_NUM,GPIO_Output);//set MOSI as OUTPUT

		GPIO_SetDirectionForPin(SPI_GROUP_ID,SPI_MISO_PIN_NUM,GPIO_Input);//set MISO as INPUT

		GPIO_SetDirectionForPin(SPI_GROUP_ID,SPI_SCK_PIN_NUM,GPIO_Output);//set SCK as OUTPUT

		//SET AS MASTER
		SPI_SPCR_REG.BITS.MSTR=1;
	}
	else if (CONFIG->SPI_ROLE == SLAVE)
	{

		GPIO_SetDirectionForPin(SPI_GROUP_ID,SPI_SS_PIN_NUM,GPIO_Input);//set ss as input

		GPIO_SetDirectionForPin(SPI_GROUP_ID,SPI_MOSI_PIN_NUM,GPIO_Input);//set MOSI as INTPUT

		GPIO_SetDirectionForPin(SPI_GROUP_ID,SPI_MISO_PIN_NUM,GPIO_Output);//set MISO as INPUT

		GPIO_SetDirectionForPin(SPI_GROUP_ID,SPI_SCK_PIN_NUM,GPIO_Input);//set SCK as OUTPUT

		//SET AS SLAVE
		SPI_SPCR_REG.BITS.MSTR=0;
	}

	/*Sck*/
	SPI_SPCR_REG.BYTE= (SPI_SPCR_REG.BYTE & SPI_SCK_MASK )| (CONFIG->SCK_VALUE&SPI_CONFIG_MASK);

	SPI_SPSR_REG.BITS.SPI2X=0;

	if(CONFIG->SCK_VALUE>OVER_128)
	{
		SPI_SPSR_REG.BITS.SPI2X=1;
	}

	//dord as Lsb
	SPI_SPCR_REG.BITS.DORD=1;

	//disable interrupt
	SPI_SPCR_REG.BITS.SPIE=0;

	/* Choose CPOL and CPHA => Raising/Falling , Setup/Sample  */
	SPI_SPCR_REG.BITS.CPOL=CONFIG->CPOL_STATE;
	//Setup  --> send
	SPI_SPCR_REG.BITS.CPHA=CONFIG->CPHA_STATE;

	//enable spi
	SPI_SPCR_REG.BITS.SPE=1;
}

u8 SPI_TransCever(const u8 Data)
{
	//data to be sent
	SPI_SPDR_REG=Data;

	while(0==SPI_SPSR_REG.BITS.SPIF)
	{
		/*nothing*/
	}

	//	clear spif -----> cleared by reading spif the accessing spdr
	//	SetBit(SPI_SPSR,SPI_SPIF);

	return SPI_SPDR_REG;
}
void SPI_TransCever_SendString(u8 * DATA_STRING)
{
	u8 i=0;
	while (DATA_STRING[i]!='\0')
	{
		DATA_STRING[i]=SPI_TransCever(DATA_STRING[i]);
		i++;
	}
}
