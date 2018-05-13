/*
 * LCD.h
 *
 *  Created on: 12 Μαΐ 2018
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

	void init(uint8_t width, uint8_t y);

	void setCursor(uint8_t x, uint8_t y);
	void setCursor(Point cords);
	uint8_t getCursorX();
	uint8_t getCursorY();
	Point getCursor();

private:
	Point cursor = Point();
	uint8_t width;
	uint8_t height;
};

#endif /* CD_LCD_H_ */
