/*
 * CFile2.c
 *
 * Created: 21/08/2022 08:49:32 ص
 *  Author: DELL
 */ 
#include "dio.h"
#include "KeyConfig.h"
#include "Keypad.h"
#include <avr/io.h>
# define F_CPU 8000000UL
#include <avr/delay.h>
#include <stdint.h>

typedef struct
{
	dio_t port;
	dio_pin_t pin;
	
}porting_t;

void key_init()
{
	/*porting_t arr_raw[KEY_RAW_NUM] = KEY_RAW_ARR_VAL;
	for (int i = 0; i < KEY_RAW_NUM; i++)
	{
		dio_set_direction(arr_raw[i].port, arr_raw[i].pin,DIO_DIRECTION_INPUT);
	}
	porting_t arr_col[KEY_COL_NUM] = KEY_COL_ARR_VAL;
	for(int i = 0; i <KEY_COL_NUM; i++)
	{
		dio_set_direction(arr_col[i].port, arr_col[i].pin, DIO_DIRECTION_OUTPUT);
	}*/
	
	DDRA = 0xF0;
}
uint8_t keypad_pressed()
{
	while(1)
	{
		PORTA = 0XEF;

		if (dio_get_level(DIO_PORTA, PIN_0) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_0) == LOW)
			;
			return '7';
		}

		if (dio_get_level(DIO_PORTA, PIN_1) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_1) == LOW)
			;
			return '4';
		}

		if (dio_get_level(DIO_PORTA, PIN_2) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_2) == LOW)
			;
			return '1';
		}

		if (dio_get_level(DIO_PORTA, PIN_3) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_3) == LOW)
			;
			return ' ';
		}

		PORTA = 0XDF;

		if (dio_get_level(DIO_PORTA, PIN_0) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_0) == LOW)
			;
			return '8';
		}

		if (dio_get_level(DIO_PORTA, PIN_1) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_1) == LOW)
			;
			return '5';
		}

		if (dio_get_level(DIO_PORTA, PIN_2) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_2) == LOW)
			;
			return '2';
		}

		if (dio_get_level(DIO_PORTA, PIN_3) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_3) == LOW)
			;
			return '0';
		}

		PORTA = 0XBF;

		if (dio_get_level(DIO_PORTA, PIN_0) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_0) == LOW)
			;
			return '9';
		}

		if (dio_get_level(DIO_PORTA, PIN_1) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_1) == LOW)
			;
			return '6';
		}

		if (dio_get_level(DIO_PORTA, PIN_2) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_2) == LOW)
			;
			return '3';
		}

		if (dio_get_level(DIO_PORTA, PIN_3) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_3) == LOW)
			;
			return '=';
		}

		PORTA = 0X7F;

		if (dio_get_level(DIO_PORTA, PIN_0) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_0) == LOW)
			;
			return '/';
		}

		if (dio_get_level(DIO_PORTA, PIN_1) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_1) == LOW)
			;
			return '*';
		}

		if (dio_get_level(DIO_PORTA, PIN_2) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_2) == LOW)
			;
			return '-';
		}

		if (dio_get_level(DIO_PORTA, PIN_3) == LOW)
		{
			while (dio_get_level(DIO_PORTA, PIN_3) == LOW)
			;
			return '+';
		}
	}
	return 0;
}