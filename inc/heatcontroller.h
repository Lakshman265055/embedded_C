#ifndef _HEATCONTROLLER_
#define _HEATCONTROLLER_H_

#include <avr/io.h>
#include <util/delay.h>
/**
 * @brief A function for button sensor and heater
 * 
 */
void buttons(void);

/**
 * @brief A function to initoalse AD
 * 
 */
void InitADC();

char pwm(uint16_t adcvar);

void timerinit(void);

uint16_t ReadADC(uint8_t ch);

void UARTinit(uint16_t ubrr_value);

char UARTreadchar();

void UARTwritecharacter(char data);

#endif