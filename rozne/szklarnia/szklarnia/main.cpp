/*
 * szklarnia.cpp
 *
 * Created: 2018-04-24 21:54:04
 * Author : T530
 */ 

#include <avr/io.h>
#include <util/delay.h>
//#include "SPI.h"
#include "ssd1306.h"
int main(void)
{
	uint8_t oled_buf[WIDTH * HEIGHT / 8];
    /* Replace with your application code */
	SSD1306_begin();
	
	SSD1306_clear(oled_buf);
	SSD1306_bitmap(0, 0, Waveshare12864, 128, 64, oled_buf);
	SSD1306_display(oled_buf);
	_delay_ms(2000);
	
	
    while (1) 
	{
    
    }
}

