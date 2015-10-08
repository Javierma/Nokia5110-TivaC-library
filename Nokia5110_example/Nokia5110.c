/*
 * Nokia5110.c
 *
 *  Created on: 2/10/2015
 *  Author: Javier Martínez Arrieta
 *  Version: 2.0
 *  This is part of the Nokia5110 library, with functions that will allow you to work with the nokia5110 screen, known as well as PCD8544.
 *  You can find a copy of the Datasheet in the parent folder of the project.
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

#include "Nokia5110.h"
#include "inc/tm4c123gh6pm.h"


/**
 * Clears the screen. Please note that if inverse mode is set it will not work as expected.
 */
void clear_screen(short SSI)
{
	int i;
	for(i=0; i<(MAX_X*MAX_Y); i=i+1)
	{
		lcd_write(DATA, 0x00,SSI);
	}

}

/**
 * Sends command or data to the screen
 */
void lcd_write(enum typeOfWrite type,char message,short SSI)
{
	switch(SSI)
	{

	case SSI0:
	{
	if(type == COMMAND)
	{
		// wait until SSI0 not busy/transmit FIFO empty
		while((SSI0_SR_R&SSI_SR_BSY)==SSI_SR_BSY){};
		DC = DC_COMMAND;
		SSI0_DR_R = message;
		// wait until SSI0 not busy/transmit FIFO empty
		while((SSI0_SR_R&SSI_SR_BSY)==SSI_SR_BSY){};
	}
	else
	{
		// wait until transmit FIFO not full
		while((SSI0_SR_R&SSI_SR_TNF)==0){};
		DC = DC_DATA;
		SSI0_DR_R = message;
	}
	break;
	}
	case SSI1:
		{
		if(type == COMMAND)
		{
			// wait until SSI2 not busy/transmit FIFO empty
			while((SSI1_SR_R&SSI_SR_BSY)==SSI_SR_BSY){};
			DC_SSI1 = DC_COMMAND;
			SSI1_DR_R = message;
			// wait until SSI2 not busy/transmit FIFO empty
			while((SSI1_SR_R&SSI_SR_BSY)==SSI_SR_BSY){};
		}
		else
		{
			// wait until transmit FIFO not full
			while((SSI1_SR_R&SSI_SR_TNF)==0){};
			DC_SSI1 = DC_DATA_SSI1;
			SSI1_DR_R = message;
		}
		break;
		}
	case SSI2:
		{
		if(type == COMMAND)
		{
			// wait until SSI2 not busy/transmit FIFO empty
			while((SSI2_SR_R&SSI_SR_BSY)==SSI_SR_BSY){};
			DC_SSI2 = DC_COMMAND;
			SSI2_DR_R = message;
			// wait until SSI2 not busy/transmit FIFO empty
			while((SSI2_SR_R&SSI_SR_BSY)==SSI_SR_BSY){};
		}
		else
		{
			// wait until transmit FIFO not full
			while((SSI2_SR_R&SSI_SR_TNF)==0){};
			DC_SSI2 = DC_DATA_SSI2;
			SSI2_DR_R = message;
		}
		break;
	}
	case SSI3:
	{
		if(type == COMMAND)
		{
			// wait until SSI3 not busy/transmit FIFO empty
			while((SSI3_SR_R&SSI_SR_BSY)==SSI_SR_BSY){};
			DC_SSI3 = DC_COMMAND;
			SSI3_DR_R = message;
			// wait until SSI2 not busy/transmit FIFO empty
			while((SSI3_SR_R&SSI_SR_BSY)==SSI_SR_BSY){};
		}
		else
		{
			// wait until transmit FIFO not full
			while((SSI3_SR_R&SSI_SR_TNF)==0){};
			DC_SSI3 = DC_DATA_SSI3;
			SSI3_DR_R = message;
		}
		break;
		}
	}
}

/**
 * Writes a character on the screen. Available for English and Spanish.
 */
