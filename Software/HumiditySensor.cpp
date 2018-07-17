/*
 * HumiditySensor.cpp
 *
 *  Created on: 10 lip 2018
 *      Author: skrobson
 */

#include "HumiditySensor.h"

HumiditySensor::HumiditySensor(uint8_t channel): AnalogSensor(channel)  {
	// TODO Auto-generated constructor stub

}
uint8_t HumiditySensor::measure(const ADCReader& reader)
{
	volatile double percentageHumidity = (MAX_VALUE - reader.read(CHANNEL));
	percentageHumidity /= MAX_VALUE;
	percentageHumidity *= 100;
	return uint8_t (percentageHumidity);
}

