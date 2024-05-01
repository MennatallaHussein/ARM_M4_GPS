#include <stdio.h>
#include <stdlib.h>
#include "../UTILITIES/tm4c123gh6pm.h"
#include "../MCAL/GPIO/DIO_Driver.h"
#include "../UTILITIES/Bit_Utilities.h"
#include "mainFUN.h"
#include "../MCAL/STK/SysTick.h"
#include "../MCAL/UART0/UART0_PC.h"
#include "../HAL/SW/SW.h"
#include "../HAL/SW/ext_SW.h"
#include "../HAL/GPS/GPS.h"
#include "../HAL/LED/LED_interface.h"

//destination of asu foe

extern float distance; // will be stored

int main(void){


DIO_vPORTINIT(DIO_PORTA);
DIO_vPORTINIT(DIO_PORTB);
DIO_vPORTINIT(DIO_PORTC);
DIO_vPORTINIT(DIO_PORTD);
DIO_vPORTINIT(DIO_PORTE);
DIO_vPORTINIT(DIO_PORTF);			


ex_sw_init();
//eeprom_init();
UART0_INIT();
SysTick_Init();
LED_LedInit();
SW_Init(SW1);
SW_Init(SW2);
//LCD_init();



while(1)
{

    if(swich2check()==1){
         do{
		 distance=0;
            mainProgram();
            }while(distance<=100);
   }


    else if(swich2check()==2){
            do{
		 distance=0;
             mainProgram();
            }while(!SW_ispressed( SW1 ));
    }


    else if(swich2check()==3){
            do{
	     distance=0;
             mainProgram();
            }while(isDestination());
    }


    else if(swich2check()==4){
          do{
		 distance=0;
             mainProgram();
            }while(~(distance<=100 || !SW_ispressed( SW1 ) ||isDestination()));
    }

    distance=0;
    int i=0;
		LED_LedInit();
		LED_LedOn(LED_GREEN);

   

    if (SWex_ispressed())
    {

    for (int i = 0; i < array_size; i++){
			eeprom_write(lon_lat[i],i,1);
		}
    LED_LedInit();
		LED_RED

    if(UART0_read()=="U")
		for(int i=0;i<lon_lat.length;i++){
        UART0_write((char)lon_lat[i]);
    }


for (int i = 0; i < array_size; i++)
 {array[i] = 0;}
	LED_OffAll();
	//LCD_clearScreen();
   }
}
