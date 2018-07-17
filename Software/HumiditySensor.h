/*
 * HumiditySensor.h
 *
 *  Created on: 10 lip 2018
 *      Author: skrobson
 */

#ifndef HUMIDITYSENSOR_H_
#define HUMIDITYSENSOR_H_

#include "AnalogSensor.h"
#include "ADC.h"

class HumiditySensor: public AnalogSensor {
public:
	HumiditySensor(uint8_t channel);
	uint8_t measure(const ADCReader & reader);
};

#endif /* HUMIDITYSENSOR_H_ */
