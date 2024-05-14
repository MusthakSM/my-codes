#include <avr/io.h>
#include <avr/interrupt.h>

volatile int overflow_count = 0;
volatile unsigned char ledPin = 1;
volatile unsigned char reverse = 0;

// vairble changing in INT0;
volatile uint8_t pause = 0;

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
    if(pause == 0)
    {

        overflow_count++;
        TCNT0 = 6;

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
    }else{

    }
}


int main(void)
{
    // Assigning LEDs to OUTPUT..
    DDRB |= (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    // Getting input from the External input PD2 (INT0);
    DDRD |= (1<<PD2);
    
    // Generate interrupt signals in falling edge..
    EICRA |= (1<<ISC01);
    EICRA &= ~(1<<ISC00);

    sei(); // Enable global interrupt..

    // Enable INT0;
    EIMSK |= (1<<INT0);

    delay_timer0();

    while(1);

    return 0;
}

// External Interrupt 0..
ISR(INT0_vect)
{
    pause ^= (1<<0);

}