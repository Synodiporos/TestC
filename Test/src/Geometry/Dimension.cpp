/*
 * Dimension.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: sgeorgiadis
 */

#include "Dimension.h"

Dimension::Dimension() {
	// TODO Auto-generated constructor stub

}

Dimension::Dimension(unsigned short int width, unsigned short int height){
	this->height = height;
	this->width = width;
}

Dimension::~Dimension() {
	// TODO Auto-generated destructor stub
}

bool Dimension::setDimensions(unsigned short int w, unsigned short h){
	if(this->width!=w || this->height!=h){
		this->width = w;
		this->height = h;
		return true;
	}
	return false;
}

bool Dimension::setWidth(unsigned short int width){
	return setDimensions(width, height);
}
unsigned short int Dimension::getWidth(){
	return this->width;
}

bool Dimension::setHeight(unsigned short int height){
	return setDimensions(width, height);
}

unsigned short int Dimension::getHeight(){
	return this->height;
}

Dimension Dimension::copy(){
	return Dimension(getWidth(), getHeight());
}

bool Dimension::equals(Dimension c){
	return equals(c.width, c.height);
}

bool Dimension::equals(short int w, short int h){
	return this->width==w && this->height==h;
}
