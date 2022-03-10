/*
 * GPIO.c
 *
 *  Created on: 8 mar. 2022
 *      Author: LENOVO
 */


#include "GPIO.h"

void GPIO_Init(void){

    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; //Habilitamos el Clock del PuertoF
    while(!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)); //Esperamos a q se habilite
    GPIO_PORTF_LOCK_R = 0x4C4F434B; //Desbloqueamos el GPIO pag648
    //GPIO_PORTF_CR_R |= 0x1;
    GPIO_PORTF_DIR_R |= (1<<3) | (1<<2) | (1<<1); //Definimos las salidas
    GPIO_PORTF_DIR_R &= ~(1<<0) & ~(1<<4);
    GPIO_PORTF_PUR_R |= (1<<0) | (1<<4);//activamos las resistencias pull up
    GPIO_PORTF_DEN_R |= (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0); //Habilitamos la Funcion Digital

}


bool Read_GPIO(Puerto port,uint8_t pin){

    bool state;

    switch (port) {
           case PA:
               state = (GPIO_PORTA_DATA_R & (1<<pin));
               break;
           case PB:
               state = (GPIO_PORTB_DATA_R & (1<<pin));
               break;
           case PC:
               state = (GPIO_PORTC_DATA_R & (1<<pin));
               break;
           case PD:
               state = (GPIO_PORTD_DATA_R & (1<<pin));
               break;
           case PE:
               state = (GPIO_PORTE_DATA_R & (1<<pin));
               break;
           case PF:
               state = (GPIO_PORTF_DATA_R & (1<<pin));
               break;
       }


    return state;
}
void Write_GPIO(Puerto port,uint8_t pin,State out){

    switch (port) {
        case PA:
             switch (out) {
                 case Low:
                      GPIO_PORTA_DATA_R &= ~(1<<pin);
                      break;
                 case High:
                      GPIO_PORTA_DATA_R |= (1<<pin);
                      break;
                    }
            break;
        case PB:
             switch (out) {
                 case Low:
                      GPIO_PORTB_DATA_R &= ~(1<<pin);
                      break;
                 case High:
                      GPIO_PORTB_DATA_R |= (1<<pin);
                      break;
                    }
            break;
        case PC:
             switch (out) {
                              case Low:
                                  GPIO_PORTC_DATA_R &= ~(1<<pin);
                                  break;
                              case High:
                                  GPIO_PORTC_DATA_R |= (1<<pin);
                                  break;
                              }
            break;
        case PD:
             switch (out) {
                              case Low:
                                  GPIO_PORTD_DATA_R &= ~(1<<pin);
                                  break;
                              case High:
                                  GPIO_PORTD_DATA_R |= (1<<pin);
                                  break;
                              }
            break;
        case PE:
             switch (out) {
                              case Low:
                                  GPIO_PORTE_DATA_R &= ~(1<<pin);
                                  break;
                              case High:
                                  GPIO_PORTE_DATA_R |= (1<<pin);
                                  break;
                              }
            break;
        case PF:
             switch (out) {
                              case Low:
                                  GPIO_PORTF_DATA_R &= ~(1<<pin);
                                  break;
                              case High:
                                  GPIO_PORTF_DATA_R |= (1<<pin);
                                  break;
                              }
            break;
    }

}
void Toggle_GPIO(Puerto port,uint8_t pin){
    switch (port) {
        case PA:
            GPIO_PORTA_DATA_R ^= (1<<pin);
            break;
        case PB:
            GPIO_PORTB_DATA_R ^= (1<<pin);
            break;
        case PC:
            GPIO_PORTC_DATA_R ^= (1<<pin);
            break;
        case PD:
            GPIO_PORTD_DATA_R ^= (1<<pin);
            break;
        case PE:
            GPIO_PORTE_DATA_R ^= (1<<pin);
            break;
        case PF:
            GPIO_PORTF_DATA_R ^= (1<<pin);
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


