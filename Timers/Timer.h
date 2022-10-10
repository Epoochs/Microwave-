/*
 * Timer.h
 *
 * Created: 08/10/2022 08:16:27 ص
 *  Author: DELL
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include <stdint.h>

void Timer0_voidInit(void);
void Timer0_deinit();
uint8_t timer_get_counter();




#endif /* TIMER_H_ */