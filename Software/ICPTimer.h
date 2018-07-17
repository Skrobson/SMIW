/*
 * ICPTimer.h
 *
 *  Created on: 14 lip 2018
 *      Author: skrobson
 */

#ifndef ICPTIMER_H_
#define ICPTIMER_H_
#include <avr/io.h>
#include <avr/interrupt.h>


class ICPTimer {
public:
	ICPTimer();

	static void captureInterrupt();
	static uint32_t getTime();

	volatile static uint8_t tick;
private:
	static bool initialized;
	volatile static uint16_t captureStart;
	volatile static uint16_t captureEnd;

	volatile static uint8_t edge;
	volatile static uint8_t endTick;

	static const float TIME_STEP;
	volatile static bool ready ;

};



#endif /* ICPTIMER_H_ */
