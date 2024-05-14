#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// vairbales to handle the led reversing

volatile int overflow_count = 0;  // counts the oveflow times of the Timer 0;
volatile unsigned char ledpin = 1;  // initially assigned to pin1 (PB1);

volatile unsigned char reverse = 0; // variable to control the reverse order of the led lit up..

volatile uint8_t pause = 0;     // variable to pause the leds when PD2 interrupt signal is triggered through INT0

void delay_timer0(){

    /* Here I am getting 4ms of delay from timer 0. So inorder to get 200 ms delay, i want 200/4 = 50 overflows.*/

    TCNT0 = 6;      // Initial value to get 4 ms delay with prescalar 256.    

    TCCR0A = 0x00;  // Normal mode..
    TCCR0B = 0x04;  // Normal mode and prescaler set to 256;

    TIMSK0 = (1<<TOIE0);    // Enabling timer0 overflow interrupt..
    sei();          // Enabling global interrupt..

}


ISR(TIMER0_OVF_vect)
{

    if(pause == 0) 
    {  
        /* If pause is 0, then button is not pressed inorder to pause the LEDS*/

        overflow_count++; // increment the overflow count.. we need 50 overflow counts...
        TCNT0 = 6;          // after every overflow se the initial value of the timer/ counter register 0 to 6, so that it can provide 4 ms delay..

        /* 
         * An LED Litup until overflow count reach 50.. it's 50*4= 200 ms time..
         * Then next lED will be litup..

        */
        
        PORTB |= (1<<ledpin);  // litup the led.. at the very biginning it will start from PB1. 

        if(overflow_count == 50)
        {
            // when it reaches 200 ms... 50 * 4ms = 200 ms;

            overflow_count = 0;   // set count to 0. so that i can next 200ms effectivly, by checking every 50 counts..
            if(reverse == 0)
            {
                /* This code block change the LED lighting in forward order..*/
                if(ledpin == 5)
                {
                    // when last LED reached.. set the lEDPIN to 4 and enable reverse order lighting by changing it to 1.
                    ledpin = 4;
                    reverse = 1;
                }
                else{
                    // increase ledpin
                    ledpin++;
                }
                
            }
            else{
                /* This code block change the LED lighting in backward order..*/
                if(ledpin == 1)
                {
                    // when the first LED reached.. set the lEDPIN to 2 and disable reverse order lighting by changing it to 0.
                    ledpin = 2;
                    reverse = 0;
                }
                else
                    ledpin--;
            }

            PORTB = 0; // set the portb to 0, so next ledpin will be litup when the previous one has been off
        }
    }else{
        // if INT0 interrupt triggered to pause the LED lighting. stop the Timer0 interrupt.
        TCCR0A = 0x00;
        TCCR0B = 0x00;

        TIMSK0 = 0x00;
    }

}


int main(void)
{
    // Defining pb1 to 5 pins to OUPUT..
    DDRB |= (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    // defining PD2 INT0 pin to input..
    DDRD &= ~(1<<PD2);

    // generating interrupt signal at the falling edge..
    EICRA |= (1<<ISC01);
    EICRA &= ~(1<<ISC00);

    // Enable global interrupt..
    sei();

    // Enable INT0
    EIMSK |= (1<<INT0);

    // activate delay_timer0();
    delay_timer0();

    // set the output compare register A of timer 2 to an initial value of 255.
    OCR2A = 255;

    while(1);   

    return 0;
}

ISR(INT0_vect)
{
    // toggle the 1st bit of the pause every time interrupt triggered..
    pause ^= (1<<0);

    // if paused == 0, avtivate delaytimer0() and off PWM if it has been on.
    if(pause == 0)
    {
        delay_timer0();

        TCCR2A &= ~((1<<COM2A1) | (1<<WGM21) | (1<<WGM20));
        TCCR2B &= ~((1<<CS20));

    }else{
        // Enable gloabal interrupt, so can take INT0 while in the loop
        sei();

        if(PORTB & (1<<PB3))
        {
            // if the PB3 pin led is on..
            // then make pwm output..
            unsigned char decreaseIntensity = 1;
            TCCR2A |= (1<<COM2A1) | (1<<WGM21) | (1<<WGM20);
            TCCR2B |= (1<<CS20);

            while(OCR2A >= 0)
            {
                if(decreaseIntensity == 1)
                {
                    if(OCR2A == 0)
                    {
                        OCR2A = 1;
                        decreaseIntensity = 0;
                        continue;
                    }
                    else{
                        OCR2A--;
                        _delay_ms(12);
                    }
                }else{

                    if(OCR2A == 255)
                    {
                        OCR2A = 254;
                        decreaseIntensity = 1;
                        continue;
                    }
                    else{
                        OCR2A++;
                        _delay_ms(12);
                    }

                }
            }
        }
    }
}