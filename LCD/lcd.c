#include <stdio.h>
#include "D:\course embedded system\projects\dio.h"
# define F_CPU 8000000UL
#include <avr\delay.h>
#include <avr\io.h>
#include <stdint.h>
# define F_CPU 8000000UL

void lcd_init(void)
{
	_delay_ms(30);
	
    set_all_direction(DIO_PORTD, DIO_DIRECTION_OUTPUT);
	dio_set_direction(DIO_PORTC, PIN_0, DIO_DIRECTION_OUTPUT);
	dio_set_direction(DIO_PORTC, PIN_1, DIO_DIRECTION_OUTPUT);
	
	/*lcd_send_Cmd(0x38); 
	_delay_ms(2);
	lcd_send_Cmd(0x0C);
	_delay_ms(2);
	lcd_send_Cmd(0x01);*/
	
	lcd_send_Cmd(0b00111000);
	lcd_send_Cmd(0b00000001);
	_delay_ms(2);
	lcd_send_Cmd(0b00000110);
	lcd_send_Cmd(0b00001100);
}

void lcd_send_Cmd(unsigned char command)
{	
    dio_set_level(DIO_PORTC, PIN_0, LOW);
	set_all_port_value(DIO_PORTD, command);

    dio_set_level(DIO_PORTC, PIN_1, HIGH);
    _delay_us(500);
    dio_set_level(DIO_PORTC, PIN_1, LOW);
}

void lcd_send_Data(char data)
{	
    dio_set_level(DIO_PORTC, PIN_0, HIGH);
	set_all_port_value(DIO_PORTD, data);
	
    dio_set_level(DIO_PORTC, PIN_1, HIGH);
    _delay_us(500);
    dio_set_level(DIO_PORTC, PIN_1, LOW);
}

void set_cursor(uint8_t x, uint8_t y)
{
    uint8_t set[] = {0x80, 0xc0};
    lcd_send_Cmd(set[y - 1] + x - 1);
    _delay_ms(1);
}

void send_string(char arr[])
{
	uint8_t i = 0;
	
	while(arr[i] != '\0')
	{
		if (i == 16)
		{
			set_cursor(1,2);
			//lcd_send_Data(arr[i]);
		}
		lcd_send_Data(arr[i]);
		i++;
	}
}

void lcd_shift_display()
{
	
}