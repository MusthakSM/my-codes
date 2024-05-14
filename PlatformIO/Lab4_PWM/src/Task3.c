#include <avr/io.h>
#include <util/delay.h>

#define BUZZER_PIN PD6

int main(void) {
    // Set PD6 as an output for PWM
    DDRD |= (1 << BUZZER_PIN);

    TCNT0 = 0x00; //Load timer counter register

    // Configure Timer/Counter 0 for Fast PWM mode non-inverting mode
    TCCR0A = (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);
    TCCR0B = 0x00; // Prescaler = None

    OCR0A = 63; //25% duty cycle


    while (1) {

        TCCR0B = 0x02;         //7812.5 Hz
        _delay_ms(1000);      // Pause between frequencies

        TCCR0B = 0x03;         //976.56 Hz
        _delay_ms(1000);      // Pause between frequencies

        TCCR0B = 0x04;         //244.14 Hz
        _delay_ms(1000);      // Pause between frequencies

        TCCR0B = 0x05;         // 61.03 Hz
        _delay_ms(1000);      // Pause between frequencies
    }

    return 0;
}