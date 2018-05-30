/*
 * CDVScrollbar.cpp
 *
 *  Created on: May 24, 2018
 *      Author: sgeorgiadis
 */
#include <iostream>
#include <cmath>
using namespace std;
#include "CDVScrollbar.h"

CDVScrollbar::CDVScrollbar(uint8_t x, uint8_t height) {
	// TODO Auto-generated constructor stub
	this->x = x;
	this->height = height;
}

CDVScrollbar::~CDVScrollbar() {
	// TODO Auto-generated destructor stub
}

void CDVScrollbar::setValue(uint8_t value){
	if(getValue()!=value){
		this->value=value;
		recalculateValue();
	}
}

uint8_t CDVScrollbar::getValue(){
		return this->value;
}

void CDVScrollbar::setParent(AbstractCDElement* parent){
	this->parent = parent;
}

AbstractCDElement* CDVScrollbar::getParent(){
	return this->parent;
}

Rectangle* CDVScrollbar::getBounds(){
	return new Rectangle(x, 0, 1, height);
}

void CDVScrollbar::printArea(LCD* lcd, Rectangle* area){

}

void CDVScrollbar::validate(){

}

void CDVScrollbar::recalculateValue(){
	uint8_t steps = 9 + (height-2)*8;
	double sy = ((double)value*steps)/100;

	short int r = std::ceil(sy);
	if(value==100)
		r = steps + 1;

	cout << "Scroll PY: " << sy << " round:"<< r << endl;
}
