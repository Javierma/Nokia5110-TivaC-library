# Nokia5110-TivaC-library
This is a library for the Nokia5110 screen using TM4C123GH6PM microcontroller. To test it, you can directly import the project in Code Composer Studio.

Please note that in case that you use another board the configuration will not be valid without any change.

In order to make it work, the connection among the board and the screen must be the following:

BOARD ---  SCREEN

PA2   ---  CLK

PA3   ---  CE

PA4   ---  BL

PA5   ---  DIN

PA6   ---  DC

PA7   ---  RST

3.3V  ---  VCC

GND   ---  GND
