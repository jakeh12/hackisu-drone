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

uint8_t imu_status(IMU_t* imu)
{
  imu_select_page(imu->dev_addr, PAGE_ZERO);
  return i2c_read_byte(imu->dev_addr, BNO055_SYS_STAT_ADDR);
}


void imu_reset(uint8_t dev_addr)
{
  imu_select_mode(dev_addr, OPERATION_MODE_CONFIG);
  i2c_write_byte(dev_addr, BNO055_SYS_TRIGGER_ADDR, RST_SYS);
  _delay_ms(1000);
  imu_loop_until_ping(dev_addr);
  i2c_write_byte(dev_addr, BNO055_PWR_MODE_ADDR, POWER_MODE_NORMAL);
}


void imu_init(IMU_t* imu, uint8_t mode) // dont forget to i2c_init()!!!!
{
  imu_loop_until_ping(imu->dev_addr);
  imu_reset(imu->dev_addr);
  imu_select_page(imu->dev_addr, PAGE_ZERO);
  i2c_write_byte(imu->dev_addr, BNO055_SYS_TRIGGER_ADDR, SELF_TEST);
  imu_select_mode(imu->dev_addr, mode);
}

void imu_update(IMU_t* imu)
{
  imu->eul.x = (int) i2c_read_word(imu->dev_addr, 0x1E);
  imu->eul.y = (int) i2c_read_word(imu->dev_addr, 0x1C);
  imu->eul.z = (int) i2c_read_word(imu->dev_addr, 0x1A);

  imu->lia.x = (int) i2c_read_word(imu->dev_addr, 0x28);
  imu->lia.y = (int) i2c_read_word(imu->dev_addr, 0x2A);
  imu->lia.z = (int) i2c_read_word(imu->dev_addr, 0x2C);

  imu->qua.w = (int) i2c_read_word(imu->dev_addr, 0x20);
  imu->qua.x = (int) i2c_read_word(imu->dev_addr, 0x22);
  imu->qua.y = (int) i2c_read_word(imu->dev_addr, 0x24);
  imu->qua.z = (int) i2c_read_word(imu->dev_addr, 0x26);

  imu->gyr.x = (int) i2c_read_word(imu->dev_addr, 0x14);
  imu->gyr.y = (int) i2c_read_word(imu->dev_addr, 0x16);
  imu->gyr.z = (int) i2c_read_word(imu->dev_addr, 0x18);

}

void imu_assign_address(IMU_t* imu, uint8_t dev_addr)
{
  imu->dev_addr = dev_addr;
}
