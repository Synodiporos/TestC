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
	if(this->x!=x){
		this->x = x;
		return true;
	}
	return false;
}

short int Point::getX(){
	return this->x;
}

bool Point::setY(short int y){
	if(this->y!=y){
		this->y = y;
		return true;
	}
	return false;
}

short int Point::getY(){
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

bool Point::setPointBy(short int x, short int y){
	if(x!=0 || y!=0){
		this->x = this->x + x;
		this->y = this->y + y;
		return true;
	}
	return false;
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
