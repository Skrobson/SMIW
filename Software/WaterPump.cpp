/*
 * WaterPump.cpp
 *
 *  Created on: 2 wrz 2018
 *      Author: skrobson
 */

#include "WaterPump.h"
#include "SH1106.h"
WaterPump::WaterPump() {
	PUMP_DDR |=(1<<PUMP);
	PUMP_PORT &=~(1<<PUMP);

	restartScreen = false;
}

bool WaterPump::controll(volatile float & waterDistance,volatile uint8_t& humidity)
{
	if(waterDistance >= WATER_MIN_LEVEL )
	{
		PUMP_PORT &=~(1<<PUMP);
		if(restartScreen)
		{
			SH1106::restart();
			restartScreen=false;
		}
		return false;
	}

	else if(humidity < MIN_HUMIDITY_LEVEL)
	{
		PUMP_PORT |=(1<<PUMP);
		restartScreen=true;

	}
	else if(humidity > MAX_HUMIDITY_LEVEL)
	{
		PUMP_PORT &=~(1<<PUMP);
		if(restartScreen)
		{
			SH1106::restart();
			restartScreen=false;
		}

	}
	return true;
}
