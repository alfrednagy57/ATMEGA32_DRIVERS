/*
 * SPI_Register.h
 *
 *  Created on: Jun 21, 2024
 *      Author: 20102
 */

#include "SPI_Private.h"

#ifndef MCAL_SPI_HEADER_SPI_REGISTER_H_
#define MCAL_SPI_HEADER_SPI_REGISTER_H_


#define SPI_SPCR_REG  (*(volatile Type_SPCR_REG * const)0x2D) //SPI Control Register
#define SPI_SPSR_REG  (*(volatile Type_SPSR_REG * const)0x2E) //SPI Status Register


#define SPI_SPDR_REG  (*(volatile u8*)0x2F) //SPI Data Register

#endif /* MCAL_SPI_HEADER_SPI_REGISTER_H_ */
