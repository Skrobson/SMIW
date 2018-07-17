/*
 * SPI.h
 *
 * Created: 2018-04-24 21:55:27
 *  Author: T530
 */ 

#ifndef SPI
#define SPI
#include <avr/io.h>

#ifndef csPORT
# warning "Define csPORT (default PORTB)"
#define csPort PORTB
#endif

#ifndef cs1 
# warning "Define cs1 if needed"
#define cs1 0
#endif

#ifndef cs2
# warning "Define cs2 if needed"
#define cs2 0
#endif

#ifndef cs3
# warning "Define cs3 if needed"
#define cs3 0
#endif


#define SCK 	PB7		//sygna³ zegarowy SCK
#define MISO 	PB6		//sygna³ MISO - Master Input Slave Output
#define MOSI	PB5		//sygna³ MOSI - Master Output Slave Input
#define SS		PB4		//sygna³ wyboru mikrokontrolera dla pracy w trybie Slave
#define OLED_DC	    PB3
#define OLED_RES    PB2

char dataIn;

void spiInitMaster(void){

	DDRB |= (1<<SCK)|(1<<MOSI)|(1<<SS)|(1<<OLED_DC)|(1<<OLED_DC);    // SCK, MOSI and SS as outputs
	DDRB &= ~(1<<4);                 // MISO as input
	
	
	SPCR |= (1<<MSTR);               // Set as Master
	SPCR |= (1<<SPR0)|(1<<SPR1);     // divided clock by 128
	SPCR |= (1<<SPE);                // Enable SPI
}

void spiInitSlave(void){

	DDRB &= ~((1<<2)|(1<<3)|(1<<5));   // SCK, MOSI and SS as inputs
	DDRB |= (1<<4);                    // MISO as output

	SPCR &= ~(1<<MSTR);                // Set as slave
	SPCR |= (1<<SPR0)|(1<<SPR1);       // divide clock by 128
	SPCR |= (1<<SPE);
	
	SPSR = (1<<SPI2X);  
}

int spiReceive(void){//Call in while(1)
	while(!(SPSR & (1<<SPIF)));    // wait until all data is received
	dataIn = SPDR;
	return dataIn;
}

void spiTransmit(char dataOut, int slavePin){//Call in while(1)
	csPort &= ~ 1<<slavePin;
	SPDR = dataOut;                 // send the data
	while(!(SPSR & (1<<SPIF)));
}
#endif