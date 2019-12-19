/*
 * main.c
 *
 *  Created on: 5 Oct 2015
 *      Author: EmbeddedFab
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include "ef_7segment.h"
#include"pwm.h"
#include"timer.h"
#include"UART.h"
#include"ADC.h"
#include"i2c.h"
#include"spi.h"



#define ADC_code 1
#define TIMER_code 0
#define PWM_code 0
#define UART_code 0
#define UART_code 0
#define I2C_code 0
#define SPI_Code 0

volatile uint32_t timer_counts;

int main()
{



#if TIMER_code
	DDRD |=(1<<PD7);
	timer_init();
	sei();

	while(1)
	{

		if(timer_counts==1000)
		{

			PORTD ^=(1<<PD7);
			timer_counts=0;
		}

	}

#endif



#if ADC_code
	unsigned int ADC_Value=0;

	ADC_init();
	init_UART();

	while(1)
	{
		ADC_Value=ADC_Get_reading_mv(7);
		UART_SEND_string("\r\nADC_VALUE =  ");
		 UART_SEND_number(ADC_Value);
		 _delay_ms(700);


	}

#endif

#if PWM_code
	uint8_t PWM_VALUE=0;
	DDRD |=(1<<PD5);
	Pwm_init();

	while(1)
	{
		Pwm_speed_value(PWM_VALUE+=20);
		_delay_ms(300);
		if(PWM_VALUE>250)
		{
			PWM_VALUE=0;
		}

	}

#endif


#if UART_code

	init_UART();

	while(1)
	{

		UART_SEND_string("Hello There iam using UART  \r\n");
		_delay_ms(1000);

	}

#endif



#if SPI_Code


	char  ReceivedChar=0;


	     SPI_SlaveInit();
	     Segment_Init();
	 	Segment_Display(ReceivedChar);

	_delay_ms(1000);

while(1)
{
	Segment_Display(ReceivedChar);
	ReceivedChar=SPI_Transmit(0x00);
}



#endif




#if I2C_code



#endif





	return 0;
}



#if TIMER_code

ISR(TIMER0_COMP_vect)
{
	timer_counts++;

}



#endif





