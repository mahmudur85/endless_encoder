/*
 * HelloWorld.c
 *
 * Created: 11/18/2014 12:28:03 PM
 *  Author: Mahmudur
 */ 


#include <avr/io.h>

/* define CPU frequency in Mhz here if not defined in Makefile */
#ifndef F_CPU
	#define F_CPU 16000000UL
#endif
#include <avr/interrupt.h>

#define sbi(address,bit)	address |= (1<<bit)
#define cbi(address,bit)	address &=~(1<<bit)
#define toggle(address,bit) address ^= (1<<bit)

#include "_delay.h"
#include "led.h"
#include "debug.h"

#define ENCODER_DDR		DDRD
#define ENCODER_PORT	PORTD
#define ENCODER_PIN		PIND
#define ENCODER_CLK		PIND0		// arduino digitalpin 21
#define ENCODER_DT		PIND1		// arduino digitalpin 20
#define CLK				PD0
#define DT				PD1

volatile uint8_t direction = 0;
volatile uint8_t position_count_flag = 0;
volatile uint8_t turn_done = 0;

ISR(ISR_DEBUG)
{
	uint8_t rec_char = UDR0;
	if(rec_char != 0x0d || rec_char != 0x0a || rec_char != 0xff)
	{
		if(rec_char == 'r')
		{
			position_count_flag = 1;
		}
	}
}

ISR(INT0_vect)
{
	if(ENCODER_PIN & _BV(ENCODER_DT))
	{
		direction = 0;
	}
	else
	{
		direction = 1;
	}
	turn_done = 1;
	LED_TOGGLE;
}


int main(void)
{
	uint32_t position_count = 0;
	direction = 0;
	position_count = 0;
	turn_done = 0;
	initLED();
	
	ENCODER_DDR &= ~_BV(CLK);
	ENCODER_DDR &= ~_BV(DT);
	
	cli();
	
	debug_init(DEBUG_BAUDRATE,1);
	
	EIMSK |= _BV(INT0);
	EICRA |= _BV(ISC01);
	
	sei();
	printf("Start\n");
    while(1)
    {
		if(position_count_flag == 1)
		{
			position_count_flag = 0;
			position_count = 0;
			printf("Reset: %lu\n",position_count);
		}
		
		if(turn_done == 1)
		{
			if(direction==1)
			{
				position_count++;
			}
			else
			{
				position_count--;
			}
			turn_done = 0;
			printf("Count: %lu\n",position_count);
		}
    }
}