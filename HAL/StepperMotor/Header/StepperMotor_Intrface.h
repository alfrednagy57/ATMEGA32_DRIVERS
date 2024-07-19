/*
 * StepperMotor_Intrface.h
 *
 *  Created on: Apr 20, 2024
 *      Author: 20102
 */

#include "../../../MCAL/GPIO/Header/GPIO_Interface.h"

#define StepCW 1
#define StepUCW 2

#ifndef HAL_STEPPERMOTOR_HEADER_STEPPERMOTOR_INTRFACE_H_
#define HAL_STEPPERMOTOR_HEADER_STEPPERMOTOR_INTRFACE_H_

void Stepper_Init(u8 GroupName,u8 PinNum0,u8 PinNum2,u8 PinNum3,u8 PinNum4);

void Stepper_RotateWithAngle(u8 GroupName,u8 PinNum0,u8 PinNum2,u8 PinNum3,u8 PinNum4,u16 Angle);
void Stepper_RotateWithAngleWithClock(u8 GroupName,u8 PinNum0,u8 PinNum2,u8 PinNum3,u8 PinNum4,u16 Angle,u8 Clock);

#endif /* HAL_STEPPERMOTOR_HEADER_STEPPERMOTOR_INTRFACE_H_ */
