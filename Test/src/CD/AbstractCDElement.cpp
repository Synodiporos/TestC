/*
 * AbstractCDElement.cpp
 *
 *  Created on: 12 Ξ�οΏ½ΞΏΞ�Β½Ξ�οΏ½Ξ’Β±Ξ�οΏ½ΞΏΞ�Β½ 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "AbstractCDElement.h"

AbstractCDElement::AbstractCDElement() {
	// TODO Auto-generated constructor stub

}

AbstractCDElement::~AbstractCDElement() {
	// TODO Auto-generated destructor stub
}

bool AbstractCDElement::isVisible(){
	return this->visible;
}

bool AbstractCDElement::setVisible(bool visible){
	if(this->visible!=visible){
		this->visible = visible;
		return true;
	}
	return false;
}

bool AbstractCDElement::hasParent(){
	if(getParent())
		return true;
	return false;
}

const uint8_t AbstractCDElement::getWidth() const{
	return getBounds().getWidth();
}

const uint8_t AbstractCDElement::getHeight() const{
	return getBounds().getHeight();
}

void AbstractCDElement::print(LCD* lcd){
	if(isVisible()){
		Rectangle* r = new Rectangle(0, 0,
					getBounds().getWidth(),
					getBounds().getHeight());
		printArea(lcd, r);
	}
}

void AbstractCDElement::reprint(){
	Rectangle* r = new Rectangle(0, 0,
			getBounds().getWidth(),
			getBounds().getHeight());
	printArea(r);
}

void AbstractCDElement::printArea(const Rectangle* area){
	if(hasParent() && isVisible()){
		Rectangle* r = new Rectangle(
				area->getX() + getBounds().getX(),
				area->getY() + getBounds().getY(),
				area->getWidth(),
				area->getHeight());
		getParent()->printArea(r);
	}
}

void AbstractCDElement::setPropertyListener(IPropertyListener* listener){
	this->propertyListener = listener;
}

IPropertyListener* AbstractCDElement::getPropertyListener(){
	return this->propertyListener;
}

void AbstractCDElement::notifyPropertyChanged(
		unsigned short int propertyId, const void* old){
	if(this->getPropertyListener())
		getPropertyListener()->propertyChanged(this, propertyId, old);
}
