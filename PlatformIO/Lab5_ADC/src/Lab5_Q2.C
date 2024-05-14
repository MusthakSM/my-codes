/*
Lab - 05
*/
#include <avr/io.h>

// unsigned char val=0;
// unsigned char lval=0;
// unsigned char hval=0;

void initADC(){
    ADCSRA |=(1<<ADEN);//enable ADC 
    ADCSRA |=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//set conversion speed by selecting ADC prescaler as 1:1/128 (Fosc/128=16MHz/128=125kHz<200kHz)

   //select AREF  as voltage reference,left-justified ADC result and ADC1 input channel
    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);
    ADMUX |= 1<<ADLAR;
    ADMUX |= 1<<MUX0;
    ADMUX &= ~(1<<MUX1 | 1<<MUX2 | 1<<MUX3);
}


int main(void){
    DDRC &= ~(1<<1);//configure ADC1 channel pin as input
    DDRD |=(1<<7);//configure PORT D pin 7 as outputs

    initADC();//call initADC() function defined to enable ADC and corresponding settings

    while(1){
        //start conversion
        ADCSRA |=(1<<ADSC);
        //wait for the conversion to be completed
        while((ADCSRA &(1<<ADIF))==0);

        //preserve the most two bits of ADCL
        // lval=((ADCL&0xC0)>>6);//shift all bits by 6 to right

        // //shift all bits by 2 to left
        // //preserve the most six bits of ADCH
        // hval=((ADCH<<2)&0xFC);

        // val=(hval|lval);
        if(ADCH>200){
            PORTD|=(1<<7);//turning on the led
        }else{
            PORTD&=~(1<<7);//turning off the led
        }
    
        ADCSRA |=(1<<ADIF);

    }
    return 0;
}
