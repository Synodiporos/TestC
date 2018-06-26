/*
 * Rectangle.h
 *
 *  Created on: 13 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
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
	const uint8_t getWidth() const;
	const uint8_t getHeight() const;
	const Dimension getDimensions() const;
	bool isNull();

	bool contains(int8_t x, int8_t y) const;
	bool contains(const Point p) const;
	Rectangle intersection(const Rectangle* rec) const;
	bool intersects(Rectangle* rec);
	static Rectangle intersection(
			const Rectangle* rec1, const Rectangle* rec2);
	static bool intersects(
			const Rectangle* rec1 , const Rectangle* rec2);

	void print() const;

private:
	mutable Dimension dims = Dimension();
};

#endif /* GEOMETRY_RECTANGLE_H_ */
