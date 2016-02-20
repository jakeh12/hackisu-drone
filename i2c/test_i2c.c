#include "i2c.h"

debug

int main()
{
  i2c_init();
  uint8_t received = i2c_read_byte(0x28, 0x00);
  
  return 0;
}
