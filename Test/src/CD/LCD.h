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

class LCD {
public:
	LCD();
	virtual ~LCD();

	void init(uint8_t width, uint8_t height);

	void setCursor(uint8_t x, uint8_t y);
	void setCursor(Point* cords);
	uint8_t getCursorX();
	uint8_t getCursorY();
	Point* getCursor();

	void print(char* str);

private:
	Rectangle* bounds = new Rectangle();
	uint8_t width = 0;
	uint8_t height = 0;
	Point* cursor = new Point(0, 0);
};

#endif /* CD_LCD_H_ */
