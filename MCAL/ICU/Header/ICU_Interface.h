/*
 * ICU_Interface.h
 *
 *  Created on: Jun 19, 2024
 *      Author: 20102
 */

#include "ICU_Register.h"


#ifndef MCAL_ICU_HEADER_ICU_INTERFACE_H_
#define MCAL_ICU_HEADER_ICU_INTERFACE_H_


void ICU_Init(ICU_ClockType Clock,ICU_EdgeType Edge);
void ICU_setEdgeType(ICU_EdgeType edgeType);
u16  ICU_getInputCaptureValue(void);
void ICU_clearTimerValue(void);
void ICU_deInit(void);

void ICU_setCallBack(void (*a_ptr)(void));


void __vector_6() __attribute__((signal));

#endif /* MCAL_ICU_HEADER_ICU_INTERFACE_H_ */
