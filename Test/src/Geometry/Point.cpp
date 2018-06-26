/*
 * Point.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: sgeorgiadis
 */

#include "Point.h"

Point::Point() {
	// TODO Auto-generated constructor stub

}

Point::Point(short int x, short int y) {
	this->x = x;
	this->y = y;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

bool Point::setX(short int x){
	return setPoint(x, y);
}

const short int Point::getX() const{
	return this->x;
}

bool Point::setY(short int y){
	return setPoint(x, y);
}

const short int Point::getY() const{
	return this->y;
}

bool Point::setPoint(short int x, short int y){
	if(this->x!=x || this->y!=y){
		this->x = x;
		this->y = y;
		return true;
	}
	return false;
}

bool Point::setPoint(Point* point){
	if(point)
		return setPoint(point->getX(), point->getY());
	return false;
}

bool Point::setPointBy(short int x, short int y){
	return setPoint(this->x + x, this->y + y);
}

Point Point::copy(){
	return Point(this->x, this->y);
}

bool Point::equals(const Point* c) const{
	return equals(c->x, c->y);
}

bool Point::equals(short int x, short int y) const{
	return this->x==x && this->y==y;
}
