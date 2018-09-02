/*
 * WaterPump.h
 *
 *  Created on: 2 wrz 2018
 *      Author: skrobson
 */

#ifndef WATERPUMP_H_
#define WATERPUMP_H_

#include <avr/io.h>

#define PUMP_DDR DDRC
#define PUMP_PORT PORTC
#define PUMP PC0

#define WATER_MIN_LEVEL 16
#define MIN_HUMIDITY_LEVEL 20
#define MAX_HUMIDITY_LEVEL 30

class WaterPump {
public:
	WaterPump();

	bool controll(volatile float & waterDistance,volatile uint8_t& humidity);
private:
	volatile bool restartScreen;
};

#endif /* WATERPUMP_H_ */
