#ifndef _LCD_DIO_H
#define _LCD_DIO_H

#include <stdint.h>

void lcd_init(void);
void lcd_send_Cmd(unsigned char command);
void lcd_send_Data(uint8_t data);
void set_cursor(uint8_t x, uint8_t y);
void send_string(char arr[]);
void lcd_shift_display();

#endif /* LCD_DIO_H */