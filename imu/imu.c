#include "imu.h"

void imu_loop_until_ping(uint8_t dev_addr)
{
  uint8_t i;
  for(i = 0; (i < 100) && (i2c_read_byte(dev_addr, BNO055_CHIP_ID_ADDR) != CHIP_ID); i++) { _delay_ms(10); }
}

void imu_select_page(uint8_t dev_addr, uint8_t page_num)
{
  i2c_write_byte(dev_addr, BNO055_PAGE_ID_ADDR, page_num);
}

void imu_select_mode(uint8_t dev_addr, uint8_t mode)
{
  imu_select_page(dev_addr, PAGE_ZERO);
  i2c_write_byte(dev_addr, BNO055_OPR_MODE_ADDR, mode);
  _delay_ms(20);
}

uint8_t imu_status(uint8_t dev_addr)
{
  imu_select_page(dev_addr, PAGE_ZERO);
  return i2c_read_byte(dev_addr, BNO055_SYS_STAT_ADDR);
}

void imu_reset(uint8_t dev_addr)
{
  imu_select_mode(dev_addr, OPERATION_MODE_CONFIG);
  i2c_write_byte(dev_addr, BNO055_SYS_TRIGGER_ADDR, _BV(RST_SYS));
  imu_loop_until_ping(dev_addr);
  i2c_write_byte(dev_addr, BNO055_PWR_MODE_ADDR, POWER_MODE_NORMAL);
}

void imu_init(uint8_t dev_addr, uint8_t mode) // dont forget to i2c_init()!!!!
{
  imu_loop_until_ping(dev_addr);
  imu_reset(dev_addr);
  imu_select_page(dev_addr, PAGE_ZERO);
  i2c_write_byte(dev_addr, BNO055_SYS_TRIGGER_ADDR, SELF_TEST);
  imu_select_mode(dev_addr, mode);
}

int imu_read_value(uint8_t dev_addr, uint8_t reg_addr)
{
  return (int) i2c_read_word(dev_addr, reg_addr);
}

int main()
{
  _delay_ms(1000);

  usart_init();
  i2c_init();
  usart_send_string("Initializing IMU...\n");
  imu_init(0x29, OPERATION_MODE_IMUPLUS);
  usart_send_string("IMU initialized!\n");
  int valuex = 0;
  int valuey = 0;
  int valuez = 0;

  char debug[100];

  while(1)
  {
    valuex = imu_read_value(0x29, 0x1E);
    valuey = imu_read_value(0x29, 0x1C);
    valuez = imu_read_value(0x29, 0x1A);

    sprintf(debug, "X: %d\tY: %d\tZ: %d\n", valuex, valuey, valuez);
    usart_send_string(debug);
    _delay_ms(100);


  }
  return 0;
}
