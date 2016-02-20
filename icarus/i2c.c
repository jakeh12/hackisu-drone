#include "i2c.h"

void i2c_init(void)
{
  TWBR = 0x20;   // set up clk speed -> 100 kHz (with 8 MHz clock)
  TWSR &= ~(_BV(TWPS1) | _BV(TWPS0));
  PRR0 &= ~(_BV(PRTWI));
}

void i2c_start(void)
{
  TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN); // send START condition
  loop_until_bit_is_set(TWCR, TWINT); // wait until transmitted
}

void i2c_write(uint8_t data)
{
  TWDR = data; // load data into the write register
  TWCR = _BV(TWINT) | _BV(TWEN); // transmit
  loop_until_bit_is_set(TWCR, TWINT); // wait until transmitted
}

void i2c_call(uint8_t address, uint8_t RW) // W=0, R=1
{
  uint8_t data = (address << 1) | RW;
  i2c_write(data);
}

void i2c_repeat_start(void)
{
  TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);   // send START condition
  loop_until_bit_is_set(TWCR, TWINT); // wait until transmitted
}

uint8_t i2c_read_data_ack(void)
{
  TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA);
  loop_until_bit_is_set(TWCR, TWINT);
  return TWDR;
}

uint8_t i2c_read_data_nack(void)
{
  TWCR = _BV(TWINT) | _BV(TWEN);
  loop_until_bit_is_set(TWCR, TWINT);
  return TWDR;
}


void i2c_stop(void)
{
  TWCR = _BV(TWINT)|_BV(TWEN)|_BV(TWSTO); // send STOP condition
  loop_until_bit_is_clear(TWCR, TWSTO);   // wait until transmitted
}

uint8_t i2c_read_byte(uint8_t dev_address, uint8_t reg_address)
{
  i2c_start();
  i2c_call(dev_address, WRITE);
  i2c_write(reg_address);
  i2c_repeat_start();
  i2c_call(dev_address, READ);
  uint8_t data = i2c_read_data_nack();
  i2c_stop();
  return data;
}

void i2c_write_byte(uint8_t dev_address, uint8_t reg_address, uint8_t data)
{
  i2c_start();
  i2c_call(dev_address, WRITE);
  i2c_write(reg_address);
  i2c_write(data);
  i2c_stop();
}

uint16_t i2c_read_word(uint8_t dev_address, uint8_t reg_lsb_address)
{
  i2c_start();
  i2c_call(dev_address, WRITE);
  i2c_write(reg_lsb_address);
  i2c_repeat_start();
  i2c_call(dev_address, READ);
  uint8_t data_lsb = i2c_read_data_ack();
  uint8_t data_msb = i2c_read_data_nack();
  i2c_stop();
  return ((data_msb << 8) | data_lsb);
}

void i2c_write_word(uint8_t dev_address, uint8_t reg_lsb_address, uint16_t data)
{
  i2c_start();
  i2c_call(dev_address, WRITE);
  i2c_write(reg_lsb_address);
  i2c_write(data & 0x00FF);
  i2c_write(data >> 8);
  i2c_stop();
}

void i2c_read_block(uint8_t dev_address, uint8_t reg_address, uint8_t* received_data, uint8_t n)
{

  i2c_start();
  i2c_call(dev_address, WRITE);
  i2c_write(reg_address);
  i2c_repeat_start();
  i2c_call(dev_address, READ);

  uint8_t i;
  for (i = 0; i < (n-1); n++)
  {
    *(received_data + i) = i2c_read_data_ack();
  }

  *(received_data + (n - 1)) = i2c_read_data_nack();
  i2c_stop();
}

void i2c_write_block(uint8_t dev_address, uint8_t reg_address, uint8_t* data, uint8_t n)
{
  i2c_start();
  i2c_call(dev_address, WRITE);
  i2c_write(reg_address);

  uint8_t i;
  for (i = 0; i < n; n++) { i2c_write(*(data + i)); }
  i2c_stop();
}

uint8_t i2c_check_status(uint8_t expected_status)
{
  if (TW_STATUS == expected_status) { return 0; }
  return 1;
}
