
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD |= (1<<PD6);


    TCCR0A |= (1<<COM0A1) | (1<<WGM00) | (1<<WGM01);

    TCCR0B |= (1<<CS00) | (1<<CS01);

    OCR0A = 127;
    char reverse = 0;
    while(1)
    {
        if(reverse == 0)
        {
            if(OCR0A == 0)
            {
                reverse = 1;
                continue;

            }

            OCR0A--;
            _delay_ms(15);

        }else{

            if( OCR0A == 127)
            {
                reverse = 0;
                continue;
            }

            OCR0A++;
            _delay_ms(15);
        }
        
    }

    return 0;
}