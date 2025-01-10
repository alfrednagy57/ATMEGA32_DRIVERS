/*
 * IntEEprom_Program.c
 *
 *  Created on: Aug 13, 2024
 *      Author: basel
 */

#include "../../../Common/Stdtype.h"
#include "../../../Common/BitMath.h"
#include "../Header/IntEEprom_Interface.h"
#include <util/delay.h>

ES_t EEPROM_write(u16 copy_u16address,u8 copy_u8data)
{
	ES_t local_enuErrorState=ES_NOK;

	while (1 == ((EECR>>1)&1));
	EEARH= (u8)(copy_u16address>>8);
	EEARL= (u8) copy_u16address;
	EEDR = copy_u8data;
	EECR|= (1<<2);
	asm("SBI 0x1C,2");
	asm("SBI 0x1C,1");
	local_enuErrorState=ES_OK;
	return local_enuErrorState;
}
ES_t EEPROM_read(u16 copy_u16address,u8 *copy_u8data){
	ES_t local_enuErrorState=ES_NOK;

	while (1 == ((EECR>>1)&1));
	EEARH= (u8)(copy_u16address>>8);
	EEARL= (u8) copy_u16address;
	EECR|= (1<<0);
	*copy_u8data = EEDR;

	return local_enuErrorState;
}
