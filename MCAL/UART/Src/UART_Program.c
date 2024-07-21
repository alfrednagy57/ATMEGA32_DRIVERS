/*
 * UART_Program.c
 *
 *  Created on: May 25, 2024
 *      Author: 20102
 */

#include "../Header/UART_Interface.h"

void UART_Init(const UART_BaudRateType * BAUD)
{
	// 1 stop bit - no parity - 8 bits data - no interrupt - asynchronous
	// asynchronous - 0 parity - 1 stop bit
	UART_UCSRC_REG.BYTE = 0x86;//0b1000 0110

	UART_UCSRB_REG.BITS.UCSZ2=0;// 8 bits data

	//disable interrupt
	UART_UCSRB_REG.BITS.UDRIE=0;//USART Data Register Empty Interrupt Enable

	UART_UCSRB_REG.BITS.TXCIE=0;//TX Complete Interrupt Enable

	UART_UCSRB_REG.BITS.RXCIE=0;// RX Complete Interrupt Enable

	//disable 2x speed
	UART_UCSRA_REG.BITS.U2X=0;

	//set the baud rate 9600bps ---> ubrr 51
	UART_UBRRH= 0x00;
	UART_UBRRL= (u8)(*BAUD);

	UART_UCSRB_REG.BITS.TXEN=1;// enable transmitter
	UART_UCSRB_REG.BITS.RXEN=1;// enable receiver
}
void UART_SentData(const u8 Data)
{

	while(0==UART_UCSRA_REG.BITS.UDRE)
	{
		/*nothing*/
	}

	// the rest 8 bits
	UART_UDR = Data;

	// clear Data Register Empty flag -> buffer not empty
	UART_UCSRA_REG.BITS.UDRE=1;

}

void UART_SenDString(const u8* Data)
{
	u8 i= 0;
	while(Data[i]!='\0')
	{
		//send the data
		UART_SentData(Data[i]);

		i++;
	}

	//ClrBit(UART_UCSRB,UART_TXEN);// disable transmitter
}

void UART_ReceiveData(u8 *ReturnData)
{

	while(0==UART_UCSRA_REG.BITS.RXC)
	{
		/*nothing*/
	}

	*ReturnData=UART_UDR;

	// clear receiver complete flag
	UART_UCSRA_REG.BITS.RXC=1;
}


void UART_DisableTx()
{
	UART_UCSRB_REG.BITS.TXEN=0;// disable transmitter
}
void UART_DisableRx()
{
	UART_UCSRB_REG.BITS.RXEN=0;// disable receiver
}
