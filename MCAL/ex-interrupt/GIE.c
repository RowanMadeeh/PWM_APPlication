/*
 * GIE.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Rowan Madeeh
 */

#include "../../LIB/std_types.h"
#include "../../LIB/BIT_MATH.h"

#define GIE_SREG_Reg *((volatile u8*)0x5F)

void MGIE_voidenable()
{
	Set_Bit(GIE_SREG_Reg,7);
}
void MGIE_voiddisable()
{
	Clr_Bit(GIE_SREG_Reg,7);
}
