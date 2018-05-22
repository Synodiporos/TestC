/*
 * Rectangle.h
 *
 *  Created on: 13 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#ifndef GEOMETRY_RECTANGLE_H_
#define GEOMETRY_RECTANGLE_H_
#include <stdint.h>
#include "Dimension.h"
#include "Point.h"

class Rectangle : public Point{
public:
	Rectangle();
	Rectangle(int8_t x, int8_t y);
	Rectangle(int8_t x, int8_t y, uint8_t width, uint8_t height);
	virtual ~Rectangle();

	bool setRectangle(int8_t x, int8_t y, uint8_t width, uint8_t height);
	bool setWidth(uint8_t width);
	bool setHeight(uint8_t height);
	bool setDimensions(uint8_t width, uint8_t height);
	bool setDimensions(Dimension dims);
	uint8_t getWidth();
	uint8_t getHeight();
	Dimension getDimensions();
	bool isNull();

	Rectangle intersection(Rectangle* rec);
	bool intersects(Rectangle* rec);
	static Rectangle intersection(Rectangle* rec1, Rectangle* rec2);
	static bool intersects(Rectangle* rec1 , Rectangle* rec2);


private:
	Dimension dims = Dimension();
};

#endif /* GEOMETRY_RECTANGLE_H_ */
