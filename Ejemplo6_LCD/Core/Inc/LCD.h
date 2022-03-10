/*
 * LCD.h
 *
 *  Created on: 9 mar. 2022
 *      Author: LENOVO
 */

#ifndef CORE_INC_LCD_H_
#define CORE_INC_LCD_H_

#include "main.h"
#include "GPIO.h"


#define E_ON GPIO_PORTB_DATA_R |= (1<<0);
#define E_OFF GPIO_PORTB_DATA_R &= ~(1<<0);

#define RS_ON GPIO_PORTB_DATA_R |= (1<<1);
#define RS_OFF GPIO_PORTB_DATA_R &= ~(1<<1);

#define D4_ON GPIO_PORTB_DATA_R |= (1<<2);
#define D4_OFF GPIO_PORTB_DATA_R &= ~(1<<2);

#define D5_ON GPIO_PORTB_DATA_R |= (1<<3);
#define D5_OFF GPIO_PORTB_DATA_R &= ~(1<<3);

#define D6_ON GPIO_PORTB_DATA_R |= (1<<4);
#define D6_OFF GPIO_PORTB_DATA_R &= ~(1<<4);

#define D7_ON GPIO_PORTB_DATA_R |= (1<<5);
#define D7_OFF GPIO_PORTB_DATA_R &= ~(1<<5);

typedef enum{
    FILA1 = 1,
    FILA2,
    FILA3 ,
    FILA4
}Ubicacion;

void LCD_TivaC_Cmd(uint8_t a);
void LCD_TivaC_DataBus(uint8_t a);
void LCD_TivaC_Init(void);
void LCD_TivaC_SetCursor(uint8_t x , uint8_t y);
void LCD_TivaC_Print_Char(char a);
void LCD_TivaC_Print_String(char *a);
void LCD_TivaC_New_Char(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t h,uint8_t i);
void LCD_TivaC_Write_New_Char(uint8_t a);
void LCD_TivaC_Clear(void);
void LCD_TivaC_Home(void);


#endif /* CORE_INC_LCD_H_ */
