/*
 * Segment_Program.c
 *
 *  Created on: Apr 7, 2024
 *      Author: 20102
 */



#include "../../../MCAL/GPIO/Header/GPIO_Interface.h"

#include "../Header/Segment_Interface.h"

void SSD_INIT(u8 GroupName)
{
	GPIO_SetDirectionForGroup(GroupName,SS_DIR);
}


void SS_DISPLAY(u8 SegType,u8 Num,u8 GroupName)
{
	if(SegType==SSANODE)
	{
		switch(Num)
		{
		case 0:
			Num=ANODE_ZERO;
			break;
		case 1:
			Num=ANODE_ONE;
			break;
		case 2:
			Num=ANODE_TWO;
			break;
		case 3:
			Num=ANODE_THREE;
			break;
		case 4:
			Num=ANODE_FOUR;
			break;
		case 5:
			Num=ANODE_FIVE;
			break;
		case 6:
			Num=ANODE_SIX;
			break;
		case 7:
			Num=ANODE_SEVEN;
			break;
		case 8:
			Num=ANODE_EIGTH;
			break;
		case 9:
			Num=ANODE_NINE;
			break;
		}
	}
	else if(SegType ==SSCATHODE)
	{
		switch(Num)
		{
		case 0:
			Num=CATHODE_ZERO;
			break;
		case 1:
			Num=CATHODE_ONE;
			break;
		case 2:
			Num=CATHODE_TWO;
			break;
		case 3:
			Num=CATHODE_THREE;
			break;
		case 4:
			Num=CATHODE_FOUR;
			break;
		case 5:
			Num=CATHODE_FIVE;
			break;
		case 6:
			Num=CATHODE_SIX;
			break;
		case 7:
			Num=CATHODE_SEVEN;
			break;
		case 8:
			Num=CATHODE_EIGTH;
			break;
		case 9:
			Num=CATHODE_NINE;
			break;
		}
	}
	GPIO_SetOutputForGroup(GroupName,Num);
}
