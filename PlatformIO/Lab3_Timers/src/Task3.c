#include <avr/io.h>
#include <util/delay.h>

void delay_timer0()
{
    TCNT0 = 131; // set initial value to 131

    TCCR0A = 0x00; // Normal mode;
    TCCR0B = 0x05; // set prescalar to 1/1024 and Normal mode;

    while( TIFR0 & (1<<TOV0) == 0);    // exit hte loop when timer gets overflow.. meaning when TOV0 becomes 1;

    TCCR0A = 0x00;
    TCCR0B = 0x00;

    TIFR0 = 0x01;   // clear the TOV0 bit. make it to refer overflow., so timer will start from 0..
}


int main(void){

    // define output in pin5 of pORTB
    DDRB |= (1<<PB5);

    while(1)
    {
        PORTB ^= (1<<PB5);
        delay_timer0();
    }

    return 0;
}