/*
 */

#include <avr/io.h>
#include<util/delay.h>
#include "heatcontroller.h"



void timerinit(void){

TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM00);
    // Insert code
TCCR0B|=(1<<CS01)|(1<<CS00);
DDRD|=(1<<PD6);


}


char pwm(uint16_t adcvar)
{

char uartdata;
if((adcvar>=0) && (adcvar<=209)){

        OCR1A = 205; //20% duty cycle
        uartdata = 'A';

        _delay_ms(20);
    }
    else if((adcvar>=210) && (adcvar<=509)){

        OCR1A = 410; //40% duty cycle
        uartdata = 'B';
        _delay_ms(20);
    }
    else if((adcvar>=510) && (adcvar<=709)){

        OCR1A = 717;//70% duty cycle
        uartdata ='C';
        _delay_ms(20);
    }
    else if((adcvar>=710) && (adcvar<=1024)){

        OCR1A = 973; //95% duty cycle
        uartdata = 'D';
        _delay_ms(20);
    }
    else{
        OCR1A = 0; //0% output
        uartdata = "0";
    }
return uartdata;
}