/*
 * main.c
 *
 *  Created on: 16/7/2015
 *  Author: Javier Martínez Arrieta
 *  Version: 1.0
 *  This is part of the Nokia5110 library, with functions that will allow you to work with the nokia5110 screen, known as well as PCD8544.
 *  You can find a copy of the Datasheet in the parent folder of the project.
 */
#include "Nokia5110.h"

 /*  Copyright (C) 2015 Javier Martínez Arrieta
 *
 *  This project is licensed under Creative Commons Attribution-Non Commercial-Share Alike 4.0 International (CC BY-NC-SA 4.0). According to this license you are free to:
 *  Share — copy and redistribute the material in any medium or format.
 *  Adapt — remix, transform, and build upon the material.
 *  The licensor cannot revoke these freedoms as long as you follow the license terms.
 *	Complete information about this license can be found at: https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 *
 */


int main(void)
{
	SysTick_Init();
	startSSI2();
	initialize_screen(BACKLIGHT_ON,SSI2);
	int i;
	while(1)
	{
		clear_screen(SSI2);
		screen_write("Hello\nMaría!",ALIGN_CENTRE_CENTRE,SSI2);
		SysTick_Wait50ms(5);
	}
	return 0;
}


// The delay parameter is in units of the 16 MHz core clock.
void SysTick_Wait(unsigned long delay){
  NVIC_ST_RELOAD_R = delay-1;  // number of counts to wait
  NVIC_ST_CURRENT_R = 0;       // any value written to CURRENT clears
  while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
  }
}


void SysTick_Wait50ms(unsigned long delay){
  unsigned long i;
  for(i=0; i<delay; i++){
    SysTick_Wait(800000);  // wait 50ms
  }
}


void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;               // disable SysTick during setup
  NVIC_ST_CTRL_R = 0x00000005;      // enable SysTick with core clock
}

