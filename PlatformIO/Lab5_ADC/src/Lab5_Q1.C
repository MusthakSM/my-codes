/*
Lab - 05
*/
#include <avr/io.h>

void initADC(){
    ADCSRA |=(1<<ADEN);//enable ADC 
    ADCSRA |=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//set conversion speed by selecting ADC prescaler as 1:1/128 (Fosc/128=16MHz/128=125kHz<200kHz)

    ADMUX |=0x61;//select AVCC as voltage reference,left-justified ADC result and ADC1 input channel
}


int main(void){
    DDRC &= ~(1<<1);//configure ADC1 channel pin as input
    DDRD =0xFF;//configure PORT D pins as outputs

    initADC();//call initADC() function defined to enable ADC and corresponding settings

    while(1){
        //start conversion
        ADCSRA |=(1<<ADSC);
        //wait for the conversion to be completed
        while((ADCSRA&(1<<ADIF))==0);

        //preserve the most two bits of ADCL
        ADCL=(ADCL&0xC0);
        ADCL=(ADCL>>6);//shift all bits by 6 to right

        ADCH=(ADCH<<2);//shift all bits by 2 to left
        //preserve the most six bits of ADCH
        ADCH=(ADCH&0xFC);
        PORTD=(ADCH|ADCL);

        ADCSRA|=(1<<ADIF);

    }
    return 0;
    
}
