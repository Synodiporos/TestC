/*
 * LCD.h
 *
 *  Created on: 12 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
 *      Author: Synodiporos
 */

#ifndef CD_LCD_H_
#define CD_LCD_H_

#include "../Geometry/Point.h"
#include "../Geometry/Rectangle.h"
#include <stdint.h>

class LCD : public Rectangle{
public:
	LCD(uint8_t width, uint8_t height);
	LCD(int8_t x, int8_t y, uint8_t width, uint8_t height);
	virtual ~LCD();

	virtual bool settingCursor(Point* sursor) = 0;
	virtual uint8_t getCharBufferAddress() = 0;
	virtual bool createChar(uint8_t id, const uint8_t[8]) = 0;
	virtual bool printChar(uint8_t id) = 0;
	virtual bool print(char* str) = 0;
	virtual bool print(char ch) = 0;
	virtual bool clear() = 0;
	virtual bool refresh() = 0;

	//void createCustomCharacters();
	bool setCursor(Point* cords);
	bool setCursor(uint8_t x, uint8_t y) ;
	bool setCursorBy(uint8_t x, uint8_t y);
	bool setCursorBy(Point* cords);
	Point* getCursor();
	uint8_t getCursorX();
	uint8_t getCursorY();
	bool writeChar(uint8_t ch[8]);
	void fillArea(Rectangle* area, char c);

private:
	Point cursor = Point(0, 0);
	//void sentCursorCoords();
};

#endif /* CD_LCD_H_ */
