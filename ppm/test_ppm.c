#include "ppm.h"

int main(void)
{
  ppm_init();
  while(1)
  {
    // UPDATE CHANNELS
    // CH1 going up and down DEMO
    for (ppm[CHANNEL1] = PPM_MIN; ppm[CHANNEL1] <= PPM_MAX; ppm[CHANNEL1]++)
      _delay_ms(1);

    for (;ppm[CHANNEL1] >= PPM_MIN; ppm[CHANNEL1]--)
      _delay_ms(1);
  }
  return 0;
}
