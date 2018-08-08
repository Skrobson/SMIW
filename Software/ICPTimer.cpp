/*
 * ICPTimer.cpp
 *
 *  Created on: 14 lip 2018
 *      Author: skrobson
 */

#include "ICPTimer.h"

bool ICPTimer::initialized = false;

volatile uint16_t  ICPTimer::captureStart = 0;
volatile uint16_t  ICPTimer::captureEnd = 0;

volatile uint8_t ICPTimer::edge = 1;
volatile uint8_t ICPTimer::endTick = 0;

const float ICPTimer::TIME_STEP = 0.5f;
volatile bool ICPTimer::ready = false;
volatile uint8_t ICPTimer::tick = 0;

ICPTimer::ICPTimer()
{

	if (!initialized) {
		DDRD &= ~(1<<PD6);
		PORTD &= ~(1<<PD6);
		TCNT1 =0;
		TCCR1B |= (1<<ICES1)| (1<<CS11) ;// preskaler 8
		TIMSK |= (1<<TICIE1)| (1<<TOIE1);
		sei();
		initialized = true;
	}

}

void ICPTimer::captureInterrupt()
{
	switch(edge)
	{
	case 1:
		tick = 0;
		captureStart = ICR1 ;
		//TCNT1 =0;
		TCCR1B &= ~(1<<ICES1);
		edge = 0;
		ready = false;
		break;
	case 0:
		captureEnd = ICR1;
		endTick = tick;
		TCCR1B |= (1<<ICES1);

		edge = 1;
		ready = true;
		break;
	default:
		break;
	}
}

uint32_t ICPTimer::getTime()
{
	while(!ready);

	captureEnd += (endTick * 0xFFFF);
	volatile uint32_t signalTime = (captureEnd - captureStart); //8 liczba us wyeksportowac do define

	return signalTime;
}

ISR(TIMER1_CAPT_vect)
{
	ICPTimer::captureInterrupt();
}

ISR(TIMER1_OVF_vect)
{
	ICPTimer::tick++;
}
