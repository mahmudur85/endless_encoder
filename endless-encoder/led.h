/*
 * led.h
 *
 * Created: 11/3/2014 11:45:37 AM
 *  Author: new
 */ 


#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

//LED Pin
#define LED_DDR		DDRB
#define LED_PORT	PORTB
#define LED			PB7

// LED Operation
#define LED_ON		LED_PORT |=  _BV(LED)
#define LED_OFF		LED_PORT &= ~_BV(LED)
#define LED_TOGGLE	LED_PORT ^= _BV(LED)

void initLED(void);

#endif /* LED_H_ */