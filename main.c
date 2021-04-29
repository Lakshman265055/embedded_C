/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include<util/delay.h>
#include "heatcontroller.h"

int main(void)
{
    InitADC();
    buttons();
    timerinit();
    UARTinit(103);
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