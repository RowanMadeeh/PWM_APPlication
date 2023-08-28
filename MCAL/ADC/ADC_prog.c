/*
 * ADC_prog.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Rowan Madeeh
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/std_types.h"
#include "ADC_init.h"
#include "ADC_priv.h"
#include "ADC_config.h"



void (*ADC_callback)(void);

void MDAC_voidinit()
{
	//reference voltage
	#if ADC_ref_volt == AVCC
		Clr_Bit(ADMUX, REFS1);
		Set_Bit(ADMUX, REFS0);
	#elif ADC_ref_volt == Internal_Ref
		Set_Bit(ADMUX, REFS1);
		Set_Bit(ADMUX, REFS0);
	#elif ADC_ref_volt == AREF
		Clr_Bit(ADMUX, REFS1);
		Clr_Bit(ADMUX, REFS0);
	#else
	#error "error wrong reference"
	#endif

	//data adjustment
	Clr_Bit(ADMUX,ADLAR);

	//auto trigger enable
	ADCSRA = (ADCSRA & 0xF8) | ADC_PS_64;

	//interrupt enable/disable
	#if ADC_interrupt_enable== DISABLE
		Clr_Bit(ADCSRA, ADIE);
	#elif ADC_interrupt_enable== ENABLE
		Set_Bit(ADCSRA, ADIE);
	#else
	#error "error wrong Mode"
	#endif

	//enable ADC
	Set_Bit(ADCSRA,ADEN);
}

u16 MADC_u16analog_read(u8 A_u8channelno)
{
	//select channel
	ADMUX = (ADMUX & 0xE0) | (A_u8channelno & 0x07);

	//start conversion
	Set_Bit(ADCSRA,ADSC);

	//poll on flag
	while(Get_Bit(ADCSRA,ADIF) != 1);

	//clear flag
	Clr_Bit(ADCSRA,ADIF);

	return ADC;
}

void MADC_voidstart_conversion (u8 A_u8channelno)
{
	//select channel
	ADMUX = (ADMUX & 0xE0) | (A_u8channelno & 0x07);

	//start conversion
	Set_Bit(ADCSRA,ADSC);
}
u16  MADC_u16get_ADC_data(void)
{
	return ADC;
}

void MADC_voidset_callback 	  (void (*A_FuncPtr)(void))
{
	ADC_callback=A_FuncPtr;
}

void __vector_16(void) 		__attribute__((signal));

void __vector_16(void){

	ADC_callback();
}
