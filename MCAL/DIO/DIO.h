/*
 * DIO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Rowan Madeeh
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

#include "../../LIB/std_types.h"
// Ports

#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

// directions

#define output 1
#define input 0

//pins

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// pin value

#define High 1
#define Low 0

void MDIO_voidSetPinDirection(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8PinDirection);
void MDIO_voidSetPinValue(u8 A_u8PortNo,u8 A_u8PinNo, u8 A_u8PinValue);
u8 MDIO_u8GetPinValue(u8 A_u8PortNo,u8 A_u8PinNo);
void MDIO_voidSetPortDirection(u8 A_u8PortNo,u8 A_u8PortDirection);
void MDIO_voidSetPortValue(u8 A_u8PortNo,u8 A_u8PortValue);



#endif /* MCAL_DIO_H_ */
