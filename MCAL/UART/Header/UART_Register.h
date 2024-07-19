/*
 * UART_Register.h
 *
 *  Created on: May 25, 2024
 *      Author: 20102
 */

#include "UART_Private.h"

#ifndef MCAL_UART_HEADER_UART_REGISTER_H_
#define MCAL_UART_HEADER_UART_REGISTER_H_

#define UART_UCSRA_REG  (*(volatile Type_UCSRA_REG * const)0x2B) // USART Control and Status Register A – UCSRA

#define UART_UCSRB_REG  (*(volatile Type_UCSRB_REG * const)0x2A) // USART Control and Status Register B – UCSRB

#define UART_UCSRC_REG  (*(volatile Type_UCSRC_REG * const)0x40) // USART Control and Status Register C – UCSRC

#define UART_UBRRH  *((volatile u8 *)0x40) // USART Baud Rate Registers – UBRRL and UBRRH
#define UART_UBRRL  *((volatile u8 *)0x29) // USART Baud Rate Registers – UBRRL and UBRRH


#define UART_UDR    *((volatile u16 *)0x2C)// USART I/O Data Register – UDR

#endif /* MCAL_UART_HEADER_UART_REGISTER_H_ */
