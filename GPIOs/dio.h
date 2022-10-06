/*
 *  dio.h
 *
 */
#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <stdint.h>

typedef enum
{
    DIO_PORTA = 0,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD
} dio_t;

typedef enum
{
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7
} dio_pin_t;

typedef enum
{
    DIO_DIRECTION_INPUT = 0,
    DIO_DIRECTION_OUTPUT = 1,
} dio_direction_t;

typedef enum
{
    LOW = 0,
    HIGH = 1,
} dio_level_t;

void dio_set_direction(dio_t port, dio_pin_t pin, dio_direction_t direction);
void dio_set_level(dio_t port, dio_pin_t pin, dio_level_t value);
dio_level_t dio_get_level(dio_t port, dio_pin_t pin);
void set_all_direction(dio_t port, dio_direction_t direction);
void set_all_port_value(dio_t port, uint8_t value);

#endif /*MCAL_DIO_DIO_H_*/