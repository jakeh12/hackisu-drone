#include "imu.h"
#include "ppm.h"
//#include "usart.h"
#include "exp_table.h"

int remap_exp(value)
{
  int index = value + 720;
  if (index < 0) { index = 0; }
  if (index > 1440) {index = 1440; }
  int result = 1100;
  result = exp_table[index];
  result = (int) &(exp_table[index]);
  result = pgm_read_word(&(exp_table[index]));
  return result;
}


int remap(int value)
{
  if (value < -720) { return 700; }
  if (value > 720) { return 1500; }
  return (int)(0.5555555555*value+1100);
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
  //usart_send_string("Initializing IMUs...\n");

  IMU_t imu_r_s;
  IMU_t* imu_r = &imu_r_s;

  IMU_t imu_l_s;
  IMU_t* imu_l = &imu_l_s;

  imu_assign_address(imu_r, 0x29);
  imu_assign_address(imu_l, 0x28);

  imu_init(imu_r, OPERATION_MODE_IMUPLUS);
  imu_init(imu_l, OPERATION_MODE_IMUPLUS);

  //usart_send_string("IMUs initialized!\n");

  int ch1;
  int ch2;
  int ch3;
  int ch4;

  while(1)
  {
    imu_update(imu_r);
    imu_update(imu_l);

    ch1 = remap_exp(imu_l->eul.x);
    ppm_send(CHANNEL1, ch1);

    ch2 = remap_exp(-imu_r->eul.y);
    ppm_send(CHANNEL2, ch2);

    ch3 = remap_exp(-imu_r->eul.x);
    ppm_send(CHANNEL3, ch3);

    ch4 = remap_exp(-imu_l->eul.y);
    ppm_send(CHANNEL4, ch4);

    _delay_ms(10);
  }

  return 0;
}
