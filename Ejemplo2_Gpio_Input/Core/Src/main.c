/*
 * main.c
 *
 *  Created on: 6 mar. 2022
 *      Author: LENOVO
 */


#include "main.h"

typedef enum{
    switch1,
    switch2
}Input;

bool Read_GPIO(Input pin);
void delay_ms(uint16_t n);
void delay_us(uint16_t n);



int main(void)
{
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; //Habilitamos el Clock del PuertoF
    while(!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)); //Esperamos a q se habilite
    GPIO_PORTF_LOCK_R = 0x4C4F434B; //Desbloqueamos el GPIO pag648
    //GPIO_PORTF_CR_R |= 0x1;
    GPIO_PORTF_DIR_R |= (1<<3) | (1<<2) | (1<<1); //Definimos las salidas
    GPIO_PORTF_DIR_R &= ~(1<<0) & ~(1<<4);
    GPIO_PORTF_PUR_R |= (1<<0) | (1<<4);//activamos las resistencias pull up
    GPIO_PORTF_DEN_R |= (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0); //Habilitamos la Funcion Digital

  for(;;)
  {
      if(!Read_GPIO(switch1)) GPIO_PORTF_DATA_R |= (1<<1) | (1<<3);
      else  if(!Read_GPIO(switch2)) GPIO_PORTF_DATA_R &= ~(1<<1) & ~(1<<3);
  }
}

bool Read_GPIO(Input pin)
{
    int state;
    switch(pin) {
        case switch1:
            state = (GPIO_PORTF_DATA_R & (1<<4));
            break;
        case switch2:
            state = (GPIO_PORTF_DATA_R & (1<<0));
            break;
    }

return state;
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

