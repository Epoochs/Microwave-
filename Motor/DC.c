/*
 * GccApplication15.c
 *
 * Created: 21/08/2022 12:58:09 م
 * Author : DELL
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include "dio.h"
#include "DCconfig.h"
#include "DCmotor.h"

typedef struct
{
	dio_t port;
	dio_pin_t pin;
} porting_t;

void DCM_init()
{
	porting_t arr[] = MOTOR_PORTING;
	
	for(int i = 0; i < 2; i++)
	{
		dio_set_direction(arr[i].port,arr[i].pin, DIO_DIRECTION_OUTPUT);
	}
	/*for(int i = 0; i < 2; i++)
	{
		dio_set_level(arr[i].port,arr[i].pin, LOW);
	}*/
}
void set_direction(directon_t direction)
{
		switch(direction)
		{
			case SET_LEFT:
				dio_set_level(DIO_PORTC, PIN_3, HIGH);
				dio_set_level(DIO_PORTC, PIN_4, LOW);
				_delay_ms(3000);
				break;
			
			case SET_RIGHT:
				dio_set_level(DIO_PORTC, PIN_3,LOW);
				dio_set_level(DIO_PORTC, PIN_4, HIGH);
				_delay_ms(3000);
				break;
				
			case _STOP_:
				dio_set_level(DIO_PORTC, PIN_3,HIGH);
				dio_set_level(DIO_PORTC, PIN_4, HIGH);
				_delay_ms(3000);
				break;
			default:
				break;	
		}
}
