#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    // enabling interrupt input pin..
    // INT0 => PD2 => Digital pin 2
    DDRD &= ~(1<<PD2);

    // set PB0 to output..
    DDRB |= (1<<PB0);

    // set the EICRA to generate signals to
    EICRA |= (1<<ISC01);
    EICRA &= ~(1<<ISC00);

    sei();
    EIMSK |= (1<<INT0);

    while(1){

    }

    return 0;
}

ISR(INT0_vect){
    
    PORTB = PORTB ^ (1<<0);
    _delay_ms(2500);
}