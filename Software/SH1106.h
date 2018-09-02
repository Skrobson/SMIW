/*
 * SH1106.h
 *
 *  Created on: 28 cze 2018
 *      Author: skrobson
 */

#ifndef SH1106_H_
#define SH1106_H_

#include "SPI.h"

#define WIDTH   128
#define HEIGHT   64
#define NUM_PAGE  8

#define PIN_DC				PB2	//
#define PIN_RESET			PB3	//
#define PIN_CS				PB1//

extern const uint8_t Waveshare12864[1024];
extern const uint8_t Font1206[95][12];
extern const uint8_t Font1608[95][16];
extern const uint8_t Font1612[11][32];
extern const uint8_t Font3216[11][64];
extern const uint8_t Signal816[16];
extern const uint8_t Msg816[16];
extern const uint8_t Bat816[16];
extern const uint8_t Bluetooth88[8];
extern const uint8_t GPRS88[8];
extern const uint8_t Alarm88[8];

class SH1106 {
public:
	SH1106();
	void clear();
	void write(uint8_t data);
	void show();
	uint8_t screen[8*128];
	void bitmap(uint8_t x, uint8_t y, const uint8_t *pBmp, uint8_t chWidth, uint8_t chHeight, uint8_t* buffer);
	void string(uint8_t x, uint8_t y, const char *pString, uint8_t Size, uint8_t Mode, uint8_t* buffer);
	static void restart();
private:
	static void writeCmd( uint8_t data);
	static void command(uint8_t data){writeCmd(data);}
	void pixel(int x, int y, char color, uint8_t* buffer);
	void char1616(uint8_t x, uint8_t y, uint8_t chChar, uint8_t* buffer);
	void char3216(uint8_t x, uint8_t y, uint8_t chChar, uint8_t* buffer);
	void writeChar(uint8_t x, uint8_t y, uint8_t acsii, uint8_t size, uint8_t mode, uint8_t* buffer);


	static bool initialized;
};

#endif /* SH1106_H_ */
