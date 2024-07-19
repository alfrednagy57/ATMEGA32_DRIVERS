/*
 * fnc.c
 *
 *  Created on: May 24, 2024
 *      Author: 20102
 */
#include "Map.h"

f32 Map_FromToRange(s32 InputTo,s32 InputMin,s32 InputMax,s32 OutputMin,s32 OutputMax)
{
	f32 LocalRes=0;

	LocalRes=InputTo-InputMin;
	LocalRes*=(OutputMax-OutputMin);
	LocalRes/=(InputMax-InputMin);
	LocalRes+=OutputMin;

	return LocalRes;
}
f32 Map_FromToRange2(DataToChangeRange * Data)
{
	s32 LocalRes=0;

	LocalRes=Data->InputTo-Data->InputMin;
	LocalRes*=(Data->OutputMax-Data->OutputMin);
	LocalRes/=((Data->InputMax)-(Data->InputMin));
	LocalRes+=Data->OutputMin;

	return LocalRes;
}
