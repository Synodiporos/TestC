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

CDVScrollbar::CDVScrollbar(){

}

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
	return new Rectangle(getX(), 0, 1, getHeight());
}

void CDVScrollbar::setX(int8_t x){
	this->x = x;
}

int8_t CDVScrollbar::getX(){
	return this->x;
}

void CDVScrollbar::setHeight(uint8_t height){
	this->height = height;
}

uint8_t CDVScrollbar::getHeight(){
	return this->height;
}

void CDVScrollbar::printArea(LCD* lcd, Rectangle* area){
	if(height>0){
		int ccx = lcd->getCursorX();
		int ccy = lcd->getCursorY();
		for(int i=0; i<height; i++){
			if(area->contains(0, i)){
				lcd->setCursor(ccx, ccy+i);
				lcd->print('^');
			}
		}

		lcd->setCursor(ccx, ccy);
	}
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

void CDVScrollbar::updateScrollBarValue(){
	AbstractCDElement* ce = getPage();
	uint8_t sh = getBounds()->getHeight();
	uint8_t w = ce->getBounds()->getHeight() - sh;
	int8_t y = getBounds()->getY() -
			ce->getBounds()->getY();
	uint8_t steps = 9 + (sh-2)*8;
	double  p = (double)y/w;
	if(p<0) p=0;
	else if(p>1) p = 1;

	short int ip = std::ceil((double)p*steps);
	if(p==1)
		ip = steps + 1;

	if(this->scrollbarValue!=ip){
		this->scrollbarValue = ip;
		reprintScrollbar(ip, steps);
	}
}

void CDVScrollbar::reprintScrollbar(uint8_t value, uint8_t pixels){
	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();
	uint8_t sw = getBounds()->getWidth()-1;
	uint8_t sh = getBounds()->getHeight()-1;
	cout<< "Scroll bar: Y=" << (int)getBounds()->getY()  ;

	cout << " - Pixel char: " ;
	if(value<=5){
		lcd->setCursor(sw, 0);
		lcd->writeChar(CDCharacters::createScrollbarTopChar(value));
		for(short int i=1; i<sh ;i++){
			lcd->setCursor(sw, i);
			char c[2] = {' ','\0'};
			lcd->print(c);
		}
		lcd->setCursor(sw, sh);
		lcd->printChar(3);
		cout << 0 << " pixel: " << (int)value;
	}
	else if(value>pixels-4){
		int px = value-(pixels-4);
		lcd->setCursor(sw, 0);
		lcd->printChar(2);
		for(short int i=1; i<sh ;i++){
			lcd->setCursor(sw, i);
			char c[2] = {' ','\0'};
			lcd->print(c);
		}
		lcd->setCursor(sw, sh);
		lcd->writeChar(CDCharacters::createScrollbarBottomChar(px));
		cout<< (int)sh << " ,pixel: " << px;
	}
	else{
		int npx = 1+((value-6)/8);
		int px = (value-6)%8 + 1;
		lcd->setCursor(sw, 0);
		lcd->printChar(2);
		for(short int i=1; i<sh ;i++){
			lcd->setCursor(sw, i);
			lcd->writeChar(CDCharacters::createScrollbarMiddleChar(px));
		}
		lcd->setCursor(sw, sh);
		lcd->printChar(3);
		cout << npx << " .pixel: " << px;
	}
	cout<<endl;
	lcd->setCursor(ccx, ccy);
}
