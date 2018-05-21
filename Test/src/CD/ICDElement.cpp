/*
 * ICDElement.cpp
 *
 *  Created on: 12 Μαΐ 2018
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
