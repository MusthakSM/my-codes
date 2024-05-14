#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

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
                    ledPin = 4;
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

        if(PORTB & (1<<PB3))
        {
            TCCR0A = 0x00;
            TCCR0B = 0x00;
            TIMSK0 = 0;
        }

    }
}


int main(void)
{
    // Assigning LEDs to OUTPUT..
    DDRB |=  (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    // Getting input from the External input PD2 (INT0);
    DDRD |= (1<<PD2);
    
    // Generate interrupt signals in falling edge..
    EICRA |= (1<<ISC01);
    EICRA &= ~(1<<ISC00);

    sei(); // Enable global interrupt..

    // Enable INT0;
    EIMSK |= (1<<INT0);

    if(pause == 0)
        delay_timer0();

    while(1);

    return 0;
}

// External Interrupt 0..
ISR(INT0_vect)
{
    pause ^= (1<<0);

    PORTB ^= (1<<PB0);

    if(pause == 0)
        delay_timer0();
    else{

        if( PORTB & (1<<PB3))
        {
            TCCR2A |= (1<<COM2A1) | (1<<WGM21) | (1<<WGM20);
            TCCR2B |= (1<<CS21) | (1<<CS20);
            OCR2A = 255;
            unsigned char reverseForPWM = 0;
            while(OCR2A >= 0)
            {
                if(reverseForPWM == 0)
                {
                    if(OCR2A == 0)
                    {
                        reverseForPWM = 1;
                        OCR2A = 1;
                        continue;
                    }
                    OCR2A--;
                    _delay_ms(10);
                }else{

                    if(OCR2A == 255)
                    {
                        reverseForPWM = 0;
                        OCR2A = 254;
                        continue;
                    }
                    OCR2A++;
                    _delay_ms(10);
                }
            }
        }
    }

}