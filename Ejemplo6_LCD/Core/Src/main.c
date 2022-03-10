/*
 * main.c
 *
 *  Created on: 6 mar. 2022
 *      Author: LENOVO
 */


#include "main.h"
#include "GPIO.h"
#include "LCD.h"

char dato[5] = "";
int main(void)
{

    GPIO_Init();
    LCD_TivaC_Init();
    LCD_TivaC_New_Char(1,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00,0x00);//Corazon
    LCD_TivaC_SetCursor(0, FILA1);
    LCD_TivaC_Print_String("Curso Tiva C ");
    LCD_TivaC_Write_New_Char(1);
    LCD_TivaC_SetCursor(0, FILA2);
    LCD_TivaC_Print_String("Godo Sanchez...");

   for(;;)
     {



  }

}

