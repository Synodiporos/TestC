/*
 * ICDElement.cpp
 *
 *  Created on: 12 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#include "ICDElement.h"

ICDElement::ICDElement() {
	// TODO Auto-generated constructor stub

}

ICDElement::~ICDElement() {
	// TODO Auto-generated destructor stub
}

void ICDElement::setParent(ICDElement* parent){
	this->parent = parent;
}

ICDElement* ICDElement::getParent(){
	return this->parent;
}

bool ICDElement::hasParent(){
	if(getParent())
		return false;
	return true;
}

void ICDElement::print(LCD* lcd){
	Rectangle* area = new Rectangle(0, 0,
				area->getWidth(),
				area->getHeight());
	printArea(lcd, area);
}

void ICDElement::reprint(){
	Rectangle* area = new Rectangle(0, 0,
			area->getWidth(),
			area->getHeight());
	printArea(area);
}

void ICDElement::printArea(Rectangle* area){
	if(hasParent()){
		Rectangle* r = new Rectangle(
				area->getX() + getBounds()->getX(),
				area->getY() + getBounds()->getY(),
				area->getWidth(),
				area->getHeight());
		getParent()->printArea(r);
	}
}
