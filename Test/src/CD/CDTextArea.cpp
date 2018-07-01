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

CDTextArea::CDTextArea(int8_t width, unsigned int capacity)
	: capacity(capacity){
	setWidth(width);
	init();
}

CDTextArea::CDTextArea(uint8_t x, uint8_t y, int8_t width, unsigned int capacity)
	: capacity(capacity){
	setPosition(x, y);
	setWidth(width);
	init();
}

CDTextArea::~CDTextArea() {
	// TODO Auto-generated destructor stub
}

void CDTextArea::init(){
	this->optionPane.setScrollMode(CDOptionPane::SCROLL_MODE_ITEM);
	this->optionPane.setParent(this);
	this->optionPane.setActionListener(this);
	this->optionPane.setPropertyListener(this);
	CDOptionChar* c = new CDOptionChar(0, 0, ' ');
	optionPane.insertOption(c);
}

void CDTextArea::setParent(AbstractCDElement* parent){
	this->parent = parent;
}


AbstractCDElement* CDTextArea::getParent(){
	return this->parent;
}

const Rectangle CDTextArea::getBounds() const{
	return Rectangle(this->x, this->y, this->width, 1);
}

bool CDTextArea::setPosition(int8_t x, uint8_t y){
	if(this->x!=x || this->y!=y){
		Rectangle old = getBounds();
		this->x = x;
		this->y = y;
		notifyPropertyChanged(AbstractCDElement::DIMENSIONS_PROPERTY,
				&old);
		return true;
	}
	return false;
}

bool CDTextArea::setWidth(uint8_t width){
	if(getWidth()!=width){
		Rectangle old = getBounds();
		this->width = width;

		this->optionPane.setViewPort(width, 1);

		notifyPropertyChanged(AbstractCDElement::DIMENSIONS_PROPERTY,
				&old);
		return true;
	}
	return false;
}

void CDTextArea::setCapacity(unsigned int capacity){
	this->capacity = capacity;
}

unsigned int CDTextArea::getCapacity(){
	return this->capacity;
}

uint8_t CDTextArea::getSize(){
	return optionPane.getSize();
}

CDOptionPane* CDTextArea::getOptionPane(){
	return &this->optionPane;
}

bool CDTextArea::setSelectedIndex(uint8_t index){
	return this->optionPane.setSelectedOptionIndex(index);
}

bool CDTextArea::setSelected(CDOptionChar* option){
	return this->optionPane.setSelectedOption(option);
}

bool CDTextArea::selectNext(){
	return this->optionPane.selectNextOption();
}

bool CDTextArea::selectPrevious(){
	return this->optionPane.selectPreviousOption();
}

bool CDTextArea::canAppendArea(){
	return optionPane.getSize() < (getCapacity());
}

CDOptionChar* CDTextArea::getSelected(){
	return (CDOptionChar*)this->optionPane.getSelectedOption();
}

bool CDTextArea::isLastOptionSelected(){
	return this->optionPane.isLastOption(getSelected());
}

bool CDTextArea::appendArea(){
	if(canAppendArea()){
		uint8_t x = getSize();
		CDOptionChar* c = new CDOptionChar(x, 0, ' ');
		if(optionPane.insertOption(c)){
			optionPane.setDimensions(
					optionPane.getWidth()+1, 1);
			cout << "Append size:" << (int)getSize() << " width:" <<
					(int)optionPane.getWidth() << endl;

			setSelected(c); // Prints Char
			return true;
		}
	}
	return false;
}

bool CDTextArea::setCharAndAppend(char ch){
	/*if(getSize()>=capacity)
		return false;
	CDOptionChar* chOp = getSelected();
	if(chOp){
		chOp->setCharacter(ch);
		return appendArea();
	}*/
	if( setChar(ch, getSize()-1) ){
		appendArea();
		return true;
	}
	return false;
}

bool CDTextArea::setChar(char c, uint8_t index){
	if(index < capacity){
		CDOptionChar* op = (CDOptionChar*)this->optionPane.getOptionAt(index);
		if(op){
			cout << "setChar: " << c << endl;
			op->setCharacter(c);
			return true;
		}
	}
	return false;
}

bool CDTextArea::eraseLastChar(){
	CDOptionChar* chOp = (CDOptionChar*)
			this->optionPane.getLastOption();
	if(getSize()<=1){
		chOp->setCharacter(' ');
		return false;
	}
	if(this->optionPane.removeOption(chOp)){
		//setSelectedIndex(optionPane.getSize()-1);
		return true;
	}
	return false;
}

std::string CDTextArea::getText(){
	std::string res;
	CDOptionPane::Node* n = optionPane.getLastOptionNode();
	if(n){
		uint8_t i = getSize()-1;
		while(n->hasPrev()){
			char c = ((CDOptionChar*)n->getValue())->getCharacter();
			res = c + res;
			n = n->getPrev();
			i--;
		}
		char c = ((CDOptionChar*)n->getValue())->getCharacter();
		res = c + res ;
	}
	return res;
}

void CDTextArea::show(){
	SystemDisplay* display =
			SystemDisplayManager::getInstanse()->getDefaultSystemDisplay();
	if(display){
		display->setPage(this);
	}
}

void CDTextArea::close(){
	SystemDisplay* display =
			SystemDisplayManager::getInstanse()->getDefaultSystemDisplay();
	if(display){
		display->setPage(this);
	}
}

void CDTextArea::printArea(LCD* lcd, const Rectangle* area){

	printChildsArea(lcd, area);
}

void CDTextArea::printChildsArea(LCD* lcd, const Rectangle* area){
	//cout << " childs[ " << endl;

	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();
	AbstractCDElement* elem = &this->optionPane;
	printChild(elem, lcd, area);
	lcd->setCursor(ccx, ccy);

}

void CDTextArea::printChild(
		AbstractCDElement* child, LCD* lcd, const Rectangle* area){
	if(child && child->isVisible()){
		Rectangle cb = child->getBounds();
		Rectangle r = area->intersection(&cb);
		if(!r.isNull()){
			int cx =  child->getBounds().getX();
			int cy =  child->getBounds().getY();

			lcd->setCursorBy(cx, cy);

			r.setPointBy(-child->getBounds().getX(),
					-child->getBounds().getY());
			child->printArea(lcd, &r);
		}
	}
}

void CDTextArea::validate(){
	this->optionPane.validate();
}

void CDTextArea::actionPerformed(Action action){
	unsigned int actionId = action.getActionId();
	//action.getContainer(); NO LIKE THIS
	switch(actionId){
		case CDOptionPane::SELECTION_CHANGE:{
			//validateSelectionChange();
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

void CDTextArea::propertyChanged(void* source,
				unsigned short int propertyId, const void* oldPropery){
	switch(propertyId){
		case CDOptionPane::POSITION_PROPERTY:{
			reprint();
			break;
		}
		case CDOptionPane::DIMENSIONS_PROPERTY:{

			break;
		}
	}
}

void CDTextArea::validateSelectionChange(){
	cout << "VALIDATE SELECTION CHANGED" << endl;
	CDOptionChar* selection = getSelected();
	if(selection){
		int8_t i = selection->getBounds().getX();
		int8_t x0 = getBounds().getX();

		//Is out of view area?
		int o = 0;
		if(i > (getWidth() - 1)){
			o = -(i + x0 - getWidth() + 1);
		}
		else if(i<0){
			o = -i;
		}
		//cout << "O=" << o << endl;
		if(this->optionPane.setPosition(
				o, this->optionPane.getPosition()->getY()) )
			reprint();
	}
	else{
		if(optionPane.setPosition(0, 0))
			reprint();
	}
}
