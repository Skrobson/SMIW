/*
 * ScreenController.cpp
 *
 *  Created on: 2 wrz 2018
 *      Author: skrobson
 */
#include "ScreenController.h"
#include "dht.h"
#include "WaterPump.h"

SH1106 screen = SH1106();
char buff[5];

void showHumidityScreen(volatile uint8_t &hum)
{
	screen.clear();
    screen.string(12, 0, HUMIDITY_STR, 12, 0, screen.screen);
    screen.show();
    updateHumidityScreen(hum);
}

void updateHumidityScreen(volatile uint8_t &hum)
{
	sprintf(buff,"%4u",hum);
	buff[4] = '%';
	screen.string(26, 12, buff, 12, 0, screen.screen);

	screen.show();
}

void showTempAndHumidityScreen()
{
	screen.clear();

	screen.string(10, 0, TEMP_STR, 12, 0, screen.screen);
	screen.string(10, 24, HUM_ENV_STR, 12, 0, screen.screen);
	screen.show();

	updateTempAndHumidityScreen();
}

void updateTempAndHumidityScreen()
{
	int8_t temp = 0;
	int8_t hum = 0;


	if(dht_gettemperaturehumidity(&temp,&hum)!=-1)
		{
			sprintf(buff,"%4u",temp);
			buff[4] = '*';
			screen.string(26, 12, buff, 12, 0, screen.screen);

		    sprintf(buff,"%4u",hum);
		    buff[4] = '%';
		    screen.string(26, 36,buff, 12, 0, screen.screen);

		    screen.show();
		}
}

void showTankScreen( volatile float &distance)
{
	screen.clear();
    screen.string(26, 12, TANK_STR, 12, 0, screen.screen);
    screen.show();
    updateTankScreen(distance);
}

void updateTankScreen(volatile float &distance)
{

	int8_t waterLevel = WATER_MIN_LEVEL - (distance);
	if(waterLevel < WATER_MIN_LEVEL) waterLevel = 0;
    sprintf(buff,"%4u",(uint8_t)waterLevel);
    screen.string(26, 24,buff, 12, 0, screen.screen);

    screen.show();
}



