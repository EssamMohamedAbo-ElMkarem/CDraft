/*
 * sevensegment.c
 *
 * Created: 1/18/2020 8:57:02 AM
 * Author : Essam Mohamed
 */ 
#define  F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>

//function declarations
void display_one(unsigned char array[], unsigned char size, unsigned char port_activator);
void display_both(unsigned char arr1[], unsigned char arr2[], unsigned char size);

int main(void)
{
    DDRA = 0b01111111;
	DDRB = 0b01111111;
	DDRC = 0b00000000;
	PORTC = 0b00000011;  //internal pull-up resistors enabled for PC0 and PC1
	unsigned char numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //numbers array in hex for 7seg
	unsigned char letters[10] = {0x79, 0x6D, 0x6D, 0x77, 0x37, 0x40, 0x66, 0x4F, 0x5B, 0x3F}; //letters array in hex for 7seg
		
    while (1) 
    {

		if(PINC == 0b00000010){display_one(numbers, 10, 0);}
		else if(PINC == 0b00000001){display_one(letters, 10, 1);}
		else if(PINC == 0b00000000){display_both(numbers, letters, 10);}
		else{PORTA = 0x76; PORTB = 0x76;}
		
    }
}

//function used to display array content on a chosen 7seg using port_activator flag
void display_one(unsigned char array[], unsigned char size, unsigned char port_activator)
{
	if(port_activator == 0){
		for(int i = 0; i < size; i++)
		{
			PORTA = array[i];
			_delay_ms(500);
		}
	}
	else{
		for(int i = 0; i < size; i++)
		{
			PORTB = array[i];
			_delay_ms(500);
		}
	}
}

//function used to display content of 2 arrays on both 7segs
void display_both(unsigned char arr1[], unsigned char arr2[], unsigned char size)
{
	for(int i = 0; i < size; i++)
	{
		PORTA = arr1[i];
		PORTB = arr2[i];
		_delay_ms(500);
	}
}

