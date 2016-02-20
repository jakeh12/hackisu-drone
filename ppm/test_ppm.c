#include "ppm.h"

int main(void)
{
  ppm_init();
  while(1)
  {
    // UPDATE CHANNELS
    // CH1 going up and down DEMO
    for (ppm[CHANNEL1] = 910; ppm[CHANNEL1] <= 1050; ppm[CHANNEL1]++)
      _delay_ms(6);

    for (;ppm[CHANNEL1] >= 910; ppm[CHANNEL1]--)
      _delay_ms(6);
  }
  return 0;
}
