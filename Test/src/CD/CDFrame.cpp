/*
 * CDFrame.cpp
 *
 *  Created on: May 21, 2018
 *      Author: sgeorgiadis
 */

#include <iostream>
using namespace std;
#include "CDFrame.h"

CDFrame::CDFrame(uint8_t width, uint8_t height,
		uint8_t capacity) : lcd{LCD(0, 0, width, height)}{
	//lcd = LCD(width, height);
	this->capacity = capacity;
	init();
}

CDFrame::CDFrame(short int x, short int y,
		uint8_t width, uint8_t height, uint8_t capacity)
		:lcd{LCD(x, y, width, height)}{
	//lcd = LCD(x, y, width, height);
	this->capacity = capacity;
	init();
}

void CDFrame::init(){
	//lcd.init(getBounds()->getWidth(), getBounds()->getHeight());
	//lcd.setCursor(0, 0);
	elements = new ICDElement*[capacity];
	for(int i=0; i<capacity; i++)
		elements[i] = nullptr;
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

void CDFrame::setParent(ICDElement* parent){
	this->parent = parent;
}

ICDElement* CDFrame::getParent(){
	return this->parent;
}

Rectangle* CDFrame::getBounds(){
	return &lcd;
}

void CDFrame::setPosition(short int x, short int y){
	lcd.setPoint(x, y);
}

void CDFrame::print(){
	print(&this->lcd);
}

void CDFrame::print(LCD* lcd){
	if(lcd)
		printArea(lcd, getBounds());
}

void CDFrame::reprint(){
	print();
}

//To Global Coordinates
void CDFrame::printArea(LCD* lcd, Rectangle* area){
	cout << "!!  PrintArea Of Root Parent  area:" << endl;

	cout << "PrintArea: [";

	cout << (int)area->getX();
	cout << ", ";
	cout << (int)area->getY();
	cout << ", ";
	cout << (int)area->getWidth();
	cout << ", ";
	cout << (int)area->getHeight();
	cout << "] of " ;
	cout << this << endl;


	if(lcd){
		ICDElement* cp = getCurrentPage();
		if(cp){
			lcd->setCursor(
					cp->getBounds()->getX()-getBounds()->getX(),
					cp->getBounds()->getY()-getBounds()->getY());
			//sc.setPointBy(-comp->getBounds()->getX(), -comp->getBounds()->getY());
			//Rectangle isc = cp->getBounds()->intersection(bounds);
			//lcd->setCursor(cp->getBounds()->getX(),
			//		cp->getBounds()->getY());
			Rectangle inter = cp->getBounds()->intersection(area);
			if(!inter.isNull()){
				//lcd->setCursor(inter.getX(), inter.getY());
				inter.setPointBy(-cp->getBounds()->getX(),
						-cp->getBounds()->getY());

				cp->printArea(lcd, &inter);
			}
		}
	}
}

void CDFrame::printArea(Rectangle* area){
	Rectangle inter = getBounds()->intersection(area);
	if(!inter.isNull())
		printArea(&lcd, &inter);
}

void CDFrame::validate(){

}
