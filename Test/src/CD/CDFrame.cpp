/*
 * CDFrame.cpp
 *
 *  Created on: May 21, 2018
 *      Author: sgeorgiadis
 */

#include <iostream>
#include <cmath>
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
	elements = new AbstractCDElement*[capacity];
	for(int i=0; i<capacity; i++)
		elements[i] = nullptr;
}

CDFrame::~CDFrame() {
	// TODO Auto-generated destructor stub
}

void CDFrame::setPage(AbstractCDElement* elem, uint8_t index){
	if(elem && index<capacity){
		elem->setParent(this);
		AbstractCDElement* old = elements[index];
		if(old)
			old->setParent(nullptr);
		elements[index] = elem;
		setCurrentPageIndex(index);
	}
}

AbstractCDElement* CDFrame::getPage(uint8_t index){
	if(index<capacity){
		return elements[index];
	}
	return nullptr;
}

void CDFrame::removePage(uint8_t index){
	if(index<capacity){
		AbstractCDElement* old = elements[index];
		if(old)
			old->setParent(nullptr);
		elements[index] = nullptr;
	}
}

void CDFrame::setCurrentPageIndex(uint8_t index){
	this->currentIndex = index;
	//
}

AbstractCDElement* CDFrame::getCurrentPage(){
	if(currentIndex>=0)
		return getPage(currentIndex);
	return nullptr;
}

void CDFrame::setParent(AbstractCDElement* parent){
	this->parent = parent;
}

AbstractCDElement* CDFrame::getParent(){
	return this->parent;
}

Rectangle* CDFrame::getBounds(){
	return &lcd;
}

void CDFrame::setPosition(short int x, short int y){
	if(lcd.setPoint(x, y))
		revalidate();
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
	//lcd->setCursor(0, 0);

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
		AbstractCDElement* cp = getCurrentPage();
		if(cp){
			Rectangle inter = cp->getBounds()->intersection(area);
			if(!inter.isNull()){
				lcd->setCursor(
						cp->getBounds()->getX() - getBounds()->getX(),
						cp->getBounds()->getY() - getBounds()->getY());
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


void CDFrame::revalidate(){
	//cout << "Revalidate Frame: ";

	updateScrollBarValue();
}

void CDFrame::updateScrollBarValue(){
	AbstractCDElement* ce = getCurrentPage();
	if(ce){
		uint8_t w = ce->getBounds()->getHeight() -
				getBounds()->getHeight();
		int8_t y = getBounds()->getY() -
				ce->getBounds()->getY();
		uint8_t steps = 9 + (getBounds()->getHeight()-2)*8;


		double  p = (double)y/w;
		if(p<0) p=0;
		else if(p>1) p = 1;

		short int ip = std::ceil((double)p*steps);

		cout<< "Scroll bar: y=" << getBounds()->getY() <<
				", p="<< p << ", round: " << ip << endl;

		if(p==1)
			ip = steps + 1;

		cout << "Scroll PY pixel: " << ip << endl;
	}
}


void CDFrame::recalculateScrollbarValue(){

}
