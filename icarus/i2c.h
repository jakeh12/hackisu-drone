#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define WRITE 0
#define READ 1

void i2c_init(void);
void i2c_start(void);
void i2c_write(uint8_t data);
void i2c_call(uint8_t address, uint8_t RW);
void i2c_repeat_start(void);
uint8_t i2c_read_data_ack(void);
uint8_t i2c_read_data_nack(void);
void i2c_stop(void);
uint8_t i2c_read_byte(uint8_t dev_address, uint8_t reg_address);
void i2c_write_byte(uint8_t dev_address, uint8_t reg_address, uint8_t data);
uint16_t i2c_read_word(uint8_t dev_address, uint8_t reg_lsb_address);
void i2c_write_word(uint8_t dev_address, uint8_t reg_lsb_address, uint16_t data);
void i2c_read_block(uint8_t dev_address, uint8_t reg_address, uint8_t* received_data, uint8_t n);
void i2c_write_block(uint8_t dev_address, uint8_t reg_address, uint8_t* data, uint8_t n);
uint8_t i2c_check_status(uint8_t expected_status);
