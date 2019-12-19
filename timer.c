/*
 * timer.c
 *
 *  Created on: Dec 19, 2019
 *      Author: embeddedfab
 */
#include"timer.h"





void timer_init(void)
{

	TCCR0=0b00001101;  // prescaler 1024 && clear in compare match mood
	TIMSK=0b00000010;   //ENable Compare Match interrupt
	OCR0=8;



}
