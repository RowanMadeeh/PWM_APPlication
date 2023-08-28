/*
 * ADC_init.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Rowan Madeeh
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_
#include "../../LIB/std_types.h"

void MDAC_voidinit();
u16 MADC_u16analog_read(u8 A_u8channelno);


void MADC_voidstart_conversion(u8 A_u8channelno);
u16  MADC_u16get_ADC_data(void);
void MADC_voidset_callback(void (*A_FuncPtr)(void));

#endif /* MCAL_ADC_ADC_INIT_H_ */
