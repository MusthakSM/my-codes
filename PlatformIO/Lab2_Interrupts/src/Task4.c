#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char count = 0;

int main(void){

    // set the 5 to 2 pins of the of PORTB to OUTPUT..
    DDRB |= (1<<PB3) | (1<<PB2) | (1<<PB1) | (1<<PB0);

    // set the pin 2 of PORTD to input..
    DDRD &= ~(1<<PD2) & ~(1<<PD3);


    EICRA |= (1<<ISC01);
    EICRA |= (1<<ISC00);

    EICRA |= (1<<ISC11);
    EICRA |= (1<<ISC10);

    sei();

    EIMSK |= (1<<INT0) | (1<<INT1);
    
    while(1)
    {
    
    }


    return 0;
}

ISR(INT0_vect){
    _delay_ms(300);
    PORTB = PORTB << 1;
    _delay_ms(2500);
}

ISR(INT1_vect){
    _delay_ms(300);
    PORTB = PORTB << 1;
    PORTB |= 1;
    _delay_ms(2500);
}