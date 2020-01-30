/*
 * uart_config.h
 *
 * Created: 1/26/2020 1:19:16 PM
 *  Author: Essam Mohamed
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

void uart_init(uint16_t baud_rate){
	uint16_t UBRR_VALUE = 103;//lrint((16000000/16L*baud_rate) - 1);
	UBRRL = (uint8_t) UBRR_VALUE;
	UBRRH = (uint8_t) (UBRR_VALUE >> 8);
	UCSRB = (1<<RXEN) | (1<<TXEN); 
	UCSRC |= (3 << UCSZ0); //only 8-bit data sent or received
}

void uart_send_char(char data){
	while(!(UCSRA & (1 << UDRE)));
		UDR = data;
}

void uart_send_string(char* string){
	while(*string > 0)
		uart_send_char(*string++);
	uart_send_char('\0');
}

char uart_receive_char(){
	while(!(UCSRA & (1 << RXC)));
		return UDR;
}


#endif /* UART_CONFIG_H_ */