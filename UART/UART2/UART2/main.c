/*
 * UART2.c
 *
 * Created: 1/26/2020 2:00:01 PM
 * Author : Essam Mohamed
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART_config.h"


int main(void)
{
	DDRC |= (1<<PC0) | (1<<PC5);
	
    uart_init(9600);
	char received;
    while (1) 
    {
		received = uart_receive_char();
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

