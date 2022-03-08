/*
 * main.c
 *
 *  Created on: 6 mar. 2022
 *      Author: LENOVO
 */


#include "main.h"
#include "GPIO.h"

void delay_ms(uint16_t n);
void delay_us(uint16_t n);

int main(void)
{

    GPIO_Init();

  for(;;)
  {

   //  Toggle_GPIO(PF, 3);
    // delay_ms(100);

      if (!Read_GPIO(PF, 0))  Write_GPIO(PF, 3, High);
      else if (!Read_GPIO(PF, 4))  Write_GPIO(PF, 3, Low);
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

