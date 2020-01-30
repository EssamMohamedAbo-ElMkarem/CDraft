/*
 * ADC.c
 *
 * Created: 1/30/2020 2:55:09 PM
 * Author : Essam Mohamed
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>


int main(void)
{
	volatile uint8_t converted_data = 0;
	DDRA = 0x00;
	DDRC = 0xff;
	ADCSRA |= (3<<ADPS0);
	ADCSRA |= (1<<ADEN);
	ADMUX |= (1<<MUX0);
	ADMUX |= (1<<ADLAR);
    while (1) 
    {
		ADCSRA |= (1<<ADSC);
		while(ADCSRA & (1<<ADSC));
		converted_data = ADCH;
		PORTC = converted_data;
    }
}

