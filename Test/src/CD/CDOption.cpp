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

CDOption::CDOption(uint8_t width, char* label)
	: AbstractCDOption(width), label(width-1, label){
	init();
}

CDOption::CDOption(int8_t x, int8_t y, uint8_t width, char* label)
	: AbstractCDOption(x, y, width), label(width-1, label){
	init();
}

CDOption::CDOption(int8_t x, int8_t y, uint8_t width, char* label, unsigned int actionId)
	: AbstractCDOption(x, y, width, actionId), label(width-1, label){
	init();
}

CDOption::~CDOption() {
	// TODO Auto-generated destructor stub
}

void CDOption::init(){
	this->label.setLocation(1,0);
	this->label.setParent(this);
	//this->indicator.setParent(this);
}

CDLabel* CDOption::getLabel(){
	return &this->label;
}

void CDOption::onOptionStateChanged(){
	reprintIndicator();

	if(AutoRolling_state==AutoRolling_Never){

	}
	else if(getOptionState()==HOVERED){
		if(AutoRolling_state==AutoRolling_OnHover)
			this->label.startRolling();
		else
			this->label.stopRolling();
	}
	else if(getOptionState()==CLICKED){
		if(AutoRolling_state==AutoRolling_OnClick)
			this->label.startRolling();
		else
			this->label.stopRolling();
	}
}


void CDOption::printArea(LCD* lcd, Rectangle* area){
	/*cout << "Option PrintArea: [";
	cout << (int)area->getX();
	cout << ", ";
	cout << (int)area->getY();
	cout << ", ";
	cout << (int)area->getWidth();
	cout << ", ";
	cout << (int)area->getHeight();
	cout << "] of " ;
	cout << this << endl;*/


	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	//Print Indicator
	if(area->getX()==0 && area->getY()==0 &&
			area->getWidth()>0 && area->getHeight()>0)
		printIndicator(lcd);

	//Print Label
	printChild(&label, lcd, area);

	lcd->setCursor(ccx, ccy);
}

void CDOption::printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area){
	if(child){
		Rectangle r = area->intersection(
				child->getBounds());
		if(!r.isNull()){
			int cx =  0 + child->getBounds()->getX();
			int cy =  0 + child->getBounds()->getY();

			lcd->setCursorBy(cx, cy);

			r.setPointBy(-child->getBounds()->getX(),
					-child->getBounds()->getY());
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

void CDOption::reprintLabel(){
	uint8_t width = getWidth();
	Rectangle* r = new Rectangle(1, 0, width, 1);
	AbstractCDElement::printArea(r);
}

void CDOption::validate(){
	//this->indicator.validate();
	this->label.validate();
}

