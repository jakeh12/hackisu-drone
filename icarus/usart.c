#include "usart.h"

void usart_init(void)
{
  UBRR1H = UBRRH_VALUE;
  UBRR1L = UBRRL_VALUE;
  #if USE_2X
  UCSR1A |= _BV(U2X1);
  #else
  UCSR1A &= ~(_BV(U2X1));
  #endif

  UCSR1B = _BV(RXEN1) | _BV(TXEN1);

  // frame format 8 bit data + 2 stop bits
  UCSR1C = _BV(USBS1) | _BV(UCSZ11) | _BV(UCSZ10);
}

void usart_transmit(uint8_t data)
{
  loop_until_bit_is_set(UCSR1A, UDRE1);
  UDR1 = data;
}

uint8_t usart_receive(void)
{
  loop_until_bit_is_set(UCSR1A, RXC1);
  return UDR1;
}

void usart_send_string(char* string)
{
  int i;
  for (i = 0; (*string != 0) && (i < 65535); i++)
  {
    usart_transmit(*string);
    string++;
  }
}
