/* Blinking 4 LEDs simultaneously*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // defining outputs..
    DDRB |= (1<<PB5) | (1<<PB4) | (1<<PB3) | (1<<PB2) ;

    // lit up at the start...
    PORTB |= 0x00111100;
    while(1)
    {
        PORTB = ~ PORTB;
        _delay_ms(300);
    }


    return 0;
}