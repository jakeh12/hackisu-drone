#define F_CPU 8000000UL
#define BAUD 9600

#include <avr/io.h>
#include <util/setbaud.h>
#include <stdint.h>

void usart_init(void);
void usart_transmit(uint8_t data);
uint8_t usart_receive(void);
void usart_send_string(char* string);
