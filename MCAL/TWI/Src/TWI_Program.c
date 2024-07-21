/*
 ============================================================================
 Name        : twi.c
 Module Name : TWI(I2C)
 Author      : Alfred Nagy
 Date        : 25 June 2024
 Description : Source file for the AVR TWI(I2C) driver
 ============================================================================
 */

#include "../Header/TWI_Interface.h"
#include "../../GPIO/Header/GPIO_Interface.h"

/*TWPS -----> COUNT
 *SCL frequency ----->REQUIRED_SCL_IN_KILOS
 *
 * */
void CALC_TWPS_TWBR(const u8 REQUIRED_SCL_IN_KILOS)
{
	u8 __4_POWER_TWPS = 0;
	u8 CALCULATED_TWBR = 0;
	for (u8 COUNT=0;COUNT < 4;COUNT++)
	{
		if(COUNT==0)
		{
			__4_POWER_TWPS=1;
		}
		else if(COUNT==1)
		{
			__4_POWER_TWPS=4;
		}
		else if(COUNT==2)
		{
			__4_POWER_TWPS=16;
		}
		else if(COUNT==2)
		{
			__4_POWER_TWPS=64;
		}

		CALCULATED_TWBR =( ( (8000u) / REQUIRED_SCL_IN_KILOS ) - 16 )/ (2* __4_POWER_TWPS);

		if(CALCULATED_TWBR>0)
		{
		__4_POWER_TWPS=COUNT;
		}
	}
	if(CALCULATED_TWBR>0)
	{
		TWSR_REG.BYTE = (TWSR_REG.BYTE & 0xFC) |  (__4_POWER_TWPS & 0x03);

		TWBR_REG.BYTE = CALCULATED_TWBR ;
	}
	else
	{
		TWSR_REG.BYTE = TWBR_REG.BYTE = 0 ;
	}
}

/*pass zero if the master will not be addressed -----> always transmitter*/
void TWI_MasterInit(const u8 MasterAdd ,const  u8 required_scl)
{
	GPIO_SetDirectionForPin(TWI_GROUP_ID,TWI_SCL_ID,GPIO_Output);//set pin0 group c to OUTPUT ----->SCL pin

	CALC_TWPS_TWBR(required_scl);

	//assign the address -----> master may be a slave at any time
	if(0!=MasterAdd)
	{
		TWAR_REG.BYTE=MasterAdd<<1;
	}

	//enable twi circuit
	TWCR_REG.BITS.TWEN=1;
}

void TWI_SlaveInit(const u8 SlaveAdd)
{
	GPIO_SetDirectionForPin(TWI_GROUP_ID,TWI_SCL_ID,GPIO_Input);//set pin0 group c to INPUT ----->SCL pin

	//assign the address
	TWAR_REG.BYTE=SlaveAdd<<1;

	//enable ack in slave --> to send ack after getting the start condition
	TWCR_REG.BITS.TWEA=1;

	//enable general call
	TWAR_REG.BITS.TWGCE=1;

	//enable twi circuit
	TWCR_REG.BITS.TWEN=1;
}

TWI_ErrStatus TWI_SendStartCondition()
{
	TWI_ErrStatus Local_ErrState=NoError;

	/************************** TWCR Description **************************
	 * TWIE   = 0 Disable TWI Interrupt
	 * TWEN   = 1 Enable TWI Module
	 * TWSTO  = 0 We don't need to generate stop condition in generate start condition mode
	 * TWSTA  = 1 generating start condition
	 * TWEA   = 0 We don't need to generate acknowledge pulse in generate start condition mode
	 * TWINT  = 1 Clear the TWINT flag before reading the data
	 ***********************************************************************/
	TWCR_REG.BYTE = 0xA4;

	//busy wait until the interrupt flag is raised again -----> operation is done
	while(0==TWCR_REG.BITS.TWINT)
	{
		/*nothing*/
	}

	if( (TWSR_REG.BYTE&0xF8) != TWI_START )
	{
		Local_ErrState=StartConditionError;
	}
	else
	{
		/*nothing*/
	}

	//set start condition
	TWCR_REG.BITS.TWSTA=0;

	return Local_ErrState;
}

TWI_ErrStatus TWI_SendRepeatedStart()
{
	TWI_ErrStatus Local_ErrState=NoError;


	/************************** TWCR Description **************************
	 * TWIE   = 0 Disable TWI Interrupt
	 * TWEN   = 1 Enable TWI Module
	 * TWSTO  = 0 We don't need to generate stop condition in generate start condition mode
	 * TWSTA  = 1 generating start condition
	 * TWEA   = 0 We don't need to generate acknowledge pulse in generate start condition mode
	 * TWINT  = 1 Clear the TWINT flag before reading the data
	 ***********************************************************************/
	TWCR_REG.BYTE = 0xA4;

	//busy wait until the interrupt flag is raised again -----> operation is done
	while(0==TWCR_REG.BITS.TWINT)
	{
		/*nothing*/
	}

	if( (TWSR_REG.BYTE&0xF8) != TWI_REP_START )
	{
		Local_ErrState=StartConditionError;
	}
	else
	{
		/*nothing*/
	}

	//set start condition
	TWCR_REG.BITS.TWSTA=0;

	return Local_ErrState;
}

