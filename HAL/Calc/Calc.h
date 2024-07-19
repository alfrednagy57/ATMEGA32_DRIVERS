/*
 * Calc.h
 *
 *  Created on: Apr 20, 2024
 *      Author: 20102
 */

#ifndef HAL_CALC_CALC_H_
#define HAL_CALC_CALC_H_

#include "../../Common/BitMath.H"
#include "../../Common/StdType.h"
#include "../../HAL/Lcd/Header/Lcd_Interface.h"
#include "../../HAL/Keypad/Header/Keypad_Interface.h"

void Calc();
void Calc_Op(u8 *Eq);


#endif /* HAL_CALC_CALC_H_ */
