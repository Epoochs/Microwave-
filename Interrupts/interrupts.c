/*
 * Interrupts.c
 *
 * Created: 23/08/2022 12:32:11 م
 * Author : DELL
 */ 

#include "interrupts.h"
#include <avr/interrupt.h>

void external_int_enable(external_int_t interrupt, sense_control_t event)
{
	switch(interrupt)
	{
		case int0:
			//disabling the interrupt
			GICR &= ~(0b1 << INT0);
			//setting the event to be rising
			MCUCR &= ~(11 << ISC00);
			MCUCR |= event << ISC00;
			//clear the flag
			GIFR |= 0b01 <<INTF0;
			//enabling the interrupt
			GICR |= 0x01 << INT0;
			
			break;
			
		case int1:
			//disabling the interrupt
			GICR &= ~(1 << INT1);
			//setting the event to be rising
			MCUCR &= ~(11 << ISC10);
			MCUCR |= 0b11 << ISC10;
			//enabling the interrupt
			GICR |= 1 << INT1;
			//clear the flag
			GIFR |= 1 <<INTF1;
			break;
		
		case int2:
			//disabling the interrupt
			GICR &= ~(1 << INT2);
			//setting the event to be rising
			MCUCSR &= ~ (1 << ISC2);
			MCUCR |= 1 << ISC2;
			//enabling the interrupt
			GICR |= 1 << INT2;
			//clear the flag
			GIFR |= 1 <<INTF2;
			break;
		
		default:
			break;
	}
}


