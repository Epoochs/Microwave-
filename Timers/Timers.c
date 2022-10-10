/*
 * Timers.c
 *
 * Created: 08/10/2022 08:15:08 ص
 *  Author: DELL
 */ 
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include "Timer.h"
#include "Timer_Config.h"
#include "BIT_MATH.h"

void Timer0_voidInit(void)
{
	// Setting Normal Mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	// Clock Set to 64
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
	// Pre-load value
	TCNT0 = 184;
	//TCCR0 = 0x03;
	
	// Enabling Timer Interrupt
	SET_BIT(TIMSK,TOIE0);
	//TIMSK = 1 << TOIE0;
}

uint8_t timer_get_counter()
{
	return TCNT0;
}

void Timer0_deinit()
{
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
}