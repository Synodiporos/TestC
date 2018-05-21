/*
 * CDFrame.cpp
 *
 *  Created on: May 21, 2018
 *      Author: sgeorgiadis
 */

#include <iostream>
using namespace std;
#include "CDFrame.h"

CDFrame::CDFrame(uint8_t width, uint8_t height){
	elements = new ICDElement*[0];
	init();
}

CDFrame::CDFrame(uint8_t width, uint8_t height, uint8_t capacity){
	this->bounds->setDimensions(width, height);
	this->capacity = capacity;
	elements = new ICDElement*[capacity];
	for(int i=0; i<capacity; i++)
		elements[i] = nullptr;
	init();
}

void CDFrame::init(){
	lcd.init(bounds->getWidth(), bounds->getHeight());
	lcd.setCursor(0, 0);
}

CDFrame::~CDFrame() {
	// TODO Auto-generated destructor stub
}

void CDFrame::setPage(ICDElement* elem, uint8_t index){
	if(elem && index<capacity){
		elem->setParent(this);
		ICDElement* old = elements[index];
		if(old)
			old->setParent(nullptr);
		elements[index] = elem;
		setCurrentPageIndex(index);
	}
}

ICDElement* CDFrame::getPage(uint8_t index){
	if(index<capacity){
		return elements[index];
	}
	return nullptr;
}

void CDFrame::removePage(uint8_t index){
	if(index<capacity){
		ICDElement* old = elements[index];
		if(old)
			old->setParent(nullptr);
		elements[index] = nullptr;
	}
}

void CDFrame::setCurrentPageIndex(uint8_t index){
	this->currentIndex = index;
	//
}

ICDElement* CDFrame::getCurrentPage(){
	if(currentIndex>=0)
		return getPage(currentIndex);
	return nullptr;
}

Rectangle* CDFrame::getBounds(){
	return this->bounds;
}

void CDFrame::setParent(ICDElement* parent){

}

ICDElement* CDFrame::getParent(){
	return nullptr;
}

void CDFrame::print(){
	print(&this->lcd);
}

void CDFrame::print(LCD* lcd){
	if(lcd)
		printArea(lcd, bounds);
}

void CDFrame::reprint(){
	print();
}

void CDFrame::printArea(LCD* lcd, Rectangle* area){
	cout << "!!  PrintArea Of Root Parent  !!" << endl;
	if(lcd){
		ICDElement* cp = getCurrentPage();
		if(cp)
			cp->printArea(lcd, area);
	}
}

void CDFrame::printArea(Rectangle* area){
	printArea(&lcd, area);
}

void CDFrame::validate(){

}
