/*
 * IntEEprom_Register.h
 *
 *  Created on: Aug 13, 2024
 *      Author: basel
 */

#ifndef MCAL_INTERNALEEPROM_HEADER_INTEEPROM_REGISTER_H_
#define MCAL_INTERNALEEPROM_HEADER_INTEEPROM_REGISTER_H_

#define EEARL		(*(volatile u8 *)0x3E)
#define EEARH		(*(volatile u8 *)0x3F)

/*The EEPROM Data Register – EEDR*/
#define EEDR  (*(volatile u8 * const )0x3D)

/*The EEPROM Control Register – EECR
 * Bits 7..4 – Reserved Bits (read as zero) */
#define EECR  (*(volatile u8 * const )0x3C)

#endif /* MCAL_INTERNALEEPROM_HEADER_INTEEPROM_REGISTER_H_ */
