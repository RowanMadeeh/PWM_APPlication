/*
 * main.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Rowan Madeeh
 */

#include "../MCAL/ex-interrupt/GIE.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMERS/TIMERS_init.h"
#include "../MCAL/TIMERS/TIMERS_priv.h"
#include "util/delay.h"

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2

volatile u8 flag=0;

void toggle()
{

	for(u8 i=0; i<=255; i++)
	{
		MTIMERS_voidset_compare_value(TIMER0, i);
		_delay_ms(100);
	}

	for(u8 i=255; i>=0; i--)
	{
		MTIMERS_voidset_compare_value(TIMER0, i);
		_delay_ms(100);
	}
}

void toggle_servo()
{
	MTIMERS_voidinit(TIMER1);
	// Calculate OCR1A values for 0 and 180 degrees
	  uint16_t ocr_0_deg = 1000;   // Replace with the appropriate value
	  uint16_t ocr_180_deg = 2000; // Replace with the appropriate value

	  // Move from 0 to 180 degrees
	  for (u16 ocr = ocr_0_deg; ocr <= ocr_180_deg; ocr++) {
		 MTIMERS_voidset_compare_value(TIMER1, ocr);         // Update the OCR1A value
	    _delay_ms(10);       // Delay to control the speed of the sweeping motion
	  }

	  // Move from 180 to 0 degrees
	  for (u16 ocr = ocr_180_deg; ocr >= ocr_0_deg; ocr--) {
		 MTIMERS_voidset_compare_value(TIMER1, ocr);          // Update the OCR1A value
	    _delay_ms(10);       // Delay to control the speed of the sweeping motion
	  }
}
void main()
{
	MDIO_voidSetPinDirection(PortB,PIN3,output);
	MTIMERS_voidinit(TIMER0);
	MTIMERS_voidStart(TIMER0);
	MTIMERS_voidPreload_value(TIMER0,224);
	MTIMERS_voidSet_intervals_CTC(TIMER0,2000,64,toggle);


	MDIO_voidSetPinDirection(PortD,PIN5,output);
	MTIMERS_voidStart(TIMER1);


	while(1)
	{
		toggle_servo();
	}
}
