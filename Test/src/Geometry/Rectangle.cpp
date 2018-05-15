/*
 * Rectangle.cpp
 *
 *  Created on: 13 Μαΐ 2018
 *      Author: Synodiporos
 */

#include "Rectangle.h"

#include "GeometryUtil.h"

Rectangle::Rectangle() {
	// TODO Auto-generated constructor stub

}

Rectangle::Rectangle(int8_t x, int8_t y) : Point(x, y){

}

Rectangle::Rectangle(int8_t x, int8_t y,
		uint8_t width, uint8_t height) : Point(x, y){
	this->dims.setDimensions(width, height);
}

Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub
}

bool Rectangle::setRectangle(int8_t x, int8_t y,
		uint8_t width, uint8_t height){
	bool res = setPoint(x, y);
	return setDimensions(width, height) || res;
}

bool Rectangle::setWidth(uint8_t width){
	return this->dims.setWidth(width);
}

bool Rectangle::setHeight(uint8_t height){
	return this->dims.setHeight(height);
}

bool Rectangle::setDimensions(uint8_t width, uint8_t height){
	return this->dims.setDimensions(width, height);
}

uint8_t Rectangle::getWidth(){
	return this->dims.getWidth();
}

uint8_t Rectangle::getHeight(){
	return this->dims.getHeight();
}

Dimension Rectangle::getDimensions(){
	return this->dims;
}

Rectangle Rectangle::intersection(Rectangle* rec){
	if(rec)
		return Rectangle::intersection(this, rec);
	return Rectangle();
}

bool Rectangle::intersects(Rectangle* rec){
	if(rec)
		return Rectangle::intersects(this, rec);
	return false;
}

Rectangle Rectangle::intersection(
		Rectangle* rec1, Rectangle* rec2){

	if(!rec1 || !rec2)
		return Rectangle();

	int left = GeometryUtil::max(rec1->x, rec2->x);
	int top = GeometryUtil::max(rec1->y, rec2->y);
	int right = GeometryUtil::min(
			rec1->x+rec1->getWidth(), rec2->x+rec2->getWidth());
	int bottom = GeometryUtil::min(
				rec1->y+rec1->getHeight(), rec2->y+rec2->getHeight());

	right = GeometryUtil::positive(right-left);
	bottom = GeometryUtil::positive(bottom-top);
	//if(right==0 || bottom==0)
	//	right = bottom = 0;

	return Rectangle(left, top, right, bottom);
}

bool Rectangle::intersects(Rectangle* A, Rectangle* B){
	if(!A || !B)
			return false;

    bool xOverlap = GeometryUtil::valueInRange(
    					A->x, B->x, B->x + B->getWidth()) ||
    				GeometryUtil::valueInRange(
    					B->x, A->x, A->x + A->getWidth());

    bool yOverlap = GeometryUtil::valueInRange(
    					A->y, B->y, B->y + B->getHeight()) ||
    				GeometryUtil::valueInRange(
    						B->y, A->y, A->y + A->getHeight());

    return xOverlap && yOverlap;
}
