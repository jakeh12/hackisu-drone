#include "imu.h"
#include "ppm.h"
#include "usart.h"

int remap(int value, int from_low, int from_high, int to_low, int to_high)
{

  return (int)(to_low + ((((long)value-(long)from_low)*((long)to_high-(long)to_low))/((long)from_high-(long)from_low)));
}

int treshold(int value, int min, int max)
{
  if (value > min && value < max) { return 1100-1; }
  return value;
}

int main()
{
  // wait for stuff to boot up
  _delay_ms(1000);


  // initialize everything
  usart_init();
  i2c_init();
  ppm_init();

  // set up imus
  usart_send_string("Initializing IMUs...\n");

  IMU_t imu_r_s;
  IMU_t* imu_r = &imu_r_s;

  IMU_t imu_l_s;
  IMU_t* imu_l = &imu_l_s;

  imu_assign_address(imu_r, 0x29);
  imu_assign_address(imu_l, 0x28);

  imu_init(imu_r, OPERATION_MODE_IMUPLUS);
  imu_init(imu_l, OPERATION_MODE_IMUPLUS);

  usart_send_string("IMUs initialized!\n");

  int ch1;
  int ch2;
  int ch3;
  int ch4;

  while(1)
  {
    imu_update(imu_r);
    imu_update(imu_l);

    ch1 = remap(imu_l->eul.y, -1100, 0, 700, 1500);
    ppm_send(CHANNEL1, ch1);

    ch2 = remap(-imu_r->eul.y, -720, 720, 700+150, 1500-150);
    ppm_send(CHANNEL2, ch2);

    ch3 = remap(-imu_r->eul.x, -720, 720, 700+150, 1500-150);
    ppm_send(CHANNEL3, ch3);

    ch4 = remap(-imu_l->eul.x, -720, 720, 700+300, 1500-300);
    ppm_send(CHANNEL4, ch4);

    _delay_ms(10);
  }

  return 0;
}
