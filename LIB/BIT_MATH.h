/*
 * BIT_MATH.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Rowan Madeeh
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define Set_Bit(Reg,bitnum) Reg |=1<<bitnum
#define Clr_Bit(Reg,bitnum) Reg &=~(1<<bitnum)
#define Toggle_Bit(Reg,bitnum) Reg ^=1<<bitnum
#define Get_Bit(Reg,bitnum) (Reg>>bitnum)&0x01
#define Set_Byte(Reg,value) (Reg = value)

#endif /* LIB_BIT_MATH_H_ */
