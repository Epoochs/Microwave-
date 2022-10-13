/*
 * MicroWave_Project.c
 *
 * Created: 09/10/2022 08:13:17 AM
 * Author : Ahmed Sherif
 */

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "lcd.h"
#include "Keypad.h"
#include "dio.h"
#include "interrupts.h"
#include "SPI.h"
#include "Timer.h"
#include "BIT_MATH.h"
#include "DCmotor.h"

int static time1;
int static time2;
int i;

// Timer used to count down every one second using overflow mode
ISR(TIMER0_OVF_vect)
{
	static uint16_t counter = 0;
	counter++;
	if (counter == 489)
	{
		if (time1 == 0 && time2 != 0)
		{
			execute(4, time1);
			time1 = 10;

			// execute(4,time1);
			time2--;
			execute(3, time2);
		}
		time1--;
		execute(4, time1);

		if (time2 == 0 && time1 == 0)
		{
			Timer0_deinit();
			set_direction(_STOP_);
			dio_set_level(DIO_PORTB, PIN_1, HIGH);
		}

		counter = 0;
	}
}

// Interrupt 2 used to initiate the whole process by initiating the timer only if the timer is set by the user
ISR(INT2_vect)
{
	if (dio_get_level(DIO_PORTB, PIN_2) == LOW)
	{
		
		if (time1 != 0 || time2 != 0)
		{
			Timer0_voidInit();
			set_direction(SET_RIGHT);
			dio_set_level(DIO_PORTB, PIN_0, HIGH);
		}
		
	}
}

// Interrupt 1 used to pause the timer if it's running and reset it if it's paused
ISR(INT1_vect)
{
	if (dio_get_level(DIO_PORTD, PIN_3) == LOW)
	{
		while (dio_get_level(DIO_PORTD,PIN_7) == HIGH && dio_get_level(DIO_PORTD,PIN_6) == HIGH)
		{
			time1 = 0;
			time2 = 0;
			execute(4, 0);
			execute(3, 0);
			Timer0_deinit();
			dio_set_level(DIO_PORTD,PIN_7, LOW);
			dio_set_level(DIO_PORTD,PIN_6, LOW);
		}
		Timer0_deinit();
		set_direction(_STOP_);
	}
}

// Interrupt 0 used to make sure that the door is closed when the pin is set to high
ISR(INT0_vect)
{
	if (dio_get_level(DIO_PORTD, PIN_2) == LOW)
	{
		while(dio_get_level(DIO_PORTD, PIN_2) == LOW)
		{
			Timer0_deinit();
			set_direction(_STOP_);
		}
	}
}


int main(void)
{
	sei();
	key_init(); // Initializing KeyPad
	lcd_init(); // Initializing LCD
	DCM_init(); // Initializing DC-motor
	max_init();

	// Enabling Interrupts
	external_int_enable(int0, _RISING_EDGE);
	external_int_enable(int1, _RISING_EDGE);
	external_int_enable(int2, _RISING_EDGE);

	// Interrupts Input pins
	dio_set_direction(DIO_PORTD, PIN_2, DIO_DIRECTION_INPUT);
	dio_set_level(DIO_PORTD, PIN_2, HIGH);
	dio_set_direction(DIO_PORTD, PIN_3, DIO_DIRECTION_INPUT);
	dio_set_level(DIO_PORTD, PIN_3, HIGH);
	dio_set_direction(DIO_PORTB, PIN_2, DIO_DIRECTION_INPUT);
	dio_set_level(DIO_PORTB, PIN_2, HIGH);
	
	// Heater pin
	dio_set_direction(DIO_PORTB, PIN_0, DIO_DIRECTION_OUTPUT);
	// Buzzer Pin
	dio_set_direction(DIO_PORTC, PIN_5, DIO_DIRECTION_OUTPUT);

	while (1)
	{
		// Prompting the timer from the user
		while(time1 == 0 && time2 == 0)
		{
			for (i = 1; i >= 0; i--)
			{
				time2 = time1;
				time1 = keypad_pressed();
				execute(4 - i, time1);
			}
		}
	}
}