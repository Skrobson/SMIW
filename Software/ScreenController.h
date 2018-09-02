#ifndef SCREEN_CONTROLLER
#define SCREEN_CONTROLLER

#include "SH1106.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


#define TANK_PI_R 78.5
#define SENSOR_HIGH 12

#define HUMIDITY_STR "wilgotnosc gleby"
#define TEMP_STR "temperatura"
#define TANK_STR "poziom wody"
#define HUM_ENV_STR "wilgotnosc"

extern SH1106 screen;

void showHumidityScreen(volatile uint8_t &hum);
void updateHumidityScreen(volatile uint8_t &hum);

void showTempAndHumidityScreen();
void updateTempAndHumidityScreen();

void showTankScreen(volatile float &distance);
void updateTankScreen(volatile float &distance);


#endif
