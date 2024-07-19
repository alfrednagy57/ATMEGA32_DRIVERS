#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

#include "EXTI_Private.h"

void EXTI_Init0(const INT0_INT1_Sense_Control SenseControl);
void EXTI_Init1(const INT0_INT1_Sense_Control SenseControl);
void EXTI_Init2(const INT2_Sense_Control SenseControl);

void EXTI_UPDATE_SENSE_0(const u8 SenseControl);
void EXTI_UPDATE_SENSE_1(const u8 SenseControl);
void EXTI_UPDATE_SENSE_2(const u8 SenseControl);

void EXTI_Disable_Interrupt_0();
void EXTI_Disable_Interrupt_1();
void EXTI_Disable_Interrupt_2();

void __vector_1() __attribute__((signal));
void __vector_2() __attribute__((signal));
void __vector_3() __attribute__((signal));

void EXTO_CallBackInt0(void (*pf)(void));
void EXTO_CallBackInt1(void (*pf)(void));
void EXTO_CallBackInt2(void (*pf)(void));

#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
