/*
 * AnalogSensor.h
 *
 *  Created on: 10 lip 2018
 *      Author: skrobson
 */

#ifndef ANALOGSENSOR_H_
#define ANALOGSENSOR_H_

#include "ADC.h"
class AnalogSensor {
public:
	AnalogSensor(uint8_t channel);
	//non pure virtual because of compile error undefined reference to pure virtual
protected:
	const uint16_t MAX_VALUE;
	const uint8_t CHANNEL;

};

#endif /* ANALOGSENSOR_H_ */
