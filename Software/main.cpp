/*
 * szklarnia.cpp
 *
 * Created: 2018-04-24 21:54:04
 * Author : T530
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "SH1106.h"
#include "ADC.h"
#include "HumiditySensor.h"
#include "DistanceSensor.h"
int main(void)
{

	DDRD |= (1<<PD7);
	PORTD |= (1<<PD7);

	SH1106 led;

	led.clear();


    led.string(26, 0, "wilgotnosc", 12, 0, led.screen);
    led.string(26, 24, "odleglosc", 12, 0, led.screen);
    led.show();

    ADCReader adc;
    DDRA &= ~(1<<PA0);
    PORTA |= (1<<PA0);
    HumiditySensor humidity(PA0);
    char mc[12];
    char dist[12];
    volatile double distance;
    DistanceSensor distanceSensor;
	while (true)
	{
		volatile uint8_t m = humidity.measure(adc);
		sprintf(mc,"%4u",m);
	    led.string(26, 12, mc, 12, 0, led.screen);

	    distance = distanceSensor.getDistance();
	    sprintf(dist,"%4u",(uint8_t)distance);
	    led.string(26, 36,dist, 12, 0, led.screen);

	    led.show();

		PORTD |= (1<<PD7);
	    _delay_ms(330);

		PORTD &= ~(1<<PD7);
	    _delay_ms(330);
	}
}

