/*
 * SPI_MASTER.c
 *
 * Created: 1/30/2020 10:40:21 PM
 * Author : Essam Mohamed
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>

void init_master_spi();
void master_transmit(char data);

int main(void)
{
    DDRC &= ~((1<<PC0) | (1<<PC3));
    PORTC |= (1<<PC0) | (1<<PC3);
    init_master_spi();
    while (1)
    {
	    if(bit_is_clear(PINC, 0)){
		    master_transmit('Y');
		    _delay_ms(300);
	    }
	    else if(bit_is_clear(PINC, 3)){
		    master_transmit('G');
		    _delay_ms(300);
	    }
    }
}

void init_master_spi(){
	SPCR |= (1<<MSTR) | (1<<SPE) | (1<<SPR0);
	DDRB |= (1<<PB5) |(1<<PB7);
}

void master_transmit( char data){
	SPDR = data;
	while(!(SPSR&(1<<SPIF)));
}

