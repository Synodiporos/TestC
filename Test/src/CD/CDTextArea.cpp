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
	CDOptionChar* c = new CDOptionChar(0, 0, ' ');
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
	return this->optionPane->setSelectedOptionIndex(index);
}

bool CDTextArea::setSelected(CDOptionChar* option){
	return this->optionPane->setSelectedOption(option);
}

bool CDTextArea::selectNext(){
	return this->optionPane->selectNextOption();
}

bool CDTextArea::selectPrevious(){
	return this->optionPane->selectPreviousOption();
}

bool CDTextArea::canAppendArea(){
	return optionPane->getSize() < (getCapacity());
}

CDOptionChar* CDTextArea::getSelected(){
	return (CDOptionChar*)this->optionPane->getSelectedOption();
}

bool CDTextArea::appendArea(){
	if(canAppendArea()){
		uint8_t x = getSize();
		CDOptionChar* c = new CDOptionChar(x, 0, ' ');
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
	if(getSize()>=capacity)
		return false;
	CDOptionChar* chOp = getSelected();
	if(chOp){
		chOp->setCharacter(ch);
		return appendArea();
	}
	return false;
}

bool CDTextArea::eraseLastChar(){
	CDOptionChar* chOp = (CDOptionChar*)
			this->optionPane->getLastOption();
	if(getSize()<=1){
		chOp->setCharacter(' ');
		return false;
	}
	if(this->optionPane->removeOption(chOp)){
		setSelectedIndex(optionPane->getSize()-1);
		return true;
	}
	return false;
}

std::string CDTextArea::getText(){
	std::string res;
	CDOptionPane::Node* n = optionPane->getLastOptionNode();
	if(n){
		uint8_t i = getSize()-1;
		while(n->hasPrev()){
			char c = ((CDOptionChar*)n->getValue())->getCharacter();
			res = c + res;
			n = n->getPrev();
			i--;
		}
		char c = ((CDOptionChar*)n->getValue())->getCharacter();
		res = c + res;
	}
	return res;
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
			validateCelectionChange();
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

void CDTextArea::validateCelectionChange(){
	//cout << "VALIDATE" << endl;
	CDOptionChar* selection = getSelected();
	if(selection){
		int8_t i = selection->getBounds()->getX();
		int8_t x0 = getBounds()->getX();

		//Is out of view area?
		int o = 0;
		if(i > (getWidth() - 1)){
			o = -(i + x0 - getWidth() + 1);
		}
		else if(i<0){
			o = -i;
		}
		//cout << "O=" << o << endl;
		if(this->optionPane->getBounds()->setX(o))
			reprint();

	}
	else{
		if(optionPane->getBounds()->setPoint(0, 0))
			reprint();
	}
}
