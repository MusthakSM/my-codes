#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char overflow_occurance = 0;

void delay_timer1()
{
    TCNT1 = 3036; // initial value to get 1s delay with 1/256 prescalar.

    TCCR1A = 0x00;    // normal mode.
    TCCR1B = 0x04;    // normal mode, and prescal by 256;
    

    TIMSK1 = (1<<TOIE1);       // Enable Timer1 overflow interrupt bit in Timer/ counter interrupt mask register..

    sei();  // Enable global interrupts..

    while(overflow_occurance == 0);

    TCCR1A = 0x00;
    TCCR1B = 0x00;

    TIMSK1 = 0x00;

    overflow_occurance = 0;
}

ISR(TIMER1_OVF_vect){

    overflow_occurance = 1;

}

int main(void){

    DDRB |= (1<<PB5) | (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3);

    unsigned char ledPin = 0;
    char reverseFlag = 0;
    while(1){
        PORTB ^= (1<<PB5);
        
        if(reverseFlag == 0)
        {
            
            if( PORTB & (1<<PB5))
            {
                PORTB |= (1<<ledPin);
            }else{

                PORTB ^= (1<<ledPin);
                ledPin++;

                if(ledPin == 4)
                {
                    reverseFlag = 1;
                    ledPin = 2;
                }
                    
            }

            delay_timer1();

        }else{

            if( PORTB & (1<<PB5))
            {
                PORTB |= (1<<ledPin);
            }else{
                
                if(ledPin == 0)
                {
                    PORTB ^= (1<<ledPin);
                    reverseFlag = 0;
                    ledPin = 1;

                }else{

                    PORTB ^= (1<<ledPin);
                    ledPin--;
                }

                
            }

            delay_timer1();
        }
    }

    return 0;
}