/*
 * LCD.h
 *
 *  Created on: 12 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#ifndef CD_LCD_H_
#define CD_LCD_H_

#include "../Geometry/Point.h"
#include "../Geometry/Rectangle.h"

class LCD : public Rectangle{
public:
	LCD(int8_t x, int8_t y);
	LCD(int8_t x, int8_t y, uint8_t width, uint8_t height);
	virtual ~LCD();

	//void init(uint8_t width, uint8_t height);

	void setCursor(int8_t x, int8_t y);
	void setCursor(Point* cords);
	void setCursorBy(Point* cords);
	uint8_t getCursorX();
	uint8_t getCursorY();
	Point* getCursor();

	void print(char* str);
	void fillArea(Rectangle* area, char c);

private:
	Point cursor = Point(0, 0);
};

#endif /* CD_LCD_H_ */
