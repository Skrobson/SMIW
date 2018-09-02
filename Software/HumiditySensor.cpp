/*
 * HumiditySensor.cpp
 *
 *  Created on: 10 lip 2018
 *      Author: skrobson
 */

#include "HumiditySensor.h"

HumiditySensor::HumiditySensor(uint8_t channel): MAX_VALUE(1023),CHANNEL(channel)  {

}
volatile uint8_t HumiditySensor::measure( )
{
	volatile double percentageHumidity =(1023 - adc.read(CHANNEL));
	percentageHumidity /= 1023;
	percentageHumidity *= 100;
	return uint8_t (percentageHumidity);
}

