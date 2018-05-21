/*
 * ICDElement.cpp
 *
 *  Created on: 12 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "ICDElement.h"

ICDElement::ICDElement() {
	// TODO Auto-generated constructor stub

}

ICDElement::~ICDElement() {
	// TODO Auto-generated destructor stub
}

bool ICDElement::hasParent(){
	if(getParent())
		return true;
	return false;
}

void ICDElement::print(LCD* lcd){
	Rectangle* r = new Rectangle(0, 0,
				getBounds()->getWidth(),
				getBounds()->getHeight());
	printArea(lcd, r);
}

void ICDElement::reprint(){
	Rectangle* r = new Rectangle(0, 0,
			getBounds()->getWidth(),
			getBounds()->getHeight());
	printArea(r);
}

void ICDElement::printArea(Rectangle* area){
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
