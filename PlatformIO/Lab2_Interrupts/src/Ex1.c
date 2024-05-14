#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1<<PB5) | (1<<PB4) | (1<<PB3) | (1<<PB2);

    DDRD &= ~(1<<PD2);

    // set the interrupt control register to generate interrupt signal at the rising edge..
    EICRA |= (1<<ISC01);
    EICRA |= (1<<ISC00);

    sei();

    EIMSK |= (1<<INT0);

    while(1){

    }

    return 0;

}

ISR(INT0_vect){
    _delay_ms(1000);
    PORTB |= (1<<PB5) | (1<<PB4) | (1<<PB3) | (1<<PB2);
    _delay_ms(1000);
    PORTB &= ~(1<<PB5) & (1<<PB4) & (1<<PB3) & (1<<PB2);
    _delay_ms(1000);
    
}