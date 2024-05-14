#include <avr/io.h>
#include <util/delay.h>


int main(void){

    // set the 5 to 2 pins of the of PORTB to OUTPUT..
    DDRB |= (1<<PB3) | (1<<PB2) | (1<<PB1) | (1<<PB0);

    // set the pin 7 of PORTD to input..
    DDRD &= ~(1<<PD7);

    unsigned char count = 0;
    unsigned char previous = 0;
    while(1)
    {
        unsigned char current = (PIND & (1<<PD7));

        if(current == 0 && previous != 0)
        {
            ++count;
            PORTB = count;
            _delay_ms(300);
        }

        previous = current;
    }


    return 0;
}