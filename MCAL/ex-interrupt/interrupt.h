/*
 * interrupt.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Rowan Madeeh
 */

#ifndef HAL_EX_INTERRUPT_INTERRUPT_H_
#define HAL_EX_INTERRUPT_INTERRUPT_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/std_types.h"
#include "../DIO/DIO.h"

#define INT_PORT PortD
#define control_port PortA

#define EXTI_line0 0
#define EXTI_line1 1
#define EXTI_line2 2

#define EXTI_lowlevel 0
#define EXTI_onchange 1
#define EXTI_falling  2
#define EXTI_rising   3

void MEXTI_voidsense_control(u8 A_u8EXTI_line,u8 A_u8EXTI_sense);
void MEXTI_voidenable(u8 A_u8EXTI_line);
void MEXTI_voiddisable(u8 A_u8EXTI_line);
#endif /* HAL_EX_INTERRUPT_INTERRUPT_H_ */
