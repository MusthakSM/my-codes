/* Blinking 4 LEDs simultaneously*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // defining outputs..
    DDRB |= (1<<PB5) | (1<<PB4) | (1<<PB3) | (1<<PB2) ;

    unsigned char status = 0;
    unsigned char pin = 2;
    while(1)
    {
        for(unsigned char i=2; i<=5; i++)
        {
            if(i == 2)
            {
                unsigned char iter = 10;
                PORTB |= (1<<i);
                while(iter != 0)
                {
                    PORTB ^= (1<<i);
                    _delay_ms(200);
                    --iter;
                }

                PORTB = 0;
                _delay_ms(200);
            }
            else if(i == 5)
            {
                unsigned char iter = 10;
                PORTB |= (1<<i);
                while(iter != 0)
                {
                    PORTB ^= (1<<i);
                    _delay_ms(200);
                    --iter;
                }

                PORTB = 0;
                _delay_ms(200);

            }else{

                PORTB |= (1<<i);
                _delay_ms(200);
                PORTB = 0;
            }
        }
        
        for(unsigned char i=4; i>=3; i--)
        {
            PORTB |= (1<<i);
            _delay_ms(200);
            PORTB = 0;
        }
    }


    return 0;
}