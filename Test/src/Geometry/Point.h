/*
 * Point.h
 *
 *  Created on: Apr 19, 2018
 *      Author: sgeorgiadis
 */

#ifndef GEOMETRY_POINT_H_
#define GEOMETRY_POINT_H_

class Point {
public:
	Point();
	Point(short int x, short int y);
	virtual ~Point();

	bool setX(short int x);
	const short int getX() const;
	bool setY(short int y);
	const short int getY() const;
	bool setPoint(short int x, short int y);
	bool setPoint(Point* point);
	bool setPointBy(short int x, short int y);
	Point copy();
	bool equals(const Point* c) const;
	bool equals(short int x, short int y) const;

protected:
	short int x = 0;
	short int y = 0;
};

#endif /* GEOMETRY_POINT_H_ */
