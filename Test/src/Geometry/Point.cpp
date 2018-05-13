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

void Point::setX(short int x){
	this->x = x;
}

short int Point::getX(){
	return this->x;
}

void Point::setY(short int y){
	this->y = y;
}

short int Point::getY(){
	return this->y;
}

void Point::setPoint(short int x, short int y){
	this->x = x;
	this->y = y;
}

Point Point::copy(){
	return Point(this->x, this->y);
}

bool Point::equals(Point c){
	return equals(c.x, c.y);
}

bool Point::equals(short int x, short int y){
	return this->x==x && this->y==y;
}
