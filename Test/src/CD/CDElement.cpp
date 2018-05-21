/*
 * CDElement.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */
#include <iostream>
using namespace std;
#include "CDElement.h"
//#include "Arduino.h"

CDElement::CDElement() {

}

CDElement::CDElement(uint8_t x, uint8_t y, int8_t w, int8_t h){
	setBounds(x, y, w, h);
}

CDElement::~CDElement() {
	delete bounds;
}

void CDElement::setDimensions(uint8_t width, uint8_t height){
	if(this->bounds->setDimensions(width, height)){
		revalidate();
	}
}

Dimension CDElement::getDimensions(){
	return this->bounds->getDimensions();
}

void CDElement::setPosition(uint8_t x, uint8_t y){
	if(this->bounds->setPoint(x, y)){
		revalidate();
	}
}

Point* CDElement::getPosition(){
	return this->bounds;
}

void CDElement::moveBy(uint8_t x, uint8_t y){
	if(this->bounds->setPointBy(x, y)){
		revalidate();
	}
}

Rectangle* CDElement::getBounds(){
	return this->bounds;
}

void CDElement::setBounds(Rectangle bounds){
	setBounds(bounds.getX(), bounds.getY(),
			bounds.getWidth(), bounds.getHeight());
}

void CDElement::setBounds(uint8_t x, uint8_t y, int8_t w, int8_t h){
	this->bounds->setRectangle(x, y, w, h);
}

void CDElement::setParent(ICDElement* parent){
	this->parent = parent;
}


ICDElement* CDElement::getParent(){
	return this->parent;
}

/*void CDElement::print(LCD* lcd){
	ICDElement::reprint();
}

void CDElement::reprint(){
	ICDElement::reprint();
}*/

void CDElement::printArea(LCD* lcd, Rectangle* area){
	//if(area->intersects(getBounds())){
		//Rectangle r = area->intersection(getBounds());

		//lcd->setCursor(area);
		cout << "PrintArea: [";
		cout << (int)area->getX();
		cout << ", ";
		cout << (int)area->getY();
		cout << ", ";
		cout << (int)area->getWidth();
		cout << ", ";
		cout << (int)area->getHeight();
		cout << "] of" ;
		cout << this << endl;
	//}
}

void CDElement::validate(){

}

void CDElement::revalidate(){

}
