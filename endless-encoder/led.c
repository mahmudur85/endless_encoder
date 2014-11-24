/*
 * led.c
 *
 * Created: 11/3/2014 11:46:13 AM
 *  Author: new
 */ 
#include "led.h"

void initLED(void){
	LED_DDR |= _BV(LED);
	LED_OFF;
}
