/*
 * CDCharOption.cpp
 *
 *  Created on: 10 Ιουν 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "CDOptionChar.h"

CDOptionChar::CDOptionChar(char c) :
	AbstractCDOption::AbstractCDOption(0, 0, 1), character(c){

}

CDOptionChar::CDOptionChar(int8_t x, int8_t y, char c)
	: AbstractCDOption::AbstractCDOption(x, y, 1), character(c){

}

CDOptionChar::~CDOptionChar() {
	// TODO Auto-generated destructor stub
}

void CDOptionChar::init(){

}

bool CDOptionChar::setCharacter(char c){
	if(this->character!=c){
		this->character = c;
		return true;
	}
	return false;
}

char CDOptionChar::getCharacter(){
	return this->character;
}

bool CDOptionChar::setStateVisible(bool visible){
	if(this->stateVisible != visible){
		this->stateVisible = visible;
		reprint();
		return true;
	}
	return false;
}

bool CDOptionChar::isStateVisible(){
	return this->stateVisible;
}

bool CDOptionChar::toogleStateDiplay(){
	return setStateVisible(!stateVisible);
}

void CDOptionChar::onOptionStateChanged(){
	reprint();
}

void CDOptionChar::printArea(LCD* lcd, const Rectangle* area){
	if(area->getX()==0 && area->getY()==0 &&
				area->getWidth()>0 && area->getHeight()>0){

		char c = getCharacter();
		if(getOptionState()==UNHOVERED || !isStateVisible()){
			lcd->print(c);
		}
		else if(getOptionState()==HOVERED){
			//c = CDOptionChar_HOVER;
			lcd->print(CDOptionChar_HOVER);
		}
		else{
			//c = CDOptionChar_SELECTED;
			lcd->print(CDOptionChar_SELECTED);
		}
	}
}

void CDOptionChar::validate(){

}
