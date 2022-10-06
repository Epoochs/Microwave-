/*
 * DC_CONFIG_H_
 *
 * Created: 21/08/2022 01:04:21 م
 *  Author: DELL
 */ 


#ifndef DC_CONFIG_H_
#define DC_CONFIG_H_
#include "dio.h"


#define MOTOR_PORTING {{DIO_PORTC,PIN_3}, {DIO_PORTC,PIN_4}}

typedef enum
{
	_STOP_ = 0,
	SET_LEFT,
	SET_RIGHT
}directon_t;



#endif /* DC_CONFIG_H_ */