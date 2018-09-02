/*
 * ADC.h
 *
 *  Created on: 7 lip 2018
 *      Author: skrobson
 */

#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>

class ADCReader {
public:
	ADCReader();

	uint16_t read(uint8_t channel);
private:
	static bool initialized;
};

#endif /* ADC_H_ */
