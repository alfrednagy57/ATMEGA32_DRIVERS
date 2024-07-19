/*
 * TWI_Private.h
 *
 *  Created on: Jun 24, 2024
 *      Author: 20102
 */

#include "../../../Common/StdType.h"
#include "../../GPIO/Header/GPIO_Register.h"

#ifndef MCAL_TWI_HEADER_TWI_PRIVATE_H_
#define MCAL_TWI_HEADER_TWI_PRIVATE_H_

#define TWI_GROUP_ID GPIO_GroupC_ID
#define TWI_SDA_ID   GPIO_PIN1
#define TWI_SCL_ID	 GPIO_PIN0

typedef union
{
	u8 BYTE;
	struct
	{
		u8 TWBR0 :1;
		u8 TWBR1 :1;
		u8 TWBR2 :1;
		u8 TWBR3 :1;
		u8 TWBR4 :1;
		u8 TWBR5 :1;
		u8 TWBR6 :1;
		u8 TWBR7 :1;
	} BITS;
} TWI_TWBR_REG;

typedef union
{
	u8 BYTE;
	struct
	{
		u8 TWIE 	 :1;
		u8 UNUSED    :1;
		u8 TWEN  	 :1;
		u8 TWWC 	 :1;
		u8 TWSTO 	 :1;
		u8 TWSTA	 :1;
		u8 TWEA  	 :1;
		u8 TWINT 	 :1;
	} BITS;
} TWI_TWCR_REG;

typedef union
{
	u8 BYTE;
	struct
	{
		u8 TWPS0 	 :1;
		u8 TWPS1     :1;
		u8 UNUSED    :1;
		u8 TWS3 	 :1;
		u8 TWS4 	 :1;
		u8 TWS5  	 :1;
		u8 TWS6  	 :1;
		u8 TWS7 	 :1;
	} BITS;
} TWI_TWSR_REG;

typedef union
{
	u8 BYTE;
	struct
	{
		u8 TWD0 :1;
		u8 TWD1 :1;
		u8 TWD2 :1;
		u8 TWD3 :1;
		u8 TWD4 :1;
		u8 TWD5 :1;
		u8 TWD6 :1;
		u8 TWD7 :1;
	} BITS;
} TWI_TWDR_REG;

typedef union
{
	u8 BYTE;
	struct
	{
		u8 TWGCE :1;
		u8 TWA0  :1;
		u8 TWA1  :1;
		u8 TWA2  :1;
		u8 TWA3  :1;
		u8 TWA4  :1;
		u8 TWA5  :1;
		u8 TWA6  :1;
	} BITS;
} TWI_TWAR_REG;

typedef enum
{
	NoError,
	StartConditionError,
	RepStartConditionError,
	SlaveAddWithReadReqError,
	SlaveAddWithWriteReqError,
	MasterSentDataByteError,
	MasterReceivedDataByteError,
	SlaveTrasmitDataACKError,
	SlaveReadDataACKError
}TWI_ErrStatus;


/* I2C Status Bits in the TWSR Register */
/**************************************************************MASTER******************************************************************************************/

#define TWI_START        		  0x08  /* start has been sent */
#define TWI_REP_START   		  0x10  /* repeated start */
#define TWI_MR_LOST_ABRI	      0x38 	/*Arbitration lost in SLA+W or data bytes*/

/**************************************************************MASTER-TRANSMETTER******************************************************************************/

#define TWI_MT_SLA_W_ACK 		  0x18  /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_W_NACK		  0x20  /*SLA+W has been transmitted; NOT ACK has been received*/
#define TWI_MT_DATA_ACK  		  0x28  /* Master transmit data and ACK has been received from Slave. */
#define TWI_MT_DATA_NACK 	      0x30  /* Master transmit data and NACK has been received from Slave. */

/**************************************************************MASTER-RECEIVER******************************************************************************/

#define TWI_MT_SLA_R_ACK 		  0x40  /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_NACK		  0x48  /* SLA+R has been transmitted; NOT ACK has been received.*/
#define TWI_MR_DATA_ACK   	      0x50  /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK       	  0x58  /* Master received data but doesn't send ACK to slave. */

/**************************************************************SLAVE-TRANSMETTER******************************************************************************/

#define TWI_ST_ADD_RCVD_RD_REQ    0xA8  /*slave address received with read req*/
#define TWI_ST_DATA_ACK  		  0xB8  /*Data byte in TWDR has been transmitted; ACK has been received.*/
#define TWI_ST_DATA_NACK			  0xC0  /*Data byte in TWDR has been transmitted; NOT ACK has been received.*/
#define TWI_ST_Send_Byte_Trans    0xB8  /*means that writting a byte is transmiteed*/

/**************************************************************SLAVE-RECEIVER******************************************************************************/

#define TWI_SR_ADD_RCVD_WR_REQ    0x60  /*slave address received with write req*/
#define TWI_SR_DATA_RCVD 	      0x80  /*means that a byte is received*/
#define TWI_SR_STOP_CONDITON      0xA0  /*means that a stop condition has been received*/

#endif /* MCAL_TWI_HEADER_TWI_PRIVATE_H_ */
