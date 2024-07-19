/*
 * fnc.h
 *
 *  Created on: May 24, 2024
 *      Author: 20102
 */

#ifndef COMMON_FNC_H_
#define COMMON_FNC_H_

#include"../StdType.h"

typedef struct
{

	s32 InputTo;
	s32 InputMin;
	s32 InputMax;
	s32 OutputMin;
	s32 OutputMax;

}DataToChangeRange;

f32 Map_FromToRange2(DataToChangeRange * Data);
f32 Map_FromToRange(s32 InputTo,s32 InputMin,s32 InputMax,s32 OutputMin,s32 OutputMax);
#endif /* COMMON_FNC_H_ */
