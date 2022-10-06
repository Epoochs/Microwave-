/*
 * KEY_CONFIG_H_
 *
 * Created: 21/08/2022 08:40:35 AM
 *  Author: Ahmed Sherif
 */ 


#ifndef KEY_CONFIG_H_
#define KEY_CONFIG_H_
#include "dio.h"
#include "lcd.h"

#define KEY_RAW_NUM 4
#define KEY_COL_NUM 4

#define KEYPAD_RO_PIN       PIN_0
#define KEYPAD_R0_PORT		DIO_PORTA

#define KEYPAD_R1_PIN		PIN_1
#define KEYPAD_R1_PORT		DIO_PORTA

#define KEYPAD_R2_PIN		PIN_2
#define KEYPAD_R2_PORT		DIO_PORTA

#define KEYPAD_R3_PIN		PIN_3
#define KEYPAD_R3_PORT		DIO_PORTA

#define KEY_RAW_ARR_VAL     {   \
	{DIO_PORTA, PIN_0},         \
	{DIO_PORTA, PIN_1},			\
	{DIO_PORTA, PIN_2},			\
	{DIO_PORTA, PIN_3}			\	
}


#define KEYPAD_CO_PIN       PIN_4
#define KEYPAD_C0_PORT		DIO_PORTA

#define KEYPAD_C1_PIN		PIN_5
#define KEYPAD_C1_PORT		DIO_PORTA

#define KEYPAD_C2_PIN		PIN_6
#define KEYPAD_C2_PORT		DIO_PORTA

#define KEYPAD_C3_PIN		PIN_7
#define KEYPAD_C3_PORT		DIO_PORTA

#define KEY_COL_ARR_VAL     {   \
	{DIO_PORTA, PIN_4},         \
	{DIO_PORTA, PIN_5},			\
	{DIO_PORTA, PIN_6},			\
	{DIO_PORTA, PIN_7}			\
}


#define key_values {	\
 {'7', '8', '9', '/'},  \
 {'4', '5', '6', '*'},  \
 {'1', '2', '3', '-'},  \
 {'O', '0', '=', '+'}	\
}

#define COL_0					dio_set_level(DIO_PORTA, PIN_4, LOW)
#define COL_1					dio_set_level(DIO_PORTA, PIN_5, LOW)
#define COL_2				    dio_set_level(DIO_PORTA, PIN_6, LOW)
#define COL_3					dio_set_level(DIO_PORTA, PIN_7, LOW)
		
#define NO_PRESSED_KEY     0
	
#endif /* KEY_CONFIG_H_ */