/*
 * DistanceSensor.h
 *
 *  Created on: 14 lip 2018
 *      Author: skrobson
 */

#ifndef DISTANCESENSOR_H_
#define DISTANCESENSOR_H_

#define SENSOR_DDR DDRD
#define SENSOR_PORT PORTD
#define TRIG_PIN PD5
#define MAX_DISTANCE 200
#include <avr/io.h>
#include "ICPTimer.h"
class DistanceSensor {
public:
	DistanceSensor();
	uint16_t getDistance();

private:
	ICPTimer timer;
	const uint8_t DIVISOR;
};

#endif /* DISTANCESENSOR_H_ */
