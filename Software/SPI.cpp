/*
 * SPI.c
 *
 *  Created on: 23 cze 2018
 *      Author: skrobson
 */
#include "SPI.h"

void spiInitMaster(void){
    DDRB = ( 1 << PB5 ) | ( 1 << PB7 ) | ( 1 << PB4 );              //MOSI, SCK, SS' jako wyjścia
    SPCR = ( 1 << SPE ) | ( 1 << MSTR ) | ( 1 << SPR1 ) | ( 1 << SPR0 );   //Włączamy SPI,
}

void spiWrite(const uint8_t& data)
{
	SPDR= data;
	while(! bit_is_set( SPSR, SPIF ));
}
