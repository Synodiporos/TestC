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
	scrollbar.setX(getBounds().getX()+getBounds().getWidth()-1);
	scrollbar.setHeight(getBounds().getHeight());
}

void CDFrame::setLCD(LCD* lcd){
	this->lcd = lcd;
}

LCD* CDFrame::getLCD(){
	return lcd;
}

void CDFrame::setPage(AbstractCDElement* elem){
	if(this->page!=elem){
		if(this->page){
			this->page->setParent(nullptr);
			this->page->setPropertyListener(nullptr);
		}
		if(elem){
			elem->setParent(this);
			elem->setPropertyListener(this);
		}
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

const Rectangle CDFrame::getBounds() const{
	return *lcd;
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
			return ce->getBounds().getHeight()>
				getBounds().getHeight();
		return false;
	}
}

void CDFrame::print(){
	//clean();
	print(this->lcd);
}

void CDFrame::print(LCD* lcd){
	Rectangle bounds = getBounds();
	printArea(lcd, &bounds);
}

void CDFrame::reprint(){
	print();
}

//To Global Coordinates
void CDFrame::printArea(LCD* lcd, const Rectangle* area){
	cout << "!!  PrintArea Of Root Parent  area:" << endl;
	//lcd->setCursor(0, 0);

	cout << "PrintArea: of " << this << " " ;
	area->print();


	if(lcd){
		AbstractCDElement* cp = getPage();
		printChild(cp, lcd, area);
		printChild(&scrollbar, lcd, area);
	}
}

void CDFrame::printChild(
		AbstractCDElement* child, LCD* lcd, const Rectangle* area){
	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	if(child && child->isVisible()){
		Rectangle inter = child->getBounds().intersection(area);
		//inter.print();
		if(!inter.isNull()){
			lcd->setCursor(
					child->getBounds().getX() - getBounds().getX(),
					child->getBounds().getY() - getBounds().getY());
			inter.setPointBy(-child->getBounds().getX(),
					-child->getBounds().getY());
			child->printArea(lcd, &inter);
		}
	}
	lcd->setCursor(ccx, ccy);
}

void CDFrame::printArea(const Rectangle* area){
	Rectangle inter = getBounds().intersection(area);
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
	revalidateScrollbar();
}

void CDFrame::revalidateScrollbar(){
	if(getPage()){
		if(this->scrollbarState == CDFrame::SRCOLLBAR_STATE_NEVER){

			}
		else if(this->scrollbarState == CDFrame::SRCOLLBAR_STATE_ALWAYS
				|| (getPage()->getHeight()>getHeight())){

			uint8_t scrollbarValue = CDVScrollbar::scrollbarValue(getPage(), this);
			this->scrollbar.setValue(scrollbarValue);
		}
	}
}

void CDFrame::propertyChanged(
			void* source, unsigned short int propertyId, const void* oldPropery){
	AbstractCDElement* ae = (AbstractCDElement*)source;

	switch (propertyId){
		case AbstractCDElement::DIMENSIONS_PROPERTY:{

			break;
		}
		case AbstractCDElement::POSITION_PROPERTY:{
			if(getPage()==ae){
				revalidateScrollbar();
				clean();
				print();
			}
			break;
		}
	}
}

