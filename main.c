/*
 */

#include <avr/io.h>
#include<util/delay.h>
#include "heatcontroller.h"

int main(void)
{
    InitADC();
    buttons();
    timerinit();
    uint16_t adcvar;
    char uartdata;

    while(1)
    {
      if((!(PIND&(1<<PD0)))&&((!(PIND&(1<<PD1)))))
      {

         PORTB|=(1<<PB0);
        adcvar = ReadADC(0);
        uartdata = pwm(adcvar);
        UARTwritecharacter(uartdata);


      }
          else
          {
          PORTB&=~(1<<PB0);
         // _delay_ms(200);
          }
     
    }

    return 0;
}