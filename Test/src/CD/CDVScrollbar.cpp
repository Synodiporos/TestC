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

const uint8_t CDVScrollbar::getHeight() const{
	return this->height;
}

const Rectangle CDVScrollbar::getBounds() const{
	return Rectangle(getX(), 0, 1, getHeight());
}

void CDVScrollbar::setX(int8_t x){
	this->x = x;
}

int8_t CDVScrollbar::getX() const{
	return this->x;
}

void CDVScrollbar::setHeight(uint8_t height) const{
	this->height = height;
}
/*

uint8_t CDVScrollbar::getHeight(){
	return this->height;
}
*/

void CDVScrollbar::printArea(LCD* lcd, const Rectangle* area){
	if(height>0){
		int ccx = lcd->getCursorX();
		int ccy = lcd->getCursorY();

		uint8_t levelValue = calculateLevelValue();
		Rectangle inter = getBounds().intersection(area);
		if(inter.getX()==getX()){
			uint8_t y = inter.getY();
			uint8_t h = y + inter.getHeight();
			for(int i=y; i<h; i++){
				//if(area->contains(0, i)){
					lcd->setCursor(ccx, ccy+i);
					//lcd->print('^');
					printChar(lcd, i, levelValue);
				//}
			}
			lcd->setCursor(ccx, ccy);
		}
	}
}

void CDVScrollbar::printChar(LCD* lcd, uint8_t index, uint8_t value){
	uint8_t tChars = getHeight();
	uint8_t ch[8] ;
	uint8_t px = value;
	if(index==0){
		if(px<4){
			CDCharacters::createScrollbarTopChar(px, ch);
			//lcd->writeChar(ch);
			lcd->print((char)px);
		}
		else{
			lcd->print(' ');
		}
		cout << "Top char: " << (int)px << endl;
	}
	else if(index>0 && index<tChars-1){
		px = value - ((index-1)*8 + 4);
		if(px<=0 && px>=8){
			lcd->print(' ');
		}else{
			CDCharacters::createScrollbarTopChar(px, ch);
			//lcd->writeChar(ch);
			lcd->print((char)px);
		}
	}
	else{
		px = value - ((index-1)*8 + 4);
		if(px>0 && px<5){
			CDCharacters::createScrollbarBottomChar(px, ch);
			//lcd->writeChar(ch);
			lcd->print((char)px);
		}
		else
			lcd->print(' ');
		cout << "Bottom char: " << (int)px << endl;
	}
}

void CDVScrollbar::validate(){
	//recalculateValue();
}

uint8_t CDVScrollbar::calculateLevelValue(){
	uint8_t steps = 9 + (height-2)*8;
	double sy = ((double)value*steps)/100;

	uint8_t r = std::ceil(sy);
	if(value==100)
		r = steps + 1;

	//cout << "Scroll steps: " << sy << " round:"<< r << endl;
	return r;
}

uint8_t CDVScrollbar::scrollbarValue(AbstractCDElement* page,
		AbstractCDElement* frame){
	float v = (float)(frame->getBounds().getY() - page->getBounds().getY()) /
			(page->getHeight()-frame->getHeight());

	uint8_t res = std::ceil(v*100);
	if(res<0)
		return 0;
	if(res>100)
		return 100;
	return res;
}
