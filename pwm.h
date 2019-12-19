/*
 * pwm.h
 *
 *  Created on: Nov 6, 2019
 *      Author: embeddedfab
 */

#ifndef PWM_H_
#define PWM_H_
#include<avr/io.h>
#include<util/delay.h>


void Pwm_init(void);
void Pwm_speed_value(unsigned char speed_value);

#endif /* PWM_H_ */
