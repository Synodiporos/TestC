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

CDElement::CDElement() : bounds{Rectangle()}{
	//setBounds(0,0,0,0);
}

CDElement::CDElement(int8_t w, int8_t h)
	: bounds{Rectangle(0,0,w,h)}{
	//setBounds(0, 0, w, h);
}

CDElement::CDElement(uint8_t x, uint8_t y, int8_t w, int8_t h)
	: bounds{Rectangle(x,y,w,h)}{
	setBounds(x, y, w, h);
}

CDElement::~CDElement() {

}

bool CDElement::setDimensions(uint8_t width, uint8_t height){
	if(this->bounds.setDimensions(width, height)){
		revalidate();
		notifyPropertyChanged(AbstractCDElement::DIMENSIONS_PROPERTY,
				&this->bounds);
		return true;
	}
	return false;
}

Dimension CDElement::getDimensions(){
	return this->bounds.getDimensions();
}

bool CDElement::setPosition(int8_t x, int8_t y){
	if(this->bounds.setPoint(x, y)){
		revalidate();
		notifyPropertyChanged(AbstractCDElement::POSITION_PROPERTY,
						&this->bounds);
		return true;
	}
	return false;
}

const Point* CDElement::getPosition(){
	return &this->bounds;
}

bool CDElement::moveBy(uint8_t x, uint8_t y){
	if(this->bounds.setPointBy(x, y)){
		revalidate();
		return true;
	}
	return false;
}

const Rectangle CDElement::getBounds() const{
	return this->bounds;
}

bool CDElement::setBounds(Rectangle bounds){
	return setBounds(bounds.getX(), bounds.getY(),
			bounds.getWidth(), bounds.getHeight());
}

bool CDElement::setBounds(uint8_t x, uint8_t y, int8_t w, int8_t h){
	if(this->bounds.setRectangle(x, y, w, h)){
		notifyPropertyChanged(AbstractCDElement::DIMENSIONS_PROPERTY,
						&this->bounds);
		return true;
	}
	return false;
}

void CDElement::setParent(AbstractCDElement* parent){
	this->parent = parent;
}


AbstractCDElement* CDElement::getParent(){
	return this->parent;
}

/*void CDElement::print(LCD* lcd){
	AbstractCDElement::reprint();
}

void CDElement::reprint(){
	AbstractCDElement::reprint();
}*/

void CDElement::printArea(LCD* lcd, const Rectangle* area){
	//if(area->intersects(getBounds())){
		//Rectangle r = area->intersection(getBounds());
		//int ccx = lcd->getCursorX();
		//int ccy = lcd->getCursorY();

		//lcd->setCursor(ccx+area->getX(), ccy+area->getY());

		/*cout << "PrintArea: [";
		cout << (int)area->getX();
		cout << ", ";
		cout << (int)area->getY();
		cout << ", ";
		cout << (int)area->getWidth();
		cout << ", ";
		cout << (int)area->getHeight();
		cout << "] of " ;
		cout << this << endl;*/

		//lcd->fillArea(area, '.');
		//lcd->setCursor(ccx, ccy);
	//}
}

void CDElement::validate(){

}

void CDElement::revalidate(){

}
