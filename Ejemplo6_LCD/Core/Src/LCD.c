/*
 * LCD.c
 *
 *  Created on: 9 mar. 2022
 *      Author: LENOVO
 */

#include "LCD.h"


Ubicacion Cursor;

void LCD_TivaC_DataBus(uint8_t a){
    //0000 0001
    if(a & 0x01){ D4_ON;}
    else{ D4_OFF;}
    //0000 0010
    if(a & 0x02) {D5_ON;}
    else{D5_OFF;}
    //0000 0100
    if(a & 0x04){D6_ON;}
    else{D6_OFF;}
     //0000 1000
    if(a & 0x08){D7_ON;}
    else{D7_OFF;}

}
void LCD_TivaC_Cmd(uint8_t a){
    E_OFF;
    E_ON;
    LCD_TivaC_DataBus(a);    //Datos
    delay_ms(2);
    E_OFF;
}
void LCD_TivaC_Init(void){


    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; //Habilitamos el Clock del PuertoF
    while(!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R1)); //Esperamos a q se habilite
    GPIO_PORTB_LOCK_R = 0x4C4F434B; //Desbloqueamos el GPIO pag648
    //GPIO_PORTF_CR_R |= 0x1;
    GPIO_PORTB_DIR_R |= (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1)| (1<<0); //Definimos las salidas
    GPIO_PORTB_DEN_R |= (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1)| (1<<0); //Habilitamos la Funcion Digital

LCD_TivaC_Cmd(0x03);
LCD_TivaC_Cmd(0x03);
LCD_TivaC_Cmd(0x03);
LCD_TivaC_Cmd(0x02);
LCD_TivaC_Cmd(0x02);
LCD_TivaC_Cmd(0x08);
LCD_TivaC_Cmd(0x00);
LCD_TivaC_Cmd(0x08);
LCD_TivaC_Cmd(0x00);
LCD_TivaC_Cmd(0x01);
LCD_TivaC_Cmd(0x00);
LCD_TivaC_Cmd(0x0C); //Inicializado

}
void LCD_TivaC_SetCursor(uint8_t x, Ubicacion y){
    RS_OFF;
    uint8_t m,n;
     switch(y){
        case FILA1:
            m=0x80+x;
            n=(0x80+x)>>4;//Corrimiento de bits
            LCD_TivaC_Cmd(n);
            LCD_TivaC_Cmd(m);
            break;
        case FILA2:
            m=0xC0+x;
            n=(0xC0+x)>>4;//Corrimiento de bits
            LCD_TivaC_Cmd(n);
            LCD_TivaC_Cmd(m);
            break;
        case FILA3:
            m=0x94+x;
            n=(0x94+x)>>4;//Corrimiento de bits
            LCD_TivaC_Cmd(n);
            LCD_TivaC_Cmd(m);
            break;
        case FILA4:
            m=0xD4+x;
            n=(0xD4+x)>>4;//Corrimiento de bits
            LCD_TivaC_Cmd(n);
            LCD_TivaC_Cmd(m);
           break;
    }
}
void LCD_TivaC_Print_Char(char a){
    uint8_t m,n;
    m=a>>4;
    n=a;
    RS_ON;
    LCD_TivaC_Cmd(m);
    LCD_TivaC_Cmd(n);
}
void LCD_TivaC_Print_String(char *a){
    char *ptr;
    ptr = a;
    while (*ptr)
        LCD_TivaC_Print_Char(*ptr++);
}
void LCD_TivaC_Clear(void){
    RS_OFF;
    LCD_TivaC_Cmd(0x00);
    LCD_TivaC_Cmd(0x01);
}
void LCD_STM32_Home(void){
    RS_OFF;
    LCD_TivaC_Cmd(0x00);
    LCD_TivaC_Cmd(0x02);
}
void LCD_TivaC_New_Char(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t h,uint8_t i){
    uint8_t m,n;
    switch(a){
        case 1:
            LCD_TivaC_Cmd(0x04);
            LCD_TivaC_Cmd(0x00);
        RS_ON;
        m=b>>4;
        n=b;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=c>>4;
        n=c;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=d>>4;
        n=d;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=e>>4;
        n=e;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=f>>4;
        n=f;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=g>>4;
        n=g;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=h>>4;
        n=h;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=i>>4;
        n=i;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        RS_OFF;
        LCD_TivaC_Cmd(0x00);
        LCD_TivaC_Cmd(0x01);
        delay_ms(100);
        break;
        case 2:
            LCD_TivaC_Cmd(0x04);
            LCD_TivaC_Cmd(0x08);
            RS_ON;
        m=b>>4;
        n=b;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=c>>4;
        n=c;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=c>>4;
        n=c;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=d>>4;
        n=d;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=e>>4;
        n=e;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=f>>4;
        n=f;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=g>>4;
        n=g;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=h>>4;
        n=h;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=i>>4;
        n=i;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        RS_OFF;
        LCD_TivaC_Cmd(0x00);
        LCD_TivaC_Cmd(0x01);
        delay_ms(100);
        break;
        case 3:
            LCD_TivaC_Cmd(0x04);
            LCD_TivaC_Cmd(0xFF);
        RS_ON;
        m=b>>4;
        n=b;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=c>>4;
        n=c;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=d>>4;
        n=d;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=e>>4;
        n=e;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=f>>4;
        n=f;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=g>>4;
        n=g;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=h>>4;
        n=h;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        m=i>>4;
        n=i;
        LCD_TivaC_Cmd(m);
        LCD_TivaC_Cmd(n);
        RS_OFF;
        LCD_TivaC_Cmd(0x00);
        LCD_TivaC_Cmd(0x01);
        delay_ms(100);
        break;
    }
}

void LCD_TivaC_Write_New_Char(uint8_t a){
    RS_ON;
    LCD_TivaC_Cmd(0x00);
    LCD_TivaC_Cmd(a-1);
    RS_OFF;
}




