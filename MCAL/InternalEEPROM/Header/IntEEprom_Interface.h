/*
 * IntEEprom_Interface.h
 *
 *  Created on: Aug 13, 2024
 *      Author: basel
 */

#ifndef MCAL_INTERNALEEPROM_HEADER_INTEEPROM_INTERFACE_H_
#define MCAL_INTERNALEEPROM_HEADER_INTEEPROM_INTERFACE_H_

#include "IntEEprom_Register.h"
#include "IntEEprom_Private.h"

ES_t EEPROM_write(u16 copy_u16address,u8 copy_u8data);
ES_t EEPROM_read(u16 copy_u16address,u8 *copy_u8data);

#endif /* MCAL_INTERNALEEPROM_HEADER_INTEEPROM_INTERFACE_H_ */
