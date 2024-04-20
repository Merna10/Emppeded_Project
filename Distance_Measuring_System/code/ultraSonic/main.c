/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: merna
 */

#include <avr/io.h>
#include "lcd.h"
#include "ultraSonic.h"

int main(void) {
	uint16 distance;
	SREG |= (1<<7);
	LCD_init();
	Ultrasonic_init();
	LCD_DisplayString("DISTANCE =    CM");
	while(1)
	{
		LCD_moveCursor(0, 11);
		distance = Ultrasonic_readDistance();
		if(distance < 100)
		{
			LCD_intgerToString(distance);
			LCD_DisplayChar(' ');
		}
		else
		{
			LCD_intgerToString(distance);
		}

	}
	return 0;

}

