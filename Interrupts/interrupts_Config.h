/*
 * interrupts_Config.h
 *
 * Created: 23/08/2022 12:33:24 PM
 *  Author: A.Sherif
 */ 


#ifndef INTERRUPTS_CONFIG_H_
#define INTERRUPTS_CONFIG_H_

typedef enum
{
	int0 = 0,
	int1,
	int2
} external_int_t;

typedef enum
{
	_LOW_LEVEL = 0,
	_FALLING_EDGE = 1,
	_RISING_EDGE = 2,
	_BOTH_CHANGE = 3
} sense_control_t;



#endif /* INTERRUPTS_CONFIG_H_ */