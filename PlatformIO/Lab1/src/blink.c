#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // defining PB5 of PORTB as output port
    DDRB |= (1<<PB5);
    
    // initially lit up the led..
    PORTB |= (1<<PB5);
    while(1)
    {
        PORTB = ~PORTB;
        _delay_ms(200);
    }

    return 0;
}