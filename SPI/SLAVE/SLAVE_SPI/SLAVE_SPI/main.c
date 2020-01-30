/*
 * SLAVE_SPI.c
 *
 * Created: 1/30/2020 11:00:19 PM
 * Author : Essam Mohamed
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void init_slave_spi();
char receive_spi();


int main(void)
{
	DDRC |= (1<<PC0) | (1<<PC5);
	init_slave_spi();
	char received;
	while (1)
	{
		received = receive_spi();
		if(received == 'Y'){
			PORTC |= (1<<PC0);
			PORTC &= ~(1<<PC5);
		}
		else if(received == 'G'){
			PORTC |= (1<<PC5);
			PORTC &= ~(1<<PC0);
		}
	}
	return 0;
}


void init_slave_spi(){
	SPCR |= (1<<SPE);
	DDRB |= (1<<PB6);
}
char receive_spi(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

