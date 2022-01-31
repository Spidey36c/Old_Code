/*
 * FinalLab.c
 *
 * Created: 5/30/2019 2:25:15 PM
 * Author : james.nordquist
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "uartDriver.h"


void playNote(uint16_t adval); 

static volatile uint16_t tonelen = 200;
static volatile uint8_t toneDone = 0; //flag to tell if the tone is done
static volatile uint16_t duration = 0; //duration of the tone

	
int main(void)
{
	uint16_t adval = 0;
	
	FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
	FILE uart_input = FDEV_SETUP_STREAM(NULL,uart_getchar,_FDEV_SETUP_READ);
	
	uart_init(); //initialize uart
	
	stdout = &uart_output;
	stdin = &uart_input;
	
	DDRD = (1 << DDD2);
	TIMSK0 = (1 << OCIE0A);
	sei();
	
    ADMUX = (0 << MUX0) | (1 << REFS0);
	ADCSRA = (1 << ADEN) | (7 << ADPS0) | (1 << ADATE) | (1 << ADSC);
    while (1) 
    {
		while(!(ADCSRA & (1 << ADIF)));
		ADCSRA |= (1 << ADIF);
		adval = ADC;
		printf("Data read is %u\n",adval);
		toneDone = 0;
		TCCR0A = (2 << WGM00); //timer0 to CTC
		TCCR0B = (4 << CS00); //timer0 prescaler 256 and turn it 0
		TCNT0 = 0; //clear timer
		playNote(adval);
		_delay_ms(1000);
    }
}

void playNote(uint16_t adval)
{	
	OCR0A = (adval >> 2); //set period of interrupt
		
	//determine number of interrupts
	duration = (uint32_t)tonelen * 1000/(16*(adval >> 2));
	
	toneDone = 0; //clear the done flag
	TCNT0 = 0; //clear timer0
	TCCR0B = (4 << CS00);
	while(!toneDone); //wait for the tone to finish
}

ISR(TIMER0_COMPA_vect)
{
	PIND = (1 << PIND2); //toggle pin on
	duration--;
	if(duration == 0)
	{
		toneDone = 1; //set flag
		TCCR0B = 0; //turn off timer
	}
}