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
#include "CDCharacters.h"

CDFrame::CDFrame(uint8_t width, uint8_t height, LCD* lcd)
	: lcd(lcd){
	init();
}

CDFrame::CDFrame(short int x, short int y,
		uint8_t width, uint8_t height, LCD* lcd)
		:lcd(lcd){
	init();
}

CDFrame::~CDFrame() {
	// TODO Auto-generated destructor stub
}

void CDFrame::init(){
	scrollbar.setX(getBounds()->getX()+getBounds()->getWidth()-1);
	scrollbar.setHeight(getBounds()->getHeight());
}

void CDFrame::setLCD(LCD* lcd){
	this->lcd = lcd;
}

LCD* CDFrame::getLCD(){
	return lcd;
}

void CDFrame::setPage(AbstractCDElement* elem){
	if(this->page!=elem){
		if(this->page)
			this->page->setParent(nullptr);
		if(elem)
			elem->setParent(this);
		this->page = elem;
		clean();
		print();
	}
}

AbstractCDElement* CDFrame::getPage(){
	return this->page;
}

void CDFrame::setParent(AbstractCDElement* parent){
	//this->parent = parent;
}

AbstractCDElement* CDFrame::getParent(){
	return nullptr;//this->parent;
}

Rectangle* CDFrame::getBounds(){
	return lcd;
}

void CDFrame::setPosition(short int x, short int y){
	if(lcd->setPoint(x, y))
		revalidate();
}

void CDFrame::setScrollbarState(uint8_t state){
	this->scrollbarState = state;
}

uint8_t CDFrame::getScrollbarState(){
	return this->scrollbarState;
}

bool CDFrame::isScrollbarVisible(){
	if(getScrollbarState()==CDFrame::SRCOLLBAR_STATE_NEVER)
		return false;
	else if(getScrollbarState()==CDFrame::SRCOLLBAR_STATE_ALWAYS)
		return true;
	else{
		AbstractCDElement* ce = getPage();
		if(ce)
			return ce->getBounds()->getHeight()>
				getBounds()->getHeight();
		return false;
	}
}

void CDFrame::print(){
	print(this->lcd);
}

void CDFrame::print(LCD* lcd){
	printArea(lcd, getBounds());
}

void CDFrame::reprint(){
	print();
}

//To Global Coordinates
void CDFrame::printArea(LCD* lcd, Rectangle* area){
	cout << "!!  PrintArea Of Root Parent  area:" << endl;
	//lcd->setCursor(0, 0);

	cout << "PrintArea: of " << this << " " ;
	area->print();


	if(lcd){
		AbstractCDElement* cp = getPage();
		/*if(cp){
			Rectangle inter = cp->getBounds()->intersection(area);
			//inter.print();
			if(!inter.isNull()){
				lcd->setCursor(
						cp->getBounds()->getX() - getBounds()->getX(),
						cp->getBounds()->getY() - getBounds()->getY());
				inter.setPointBy(-cp->getBounds()->getX(),
						-cp->getBounds()->getY());
				cp->printArea(lcd, &inter);
			}
		}*/

		printChild(cp, lcd, area);
		printChild(&scrollbar, lcd, area);
	}
}

void CDFrame::printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area){
	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	if(child && child->isVisible()){
		Rectangle inter = child->getBounds()->intersection(area);
		//inter.print();
		if(!inter.isNull()){
			lcd->setCursor(
					child->getBounds()->getX() - getBounds()->getX(),
					child->getBounds()->getY() - getBounds()->getY());
			inter.setPointBy(-child->getBounds()->getX(),
					-child->getBounds()->getY());
			child->printArea(lcd, &inter);
		}
	}
	lcd->setCursor(ccx, ccy);
}

void CDFrame::printArea(Rectangle* area){
	Rectangle inter = getBounds()->intersection(area);
	if(!inter.isNull())
		printArea(lcd, &inter);
}

void CDFrame::clean(){
	if(lcd)
		lcd->clear();
}

void CDFrame::validate(){
	AbstractCDElement* page = getPage();
	if(page)
		page->validate();
}


void CDFrame::revalidate(){
	//cout << "Revalidate Frame: ";

	updateScrollBarValue();
}

void CDFrame::updateScrollBarValue(){

	if(isScrollbarVisible()){
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
}

void CDFrame::reprintScrollbar(uint8_t value, uint8_t pixels){
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

