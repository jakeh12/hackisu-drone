#include "usart.h"

int remap(int value, int from_low, int from_high, int to_low, int to_high)
{
  return to_low + (value - from_low) * (to_high - to_low) / (from_high - from_low);
}

int main(void)
{
  usart_init();
  while(1)
  {
  usart_transmit_string("Hello\n\n");
  }
  return 0;
}
