/*
 * pwm.c
 *
 *  Created on: Nov 6, 2019
 *      Author: embeddedfab
 */
#include"pwm.h"




void Pwm_init(void)
{


	TCCR1A=0b10000001;      //TCCR1A=0b10000011;  //  config 980hz
	TCCR1B=0b00001011;       //TCCR1B=0b00001010;    //


	_delay_ms(10);
	TCNT1L=0;           //400
	OCR1A=30;
}


void Pwm_speed_value(unsigned char speed_value)
{

	OCR1AL=speed_value;
}
