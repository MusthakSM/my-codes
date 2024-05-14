#include <avr/io.h>

int main(void)
{
  DDRD |= (1<<PD6); // enabling OC0A output of Timer/Counter 0

  TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // Set Timer/Counter 0 for Fast PWM mode

  TCCR0B |= (1 << CS01) | (1 << CS00); // Set Timer/Counter 0 with a prescaler of 64

  OCR0A = 20; // updating the required value in Ouput compare register of timer/counter 0 for the 50% duty cycle..

  while(1);

  return 0;
}