/*
 * main.c
 *
 *  Created on: 6 mar. 2022
 *      Author: LENOVO
 */


#include "main.h"

/*
LedR-> f1
LedB-> f2
LedG-> f3
Switch1-> f4
Switch2-> f0
*/

typedef enum{
    Red=1,
    Blue,
    Green
}RGB;

typedef enum{
        Low,
        High
}State;

void delay_ms(uint16_t n);
void delay_us(uint16_t n);
void ConfigGPIO(void);
void LedOutput(RGB led,State Out);
void LedBlink(RGB led);

int main(void)
{

 ConfigGPIO();

  for(;;)
  {

     LedBlink(Blue);
     delay_ms(500);
  }

}
void LedBlink(RGB led){

    GPIO_PORTF_DATA_R ^= (1<<led);
}


void ConfigGPIO(void){
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; //Habilitamos el Clock del PuertoF
    while(!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)); //Esperamos a q se habilite
    GPIO_PORTF_DIR_R |= (1<<3) | (1<<2) | (1<<1); //Definimos las salidas
    GPIO_PORTF_DEN_R |= (1<<3) | (1<<2) | (1<<1); //Habilitamos la Funcion Digital
}

void LedOutput(RGB led,State Out){
    switch (Out) {
        case Low:
            GPIO_PORTF_DATA_R &= ~(1<<led);
            break;
        case High:
            GPIO_PORTF_DATA_R |= (1<<led);
            break;
        }
}

void delay_ms(uint16_t n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}


void delay_us(uint16_t n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}

}

