/*
 * ADC.cpp
 *
 *  Created on: 7 lip 2018
 *      Author: skrobson
 */

#include "ADC.h"

bool ADCReader::initialized = false;

ADCReader::ADCReader()
{
	if(!initialized)
	{
		ADMUX=(1<<REFS0);
		ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
		ADCSRA |= ( 1 << ADSC );

		initialized = true;
	}

}

uint16_t ADCReader::read(uint8_t channel)
{
	// select the corresponding channel 0~7
	// ANDing with ’7′ will always keep the value
    // of ‘ch’ between 0 and 7
	channel &= 0b00000111;  // AND operation with 7
	ADMUX |= (ADMUX & 0xF0)|channel; // clears the bottom 3 bits before ORing   (ADMUX & 0xF8)|

	// start single convertion
	// write ’1′ to ADSC
	ADCSRA |= (1<<ADSC);

	// wait for conversion to complete
	// ADSC becomes ’0′ again
	// till then, run loop continuously
	while((ADCSRA & (1<<ADIF)));
	//while(ADCSRA & (1<<ADSC));
	//ADCSRA|=(1<<ADIF);
	return (ADC);
}

