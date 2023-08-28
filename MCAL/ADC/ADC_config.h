/*
 * ADC_config.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Rowan Madeeh
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
//#include "ADC_priv.h"
/**
 * options:
 *  AVCC
 *  AREF
 *  Internal_Ref
  */

#define ADC_ref_volt AVCC

/**
 * INT:
 * ENABLE or DISABLE
 */

#define ADC_interrupt_enable	ENABLE

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
