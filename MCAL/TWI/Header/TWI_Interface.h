/*
 * TWI_Interface.h
 *
 *  Created on: Jun 24, 2024
 *      Author: 20102
 */

#include "TWI_Register.h"

#ifndef MCAL_TWI_HEADER_TWI_INTERFACE_H_
#define MCAL_TWI_HEADER_TWI_INTERFACE_H_

void CALC_TWPS_TWBR(u8 REQUIRED_SCL_IN_KILOS);
/*pass zero if the master will not be addressed -----> always transmitter*/
void TWI_MasterInit(u8 MasterAdd , u8 required_scl);

void TWI_SlaveInit(u8 SlaveAdd);

TWI_ErrStatus TWI_SendStartCondition();

TWI_ErrStatus TWI_SendRepeatedStart();
/*sending slave add + R/W   is simply sending data where slave add is 7 BITS then the R/W BIT comes */

TWI_ErrStatus TWI_MasterWriteDataByte(u8 DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8* ReceiveDate);

TWI_ErrStatus TWI_SlaveWriteDataByte(u8 DataByte);

TWI_ErrStatus TWI_SlaveReadDataByte(u8* ReceiveDate);

u8 TWI_getStatus(void);

void TWI_EnableACK();

void TWI_DisableACK();

void TWI_SendStopCondition();

#endif /* MCAL_TWI_HEADER_TWI_INTERFACE_H_ */
