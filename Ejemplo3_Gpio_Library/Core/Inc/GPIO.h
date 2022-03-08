/*
 * GPIO.h
 *
 *  Created on: 8 mar. 2022
 *      Author: LENOVO
 */

#ifndef CORE_INC_GPIO_H_
#define CORE_INC_GPIO_H_

#include "main.h"


typedef enum{
    PA,
    PB,
    PC,
    PD,
    PE,
    PF
}Puerto;

typedef enum{
        Low,
        High
}State;


void GPIO_Init(void);
bool Read_GPIO(Puerto port,uint8_t pin);
void Write_GPIO(Puerto port,uint8_t pin,State out);
void Toggle_GPIO(Puerto port,uint8_t pin);


#endif /* CORE_INC_GPIO_H_ */
