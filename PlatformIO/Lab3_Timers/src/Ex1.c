
#include <avr/io.h>
#include <util/delay.h>

void delay_timer0(){

    TCNT0 = 0x00;  // Load the timer counter register with a initial value 0

    TCCR0A = 0x00; // Normal mode
    TCCR0B = 0x01; // No prescalar and Normal mode

    /* Check the TOV0 bit of the TIFR0 register..  whether overflow occurs or not.. */
    while((TIFR0 & 0x01) == 0); 

    // claer the timer settings..
    TCCR0A = 0x00;
    TCCR0B = 0x00;

    TIFR0 = 0x01; // clear the timer overflow bit for next round...

}

int main(void){

    DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3);

    PORTB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3);

    while(1){

        PORTB = ~PORTB;
        delay_timer0();
    }

    return 0;
}