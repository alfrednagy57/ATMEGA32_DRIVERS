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
void GPIO_SetDirectionForPin(const u8 GroupName,const u8 PinNumber,const u8 DirectionState);
void GPIO_SetDirectionForGroup(const u8 GroupName,const u8 Direction);

/*Output*/
void GPIO_SetOutputForPin(const u8 GroupName,const u8 PinNumber,const u8 OutputState);
void GPIO_SetOutputForGroup(const u8 GroupName,const u8 Output);
void GPIO_TogOutputForPin(const u8 GroupName,const u8 PinNumber);
void GPIO_TogOutputForGroup(const u8 GroupName);

/*Input*/
u8 GPIO_ReadValueForPin(const u8 GroupName,const u8 PinNumber);
u8 GPIO_ReadValueForGroup(const u8 GroupName);

#endif /* MCAL_GPIO_HEADER_GPIO_INTERFACE_H_ */
