/*
 * TWI_Register.h
 *
 *  Created on: Jun 24, 2024
 *      Author: 20102
 */

#include "TWI_Private.h"

#ifndef MCAL_TWI_HEADER_TWI_REGISTER_H_
#define MCAL_TWI_HEADER_TWI_REGISTER_H_

/* definition for TWBR registers */
#define TWBR_REG (*(volatile TWI_TWBR_REG *const) 0x20)

/* definition for TWSR registers */
#define TWSR_REG (*(volatile TWI_TWSR_REG *const) 0x21)

/* definition for TWAR registers */
#define TWAR_REG (*(volatile TWI_TWAR_REG *const) 0x22)

/* definition for TWDR registers */
#define TWDR_REG (*(volatile TWI_TWDR_REG *const) 0x23)

/* definition for TWCR registers */
#define TWCR_REG (*(volatile TWI_TWCR_REG *const) 0x56)

#endif /* MCAL_TWI_HEADER_TWI_REGISTER_H_ */
