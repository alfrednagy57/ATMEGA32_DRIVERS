/*
 * SPI_Interface.h
 *
 *  Created on: Jun 21, 2024
 *      Author: 20102
 */

#include "SPI_Register.h"

#ifndef MCAL_SPI_HEADER_SPI_INTERFACE_H_
#define MCAL_SPI_HEADER_SPI_INTERFACE_H_

void SPI_Init(SPI_CONFIG *CONFIG);
u8 SPI_TransCever(const u8 Data);
void SPI_TransCever_SendString(u8 * DATA_STRING);

#endif /* MCAL_SPI_HEADER_SPI_INTERFACE_H_ */