void char_write(char character,short SSI)
{
	if(character>='A'&&character<='Z')
	{
		switch(character)
		{
			case 'A':
			{
				//A
				lcd_write(DATA,0xF8,SSI);
				lcd_write(DATA,0x24,SSI);
				lcd_write(DATA,0x22,SSI);
				lcd_write(DATA,0x24,SSI);
				lcd_write(DATA,0xF8,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'B':
			{
				//B
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x6C,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'C':
			{
				//C
				lcd_write(DATA,0x7C,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x44,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'D':
			{
				//D
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x44,SSI);
				lcd_write(DATA,0x38,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'E':
			{
				//E
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'F':
			{
				//F
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x12,SSI);
				lcd_write(DATA,0x12,SSI);
				lcd_write(DATA,0x02,SSI);
				lcd_write(DATA,0x02,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'G':
			{
				//G
				lcd_write(DATA,0x7C,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x66,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'H':
			{
				//H
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x10,SSI);
				lcd_write(DATA,0x10,SSI);
				lcd_write(DATA,0x10,SSI);
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'I':
			{
				//I
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'J':
			{
				//J
				lcd_write(DATA,0x70,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x7E,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'K':
			{
				//K
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x10,SSI);
				lcd_write(DATA,0x28,SSI);
				lcd_write(DATA,0x44,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'L':
			{
				//L
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'M':
			{
				//M
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x04,SSI);
				lcd_write(DATA,0x08,SSI);
				lcd_write(DATA,0x04,SSI);
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'N':
			{
				//N
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x08,SSI);
				lcd_write(DATA,0x10,SSI);
				lcd_write(DATA,0x20,SSI);
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}

			case 'O':
			{
				//O
				lcd_write(DATA,0x7C,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0x7C,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'P':
			{
				//P
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x12,SSI);
				lcd_write(DATA,0x12,SSI);
				lcd_write(DATA,0x12,SSI);
				lcd_write(DATA,0x0C,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'Q':
			{
				//Q
				lcd_write(DATA,0x7C,SSI);
				lcd_write(DATA,0x82,SSI);
				lcd_write(DATA,0xA2,SSI);
				lcd_write(DATA,0xC2,SSI);
				lcd_write(DATA,0xFC,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'R':
			{
				//R
				lcd_write(DATA,0xFC,SSI);
				lcd_write(DATA,0x32,SSI);
				lcd_write(DATA,0x32,SSI);
				lcd_write(DATA,0x52,SSI);
				lcd_write(DATA,0x8C,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'S':
			{
				//S
				lcd_write(DATA,0x8C,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x62,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'T':
			{
				//T
				lcd_write(DATA,0x02,SSI);
				lcd_write(DATA,0x02,SSI);
				lcd_write(DATA,0xFE,SSI);
				lcd_write(DATA,0x02,SSI);
				lcd_write(DATA,0x02,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'U':
			{
				//U
				lcd_write(DATA,0x7E,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x7E,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'V':
			{
				//V
				lcd_write(DATA,0x3E,SSI);
				lcd_write(DATA,0x40,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x40,SSI);
				lcd_write(DATA,0x3E,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'W':
			{
				//W
				lcd_write(DATA,0x7E,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x40,SSI);
				lcd_write(DATA,0x80,SSI);
				lcd_write(DATA,0x7E,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'X':
			{
				//X
				lcd_write(DATA,0xC6,SSI);
				lcd_write(DATA,0x28,SSI);
				lcd_write(DATA,0x10,SSI);
				lcd_write(DATA,0x28,SSI);
				lcd_write(DATA,0xC6,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'Y':
			{
				//Y
				lcd_write(DATA,0x06,SSI);
				lcd_write(DATA,0x08,SSI);
				lcd_write(DATA,0xF0,SSI);
				lcd_write(DATA,0x08,SSI);
				lcd_write(DATA,0x06,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
			case 'Z':
			{
				//Z
				lcd_write(DATA,0xD2,SSI);
				lcd_write(DATA,0xB2,SSI);
				lcd_write(DATA,0x92,SSI);
				lcd_write(DATA,0x9A,SSI);
				lcd_write(DATA,0x96,SSI);
				lcd_write(DATA,0x00,SSI);
				break;
			}
		}
	}
	else
	{
		if(character>='a'&&character<='z')
		{
			switch(character)
			{
				case 'a':
				{
					//a
					lcd_write(DATA,0x40,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0x70,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'b':
				{
					//b
					lcd_write(DATA,0xFE,SSI);
					lcd_write(DATA,0x90,SSI);
					lcd_write(DATA,0x90,SSI);
					lcd_write(DATA,0x90,SSI);
					lcd_write(DATA,0x60,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'c':
				{
					//c
					lcd_write(DATA,0x70,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x50,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'd':
				{
					//d
					lcd_write(DATA,0x60,SSI);
					lcd_write(DATA,0x90,SSI);
					lcd_write(DATA,0x90,SSI);
					lcd_write(DATA,0x90,SSI);
					lcd_write(DATA,0xFE,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'e':
				{
					//e
					lcd_write(DATA,0x70,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0x90,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'f':
				{
					//f
					lcd_write(DATA,0x20,SSI);
					lcd_write(DATA,0xF8,SSI);
					lcd_write(DATA,0x24,SSI);
					lcd_write(DATA,0x04,SSI);
					lcd_write(DATA,0x04,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'g':
				{
					//g
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0x94,SSI);
					lcd_write(DATA,0x94,SSI);
					lcd_write(DATA,0x94,SSI);
					lcd_write(DATA,0x7C,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'h':
				{
					//h
					lcd_write(DATA,0xFE,SSI);
					lcd_write(DATA,0x20,SSI);
					lcd_write(DATA,0x10,SSI);
					lcd_write(DATA,0x10,SSI);
					lcd_write(DATA,0xE0,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'i':
				{
					//i
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0xFA,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'j':
				{
					//j
					lcd_write(DATA,0x40,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x7A,SSI);
					lcd_write(DATA,0x00,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'k':
				{
					//k
					lcd_write(DATA,0xFE,SSI);
					lcd_write(DATA,0x10,SSI);
					lcd_write(DATA,0x28,SSI);
					lcd_write(DATA,0x44,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'l':
				{
					//l
					lcd_write(DATA,0x00,SSI);
					lcd_write(DATA,0x82,SSI);
					lcd_write(DATA,0xFE,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x00,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'm':
				{
					//m
					lcd_write(DATA,0xF0,SSI);
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0xF0,SSI);
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0xF0,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'n':
				{
					//n
					lcd_write(DATA,0xF8,SSI);
					lcd_write(DATA,0x10,SSI);
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0xF0,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'o':
				{
					//o
					lcd_write(DATA,0x70,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x70,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'p':
				{
					//p
					lcd_write(DATA,0xF8,SSI);
					lcd_write(DATA,0x48,SSI);
					lcd_write(DATA,0x48,SSI);
					lcd_write(DATA,0x48,SSI);
					lcd_write(DATA,0x30,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'q':
				{
					//q
					lcd_write(DATA,0x30,SSI);
					lcd_write(DATA,0x48,SSI);
					lcd_write(DATA,0x48,SSI);
					lcd_write(DATA,0x48,SSI);
					lcd_write(DATA,0xF8,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'r':
				{
					//r
					lcd_write(DATA,0xF8,SSI);
					lcd_write(DATA,0x10,SSI);
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0x10,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 's':
				{
					//s
					lcd_write(DATA,0x90,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0x48,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 't':
				{
					//t
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0x7C,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x00,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'u':
				{
					//u
					lcd_write(DATA,0x78,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0xF8,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'v':
				{
					//v
					lcd_write(DATA,0x38,SSI);
					lcd_write(DATA,0x40,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x40,SSI);
					lcd_write(DATA,0x38,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'w':
				{
					//w
					lcd_write(DATA,0x78,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x40,SSI);
					lcd_write(DATA,0x80,SSI);
					lcd_write(DATA,0x78,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'x':
				{
					//x
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x50,SSI);
					lcd_write(DATA,0x20,SSI);
					lcd_write(DATA,0x50,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'y':
				{
					//y
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x50,SSI);
					lcd_write(DATA,0x20,SSI);
					lcd_write(DATA,0x10,SSI);
					lcd_write(DATA,0x08,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
				case 'z':
				{
					//z
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0xC8,SSI);
					lcd_write(DATA,0xA8,SSI);
					lcd_write(DATA,0x98,SSI);
					lcd_write(DATA,0x88,SSI);
					lcd_write(DATA,0x00,SSI);
					break;
				}
			}
		}
		else
		{
			if(character>='á'&&character<='ú')
			{
				switch(character)
				{
					case 'á':
					{
						//á
						lcd_write(DATA,0x40,SSI);
						lcd_write(DATA,0xA8,SSI);
						lcd_write(DATA,0xAA,SSI);
						lcd_write(DATA,0xA9,SSI);
						lcd_write(DATA,0x70,SSI);
						lcd_write(DATA,0x00,SSI);
						break;
					}
					case 'é':
					{
						//é
						lcd_write(DATA,0x70,SSI);
						lcd_write(DATA,0xA8,SSI);
						lcd_write(DATA,0xAA,SSI);
						lcd_write(DATA,0xA9,SSI);
						lcd_write(DATA,0x90,SSI);
						lcd_write(DATA,0x00,SSI);
						break;
					}
					case 'í':
					{
						//í
						lcd_write(DATA,0x80,SSI);
						lcd_write(DATA,0x90,SSI);
						lcd_write(DATA,0xF4,SSI);
						lcd_write(DATA,0x82,SSI);
						lcd_write(DATA,0x80,SSI);
						lcd_write(DATA,0x00,SSI);
						break;
					}
					case 'ó':
					{
						//ó
						lcd_write(DATA,0x70,SSI);
						lcd_write(DATA,0x88,SSI);
						lcd_write(DATA,0x8A,SSI);
						lcd_write(DATA,0x89,SSI);
						lcd_write(DATA,0x70,SSI);
						lcd_write(DATA,0x00,SSI);
						break;
					}
					case 'ú':
					{
						//ú
						lcd_write(DATA,0x78,SSI);
						lcd_write(DATA,0x80,SSI);
						lcd_write(DATA,0x82,SSI);
						lcd_write(DATA,0x81,SSI);
						lcd_write(DATA,0xF8,SSI);
						lcd_write(DATA,0x00,SSI);
						break;
					}
					case 'ñ':
					{
						//ñ
						lcd_write(DATA,0xF4,SSI);
						lcd_write(DATA,0x22,SSI);
						lcd_write(DATA,0x16,SSI);
						lcd_write(DATA,0x14,SSI);
						lcd_write(DATA,0xE2,SSI);
						lcd_write(DATA,0x00,SSI);
						break;
					}

				}
			}
			else
			{
				if(character>='0'&&character<='9')
				{
					switch(character)
					{
						case '0':
						{
							//O
							lcd_write(DATA,0x7C,SSI);
							lcd_write(DATA,0x82,SSI);
							lcd_write(DATA,0x82,SSI);
							lcd_write(DATA,0x82,SSI);
							lcd_write(DATA,0x7C,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '1':
						{
							//1
							lcd_write(DATA,0x88,SSI);
							lcd_write(DATA,0x84,SSI);
							lcd_write(DATA,0xFE,SSI);
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '2':
						{
							//2
							lcd_write(DATA,0x84,SSI);
							lcd_write(DATA,0xC2,SSI);
							lcd_write(DATA,0xA2,SSI);
							lcd_write(DATA,0x92,SSI);
							lcd_write(DATA,0x8C,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '3':
						{
							//3
							lcd_write(DATA,0x44,SSI);
							lcd_write(DATA,0x82,SSI);
							lcd_write(DATA,0x92,SSI);
							lcd_write(DATA,0x92,SSI);
							lcd_write(DATA,0x6C,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '4':
						{
							//4
							lcd_write(DATA,0x20,SSI);
							lcd_write(DATA,0x30,SSI);
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x24,SSI);
							lcd_write(DATA,0xFE,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '5':
						{
							//5
							lcd_write(DATA,0x1E,SSI);
							lcd_write(DATA,0x1A,SSI);
							lcd_write(DATA,0x1A,SSI);
							lcd_write(DATA,0x1A,SSI);
							lcd_write(DATA,0x72,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '6':
						{
							//6
							lcd_write(DATA,0x7C,SSI);
							lcd_write(DATA,0xA4,SSI);
							lcd_write(DATA,0x92,SSI);
							lcd_write(DATA,0x92,SSI);
							lcd_write(DATA,0x64,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '7':
						{
							//7
							lcd_write(DATA,0x82,SSI);
							lcd_write(DATA,0x42,SSI);
							lcd_write(DATA,0x22,SSI);
							lcd_write(DATA,0x12,SSI);
							lcd_write(DATA,0x0E,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '8':
						{
							//8
							lcd_write(DATA,0x44,SSI);
							lcd_write(DATA,0xAA,SSI);
							lcd_write(DATA,0x92,SSI);
							lcd_write(DATA,0xAA,SSI);
							lcd_write(DATA,0x44,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '9':
						{
							//9
							lcd_write(DATA,0x0C,SSI);
							lcd_write(DATA,0x12,SSI);
							lcd_write(DATA,0x12,SSI);
							lcd_write(DATA,0x0A,SSI);
							lcd_write(DATA,0xFC,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
					}
				}
				else
				{
					//Signos y demás
					switch(character)
					{
						case 'Ñ':
						{
							//Ñ
							lcd_write(DATA,0xFA,SSI);
							lcd_write(DATA,0x09,SSI);
							lcd_write(DATA,0x13,SSI);
							lcd_write(DATA,0x12,SSI);
							lcd_write(DATA,0x22,SSI);
							lcd_write(DATA,0xF9,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case 'ü':
						{
							//u
							lcd_write(DATA,0x78,SSI);
							lcd_write(DATA,0x82,SSI);
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x82,SSI);
							lcd_write(DATA,0xF8,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case' ':
						{
							//' '
							lcd_write(DATA,0x00,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '¡':
						{
							//¡
							lcd_write(DATA,0xFA,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '!':
						{
							//!
							lcd_write(DATA,0xBE,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '?':
						{
							//?
							lcd_write(DATA,0x04,SSI);
							lcd_write(DATA,0x02,SSI);
							lcd_write(DATA,0xA2,SSI);
							lcd_write(DATA,0x12,SSI);
							lcd_write(DATA,0x0C,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '¿':
						{
							//¿
							lcd_write(DATA,0x60,SSI);
							lcd_write(DATA,0x90,SSI);
							lcd_write(DATA,0x8A,SSI);
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x40,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '|':
						{
							//|
							lcd_write(DATA,0xFE,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '"':
						{
							//"
							lcd_write(DATA,0x06,SSI);
							lcd_write(DATA,0x00,SSI);
							lcd_write(DATA,0x06,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '·':
						{
							//·
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '#':
						{
							//#
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x7C,SSI);
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x7C,SSI);
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '$':
						{
							//$
							lcd_write(DATA,0x48,SSI);
							lcd_write(DATA,0x54,SSI);
							lcd_write(DATA,0xFE,SSI);
							lcd_write(DATA,0x54,SSI);
							lcd_write(DATA,0x24,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '~':
						{
							//~
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x08,SSI);
							lcd_write(DATA,0x18,SSI);
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x08,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '%':
						{
							//%
							lcd_write(DATA,0x04,SSI);
							lcd_write(DATA,0x4A,SSI);
							lcd_write(DATA,0x24,SSI);
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x08,SSI);
							lcd_write(DATA,0x24,SSI);
							lcd_write(DATA,0x52,SSI);
							lcd_write(DATA,0x20,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '€':
						{
							//€
							lcd_write(DATA,0x18,SSI);
							lcd_write(DATA,0x7E,SSI);
							lcd_write(DATA,0x99,SSI);
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x42,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '&':
						{
							//&
							lcd_write(DATA,0x44,SSI);
							lcd_write(DATA,0xAA,SSI);
							lcd_write(DATA,0x92,SSI);
							lcd_write(DATA,0xAA,SSI);
							lcd_write(DATA,0x44,SSI);
							lcd_write(DATA,0xA0,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '¬':
						{
							//¬
							lcd_write(DATA,0x08,SSI);
							lcd_write(DATA,0x08,SSI);
							lcd_write(DATA,0x18,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '/':
						{
							// /
							lcd_write(DATA,0x40,SSI);
							lcd_write(DATA,0x20,SSI);
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x08,SSI);
							lcd_write(DATA,0x04,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '(':
						{
							//(
							lcd_write(DATA,0x3C,SSI);
							lcd_write(DATA,0x42,SSI);
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case ')':
						{
							//)
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x42,SSI);
							lcd_write(DATA,0x3C,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '=':
						{
							//=
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '\'':
						{
							//'
							lcd_write(DATA,0x06,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '-':
						{
							//-
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '+':
						{
							//+
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x38,SSI);
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '*':
						{
							//*
							lcd_write(DATA,0x54,SSI);
							lcd_write(DATA,0x38,SSI);
							lcd_write(DATA,0x7C,SSI);
							lcd_write(DATA,0x38,SSI);
							lcd_write(DATA,0x54,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '@':
						{
							//@
							lcd_write(DATA,0x38,SSI);
							lcd_write(DATA,0x44,SSI);
							lcd_write(DATA,0xBA,SSI);
							lcd_write(DATA,0xAA,SSI);
							lcd_write(DATA,0xBA,SSI);
							lcd_write(DATA,0xA4,SSI);
							lcd_write(DATA,0x18,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '>':
						{
							//>
							lcd_write(DATA,0x44,SSI);
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '<':
						{
							//<
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x44,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '[':
						{
							//[
							lcd_write(DATA,0xFE,SSI);
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case ']':
						{
							//]
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0xFE,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '{':
						{
							//{
							lcd_write(DATA,0x18,SSI);
							lcd_write(DATA,0x66,SSI);
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '}':
						{
							//}
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x81,SSI);
							lcd_write(DATA,0x66,SSI);
							lcd_write(DATA,0x18,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case ',':
						{
							//,
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x40,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case ';':
						{
							//;
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x50,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case ':':
						{
							//:
							lcd_write(DATA,0x28,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '.':
						{
							//.
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '_':
						{
							//_
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x80,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case 'º':
						{
							lcd_write(DATA,0x14,SSI);
							lcd_write(DATA,0x1A,SSI);
							lcd_write(DATA,0x14,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case 'ª':
						{
							lcd_write(DATA,0x52,SSI);
							lcd_write(DATA,0x6A,SSI);
							lcd_write(DATA,0x6A,SSI);
							lcd_write(DATA,0x7C,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
						case '\\':
						{
							//\
							lcd_write(DATA,0x04);
							lcd_write(DATA,0x08,SSI);
							lcd_write(DATA,0x10,SSI);
							lcd_write(DATA,0x20,SSI);
							lcd_write(DATA,0x40,SSI);
							lcd_write(DATA,0x00,SSI);
							break;
						}
					}
				}
			}
		}
	}
}


/*
 * Initializes screen, setting temperature coefficient, contrast and other parameters
 */
void initialize_screen(short backlight,short SSI)
{
	lcd_write(COMMAND, 0x21,SSI);              	// chip active; horizontal addressing mode (V = 0); use extended instruction set (H = 1)
											// set LCD Vop (contrast), which may require some tweaking:
	lcd_write(COMMAND, CONTRAST,SSI);          	// 0xB1 for 3.3V red SparkFun, 0xB8 for 3.3V blue SparkFun, 0xBF if your display is too dark or 0x80 to 0xFF if experimenting
	lcd_write(COMMAND, 0x04,SSI);              	// set temp coefficient
	lcd_write(COMMAND, 0x14,SSI);              	// LCD bias mode 1:48: try 0x13 or 0x14
	lcd_write(COMMAND, 0x20,SSI);              	// we must send 0x20 before modifying the display control mode
	lcd_write(COMMAND, 0x0C,SSI);              	// Display control (0x0C for normal mode, 0x0D for inverse mode)

	switch(SSI)
	{
		case SSI0:
		{
			switch(backlight)
			{
				case BACKLIGHT_ON:
				{
					GPIO_PORTA_DATA_R&=~0x10;				//Screen's light on
					break;
				}
				case BACKLIGHT_OFF:
				{
					GPIO_PORTA_DATA_R|=0x10;				//Screen's light off
					break;
				}
			}
			break;
		}
		case SSI1:
		{
			switch(backlight)
			{
				case BACKLIGHT_ON:
				{
					GPIO_PORTE_DATA_R&=~0x08; //Screen's light on
					break;
				}
				case BACKLIGHT_OFF:
				{
					GPIO_PORTE_DATA_R|=0x08; //Screen's light off
					break;
				}
			}
			break;
		}
		case SSI2:
		{
			switch(backlight)
			{
				case BACKLIGHT_ON:
				{
					GPIO_PORTB_DATA_R&=~0x40;				//Screen's light on
					break;
				}
				case BACKLIGHT_OFF:
				{
					GPIO_PORTB_DATA_R|=0x40;				//Screen's light off
					break;
				}
			}
			break;
		}
		case SSI3:
		{
			switch(backlight)
			{
				case BACKLIGHT_ON:
				{
					GPIO_PORTD_DATA_R&=~0x04;				//Screen's light on
					break;
				}
				case BACKLIGHT_OFF:
				{
					GPIO_PORTD_DATA_R|=0x04;				//Screen's light off
					break;
				}
			}
			break;
		}
	}
}

/**
 * Sets backlight on
 */
void enable_backlight(short SSI)
{
	switch(SSI)
	{
		case SSI0:
		{
			GPIO_PORTA_DATA_R&=~0x10;
			break;
		}
		case SSI1:
		{
			GPIO_PORTE_DATA_R&=~0x08;
			break;
		}
		case SSI2:
		{
			GPIO_PORTB_DATA_R&=~0x40;
			break;
		}
		case SSI3:
		{
			GPIO_PORTD_DATA_R&=~0x04;
			break;
		}
}

/**
 * Sets backlight off
 */
void disable_backlight(short SSI)
{
	switch(SSI)
	{
		case SSI0:
		{
			GPIO_PORTA_DATA_R|=0x10;
			break;
		}
		case SSI1:
		{
			GPIO_PORTE_DATA_R|=0x08;
			break;
		}
		case SSI2:
		{
			GPIO_PORTB_DATA_R|=0x40;
			break;
		}
		case SSI3:
		{
			GPIO_PORTD_DATA_R|=0x04;
			break;
		}
}


/**
 * In case you are not willing to send commands to set position, for example, within the same block, you can use this as a custom space.
 */
void clear_columns(char ncolumns,short SSI)
{
	char i;
	for(i=0;i<ncolumns;i++)
	{
		lcd_write(DATA,0x00,SSI);
	}
}

/**
 * Fills the whole screen, leaving all pixels black unless screen is set in inverse mode
 */
void fill_screen(short SSI)
{
	char i;
	for(i=0;i<MAX_X*MAX_Y;i++)
	{
		lcd_write(DATA,0xFF,SSI);
	}
}

/**
 * Writes text on the screen with the alignment selected
 */
void screen_write(char string_to_write[],short alignment,short SSI)
{
	unsigned int word_length=0;
	short times=0;
	int max_x_position, x_position,y_position;
	unsigned int lines=0;
	int i=0,j=0,y_pos=0;
	if((alignment!=ALIGN_LEFT_TOP)&&(alignment!=ALIGN_CENTRE_TOP)&&(alignment!=ALIGN_RIGHT_TOP))
	{
		while(string_to_write[i]!='\0')
		{
			if(string_to_write[i]=='\n')
			{
				lines++;
			}
			i++;
		}
	}
	if((alignment==ALIGN_LEFT_CENTRE)||(alignment==ALIGN_CENTRE_CENTRE)||(alignment==ALIGN_RIGHT_CENTRE))
	{
		y_pos=set_Y_position_centre(lines,SSI);
	}
	else
	{
		if((alignment==ALIGN_LEFT_BOTTOM)||(alignment==ALIGN_CENTRE_BOTTOM)||(alignment==ALIGN_RIGHT_BOTTOM))
		{
			y_pos=set_Y_position_bottom(lines,SSI);
		}
		else
		{
			lcd_write(COMMAND,0x40,SSI);
		}
	}
	i=0;
	//Set (0,0)
	lcd_write(COMMAND,0x80, SSI);
	while(string_to_write[i]!='\0')
	{
		while(string_to_write[i]!='\0'&&string_to_write[i]!='\n'&&word_length<84)
		{
			word_length=word_length+get_character_length(string_to_write[i]);
			i++;
		}
		switch (alignment)
		{
			case ALIGN_LEFT_TOP:
			{
				break;
			}
			case ALIGN_RIGHT_TOP:
			{
				lcd_write(COMMAND,0xD3-word_length,SSI);
				break;
			}
			case ALIGN_CENTRE_TOP:
			{
				lcd_write(COMMAND,(0xA9)-(word_length/2),SSI);
				break;
			}
			case ALIGN_LEFT_CENTRE:
			{
				lcd_write(COMMAND,0x80,SSI);
				break;
			}
			case ALIGN_RIGHT_CENTRE:
			{
				lcd_write(COMMAND,0xD3-word_length,SSI);
				break;
			}
			case ALIGN_CENTRE_CENTRE:
			{
				lcd_write(COMMAND,(0xA9)-(word_length/2),SSI);
				break;
			}
			case ALIGN_LEFT_BOTTOM:
			{
				lcd_write(COMMAND,0x80,SSI);
				break;
			}
			case ALIGN_RIGHT_BOTTOM:
			{
				lcd_write(COMMAND,0xD3-word_length,SSI);
				break;
			}
			case ALIGN_CENTRE_BOTTOM:
			{
				lcd_write(COMMAND,(0xA9)-(word_length/2),SSI);
				break;
			}
			case ALIGN_RANDOM:
			{	//This case is for one line text such as "welcome"
				srand(time(NULL));
				y_position=rand()%5;
				lcd_write(COMMAND,0x40+y_position,SSI);
				max_x_position=84-word_length;
				srand(time(NULL));
				x_position=(rand()%(max_x_position));
				lcd_write(COMMAND,0x80+x_position,SSI);
				break;
			}
		}
		while(j<i)
		{
			char_write(string_to_write[j],SSI);
			j++;
		}
		if(string_to_write[i]!='\0')
		{
			i++;
		}
		word_length=0;
		lcd_write(COMMAND,0x80,SSI);
		if(y_pos==5)
		{
			y_pos=0;
		}
		else
		{
			y_pos++;
		}
		lcd_write(COMMAND,0x40|y_pos,SSI);
	}
}

int set_Y_position_bottom(int lines,short SSI)
{
	int y_pos;
	switch(lines)
	{
		case 0:
		{
			lcd_write(COMMAND,0x45,SSI);
			y_pos=5;
			break;
		}
		case 1:
		{
			lcd_write(COMMAND,0x44,SSI);
			y_pos=4;
			break;
		}
		case 2:
		{
			lcd_write(COMMAND,0x43,SSI);
			y_pos=3;
			break;
		}
		case 3:
		{
			lcd_write(COMMAND,0x42,SSI);
			y_pos=2;
			break;
		}
		case 4:
		{
			lcd_write(COMMAND,0x41,SSI);
			y_pos=1;
			break;
		}
		case 5:
		{
			lcd_write(COMMAND,0x40,SSI);
			y_pos=0;
			break;
		}
	}
	return y_pos;
}

int set_Y_position_centre(int lines,short SSI)
{
	int y_pos;
	switch(lines)
	{
		case 0:
		{
			lcd_write(COMMAND,0x42,SSI);
			y_pos=2;
			break;
		}
		case 1:
		{
			lcd_write(COMMAND,0x42,SSI);
			y_pos=2;
			break;
		}
		case 2:
		{
			lcd_write(COMMAND,0x42,SSI);
			y_pos=2;
			break;
		}
		case 3:
		{
			lcd_write(COMMAND,0x41,SSI);
			y_pos=1;
			break;
		}
		case 4:
		{
			lcd_write(COMMAND,0x41,SSI);
			y_pos=1;
			break;
		}
		case 5:
		{
			lcd_write(COMMAND,0x40,SSI);
			y_pos=0;
			break;
		}
	}
	return y_pos;
}

void startSSI0()//This one works
{
	  volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x00000001;   		//  activate clock for Port A
	  SYSCTL_RCGCSSI_R|=0x1;		  		//  activate clock for SSI0
	  delay = SYSCTL_RCGC2_R;         		//  allow time for clock to stabilize
	  GPIO_PORTA_DIR_R |= 0xD0;             // make PA6,7 out
	  GPIO_PORTA_AFSEL_R |= 0x2C;           // enable alt funct on PA2,3,5
	  GPIO_PORTA_AFSEL_R &= ~0xC0;          // disable alt funct on PA6,7
	  GPIO_PORTA_DEN_R |= 0xFC;             // enable digital I/O on PA2,3,5,6,7
	                                        // configure PA2,3,5 as SSI
	  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFF0F00FF)+0x00202200;
	                                        // configure PA6,7 as GPIO
	  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0x00FFFFFF)+0x00000000;
	  GPIO_PORTA_AMSEL_R &= ~0xFC;          // disable analog functionality on PA2,3,5,6,7
	  //SYSCTL_RCGCSSI_R|=0x1;		  // 2) activate clock for SSI0
	  SSI0_CR1_R&=~SSI_CR1_SSE;		  // 3)Disable SSI while configuring it
	  SSI0_CR1_R&=~SSI_CR1_MS;		  // 4) Set as Master
	  SSI0_CC_R|=SSI_CC_CS_M; // 5) Configure clock source
	  SSI0_CC_R|=SSI_CC_CS_SYSPLL; // 5) Configure clock source
	  SSI0_CC_R|=SSI_CPSR_CPSDVSR_M;// 6) Configure prescale divisor
	  SSI0_CPSR_R = (SSI0_CPSR_R&~SSI_CPSR_CPSDVSR_M)+2; // must be even number
	  SSI0_CR0_R |=0x7000;
	  SSI0_CR0_R &= ~(SSI_CR0_SPH | SSI_CR0_SPO);
	  //SSI0_CPSR_R = (SSI0_CPSR_R&~SSI_CR0_SCR_M)+7; // must be even number
	  SSI0_CR0_R = (SSI0_CR0_R&~SSI_CR0_FRF_M)+SSI_CR0_FRF_MOTO;
	                                        // DSS = 8-bit data
	  SSI0_CR0_R = (SSI0_CR0_R&~SSI_CR0_DSS_M)+SSI_CR0_DSS_8;
	  SSI0_CR1_R|=SSI_CR1_SSE;		  // 3)Enable SSI
	  RESET = RESET_LOW;                    // reset the LCD to a known state
	  for(delay=0; delay<10; delay=delay+1);// delay minimum 100 ns
	  RESET = RESET_HIGH;                   // negative logic

}

void startSSI1()
{
	  volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x30;   		// activate clock for Port E and Port F
	  SYSCTL_RCGC1_R |= SYSCTL_RCGC1_SSI1;
	  SYSCTL_RCGCSSI_R|=SYSCTL_RCGCSSI_R1;	// activate clock for SSI1
	  delay = SYSCTL_RCGC2_R;         		// allow time for clock to stabilize

	  GPIO_PORTF_LOCK_R=0x4C4F434B;
	  GPIO_PORTF_CR_R=0x01;
	  GPIO_PORTF_DIR_R |= 0x11;             // make PF0 and PF4 out
	  GPIO_PORTF_AFSEL_R |= 0x0E;           // enable alt funct on PF1, PF2 and PF3
	  GPIO_PORTF_AFSEL_R &= ~0xF1;          // disable alt funct on PF0
	  GPIO_PORTF_DEN_R |= 0x1F;             // enable digital I/O on PF0,PF1,PF2,PF3 and PF4
	                                        // configure PF1, PF2 and PF3 as SSI
	  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0x0000FFF0)+0x00002220;
	                                        // configure PF4 and PF5 as GPIO
	  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFF00FFFF)+0x00000000;
	  GPIO_PORTF_AMSEL_R &= ~0x3E;          // disable analog functionality on PF1,PF2,PF3,PF4 and PF5
	  SSI1_CR1_R&=~SSI_CR1_SSE;		  		// Disable SSI while configuring it
	  SSI1_CR1_R&=~SSI_CR1_MS;		  		// Set as Master
	  SSI1_CC_R|=SSI_CC_CS_M; 				// Configure clock source
	  SSI1_CC_R|=SSI_CC_CS_SYSPLL; 			// Configure clock source
	  SSI1_CC_R|=SSI_CPSR_CPSDVSR_M;		// Configure prescale divisor
	  SSI1_CPSR_R = (SSI1_CPSR_R&~SSI_CPSR_CPSDVSR_M)+2; // must be even number
	  SSI1_CR0_R |=0x7000;
	  SSI1_CR0_R &= ~(SSI_CR0_SPH | SSI_CR0_SPO);
	  //SSI0_CPSR_R = (SSI0_CPSR_R&~SSI_CR0_SCR_M)+7; // must be even number
	  SSI1_CR0_R = (SSI1_CR0_R&~SSI_CR0_FRF_M)+SSI_CR0_FRF_MOTO;
	                                        // DSS = 8-bit data
	  SSI1_CR0_R = (SSI1_CR0_R&~SSI_CR0_DSS_M)+SSI_CR0_DSS_8;
	  SSI1_CR1_R|=SSI_CR1_SSE;		  		// Enable SSI

	  GPIO_PORTE_DIR_R |= 0x06;             // make PE1 and PE2 out
	  GPIO_PORTE_AFSEL_R &= ~0x06;          // disable alt funct on PE3
	  GPIO_PORTE_DEN_R |= 0x06;             // enable digital I/O on PE3
	  GPIO_PORTE_AMSEL_R &= ~0x06;          // disable analog functionality on PE3

	  RESET_SSI1 = RESET_LOW;                    // reset the LCD to a known state
	  for(delay=0; delay<10; delay=delay+1);// delay minimum 100 ns
	  RESET_SSI1 = RESET_HIGH_SSI1;                   // negative logic

}

void startSSI2()
{
	  volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x00000002;   //  activate clock for Port B

	  SYSCTL_RCGCSSI_R|=SYSCTL_RCGCSSI_R2;	// activate clock for SSI2
	  delay = SYSCTL_RCGC2_R;         //    allow time for clock to stabilize
	  GPIO_PORTB_LOCK_R=0x4C4F434B;
	  GPIO_PORTB_CR_R=0x0C;
	  GPIO_PORTB_DIR_R |= 0x4C;             // make PB2, PB3 and PB6 out
	  GPIO_PORTB_AFSEL_R |= 0xB0;           // enable alt funct on PB4,PB5 and PB7
	  GPIO_PORTB_AFSEL_R &= ~0xB0;          // disable alt funct on PB6
	  GPIO_PORTB_DEN_R |= 0xFC;             // enable digital I/O on PB2,PB3,PB4,PB5,PB6 and PB7
	                                        // configure PB4,PB5 and PB7 as SSI
	  GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0x0F00FFFF)+0x20220000;
	                                        // configure PB3 and PB6 as GPIO
	  GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xF0FF00FF)+0x00000000;
	  GPIO_PORTB_AMSEL_R &= ~0xFC;          // disable analog functionality from PB2 to PB7
	  SSI2_CR1_R&=~SSI_CR1_SSE;		  // Disable SSI while configuring it
	  SSI2_CR1_R&=~SSI_CR1_MS;		  //  Set as Master
	  SSI2_CC_R|=SSI_CC_CS_M; //  Configure clock source
	  SSI2_CC_R|=SSI_CC_CS_SYSPLL; //  Configure clock source
	  SSI2_CC_R|=SSI_CPSR_CPSDVSR_M;//  Configure prescale divisor
	  SSI2_CPSR_R = (SSI2_CPSR_R&~SSI_CPSR_CPSDVSR_M)+2; // must be even number
	  SSI2_CR0_R |=0x7000;
	  SSI2_CR0_R &= ~(SSI_CR0_SPH | SSI_CR0_SPO);
	  //SSI0_CPSR_R = (SSI0_CPSR_R&~SSI_CR0_SCR_M)+7; // must be even number
	  SSI2_CR0_R = (SSI2_CR0_R&~SSI_CR0_FRF_M)+SSI_CR0_FRF_MOTO;
	                                        // DSS = 8-bit data
	  SSI2_CR0_R = (SSI2_CR0_R&~SSI_CR0_DSS_M)+SSI_CR0_DSS_8;
	  SSI2_CR1_R|=SSI_CR1_SSE;		  // 3)Enable SSI
	  RESET_SSI2 = RESET_LOW;                    // reset the LCD to a known state
	  for(delay=0; delay<10; delay=delay+1);// delay minimum 100 ns
	  RESET_SSI2 = RESET_HIGH_SSI2;                   // negative logic

}

/*
 * It works with the following connection
 * PD0 -> SSI3CLK
 * PD1 -> SSI3FSS
 * PD2 -> Backlight
 * PD3 -> SSI3TX
 * PD6 -> DC
 * PD7 -> Reset
 */
void startSSI3()
{
	  volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x00000008;   		// activate clock for Port D
	  SYSCTL_RCGC1_R|=SYSCTL_RCGC1_SSI1;	// activate clock for SSI3
	  SYSCTL_RCGCSSI_R|=SYSCTL_RCGCSSI_R3;	// activate clock for SSI3
	  delay = SYSCTL_RCGC2_R;         		// allow time for clock to stabilize
	  GPIO_PORTD_LOCK_R=0x4C4F434B;
	  GPIO_PORTD_CR_R=0x80;
	  GPIO_PORTD_DIR_R |= 0xC4;             // make PD2, PD6 and PD7 out
	  GPIO_PORTD_AFSEL_R |= 0x0B;           // enable alt funct on PD0, PD1 and PD3
	  GPIO_PORTD_AFSEL_R &= ~0xF4;          // disable alt funct on PD2 and from PD4 to PD7
	  GPIO_PORTD_DEN_R |= 0xCF;             // enable digital I/O on PD0, PD1, PD2, PD3, PD6 and PD7
      // configure PD0, PD1 and PD3 as SSI
 GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFFFF0F00)+0x00001011;
      // configure PD2 and from PD4 to PD7 as GPIO
GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0x0000F0FF)+0x00000000;
	                                        // configure PD0, PD1 and PD3 as SSI
	 /* GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFFFF0F00)+0x00002022;
	                                        // configure PD2 and from PD4 to PD7 as GPIO
	  GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0x0000F0FF)+0x00000000;*/
	  GPIO_PORTD_AMSEL_R &= ~0xCF;          // disable analog functionality on PD0, PD1, PD2, PD3, PD6 and PD7
	  SSI3_CR1_R&=~SSI_CR1_SSE;		  		// Disable SSI while configuring it
	  SSI3_CR1_R&=~SSI_CR1_MS;		  		// Set as Master
	  SSI3_CC_R|=SSI_CC_CS_M; 				// Configure clock source
	  SSI3_CC_R|=SSI_CC_CS_SYSPLL; 			// Configure clock source
	  SSI3_CC_R|=SSI_CPSR_CPSDVSR_M;		// Configure prescale divisor
	  SSI3_CPSR_R = (SSI3_CPSR_R&~SSI_CPSR_CPSDVSR_M)+2; // must be even number
	  SSI3_CR0_R |=0x7000;
	  SSI3_CR0_R &= ~(SSI_CR0_SPH | SSI_CR0_SPO);
	  //SSI0_CPSR_R = (SSI0_CPSR_R&~SSI_CR0_SCR_M)+7; // must be even number
	  SSI3_CR0_R = (SSI3_CR0_R&~SSI_CR0_FRF_M)+SSI_CR0_FRF_MOTO;
	                                        // DSS = 8-bit data
	  SSI3_CR0_R = (SSI3_CR0_R&~SSI_CR0_DSS_M)+SSI_CR0_DSS_8;
	  SSI3_CR1_R|=SSI_CR1_SSE;		  // 3)Enable SSI
//
	  /*SYSCTL_RCGC2_R |= 0x00000001;   		//  activate clock for Port A
	  //SYSCTL_RCGCSSI_R|=0x1;		  		//  activate clock for SSI0
	  delay = SYSCTL_RCGC2_R;         		//  allow time for clock to stabilize
	  GPIO_PORTA_DIR_R |= 0xC0;             // make PA6,7 out
	  //GPIO_PORTA_AFSEL_R |= 0x2C;           // enable alt funct on PA2,3,5
	  GPIO_PORTA_AFSEL_R &= ~0xFF;          // disable alt funct on PA6,7
	  GPIO_PORTA_DEN_R |= 0xC0;             // enable digital I/O on PA2,3,5,6,7
	  GPIO_PORTA_AMSEL_R &= ~0xCF;          // disable analog functionality on PD0, PD1, PD2, PD3, PD6 and PD7*/
//
	  RESET_SSI3 = RESET_LOW;                    // reset the LCD to a known state
	  //GPIO_PORTD_DATA_R&=~0x40;
	  for(delay=0; delay<10; delay=delay+1);// delay minimum 100 ns
	  RESET_SSI3 = RESET_HIGH_SSI3;                   // negative logic
	  //GPIO_PORTD_DATA_R|=0x40;
}

unsigned short get_character_length(char character)
{
	//int character_length;
	short character_length;
	if(character>='A'&&character<='Z')
	{
		character_length=6;
	}
	else
	{
		if(character>='a'&&character<='z')
		{
			character_length=6;
		}
		else
		{
			if(character>='á'&&character<='ú')
			{
				switch(character)
				{
					case 'Ñ':
					{
						character_length=7;
						break;
					}
					default:
					{
						character_length=6;
						break;
					}
				}
			}
			else
			{
				if(character>='0'&&character<='9')
				{
					character_length=6;
				}
				else
				{
					//Signos y demás
					switch(character)
					{
						case 'ü':
						{
							character_length=6;
							break;
						}
						case' ':
						{
							character_length=2;
							break;
						}
						case '¡':
						{
							character_length=2;
							break;
						}
						case '!':
						{
							character_length=2;
							break;
						}
						case '?':
						{
							character_length=6;
							break;
						}
						case '¿':
						{
							character_length=6;
							break;
						}
						case '|':
						{
							character_length=2;
							break;
						}
						case '"':
						{
							character_length=4;
							break;
						}
						case '·':
						{
							character_length=2;
							break;
						}
						case '#':
						{
							character_length=6;
							break;
						}
						case '$':
						{
							character_length=6;
							break;
						}
						case '~':
						{
							character_length=6;
							break;
						}
						case '%':
						{
							character_length=9;
							break;
						}
						case '€':
						{
							character_length=6;
							break;
						}
						case '&':
						{
							character_length=7;
							break;
						}
						case '¬':
						{
							character_length=4;
							break;
						}
						case '/':
						{
							character_length=6;
							break;
						}
						case '(':
						{
							character_length=4;
							break;
						}
						case ')':
						{
							character_length=4;
							break;
						}
						case '=':
						{
							character_length=4;
							break;
						}
						case '\'':
						{
							character_length=2;
							break;
						}
						case '-':
						{
							character_length=4;
							break;
						}
						case '+':
						{
							character_length=4;
							break;
						}
						case '*':
						{
							character_length=6;
							break;
						}
						case '@':
						{
							character_length=8;
							break;
						}
						case '>':
						{
							character_length=4;
							break;
						}
						case '<':
						{
							character_length=4;
							break;
						}
						case '[':
						{
							character_length=4;
							break;
						}
						case ']':
						{
							character_length=4;
							break;
						}
						case '{':
						{
							character_length=5;
							break;
						}
						case '}':
						{
							character_length=5;
							break;
						}
						case ',':
						{
							character_length=3;
							break;
						}
						case ';':
						{
							character_length=3;
							break;
						}
						case ':':
						{
							character_length=2;
							break;
						}
						case '.':
						{
							character_length=2;
							break;
						}
						case '_':
						{
							character_length=4;
							break;
						}
						case 'º':
						{
							character_length=4;
							break;
						}
						case 'ª':
						{
							character_length=5;
							break;
						}
						case '\\':// \ is a special character,so it must be ignored
						{
							character_length=5;
							break;
						}
					}
				}
			}
		}
	}
	return character_length;
}


