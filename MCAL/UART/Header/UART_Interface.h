/*
 * UART_Intrface.h
 *
 *  Created on: May 25, 2024
 *      Author: 20102
 */

#include"UART_Register.h"

#ifndef MCAL_UART_HEADER_UART_INTERFACE_H_
#define MCAL_UART_HEADER_UART_INTERFACE_H_


void UART_Init(UART_BaudRateType * BAUD);
void UART_SentData(const u8 Data);
void UART_SenDString(const u8* Data);
void UART_ReceiveData(u8 *ReturnData);
void UART_DisableTx();
void UART_DisableRx();
//u8   UART_ReceiveData2();

#endif /* MCAL_UART_HEADER_UART_INTERFACE_H_ */
