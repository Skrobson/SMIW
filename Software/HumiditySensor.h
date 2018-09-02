/*
 * HumiditySensor.h
 *
 *  Created on: 10 lip 2018
 *      Author: skrobson
 */

#ifndef HUMIDITYSENSOR_H_
#define HUMIDITYSENSOR_H_
#include "ADC.h"

class HumiditySensor{
public:
	HumiditySensor(uint8_t channel);
	volatile uint8_t measure( );
private:
	const uint16_t MAX_VALUE;
	const uint8_t CHANNEL;
	ADCReader adc;
};

#endif /* HUMIDITYSENSOR_H_ */
