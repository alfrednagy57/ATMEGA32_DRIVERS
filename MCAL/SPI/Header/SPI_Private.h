/*
 * SPI_Private.h
 *
 *  Created on: Jun 21, 2024
 *      Author: 20102
 */

#ifndef MCAL_SPI_HEADER_SPI_PRIVATE_H_
#define MCAL_SPI_HEADER_SPI_PRIVATE_H_

#include "../../../Common/StdType.h"
#include "../../GPIO/Header/GPIO_Private.h"

typedef union
{
	u8 BYTE;
	struct
	{
		u8  SPR0 : 1;//SPI Clock Rate Select 0
		u8  SPR1 : 1;//SPI Clock Rate Select 1
		u8  CPHA : 1;//Clock Phase
		u8  CPOL : 1;//Clock Polarity
		u8  MSTR : 1;//Master/Slave Select
		u8  DORD : 1;//Data Order
		u8  SPE  : 1;//SPI Enable
		u8  SPIE : 1;//SPI Interrupt Enable
	}BITS;
}Type_SPCR_REG;

typedef union
{
	u8 BYTE;
	struct
	{
		u8  SPI2X : 1;
		u8  UNUSED__5 : 5;
		u8  WCOL  : 1;
		u8  SPIF : 1;
	}BITS;
}Type_SPSR_REG;

typedef enum
{
	OVER_4,
	OVER_16,
	OVER_64,
	OVER_128,
	OVER_2,
	OVER_8,
	OVER_32,

}TYPE_SCK_SPEED;

typedef enum
{
	LEADING_SAMPLE_TRAILING_SETUP,
	LEADING_SETUP_TRAILING_SAMPLE
}TYPE_CPHA_STATUS;

typedef enum
{
	LEADING_RISING_TRAILING_FALLING,
	LEADING_FALLING_TRAILING_RISING
}TYPE_CPOL_STATUS;

typedef enum
{
	MASTER,
	SLAVE
}TYPE_SPI_ROLE;
typedef struct
{
	TYPE_CPOL_STATUS CPOL_STATE;
	TYPE_CPHA_STATUS CPHA_STATE;
	TYPE_SCK_SPEED   SCK_VALUE;
	TYPE_SPI_ROLE   SPI_ROLE;
}SPI_CONFIG;

#define SPI_GROUP_ID  GPIO_GroupB_ID

#define SPI_SS_PIN_NUM   4
#define SPI_MOSI_PIN_NUM 5
#define SPI_MISO_PIN_NUM 6
#define SPI_SCK_PIN_NUM  7


#define SPI_SCK_MASK     0xFC
#define SPI_CONFIG_MASK  0x03

#endif /* MCAL_SPI_HEADER_SPI_PRIVATE_H_ */
