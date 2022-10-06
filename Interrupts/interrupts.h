/*
 * interrupts.h
 *
 * Created: 23/08/2022 12:33:05 م
 *  Author: Ahmed Sherif
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "interrupts_Config.h"


void external_int_enable(external_int_t interrupt, sense_control_t event);


#endif /* INTERRUPTS_H_ */