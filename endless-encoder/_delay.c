/*
 * delay.c
 *
 * Created: 11/3/2014 11:41:58 AM
 *  Author: new
 */ 
#include "_delay.h"

// delay for a minimum of <ms>
void delay_ms(uint16_t ms){
	while(ms){
		_delay_ms(0.96);
		ms--;
	}
}

//delay for a minimum of <us>
void delay_us(uint16_t us){
	while(us){
		_delay_us(0.96);
		us--;
	}
}