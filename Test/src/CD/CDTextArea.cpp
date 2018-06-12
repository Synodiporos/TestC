/*
 * CDTextArea.cpp
 *
 *  Created on: Jun 12, 2018
 *      Author: sgeorgiadis
 */

#include "CDTextArea.h"
#include <iostream>
using namespace std;

CDTextArea::CDTextArea() {
	// TODO Auto-generated constructor stub
	init();
}

CDTextArea::CDTextArea(int8_t w, unsigned int capacity)
	: capacity(capacity){
	bounds->setDimensions(w, 1);
	init();
}

CDTextArea::CDTextArea(uint8_t x, uint8_t y, int8_t w, unsigned int capacity)
	: capacity(capacity){
	bounds->setPoint(x, y);
	bounds->setWidth(w);
	init();
}

CDTextArea::~CDTextArea() {
	// TODO Auto-generated destructor stub
}

void CDTextArea::init(){
	this->optionPane = new CDOptionPane(1, 1);
	this->optionPane->setParent(this);
	this->optionPane->setActionListener(this);
	CDCharOption* c = new CDCharOption(0, 0, ' ');
	optionPane->insertOption(c);
}

void CDTextArea::setParent(AbstractCDElement* parent){
	this->parent = parent;
}


AbstractCDElement* CDTextArea::getParent(){
	return this->parent;
}

Rectangle* CDTextArea::getBounds(){
	return this->bounds;
}

void CDTextArea::setCapacity(unsigned int capacity){
	this->capacity = capacity;
}

unsigned int CDTextArea::getCapacity(){
	return this->capacity;
}

uint8_t CDTextArea::getSize(){
	return optionPane->getSize();
}

CDOptionPane* CDTextArea::getOptionPane(){
	return this->optionPane;
}

bool CDTextArea::setSelectedIndex(uint8_t index){
	if(this->optionPane->setSelectedOptionIndex(index)){
		if(index>(getWidth()-1)){
			int o = -(index-getWidth()+1);
			cout << "OFFSET: " << o << endl;
			optionPane->getBounds()->setPointBy(o, 0);
		}
	}
	return false;
}

bool CDTextArea::setSelected(CDCharOption* option){
	if(this->optionPane->setSelectedOption(option)){
		int8_t x = option->getBounds()->getX();
		if(x>(getWidth()-1)){
			int o = -(x-getWidth()+1);
			cout << "OFFSET: " << o << endl;
			optionPane->getBounds()->setPointBy(o, 0);
		}
	}
	return false;
}

bool CDTextArea::canAppendArea(){
	return optionPane->getSize() < (getCapacity());
}

CDCharOption* CDTextArea::getSelected(){
	return (CDCharOption*)this->optionPane->getSelectedOption();
}

bool CDTextArea::appendArea(){
	if(canAppendArea()){
		uint8_t x = getSize();
		CDCharOption* c = new CDCharOption(x, 0, ' ');
		if(optionPane->insertOption(c)){
			optionPane->setDimensions(
					optionPane->getWidth()+1, 1);
			setSelected(c);
			return true;;
		}
	}
	return false;
}

bool CDTextArea::setCharAndAppend(char ch){
	CDCharOption* chOp = getSelected();
	if(chOp){
		chOp->setCharacter(ch);
		return appendArea();
	}
	return false;
}

bool CDTextArea::erase(){
	CDCharOption* chOp = (CDCharOption*)
			this->optionPane->getLastOption();
	if(chOp){
		if(this->optionPane->removeOption(chOp)){
			return true;
		}
	}
	return false;
}

void CDTextArea::printArea(LCD* lcd, Rectangle* area){

	printChildsArea(lcd, area);
}

void CDTextArea::printChildsArea(LCD* lcd, Rectangle* area){
	//cout << " childs[ " << endl;

	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	AbstractCDElement* elem = this->optionPane;
	printChild(elem, lcd, area);
	lcd->setCursor(ccx, ccy);

}

void CDTextArea::printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area){
	if(child && child->isVisible()){
		Rectangle r = area->intersection(
				child->getBounds());
		if(!r.isNull()){
			cout << "HERE" <<endl;
			int cx =  child->getBounds()->getX();
			int cy =  child->getBounds()->getY();

			lcd->setCursorBy(cx, cy);

			r.setPointBy(-child->getBounds()->getX(),
					-child->getBounds()->getY());
			child->printArea(lcd, &r);
		}
	}
}

void CDTextArea::validate(){
	this->optionPane->validate();
}

void CDTextArea::actionPerformed(Action action){
	unsigned int actionId = action.getActionId();
	//action.getContainer(); NO LIKE THIS
	switch(actionId){
		case CDOptionPane::SELECTION_CHANGE:{

			break;
		}
		case CDOptionPane::SELECTION_CONFIRM:{

			break;
		}
		case CDOptionPane::PANE_CLOSE:{

			break;
		}
	}
}
