/*
 * main.c
 */

#include "Nokia5110.h"

 /*  Copyright (C) 2015 Javier Martínez Arrieta
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 *  Information about the license can be found at https://www.gnu.org/licenses/gpl-2.0.html
 */


int main(void)
{
	SysTick_Init();
	startSSI0();
	initialize_screen(BACKLIGHT_ON);
	while(1)
	{
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_LEFT_TOP);
		SysTick_Wait50ms(200);
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_CENTRE_TOP);
		SysTick_Wait50ms(200);
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_RIGHT_TOP);
		SysTick_Wait50ms(200);
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_LEFT_CENTRE);
		SysTick_Wait50ms(200);
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_CENTRE_CENTRE);
		SysTick_Wait50ms(200);
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_RIGHT_CENTRE);
		SysTick_Wait50ms(200);
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_LEFT_BOTTOM);
		SysTick_Wait50ms(200);
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_CENTRE_BOTTOM);
		SysTick_Wait50ms(200);
		clear_screen();
		screen_write("Hi!\nHow are you?",ALIGN_RIGHT_BOTTOM);
		SysTick_Wait50ms(200);
		int i=0;
		for(i=0;i<5;i++)
		{
			clear_screen();
			screen_write("Welcome",ALIGN_RANDOM);
			SysTick_Wait50ms(200);
		}
	}
	return 0;
}

// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTick_Wait(unsigned long delay){
  NVIC_ST_RELOAD_R = delay-1;  // number of counts to wait
  NVIC_ST_CURRENT_R = 0;       // any value written to CURRENT clears
  while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
  }
}

// 800000*62.5ns equals 50ms (number of cycles * cycle time,being cycle time the inverse of working clock)
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
