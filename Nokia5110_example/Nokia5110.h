/*
 * Nokia5110.h
 *
 *  Created on: 2/10/2015
 *  Version: 0.0
 *  Information about the license can be found at https://www.gnu.org/licenses/gpl-2.0.html
 */

/*  Copyright (C) 2015 Javier Martínez Arrieta
 *
 *  This project is licensed under Creative Commons Attribution-Non Commercial-Share Alike 4.0 International (CC BY-NC-SA 4.0). According to this license you are free to:
 *  Share — copy and redistribute the material in any medium or format.
 *  Adapt — remix, transform, and build upon the material.
 *  The licensor cannot revoke these freedoms as long as you follow the license terms.
 *	Complete information about this license can be found at: https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 *
 */

#include "inc/tm4c123gh6pm.h"
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#ifndef NOKIA5110_H_
#define NOKIA5110_H_


#endif /* NOKIA5110_H_ */

#define DC                      (*((volatile unsigned long *)0x40004100))//For SSI0
#define DC_SSI1                 (*((volatile unsigned long *)0x40024008))//For SSI1
#define DC_SSI2                 (*((volatile unsigned long *)0x40005010))//For SSI2
#define DC_SSI3                 (*((volatile unsigned long *)0x40007100))//For SSI3
#define DC_COMMAND              0
#define DC_DATA                 0x40
#define DC_DATA_SSI1			0x02
#define DC_DATA_SSI2			0x04
#define DC_DATA_SSI3			0x40
#define CONTRAST				0xB1
#define RESET                   (*((volatile unsigned long *)0x40004200)) //For SSI0
#define RESET_SSI1              (*((volatile unsigned long *)0x40024010)) //For SSI1
#define RESET_SSI2              (*((volatile unsigned long *)0x40005020))//For SSI2
#define RESET_SSI3              (*((volatile unsigned long *)0x40007200))//For SSI3
#define RESET_LOW               0
#define RESET_HIGH              0x80 //For SSI0
#define RESET_HIGH_SSI1         0x04 //For SSI1
#define RESET_HIGH_SSI2         0x08 //For SSI2
#define RESET_HIGH_SSI3         0x80 //For SSI3
#define MAX_X					84
#define MAX_Y					6
#define ALIGN_LEFT_TOP			0
#define ALIGN_CENTRE_TOP		1
#define ALIGN_RIGHT_TOP			2
#define ALIGN_LEFT_CENTRE		3
#define ALIGN_CENTRE_CENTRE		4
#define ALIGN_RIGHT_CENTRE		5
#define ALIGN_LEFT_BOTTOM		6
#define ALIGN_CENTRE_BOTTOM		7
#define ALIGN_RIGHT_BOTTOM		8
#define ALIGN_RANDOM			9

#define BACKLIGHT_ON			0
#define BACKLIGHT_OFF			1

#define SSI0	0
#define SSI1	1
#define SSI2	2
#define SSI3	3

enum typeOfWrite{
  COMMAND,                              // the transmission is an LCD command
  DATA                                  // the transmission is data
};


void clear_screen(short SSI);
void lcd_write(enum typeOfWrite type,char message,short SSI);
void char_write(char character,short SSI);
void enable_backlight(void);
void disable_backlight(void);
void clear_columns(char ncolumns,short SSI);
void fill_screen(short SSI);
void screen_write(char string_to_write[],short alignment,short SSI);
unsigned short get_spacing(char character);
unsigned short get_character_length(char character);
void initialize_screen(short backlight,short SSI);
void startSSI(void);
int set_Y_position_bottom(int lines,short SSI);
int set_Y_position_centre(int lines,short SSI);
void startSSI0(void);
void startSSI1(void);
void startSSI2(void);
void startSSI3(void);

