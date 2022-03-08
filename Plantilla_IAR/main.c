#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"                

/*
LedR-> f1
LedB-> f2
LedG-> f3
Switch1-> f4
Switch2-> f0
*/

int main(int argc, char** argv) {
	
	SYSCTL -> RCGCGPIO |= (1<<5);//HABILITAMOS EL CLOCK del puerto F
	GPIOF -> LOCK |= 0x4C4F434B;//Desbloqueamos el GPIO
	GPIOF -> CR |= 0x1;
	GPIOF->AFSEL &= ~(1<<0) & ~(1<<1) & ~(1<<2) & ~(1<<3) & ~(1<<4); //Desactivos la funcion alternativa
	GPIOF->DIR &= ~(1<<0) & ~(1<<4); //Configuramos las entradas
	GPIOF->DIR |= (1<<1) | (1<<2)| (1<<3); //Configuramos las salidas
	GPIOF->PUR |= (1<<0) | (1<<4);//activamos los pull up para los swithcts
	GPIOF->DEN |= (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4);//ACtivamos la funcion digital
	
	
   for(;;){

		if(!(GPIOF->DATA & (1<<4))) GPIOF->DATA |= (1<<3)|(1<<1);
			 
		else if(!(GPIOF->DATA & (1<<0))) GPIOF->DATA &=  ~(1<<1)  & ~(1<<3);

	}

    
    return (EXIT_SUCCESS);
}


