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

bool AbstractCDElement::hasParent(){
	if(getParent())
		return true;
	return false;
}

void AbstractCDElement::print(LCD* lcd){
	Rectangle* r = new Rectangle(0, 0,
				getBounds()->getWidth(),
				getBounds()->getHeight());
	printArea(lcd, r);
}

void AbstractCDElement::reprint(){
	Rectangle* r = new Rectangle(0, 0,
			getBounds()->getWidth(),
			getBounds()->getHeight());
	printArea(r);
}

void AbstractCDElement::printArea(Rectangle* area){
	//cout << this << " has parent: "<< hasParent() << endl;
	if(hasParent()){
		Rectangle* r = new Rectangle(
				area->getX() + getBounds()->getX(),
				area->getY() + getBounds()->getY(),
				area->getWidth(),
				area->getHeight());
		getParent()->printArea(r);
	}
}
