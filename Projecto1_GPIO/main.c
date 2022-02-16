
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

int main(void)
{
    volatile uint32_t ui32Loop;



    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);        // habilitamos el clok del puerto F
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // esperamos que habilite el perifierico
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);  //habilitar el pin F3 como salida digital
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); //habilitar el pin F2 como salida digital

    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3); // Encendemos el PinF3
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0); // apagamos el PinF2
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++);//delay

        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0); // apagamos el PinF3
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2); // Encendemos el PinF2

        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++);//delay

    }
}
