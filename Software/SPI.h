/*
 * SPI.h
 *
 * Created: 2018-04-24 21:55:27
 *  Author: T530
 */ 

#ifndef SPI
#define SPI
#include <avr/io.h>




#define SCK 	PB7		//sygna� zegarowy SCK
#define MISO 	PB6		//sygna� MISO - Master Input Slave Output
#define MOSI	PB5	//sygna� MOSI - Master Output Slave Input
#define SS		PB1		//sygna� wyboru mikrokontrolera dla pracy w trybie Slave
#define OLED_DC	    PB3
#define OLED_RES    PB2


void spiInitMaster(void);

void spiWrite(const uint8_t& data);

#endif
