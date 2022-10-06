/*
 * ADC_CONFIG.h
 *
 * Created: 22/08/2022 10:21:27 م
 *  Author: DELL
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

typedef enum{
	AREF = 0,
	AVCC = 1,
	RESERVED = 2,
	INTERNAL2_56V = 3,
	}adc_ref_t;
	
typedef enum
{
	PRESCALAR_2 = 0,	
	PRESCALAR_4 = 0b10,	
	PRESCALAR_8 = 0b11,	
	PRESCALAR_16 = 0b01,	
	PRESCALAR_32 = 0b101,	
	PRESCALAR_64 = 0b011,
	PRESCALAR_128 = 0b111,	
} adc_pre_val;
	

#endif /* ADC_CONFIG_H_ */