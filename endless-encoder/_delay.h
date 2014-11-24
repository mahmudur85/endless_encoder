/*
 * delay.h
 *
 * Created: 11/3/2014 11:41:37 AM
 *  Author: new
 */ 


#ifndef _DELAY_H_
#define _DELAY_H_

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif
#include <util/delay.h>

void delay_ms(uint16_t ms);
void delay_us(uint16_t us);

#endif /* DELAY_H_ */