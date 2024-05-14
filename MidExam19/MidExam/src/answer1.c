#include <avr/io.h>
#include <avr/interrupt.h>

volatile int overflow_count = 0;
volatile unsigned char ledpin = 1;
volatile unsigned char reverse = 0;
void delay_timer0(){

    TCNT0 = 6;      // Initial value to get 4 ms delay with prescalar 256.

    TCCR0A = 0x00;
    TCCR0B = 0x04;

    TIMSK0 = (1<<TOIE0);

    sei();

}


ISR(TIMER0_OVF_vect)
{
    overflow_count++;
    TCNT0 = 6;

    PORTB |= (1<<ledpin);

    if(overflow_count == 50)
    {
        overflow_count = 0;
        if(reverse == 0)
        {
            if(ledpin == 5)
            {
                ledpin = 4;
                reverse = 1;
            }
            else{
                ledpin++;
            }
            
        }
        else{

            if(ledpin == 1)
            {
                ledpin = 2;
                reverse = 0;
            }
            else
                ledpin--;
        }

        PORTB = 0;
    }

}


int main(void)
{

    DDRB |= (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    delay_timer0();

    while(1);   

    return 0;
}