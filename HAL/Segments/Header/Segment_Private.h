/*
 * Segment_Private.h
 *
 *  Created on: Apr 6, 2024
 *      Author: 20102
 */

#ifndef HAL_SEGMENT_HEADER_SEGMENT_PRIVATE_H_
#define HAL_SEGMENT_HEADER_SEGMENT_PRIVATE_H_

/*Anode -----> ON = 0  ________ OFF = 1*/
/*ANODE       a b c d e f g dot*/
/*pin number  0 1 2 3 4 5 6  7 */
// dot on
#define ANODE_ZERO  0x40
#define ANODE_ONE   0x79
#define ANODE_TWO   0x24
#define ANODE_THREE 0x30
#define ANODE_FOUR  0x19
#define ANODE_FIVE  0x12
#define ANODE_SIX   0x02
#define ANODE_SEVEN 0x78
#define ANODE_EIGTH 0x00
#define ANODE_NINE  0x10
/**********************************************************************************************************************************************/
//dot off
#define ANODE_ZERO_OFF  0xC0
#define ANODE_ONE_OFF   0xF9
#define ANODE_TWO_OFF   0xA4
#define ANODE_THREE_OFF 0xB0
#define ANODE_FOUR_OFF  0x99
#define ANODE_FIVE_OFF  0x92
#define ANODE_SIX_OFF   0x82
#define ANODE_SEVEN_OFF 0xF8
#define ANODE_EIGTH_OFF 0x80
#define ANODE_NINE_OFF  0x90
/**********************************************************************************************************************************************/
// dot on
#define CATHODE_ZERO  0xBF
#define CATHODE_ONE   0x86
#define CATHODE_TWO   0xDB
#define CATHODE_THREE 0xCF
#define CATHODE_FOUR  0xE6
#define CATHODE_FIVE  0xED
#define CATHODE_SIX   0xFD
#define CATHODE_SEVEN 0x87
#define CATHODE_EIGTH 0xff
#define CATHODE_NINE  0xEF
/**********************************************************************************************************************************************/
//dot off
#define CATHODE_ZERO_OFF  0x3F
#define CATHODE_ONE_OFF   0x06
#define CATHODE_TWO_OFF   0x5B
#define CATHODE_THREE_OFF 0x4F
#define CATHODE_FOUR_OFF  0x66
#define CATHODE_FIVE_OFF  0x6D
#define CATHODE_SIX_OFF   0x7D
#define CATHODE_SEVEN_OFF 0x07
#define CATHODE_EIGTH_OFF 0x7F
#define CATHODE_NINE_OFF  0x6F
/**********************************************************************************************************************************************/

#define SSANODE   1
#define SSCATHODE 2

#define SIZE      10

#define SS_DIR    0xFF

#endif /* HAL_SEGMENT_HEADER_SEGMENT_PRIVATE_H_ */
