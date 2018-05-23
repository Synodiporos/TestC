/*
 * CDOption.cpp
 *
 *  Created on: May 23, 2018
 *      Author: sgeorgiadis
 */

#include "CDOption.h"

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

CDOption::~CDOption() {
	// TODO Auto-generated destructor stub
}

void CDOption::init(){
	this->label.setLocation(1,0);
}

void CDOption::setParent(ICDElement* parent){
	this->parent = parent;
}

ICDElement* CDOption::getParent(){
	return this->parent;
}

Rectangle* CDOption::getBounds(){
	return new Rectangle(x, y, 1, 1);
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
	this->indicator.setState(state);
}

uint8_t CDOption::getOptionState(){
	return this->indicator.getState();
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

}

void CDOption::printIndicator(){

}

void CDOption::printArea(LCD* lcd, Rectangle* area){


}

void CDOption::validate(){

}

