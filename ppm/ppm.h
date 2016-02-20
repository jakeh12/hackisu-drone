#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>

#define PPM_GAP 400-1 // 0.4 ms
#define PPM_FIL 9600-1 // 9.6 ms

#define PPM_MAX 1500-1 // 1.5 ms
#define PPM_CTR 1100-1 // 1.1 ms
#define PPM_MIN 700-1 // 0.7 ms

#define CHANNEL1 1
#define CHANNEL2 3
#define CHANNEL3 5
#define CHANNEL4 7
#define CHANNEL5 9
#define CHANNEL6 11
#define CHANNEL7 13
#define CHANNEL8 15

extern volatile uint16_t ppm[18];

ISR (TIMER1_COMPA_vect);
void ppm_init(void);
void ppm_send(uint8_t ppm_channel, uint16_t usecs);
uint16_t ppm_read(uint8_t ppm_channel);
