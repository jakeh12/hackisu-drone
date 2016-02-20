#include "imu.h"

int main()
{
  _delay_ms(1000);

  usart_init();
  i2c_init();

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

  char debugr[100];
  char debugl[100];


  while(1)
  {
    imu_update(imu_r);
    imu_update(imu_l);

    sprintf(debugr, "\033[2J\033[;HR: PITCH: %06d\tROLL: %06d\tYAW: %06d\n\r", imu_r->eul.x/16, imu_r->eul.y/16, imu_r->eul.z/16);
    sprintf(debugl, "L: PITCH: %06d\tROLL: %06d\tYAW: %06d", imu_l->eul.x/16, imu_l->eul.y/16, imu_l->eul.z/16);

    usart_send_string(debugr);
    usart_send_string(debugl);

    _delay_ms(1);


  }

  return 0;
}
