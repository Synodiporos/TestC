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
	: CDOptionPane(w, 1), capacity(capacity){
	init();
}

CDTextArea::CDTextArea(uint8_t x, uint8_t y, int8_t w, unsigned int capacity)
	: CDOptionPane(x, y, w, 1), capacity(capacity){
	init();
}

CDTextArea::~CDTextArea() {
	// TODO Auto-generated destructor stub
}

void CDTextArea::init(){
	CDCharOption* c = new CDCharOption(0, 0, ' ');
	insertOption(c);
}

void CDTextArea::setCapacity(unsigned int capacity){
	this->capacity = capacity;
}

unsigned int CDTextArea::getCapacity(){
	return this->capacity;
}

void CDTextArea::setLabelIndex(uint8_t index){
	if(this->strIndex!=index){
		this->strIndex = index;
		//cout << "Label: " << label << " index: " << (int)strIndex << endl;
		//
		reprint();
	}
}

uint8_t CDTextArea::getLabelIndex(){
	return this->strIndex;
}

bool CDTextArea::canAppendArea(){
	return getSize() < (getCapacity());
}

bool CDTextArea::appendArea(){
	if(canAppendArea()){
		uint8_t x = getSize();
		CDCharOption* c = new CDCharOption(x, 0, ' ');
		if(insertOption(c)){
			setSelectedOption(c);
			reprint();
			return true;;
		}
	}
	return false;
}

bool CDTextArea::setCharAndAppend(char ch){
	CDCharOption* chOp = (CDCharOption*)getSelectedOption();
	if(chOp){
		chOp->setCharacter(ch);
		return appendArea();
	}
	return false;
}

bool CDTextArea::erase(){
	CDCharOption* chOp = (CDCharOption*)getLastOption();
	if(chOp){
		if(removeOption(chOp)){
			return true;
		}
	}
	return false;
}
