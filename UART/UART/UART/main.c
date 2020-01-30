/*
 * UART.c
 *
 * Created: 1/26/2020 12:20:03 PM
 * Author : Essam Mohamed
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include "uart_config.h"
int main(void)
{
    //UART initialization
	uart_init(9600);
	DDRC &= ~((1<<PC0) | (1<<PC3));
	PORTC |= (1<<PC0) | (1<<PC3);
	
    while (1) 
    {
		if(bit_is_clear(PINC, 0)){
			uart_send_char('Y');
			_delay_ms(300);
		}
		else if(bit_is_clear(PINC, 3)){
			uart_send_char('G');
			_delay_ms(300);
		}
    }
	return 0;
}

