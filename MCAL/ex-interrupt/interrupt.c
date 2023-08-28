/*
 * interrupt.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Rowan Madeeh
 */

#include "../../LIB/std_types.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO.h"
#include "interrupt.h"


#define EXTI_GICR *((volatile u8*)0x5B)
#define EXTI_MCUCR *((volatile u8*)0x55)
#define EXTI_MCUCSR *((volatile u8*)0x54)
#define EXTI_GIFR *((volatile u8*)0x5A)



void MEXTI_voidsense_control(u8 A_u8EXTI_line,u8 A_u8EXTI_sense)
{
	switch(A_u8EXTI_line)
	{
		case EXTI_line0:
			switch(A_u8EXTI_sense)
			{
				case EXTI_lowlevel:
					Clr_Bit(EXTI_MCUCR,0);
					Clr_Bit(EXTI_MCUCR,1);
					break;

				case EXTI_onchange:
					Set_Bit(EXTI_MCUCR,0);
					Clr_Bit(EXTI_MCUCR,1);
					break;

				case EXTI_falling:
					Clr_Bit(EXTI_MCUCR,0);
					Set_Bit(EXTI_MCUCR,1);
					break;

				case EXTI_rising:
					Set_Bit(EXTI_MCUCR,0);
					Set_Bit(EXTI_MCUCR,1);
					break;
			}
			break;

		case EXTI_line1:
			switch(A_u8EXTI_sense)
			{
				case EXTI_lowlevel:
					Clr_Bit(EXTI_MCUCR,2);
					Clr_Bit(EXTI_MCUCR,3);
					break;

				case EXTI_onchange:
					Set_Bit(EXTI_MCUCR,2);
					Clr_Bit(EXTI_MCUCR,3);
					break;

				case EXTI_falling:
					Clr_Bit(EXTI_MCUCR,2);
					Set_Bit(EXTI_MCUCR,3);
					break;

				case EXTI_rising:
					Set_Bit(EXTI_MCUCR,2);
					Set_Bit(EXTI_MCUCR,3);
					break;
			}
			break;

		case EXTI_line2:
			switch(A_u8EXTI_sense)
			{
				case EXTI_falling:
					Clr_Bit(EXTI_MCUCSR,6);
					break;

				case EXTI_rising:
					Set_Bit(EXTI_MCUCSR,6);
					break;
			}
			break;
	}
}
void MEXTI_voidenable(u8 A_u8EXTI_line)
{
	switch(A_u8EXTI_line)
	{
		case EXTI_line0: Set_Bit(EXTI_GICR,6);break;
		case EXTI_line1: Set_Bit(EXTI_GICR,7);break;
		case EXTI_line2: Set_Bit(EXTI_GICR,5);break;
	}
}
void MEXTI_voiddisable(u8 A_u8EXTI_line)
{
	switch(A_u8EXTI_line)
	{
		case EXTI_line0: Clr_Bit(EXTI_GICR,6);break;
		case EXTI_line1: Clr_Bit(EXTI_GICR,7);break;
		case EXTI_line2: Clr_Bit(EXTI_GICR,5);break;
	}
}
