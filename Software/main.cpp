/*
 * szklarnia.cpp
 *
 * Created: 2018-04-24 21:54:04
 * Author : T530
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/eeprom.h>

#include "SH1106.h"
#include "ADC.h"
#include "HumiditySensor.h"
#include "DistanceSensor.h"
#include "dht.h"
#include "button.h"
#include "ScreenController.h"
#include "WaterPump.h"

volatile float distance = 0;
volatile uint8_t humidity = 0;

//volatile bool leftButtonPressed = false;
//volatile bool rightButtonPressed = false;
volatile bool showNewScreen = true;
volatile uint8_t screenSelector = 0;
volatile uint8_t screenIndex = 0;
int main(void)
{

    HumiditySensor humiditySensor(1);
    DistanceSensor distanceSensor;


    volatile float distance = distanceSensor.getDistance();
    volatile uint8_t humidity = humiditySensor.measure();

	Button leftButton = Button(PD3);
	Button rightButton = Button(PD4);

	WaterPump pump;

    while(1)
    {
     	distance = distanceSensor.getDistance();
     	humidity = humiditySensor.measure();

    	if((rightButton.isPressed()) && (! leftButton.isPressed()))
    		{
    		++screenSelector;
    		showNewScreen = true;
    		}
    	else if((leftButton.isPressed()) && (! rightButton.isPressed()))
    		{
    		--screenSelector;
    		showNewScreen = true;
    		}

    	screenIndex = screenSelector%3;

    	switch(screenIndex)
    	{
    	case 0:
    		if(showNewScreen)

    			{
    				showHumidityScreen(humidity);
    				showNewScreen = false;
    			}
    		else updateHumidityScreen(humidity);
    		break;
    	case 1:
    		if(showNewScreen)
    			{
    				showTempAndHumidityScreen();
    				showNewScreen = false;
    			}
    		else updateTempAndHumidityScreen();
    		break;
    	case 2:

    		if(showNewScreen)
    			{
    				showTankScreen(distance);
    				showNewScreen = false;
    			}
    		else updateTankScreen(distance);
    		break;
    	default:
    		break;
    	}

    	if(pump.controll(distance,humidity))
    		screen.string(3, 48, "                     ", 12, 1, screen.screen);
    	else
        	screen.string(3, 48, "NISKI POZIOM WODY", 12, 1, screen.screen);

    	//eeprom_read_byte();

    	screen.show();
    	//debug here
//        char buff[4];
//    	sprintf(buff,"%4u",screenIndex);
//    	screen.string(26, 48, buff, 12, 0, screen.screen);

//    	screen.show();
	}
}

