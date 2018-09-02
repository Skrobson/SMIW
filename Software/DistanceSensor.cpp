/*
 * DistanceSensor.cpp
 *
 *  Created on: 14 lip 2018
 *      Author: skrobson
 */

#include "DistanceSensor.h"
#include <util/delay.h>
DistanceSensor::DistanceSensor() {
	SENSOR_DDR |= (1<<TRIG_PIN);
	SENSOR_PORT &= ~(1<<TRIG_PIN);
}

float DistanceSensor::getDistance()
{
	SENSOR_PORT &= ~(1<<TRIG_PIN);
	_delay_ms(2);

	SENSOR_PORT |= (1<<TRIG_PIN);
	_delay_ms(15);
	SENSOR_PORT &= ~(1<<TRIG_PIN);

	volatile uint32_t echoTime = timer.getTime();
	if (echoTime>0)
	{
		volatile float distance = echoTime/58;
//		volatile double distance = (double)((echoTime*34)/1000/2);
		return distance;
	}
	else return 0;
}


