/*
 * DIO_Interface.h
 *
 *  Created on: Apr 5, 2024
 *      Author: 20102
 */

#include "../../../Common/StdType.h"
#include "GPIO_Register.h"
/*
 * configure ddr_X as input then write 1 on port_X to activate pull up resistors
 *
 * */
#ifndef MCAL_GPIO_HEADER_GPIO_INTERFACE_H_
#define MCAL_GPIO_HEADER_GPIO_INTERFACE_H_

/*DIrection*/
void GPIO_SetDirectionForPin(u8 GroupName,u8 PinNumber,u8 DirectionState);
void GPIO_SetDirectionForGroup(u8 GroupName,u8 Direction);

/*Output*/
void GPIO_SetOutputForPin(u8 GroupName,u8 PinNumber,u8 OutputState);
void GPIO_SetOutputForGroup(u8 GroupName,u8 Output);
void GPIO_TogOutputForPin(u8 GroupName,u8 PinNumber);
void GPIO_TogOutputForGroup(u8 GroupName);

/*Input*/
u8 GPIO_ReadValueForPin(u8 GroupName,u8 PinNumber);
u8 GPIO_ReadValueForGroup(u8 GroupName);

#endif /* MCAL_GPIO_HEADER_GPIO_INTERFACE_H_ */
