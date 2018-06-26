/*
 * CDOption.cpp
 *
 *  Created on: May 23, 2018
 *      Author: sgeorgiadis
 */
#include <iostream>
using namespace std;
#include "CDOption.h"
#include "../Commons/State.h"
#include "CDConstants.h"

CDOption::CDOption(uint8_t width, AbstractCDElement* element)
	: AbstractCDOption(width){
	init();
	setElement(element);
}

CDOption::CDOption(int8_t x, int8_t y, uint8_t width, AbstractCDElement* element)
	: AbstractCDOption(x, y, width){
	init();
	setElement(element);
}

CDOption::CDOption(int8_t x, int8_t y, uint8_t width,
		AbstractCDElement* element, unsigned int actionId)
	: AbstractCDOption(x, y, width, actionId){
	init();
	setElement(element);
}

CDOption::~CDOption() {
	// TODO Auto-generated destructor stub
}

void CDOption::init(){
	//this->label.setLocation(0,0);
	//this->label.setParent(this);
	//this->indicator.setParent(this);
}

/*CDLabel* CDOption::getLabel(){
	return &this->label;
}*/

bool CDOption::setElement(AbstractCDElement* element){
	if(this->element != element){
		if(this->element)
			this->element->setParent(nullptr);
		this->element = element;
		this->element->setParent(this);
		return true;
	}
	return false;
}

AbstractCDElement* CDOption::getElement(){
	return this->element;
}

void CDOption::onOptionStateChanged(){
	reprintIndicator();
}


void CDOption::printArea(LCD* lcd, const Rectangle* area){
	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	//Print Indicator
	if(area->getX()==0 && area->getY()==0 &&
			area->getWidth()>0 && area->getHeight()>0)
		printIndicator(lcd);

	//Print Element
	//area->setDimensions(area->getWidth()-1, area->getHeight());
	Rectangle* const r = new Rectangle(area->getX(), area->getY(),
			area->getWidth()-1, area->getHeight());
	printChild(getElement(), lcd, r);

	lcd->setCursor(ccx, ccy);
}

void CDOption::printChild(AbstractCDElement* child, LCD* lcd, const Rectangle* area){
	if(child){
		Rectangle cb = child->getBounds();
		Rectangle r = area->intersection(&cb);
		if(!r.isNull()){
			int cx =  1 + cb.getX();
			int cy =  0 + cb.getY();

			lcd->setCursorBy(cx, cy);

			r.setPointBy(-cb.getX(), -cb.getY());
			child->printArea(lcd, &r);
		}
	}
}

void CDOption::printIndicator(LCD* lcd){
	char ind = '\0';
	switch(this->getOptionState()){
		case UNHOVERED:{
			ind = CDOptionLabel_UNHOVERED;
			break;
		}
		case HOVERED:{
			ind = CDOptionLabel_HOVERED;
			break;
		}
		case CLICKED:{
			ind = CDOptionLabel_SELECTED;
			break;
		}
	}
	lcd->print(ind);
}

void CDOption::reprintIndicator(){
	Rectangle* r = new Rectangle(0, 0, 1, 1);
	AbstractCDElement::printArea(r);
}

void CDOption::reprintElement(){
	uint8_t width = getWidth();
	Rectangle* r = new Rectangle(1, 0, width, 1);
	AbstractCDElement::printArea(r);
}

void CDOption::validate(){
	//this->indicator.validate();
	if(getElement())
		getElement()->validate();
}

