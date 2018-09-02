#ifndef BUTTON_H_
#define BUTTON_H_

#include <avr/io.h>				// this is always included in AVR programs
#include <util/delay.h>			// add this to use the delay function

#define BIT_IS_SET(byte, bit) (byte & (1 << bit))
#define BIT_IS_CLEAR(byte, bit) (!(byte & (1 << bit)))

#define NUM_OF_CONSECUTIVE_PRESSES 2
#define NUM_OF_CONSECUTIVE_NON_PRESSES 2

#define BUTTON_DDR DDRD
#define BUTTON_PORT PORTD
#define BUTTON_PIN PIND

volatile bool check(uint8_t&);

class Button
{
public:
	Button(uint8_t button);

	volatile bool isPressed();

private:

	uint8_t button;
	volatile int intConsecutivePresses ;
	volatile int intConsecutiveNonPresses ;
};
#endif