TWI_ErrStatus TWI_MasterWriteDataByte(const u8 DataByte)
{
	GPIO_SetDirectionForPin(TWI_GROUP_ID,TWI_SDA_ID,GPIO_Output);//set pin1 group c to OUTPUT ----->SDA pin

	TWI_ErrStatus Local_ErrState=NoError;

	//sending slave
	TWDR_REG.BYTE=DataByte;

	/************************** TWCR Description **************************
	 * TWIE   = 0 Disable TWI Interrupt
	 * TWEN   = 1 Enable TWI Module
	 * TWSTO  = 0 We don't need to generate stop condition in send data mode
	 * TWSTA  = 0 We don't need to generate start condition in send data mode
	 * TWEA   = 0 We don't need to generate acknowledge pulse in send data mode
	 * TWINT  = 1 Clear the TWINT flag before reading the data
	 ***********************************************************************/
	TWCR_REG.BYTE = 0x84;

	//busy wait until the interrupt flag is raised again -----> operation is done
	while(0==TWCR_REG.BITS.TWINT)
	{
		/*nothing*/
	}

	if( (TWSR_REG.BYTE&0xF8) != TWI_MT_DATA_ACK )
	{
		Local_ErrState=MasterSentDataByteError;
	}
	else
	{
		/*nothing*/
	}

	return Local_ErrState;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8* ReceiveDate)
{
	GPIO_SetDirectionForPin(TWI_GROUP_ID,TWI_SDA_ID,GPIO_Input);//set pin1 group c to INPUT ----->SDA pin

	TWI_ErrStatus Local_ErrState=NoError;

	/************************** TWCR Description **************************
	 * TWIE   = 0 Disable TWI Interrupt
	 * TWEN   = 1 Enable TWI Module
	 * TWSTO  = 0 We don't need to generate stop condition in receive mode
	 * TWSTA  = 0 We don't need to generate start condition in receive mode
	 * TWEA   = 1 generating acknowledge pulse
	 * TWINT  = 1 Clear the TWINT flag before reading the data
	 ***********************************************************************/
	//NACK 0x84
	TWCR_REG.BYTE = 0xC4;

	//busy wait until the interrupt flag is raised again -----> operation is done
	while(0==TWCR_REG.BITS.TWINT)
	{
		/*nothing*/
	}

	if( (TWSR_REG.BYTE&0xF8) != TWI_MR_DATA_ACK )
	{
		Local_ErrState=MasterReceivedDataByteError;
	}
	else
	{
		//read the received data
		*ReceiveDate=TWDR_REG.BYTE;
	}

	//disable ack
	TWAR_REG.BITS.TWGCE=0;

	return Local_ErrState;
}
TWI_ErrStatus TWI_SlaveWriteDataByte(const u8 DataByte)
{
	GPIO_SetDirectionForPin(TWI_GROUP_ID,TWI_SDA_ID,GPIO_Output);//set pin1 group c to OUTPUT ----->SDA pin

	TWI_ErrStatus Local_ErrState=NoError;

	//assign the data to be sent
	TWDR_REG.BYTE=DataByte;

	//clear flag to start previous operation
	TWCR_REG.BITS.TWINT=1;

	//busy wait until the interrupt flag is raised again -----> operation is done
	while(0==TWCR_REG.BITS.TWINT)
	{
		/*nothing*/
	}

	if( (TWSR_REG.BYTE&0xF8) != TWI_ST_DATA_ACK )
	{
		Local_ErrState=SlaveTrasmitDataACKError;
	}
	else
	{
		/*nothing*/
	}

	return Local_ErrState;
}

TWI_ErrStatus TWI_SlaveReadDataByte(u8* ReceiveDate)
{
	//enable ack in master --> data with ack
	TWAR_REG.BITS.TWGCE=1;

	GPIO_SetDirectionForPin(TWI_GROUP_ID,TWI_SDA_ID,GPIO_Input);;//set pin1 group c to INPUT ----->SDA pin

	TWI_ErrStatus Local_ErrState=NoError;

	//clear flag to start previous operation
	TWCR_REG.BITS.TWINT=1;

	//busy wait until the interrupt flag is raised again -----> operation is done
	while(0==TWCR_REG.BITS.TWINT)
	{
		/*nothing*/
	}

	if( (TWSR_REG.BYTE&0xF8) != TWI_SR_DATA_RCVD )
	{
		Local_ErrState=SlaveReadDataACKError;
	}
	else
	{
		//assign the data to be sent
		*ReceiveDate=TWDR_REG.BYTE;
	}

	return Local_ErrState;
}

void TWI_EnableACK()
{
	TWAR_REG.BITS.TWGCE=1;

	//clear flag to start previous operation
	TWCR_REG.BITS.TWINT=1;

}

void TWI_DisableACK()
{
	TWAR_REG.BITS.TWGCE=1;

	//clear flag to start previous operation
	TWCR_REG.BITS.TWINT=1;

}

u8 TWI_getStatus(void)
{

	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */

	return  TWSR_REG.BYTE & 0xF8;
}

void TWI_SendStopCondition()
{

	/************************** TWCR Description **************************
	 * TWIE   = 0 Disable TWI Interrupt
	 * TWEN   = 1 Enable TWI Module
	 * TWSTO  = 1 generating stop condition
	 * TWSTA  = 0 We don't need to generate start condition in generate stop condition mode
	 * TWEA   = 0 We don't need to generate acknowledge pulse in generate stop condition mode
	 * TWINT  = 1 Clear the TWINT flag before reading the data
	 ***********************************************************************/
	TWCR_REG.BYTE = 0x94;
}
