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

uint8_t AbstractCDElement::getWidth(){
	return getBounds()->getWidth();
}

uint8_t AbstractCDElement::getHeight(){
	return getBounds()->getHeight();
}

void AbstractCDElement::print(LCD* lcd){
	if(isVisible()){
		Rectangle* r = new Rectangle(0, 0,
					getBounds()->getWidth(),
					getBounds()->getHeight());
		printArea(lcd, r);
	}
}

void AbstractCDElement::reprint(){
	Rectangle* r = new Rectangle(0, 0,
			getBounds()->getWidth(),
			getBounds()->getHeight());
	printArea(r);
}

void AbstractCDElement::printArea(Rectangle* area){
	if(hasParent() && isVisible()){
		Rectangle* r = new Rectangle(
				area->getX() + getBounds()->getX(),
				area->getY() + getBounds()->getY(),
				area->getWidth(),
				area->getHeight());
		getParent()->printArea(r);
	}
}
