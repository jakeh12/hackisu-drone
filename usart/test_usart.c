#include "usart.h"

int main(void)
{
  usart_init();
  while(1)
  {
  usart_transmit_string("Hello\n\n");
  }
  return 0;
}
