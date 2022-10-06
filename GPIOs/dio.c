#include <stdio.h>
#include "D:\course embedded system\projects\dio.h"
#include <avr\delay.h>
#include <avr\io.h>
#include <stdint.h>

void dio_set_direction(dio_t port, dio_pin_t pin, dio_direction_t direction)
{
	switch (port)
	{
	case DIO_PORTA:
		DDRA &= ~(0X01 << pin);
		DDRA |= direction << pin;
		break;
	case DIO_PORTB:
		DDRB &= ~(0X01 << pin);
		DDRB |= direction << pin;
		break;

	case DIO_PORTC:
		DDRC &= ~(0X01 << pin);
		DDRC |= direction << pin;
		break;

	case DIO_PORTD:
		DDRD &= ~(0X01 << pin);
		DDRD |= direction << pin;
		break;

	default:
		break;
	}
}

void dio_set_level(dio_t port, dio_pin_t pin, dio_level_t value)
{
	switch (port)
	{
	case DIO_PORTA:
		PORTA &= ~(0x01 << pin);
		PORTA |= value << pin;
		break;

	case DIO_PORTB:
		PORTB &= ~(0x01 << pin);
		PORTB |= value << pin;
		break;
	case DIO_PORTC:
		PORTC &= ~(0x01 << pin);
		PORTC |= value << pin;
		break;
	case DIO_PORTD:
		PORTD &= ~(0x01 << pin);
		PORTD |= value << pin;
		break;
	default:
		break;
	}
}

dio_level_t dio_get_level(dio_t port, dio_pin_t pin)
{
	switch (port)
	{
	case DIO_PORTA:
		return 0b01 & (PINA >> pin);
		break;

	case DIO_PORTB:
		return 0b01 & (PINB >> pin);
		break;

	case DIO_PORTC:
		return 0b01 & (PINC >> pin);
		break;

	case DIO_PORTD:
		return 0b01 & (PIND >> pin);
		break;

	default:
		break;
	}
}

void set_all_direction(dio_t port, dio_direction_t direction)
{
	if (direction == DIO_DIRECTION_OUTPUT)
	{
		switch (port)
		{
		case DIO_PORTA:
			DDRA = 0xFF;
			break;
		case DIO_PORTB:
			DDRB = 0XFF;
			break;

		case DIO_PORTC:
			DDRC = 0xFF;
			break;

		case DIO_PORTD:
			DDRD = 0XFF;
			break;

		default:
			break;
		}
	}
	else
	{
		switch (port)
		{
		case DIO_PORTA:
			DDRA = 0x00;
			break;
		case DIO_PORTB:
			DDRB = 0x00;
			break;

		case DIO_PORTC:
			DDRC = 0x00;
			break;

		case DIO_PORTD:
			DDRD = 0x00;
			break;

		default:
			break;
		}
	}
}

void set_all_port_value(dio_t port, uint8_t value)
{
	switch (port)
	{
	case DIO_PORTA:
		PORTA = value;
		break;

	case DIO_PORTB:
		PORTB = value;
		break;

	case DIO_PORTC:
		PORTC = value;
		break;

	case DIO_PORTD:
		PORTD = value;
		break;

	default:
		break;
	}
}
