/*
 * Nokia5110.h
 *
 *  Created on: 16/7/2015
 *  Version: 1.0
 *  Information about the license can be found at https://www.gnu.org/licenses/gpl-2.0.html
 */

/*  Copyright (C) 2015 Javier Martínez Arrieta
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 *  Information about the license can be found at https://www.gnu.org/licenses/gpl-2.0.html
 *
 *  This is part of the Nokia5110 library, with functions that will allow you to work with the nokia5110 screen, known as well as PCD8544.
 *  You can find a copy of the Datasheet in the parent folder of the project.
 */

#include "inc/tm4c123gh6pm.h"
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#ifndef NOKIA5110_H_
#define NOKIA5110_H_



#endif /* NOKIA5110_H_ */

#define DC                      (*((volatile unsigned long *)0x40004100))
#define DC_COMMAND              0
#define DC_DATA                 0x40
#define CONTRAST				0xB1
#define RESET                   (*((volatile unsigned long *)0x40004200))
#define RESET_LOW               0
#define RESET_HIGH              0x80
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
enum typeOfWrite{
  COMMAND,                              // the transmission is an LCD command
  DATA                                  // the transmission is data
};


void clear_screen(void);
void lcd_write(enum typeOfWrite type,char message);
void char_write(char character);
void enable_backlight(void);
void disable_backlight(void);
void clear_columns(char ncolumns);
void fill_screen(void);
void screen_write(char string_to_write[],short alignment);
unsigned short get_spacing(char character);
unsigned short get_character_length(char character);
void initialize_screen(short backlight);
void startSSI(void);
int set_Y_position_bottom(int lines);
int set_Y_position_centre(int lines);
void startSSI0(void);


