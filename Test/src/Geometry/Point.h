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

	void setX(short int x);
	short int getX();
	void setY(short int y);
	short int getY();
	void setPoint(short int x, short int y);
	Point copy();
	bool equals(Point c);
	bool equals(short int x, short int y);

protected:
	short int x = 0;
	short int y = 0;
};

#endif /* GEOMETRY_POINT_H_ */
