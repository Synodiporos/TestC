/*
 * CDElement.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDElement.h"
//#include "Arduino.h"

CDElement::CDElement() {

}

CDElement::~CDElement() {

}

void CDElement::setDimensions(uint8_t width, uint8_t height){
	if(dimensions.equals(width, height)){
		this->dimensions.setWidth(width);
		this->dimensions.setHeight(height);
		//
	}
}

Dimension CDElement::getDimensions(){
	return this->dimensions;
}

void CDElement::setPreferedDimensions(uint8_t width, uint8_t height){
	if(pDimensions.equals(width, height)){
		this->pDimensions.setWidth(width);
		this->pDimensions.setHeight(height);
		//
	}
}

Dimension CDElement::getPreferedDimensions(){
	return this->pDimensions;
}

void CDElement::setPosition(uint8_t x, uint8_t y){
	if(!position.equals(x, y)){
		this->position.setPoint(x, y);
		//
	}
}

Point CDElement::getPosition(){
	return this->position;
}

void CDElement::moveBy(uint8_t x, uint8_t y){
	if(x!=0 && y!=0){
		uint8_t mx = position.getX();
		uint8_t my = position.getY();
		this->position.setPoint(mx, my);
		//
	}
}


void CDElement::print(LCD* lcd){

}

void CDElement::validate(){

}
