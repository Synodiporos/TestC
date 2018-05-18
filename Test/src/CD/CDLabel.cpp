/*
 * CDLabel.cpp
 *
 *  Created on: 18 Μαΐ 2018
 *      Author: Synodiporos
 */

#include "CDLabel.h"

CDLabel::CDLabel() {
	// TODO Auto-generated constructor stub

}

CDLabel::CDLabel(uint8_t width, char* label){
	setWidth(width);
	setLabel(label);
}

CDLabel::CDLabel(int8_t x, int8_t y, uint8_t width, char* label){
	setLocation(x, y);
	setWidth(width);
	setLabel(label);
}

CDLabel::~CDLabel() {
	// TODO Auto-generated destructor stub
}

void CDLabel::setLabel(char* label){
	this->label = label;
}

char* CDLabel::getLabel(){
	return this->label;
}

void CDLabel::setWidth(uint8_t width){
	this->width = width;
}

uint8_t CDLabel::getWidth(){
	return this->width;
}

void CDLabel::setLocation(int8_t x, int8_t y){
	this->x = x;
	this->y = y;
}

Point* CDLabel::getLocation(){
	return new Point(this->x, this->y);
}

Rectangle* CDLabel::getBounds(){
	return new Rectangle(this->x, this->y, this->width, 0);
}

void CDLabel::print(LCD* lcd){

}

void CDLabel::printArea(LCD* lcd, Rectangle* area){

}

void CDLabel::validate(){

}
