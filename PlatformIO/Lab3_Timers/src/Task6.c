
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int timer0_overflow_tracker = 0;
volatile int timer1_overflow_tracker = 0;

// time0 implementation..
void delay_timer0(){

    TCNT0 = 110;
    TCCR0A = 0x00;
    TCCR0B = 0x05;
    TIMSK0 |= (1<<TOIE0);

    sei();

}

// timer1 implementation..
void delay_timer1(){

    TCNT1 = 3036;
    TCCR1A = 0x00;
    TCCR1B = 0x03;

    TIMSK1 |= (1<<TOIE1);
    sei();
}

// isr for timer0;
ISR(TIMER0_OVF_vect)
{
    timer0_overflow_tracker++;
    if(timer0_overflow_tracker == 5)
    {
        PORTB ^= (1<<PB0);
        timer0_overflow_tracker = 0;
    }
}

//isr for timer1;

ISR(TIMER1_OVF_vect)
{
    timer1_overflow_tracker++;
    if(timer1_overflow_tracker % 2 == 0)
    {
        PORTB ^= (1<<PB1);
    }
}


int main(void)
{
    DDRB |= (1<<PB0) | (1<<PB1);

    delay_timer0();
    delay_timer1();

    while(1);

    return 0;
}