/*
 * Timer_Config.h
 *
 * Created: 08/10/2022 08:15:59 ص
 *  Author: DELL
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

typedef enum
{
	_NORMAL_ = 0,
	_PWM_,
	_CTC_,
	_FAST_PWM 	
} wave_generation_t;

typedef enum
{
	NO_CLK = 0,
	NO_PRESCALER,
	CLK_8,
	CLK_64,
	CLK_256,
	CLK_1024,
	Ex_CLK_F,
	Ex_CLK_R
} clock_select_t;




#endif /* TIMER_CONFIG_H_ */