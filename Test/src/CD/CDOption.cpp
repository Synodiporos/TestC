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
	: label(width-1, label){
	setWidth(width);
	init();
}

CDOption::CDOption(int8_t x, int8_t y, uint8_t width, char* label)
	: label(width-1, label){
	setWidth(width);
	setLocation(x, y);
	init();
}

CDOption::CDOption(int8_t x, int8_t y, uint8_t width, char* label, unsigned int actionId)
	: label(width-1, label){
	setWidth(width);
	setLocation(x, y);
	setActionId(actionId);
	init();
}

CDOption::~CDOption() {
	// TODO Auto-generated destructor stub
}

void CDOption::init(){
	this->label.setLocation(1,0);
	this->label.setParent(this);
	this->indicator.setParent(this);
}

void CDOption::setActionId(unsigned int actionId){
	this->actionId = actionId;
}

unsigned int CDOption::getActionId(){
	return this->actionId;
}

void CDOption::setParent(AbstractCDElement* parent){
	this->parent = parent;
}

AbstractCDElement* CDOption::getParent(){
	return this->parent;
}

Rectangle* CDOption::getBounds(){
	return new Rectangle(x, y, width, 1);
}

CDLabel* CDOption::getLabel(){
	return &this->label;
}

CDOptionIndicator* CDOption::getIndicator(){
	return &this->indicator;
}

void CDOption::setWidth(uint8_t width){
	this->width = width;
}

uint8_t CDOption::getWidth(){
	return this->width;
}

void CDOption::setLocation(int8_t x, int8_t y){
	this->x = x;
	this->y = y;
}

Point* CDOption::getLocation(){
	return new Point(this->x, this->y);
}

void CDOption::setOptionState(uint8_t state){
	if(getOptionState()!=state){
		this->indicator.setState(state);
		notifyStateChanged();

		if(AutoRolling_state==AutoRolling_Never){}
		else if(state==CDOptionIndicator::HOVERED){
			if(AutoRolling_state==AutoRolling_OnHover)
				this->label.startRolling();
			else
				this->label.stopRolling();
		}
		else if(state==CDOptionIndicator::CLICKED){
			if(AutoRolling_state==AutoRolling_OnClick)
				this->label.startRolling();
			else
				this->label.stopRolling();
		}
	}
}

uint8_t CDOption::getOptionState(){
	return this->indicator.getState();
}

void CDOption::hover(){
	setOptionState(CDOptionIndicator::HOVERED);
}

void CDOption::unhover(){
	setOptionState(CDOptionIndicator::UNHOVERED);
}

void CDOption::click(){
	setOptionState(CDOptionIndicator::CLICKED);
}

void CDOption::setStateListener(IStateListener* l){
	this->stateListener = l;
}

void CDOption::removeStateListener(IStateListener* l){
	this->stateListener = nullptr;
}

IStateListener* CDOption::getStateListener(){
	return this->stateListener;
}

void CDOption::notifyStateChanged(){
	if(this->stateListener!=nullptr){
		State* s = new State(this,'\0', nullptr);
		this->stateListener->stateChanged(s);
	}
}

void CDOption::printIndicator(){

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

	printChild(&indicator, lcd, area);
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

void CDOption::validate(){
	this->indicator.validate();
	this->label.validate();
}

