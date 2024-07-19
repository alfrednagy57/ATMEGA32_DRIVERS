
#include "../../../Common/StdType.h"

#ifndef MCAL_EXTI_HEADER_EXTI_PRIVATE_H_
#define MCAL_EXTI_HEADER_EXTI_PRIVATE_H_

typedef union {
    u8 BYTE;
    struct {
        u8 ISC00 : 1;
        u8 ISC01 : 1;
        u8 ISC10 : 1;
        u8 ISC11 : 1;
        u8 UNUSED_4 : 4;
    }Bits;
} Type_MCUCR_REG;

typedef union {
    u8 BYTE;
    struct {
        u8 UNUSED_6 : 6;
        u8 ISC2 : 1;
        u8 UNUSED_1 : 1;
    }Bits;
} Type_MCUCSR_REG;

typedef union {
    u8 BYTE;
    struct {
        u8 UNUSED_5 : 5;
        u8 INT2 : 1;
        u8 INT0 : 1;
        u8 INT1 : 1;
    } Bits;
} Type_GICR_REG;

typedef union {
    u8 BYTE;
    struct {
        u8 UNUSED_5 : 5;
        u8 INTF2 : 1;
        u8 INTF0 : 1;
        u8 INTF1 : 1;
    }Bits;
} Type_GIFR_REG;

typedef enum {
    Low_Level,
    Any_Logic_Change,
    Falling_Edge,
    Rising_Edge
} INT0_INT1_Sense_Control;

typedef enum {
    Falling_Edge_2,
    Rising_Edge_2
} INT2_Sense_Control;

#define null  (void *)0

#define MCUCR_REG  (*(volatile Type_MCUCR_REG  * const)0x55)
#define MCUCSR_REG (*(volatile Type_MCUCSR_REG * const)0x54)
#define GICR_REG   (*(volatile Type_GICR_REG   * const)0x5B)
#define GIFR_REG   (*(volatile Type_GIFR_REG   * const)0x5A)

#define INT_0_1_GROUP_ID 4
#define INT_0_PIN_ID     2
#define INT_1_PIN_ID     3

#define INT_2_GROUP_ID   2
#define INT_2_PIN_ID     2

#define INT_STATE		 0

#endif /* MCAL_EXTI_HEADER_EXTI_PRIVATE_H_ */
