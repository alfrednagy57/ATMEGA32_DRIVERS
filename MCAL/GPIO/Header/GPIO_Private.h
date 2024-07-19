/*
 * DIO_Private.h
 *
 *  Created on: Apr 5, 2024
 *      Author: 20102
 */

#ifndef MCAL_GPIO_HEADER_GPIO_PRIVATE_H_
#define MCAL_GPIO_HEADER_GPIO_PRIVATE_H_

typedef union
{
	u8 BYTE;
	struct
	{
		u8 BIT0 : 1;
		u8 BIT1 : 1;
		u8 BIT2 : 1;
		u8 BIT3 : 1;
		u8 BIT4 : 1;
		u8 BIT5 : 1;
		u8 BIT6 : 1;
		u8 BIT7 : 1;

	}BITS;
}DDR_X_PORT_X_PIN_X;

typedef enum
{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7
}PINS;

#define GPIO_Input     0
#define GPIO_Output    1

#define GPIO_High      1
#define GPIO_Low 	  0

#define GPIO_GroupA_ID    1
#define GPIO_GroupB_ID    2
#define GPIO_GroupC_ID    3
#define GPIO_GroupD_ID    4

#define ResistorNotUp 0
#define ResistorUp    1

#define HIGH_GROUP 		  0xFF
#endif /* MCAL_GPIO_HEADER_GPIO_PRIVATE_H_ */
