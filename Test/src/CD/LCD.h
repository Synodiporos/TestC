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
	LCD(int8_t x, int8_t y);
	LCD(int8_t x, int8_t y, uint8_t width, uint8_t height);
	virtual ~LCD();
	void createCustomCharacters();
	void setCursor(uint8_t x, uint8_t y);
	void setCursorBy(uint8_t x, uint8_t y);
	void setCursor(Point* cords);
	void setCursorBy(Point* cords);
	uint8_t getCursorX();
	uint8_t getCursorY();
	Point* getCursor();

	void createChar(uint8_t id, const uint8_t[8]);
	void printChar(uint8_t id);
	void writeChar(uint8_t ch[8]);
	void print(char* str);
	void fillArea(Rectangle* area, char c);
	void clear();
	void refresh();

private:
	Point cursor = Point(0, 0);
	void sentCursorCoords();
};

#endif /* CD_LCD_H_ */
