#include <avr/io.h>
#include <avr/interrupt.h>

volatile int overflow_count = 0;

void delay_timer0(){

    TCNT0 = 110;
    TCCR0A = 0x00;
    TCCR0B = 0x05;
    
    TIMSK0 |= (1<<TOIE0);
    sei();

}

ISR(TIMER0_OVF_vect)
{
    overflow_count++;
    if(overflow_count == 20)
    {
        overflow_count = 0;
        PORTB ^= (1<<PB5);
    }

}


int main(void)
{
    DDRB |= (1<<PB5);
    
    delay_timer0();

    while(1);
    
    
    return 0;
}