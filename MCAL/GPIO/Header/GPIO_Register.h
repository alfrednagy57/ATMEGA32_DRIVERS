/*
 * DIO_Register.h
 *
 *  Created on: Apr 5, 2024
 *      Author: 20102
 */

#include "../../../Common/StdType.h"

#include "GPIO_Private.h"

#ifndef MCAL_GPIO_HEADER_GPIO_REGISTER_H_
#define MCAL_GPIO_HEADER_GPIO_REGISTER_H_


#define GPIO_DDRA_REG  (*(volatile DDR_X_PORT_X_PIN_X * const)0x3A)
#define GPIO_DDRB_REG  (*(volatile DDR_X_PORT_X_PIN_X * const)0x37)
#define GPIO_DDRC_REG  (*(volatile DDR_X_PORT_X_PIN_X * const)0x34)
#define GPIO_DDRD_REG  (*(volatile DDR_X_PORT_X_PIN_X * const)0x31)


#define GPIO_PORTA_REG (*(volatile DDR_X_PORT_X_PIN_X * const)0x3B)
#define GPIO_PORTB_REG (*(volatile DDR_X_PORT_X_PIN_X * const)0x38)
#define GPIO_PORTC_REG (*(volatile DDR_X_PORT_X_PIN_X * const)0x35)
#define GPIO_PORTD_REG (*(volatile DDR_X_PORT_X_PIN_X * const)0x32)


#define GPIO_PINA_REG  (*(volatile DDR_X_PORT_X_PIN_X * const)0x39)
#define GPIO_PINB_REG  (*(volatile DDR_X_PORT_X_PIN_X * const)0x36)
#define GPIO_PINC_REG  (*(volatile DDR_X_PORT_X_PIN_X * const)0x33)
#define GPIO_PIND_REG  (*(volatile DDR_X_PORT_X_PIN_X * const)0x30)


#endif /* MCAL_GPIO_HEADER_GPIO_REGISTER_H_ */
