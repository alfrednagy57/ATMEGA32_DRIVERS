/*
 * UART_Private.h
 *
 *  Created on: May 25, 2024
 *      Author: 20102
 */

#include "../../../Common/StdType.h"

#ifndef MCAL_UART_HEADER_UART_PRIVATE_H_
#define MCAL_UART_HEADER_UART_PRIVATE_H_

typedef union
{
	u8 BYTE ;
	struct
	{
		u8  MPCM : 1;
		u8 	U2X  : 1;
		u8  PE   : 1;
		u8  DOR  : 1;
		u8  FE   : 1;
		u8  UDRE : 1;
		u8  TXC  : 1;
		u8  RXC  : 1;
	}BITS;

}Type_UCSRA_REG;

typedef union
{
	u8 BYTE ;
	struct
	{
		u8  TXB8    : 1;
		u8 	RXB8    : 1;
		u8  UCSZ2   : 1;
		u8  TXEN    : 1;
		u8  RXEN    : 1;
		u8  UDRIE   : 1;
		u8  TXCIE   : 1;
		u8  RXCIE   : 1;
	}BITS;

}Type_UCSRB_REG;

typedef union
{
	u8 BYTE ;
	struct
	{
		u8  UCPOL   : 1;
		u8 	UCSZ0   : 1;
		u8  UCSZ1   : 1;
		u8  USBS    : 1;
		u8  UMP0    : 1;
		u8  UMP1    : 1;
		u8  UMSEL   : 1;
		u8  URSEL   : 1;
	}BITS;

}Type_UCSRC_REG;

typedef enum
{
	BAUD_RATE_2400   = 207,
	BAUD_RATE_4800   = 103,
	BAUD_RATE_9600   = 51,
	BAUD_RATE_14400  = 34,
	BAUD_RATE_19200  = 25,
	BAUD_RATE_28800  = 16,
	BAUD_RATE_38400  = 12,
	BAUD_RATE_57600  = 8,
	BAUD_RATE_76800  = 6,
	BAUD_RATE_115200 = 3,
	BAUD_RATE_230400 = 1,
	BAUD_RATE_250000 = 1,
} UART_BaudRateType;

/************************** UCSRC Description **************************
 * URSEL   = 1 The URSEL must be one when writing the UCSRC
 * UCPOL   = 0 Used with the Synchronous operation only
 ***********************************************************************/


#endif /* MCAL_UART_HEADER_UART_PRIVATE_H_ */
