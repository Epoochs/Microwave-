/*
 * ADC.c
 *
 * Created: 27/08/2022 11:20:16 م
 *  Author: DELL
 */ 
 #define F_CPU 8000000UL
 #include <util/delay.h>
 #include <avr/io.h>
 #include "ADC.h"
 #include "ADC_CONFIG.h"
 #include <avr/interrupt.h>
 #include "BIT_MATH.h"
 
 void adc_init()
{
	ADCSRA = 0;
	ADMUX = 0;
	//enable adc
	SET_BIT(ADCSRA, ADEN);
	// data will be left adjusted
	SET_BIT(ADMUX, ADLAR);
	// VREF SAME AS VCC
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
	// ADC prescalar 128
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
}

void adc_select_channel(uint8_t channel)
{
	// clearing bits of MUX4:0
	ADMUX &= ~ (0b11111 < MUX0);
	ADMUX |= channel << MUX0;
}

void adc_start_conv()
{
	ADCSRA |= (1 << ADSC);
	
	while(GET_BIT(ADCSRA, ADIF) == 0);
}

uint16_t adc_get_data()
{
	ADCSRA |= (1 << ADIF); //CLEAR THE FLAG
	_delay_ms(1);
	uint16_t adc_val;
	adc_val = ADCL;
	adc_val |= ADCH << 8;
	return adc_val;
}