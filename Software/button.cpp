#include "button.h"

volatile int intConsecutivePresses = 0;
volatile int intConsecutiveNonPresses = 0;

Button::Button(uint8_t button): button(button)
{
	DDRD &= ~(1 << button);

	PORTD |= (1 << button);

	intConsecutiveNonPresses = 0;
	intConsecutivePresses = 0;
}

volatile bool Button::isPressed()
{
	if(BIT_IS_CLEAR(BUTTON_PIN, button)) {
			intConsecutivePresses++;
			if(intConsecutivePresses >= NUM_OF_CONSECUTIVE_PRESSES) {
				return true;
			}
		} else if(BIT_IS_SET(BUTTON_PIN, button)) {
			intConsecutiveNonPresses++;
			if(intConsecutiveNonPresses >= NUM_OF_CONSECUTIVE_NON_PRESSES) {
				intConsecutivePresses = 0;
				intConsecutiveNonPresses = 0;
			}
			return false;
		}
		return false;
}

volatile bool check(uint8_t& b) {


	if(BIT_IS_CLEAR(PIND, b)) {										// if button is pressed (logic low)
		intConsecutivePresses++;											// increment counter for number of presses
		if(intConsecutivePresses >= NUM_OF_CONSECUTIVE_PRESSES) {			// if enough presses to constitute a press
			return true;														// increment Port D LEDs
//				intConsecutivePresses = 0;										// and reset press counts
//				intConsecutiveNonPresses = 0;
		}
	} else if(BIT_IS_SET(PIND, b)) {						// else if button is not pressed (logic low)
		intConsecutiveNonPresses++;											// increment counter for number of non-presses
		if(intConsecutiveNonPresses >= NUM_OF_CONSECUTIVE_NON_PRESSES) {	// if enough consecutive non-presses that we are convinced the switch is not being pressed
			intConsecutivePresses = 0;										// reset press counts
			intConsecutiveNonPresses = 0;
		}
		return false;
	}
	return false;




}
