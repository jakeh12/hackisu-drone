#include "ppm.h"

volatile uint16_t ppm[18] = {       PPM_GAP, // gap 0
                                    PPM_CTR, // CH1 1
                                    PPM_GAP, // gap 2
                                    PPM_CTR, // CH2 3
                                    PPM_GAP, // gap 4
                                    PPM_CTR, // CH3 5
                                    PPM_GAP, // gap 6
                                    PPM_CTR, // CH4 7
                                    PPM_GAP, // gap 8
                                    PPM_CTR, // CH5 9
                                    PPM_GAP, // gap 10
                                    PPM_CTR, // CH6 11
                                    PPM_GAP, // gap 12
                                    PPM_CTR, // CH7 13
                                    PPM_GAP, // gap 14
                                    PPM_CTR, // CH8 15
                                    PPM_GAP, // gap 16
                                    PPM_FIL  // FILLER 17
                                  };

// index for accessing the frame
uint8_t i_ppm = 0;

/*
* TIMER1 interrupt function
*/
ISR (TIMER1_COMPA_vect)
{
  // disable global interrupts
  cli();
  // positive on data part of frame, zero on gaps
  if (i_ppm % 2 == 0)
    PORTC &= ~(_BV(PORTC7));
  else
    PORTC |= _BV(PORTC7);
  // recalculate PPM_PST so the frame is exactly 22 ms (22 ms - (0.4ms)(9 gaps) = 18.4 ms)
  if (i_ppm == 17)
    ppm[17] = 18400 - (ppm[1] + ppm[3] + ppm[5] + ppm[7] + ppm[9] + ppm[11] + ppm[13] + ppm[15]);
  // set new timer interval
  OCR1A = ppm[i_ppm];
  // update index and roll over if 18
  i_ppm = ((i_ppm + 1) % 18);
  // enable global interrupts
  sei();
}

/*
* TIMER1 initialization function
*/
void ppm_init(void)
{
  // set PORTC7 as output
  DDRC = (DDRC & 0x00) | _BV(PORTC7);

  // disable global interrupt
  cli();
  // setup timer1 with prescale 8 and ctc mode
  TCCR1B |= _BV(WGM12) | _BV(CS11);
  // enable timer compare interrupt
  TIMSK1 |= _BV(OCIE1A);
  // initialize compare value (= 22 ms)
  OCR1A = 22000;
  // disable usb interrupt otherwise timer1 interupt does not work
  USBCON = 0;
  // enable global interrupt
  sei();
}

void ppm_send(uint8_t ppm_channel, uint16_t usecs)
{
  if (usecs > 1500)
    ppm[ppm_channel] = 1500;
  else if (usecs < 700)
    ppm[ppm_channel] = 700;
  else
    ppm[ppm_channel] = usecs;
}

uint16_t ppm_read(uint8_t ppm_channel)
{
  return ppm[ppm_channel];
}
