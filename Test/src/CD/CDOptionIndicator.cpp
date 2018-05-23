/*
 * CDOptionIndicator.cpp
 *
 *  Created on: May 23, 2018
 *      Author: sgeorgiadis
 */

#include "CDOptionIndicator.h"

CDOptionIndicator::CDOptionIndicator() {
	// TODO Auto-generated constructor stub

}

CDOptionIndicator::~CDOptionIndicator() {
	// TODO Auto-generated destructor stub
}

void CDOptionIndicator::setState(uint8_t state){
	if(this->state!=state){
		this->state = state;
		reprint();
	}
}

uint8_t CDOptionIndicator::getState(){
	return this->state;
}

void CDOptionIndicator::setParent(ICDElement* parent){
	this->parent = parent;
}

ICDElement* CDOptionIndicator::getParent(){
	return this->parent;
}

Rectangle* CDOptionIndicator::getBounds(){
	return new Rectangle(0, 0, 1, 1);
}

void CDOptionIndicator::printArea(LCD* lcd, Rectangle* area){
	//if(area->getX()==0 && area->getY()==0)
	char ind = '\0';
	switch(this->state){
		case CDOptionIndicator::UNHOVERED:{
			ind = '+';
			break;
		}
		case CDOptionIndicator::HOVERED:{
			ind = '-';
			break;
		}
		case CDOptionIndicator::CLICKED:{
			ind = '>';
			break;
		}
	}
	lcd->print(&ind);
}

void CDOptionIndicator::validate(){

}

