#include <avr/io.h>
#include <avr/interrupt.h>

volatile int overflow_count = 0;
volatile unsigned char ledPin = 1;
volatile unsigned char reverse = 0;
void delay_timer0()
{
    TCNT0 = 6;

    TCCR0A = 0x00;
    TCCR0B = 0x04;
    TIMSK0 = (1<<TOIE0);
    sei();

}

ISR(TIMER0_OVF_vect)
{
    overflow_count++;
    PORTB = (1<<ledPin);

    if(overflow_count == 50)
    {
        overflow_count = 0;
        PORTB &= ~(1<<ledPin);

        if(reverse == 0)
        {
            ledPin++;
            if(ledPin == 6)
            {
                reverse = 1;
                ledPin = 3;
            }
        }else{
            ledPin--;
            if(ledPin == 0)
            {
                reverse = 0;
                ledPin = 2;
            }
        }
        
    }
}


int main(void)
{
    DDRB |= (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    delay_timer0();

    while(1);

    return 0;
}