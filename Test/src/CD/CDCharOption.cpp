/*
 * CDCharOption.cpp
 *
 *  Created on: 10 Ιουν 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "CDCharOption.h"

CDCharOption::CDCharOption(char c) :
	AbstractCDOption::AbstractCDOption(0, 0, 1), character(c){

}

CDCharOption::CDCharOption(int8_t x, int8_t y, char c)
	: AbstractCDOption::AbstractCDOption(x, y, 1), character(c){

}

CDCharOption::~CDCharOption() {
	// TODO Auto-generated destructor stub
}

void CDCharOption::init(){

}

void CDCharOption::setCharacter(char c){
	this->character = c;
}

char CDCharOption::getCharacter(){
	return this->character;
}

bool CDCharOption::setStateVisible(bool visible){
	if(this->stateVisible != visible){
		this->stateVisible = visible;
		reprint();
		return true;
	}
	return false;
}

bool CDCharOption::isStateVisible(){
	return this->stateVisible;
}

bool CDCharOption::toogleStateDiplay(){
	return setStateVisible(!stateVisible);
}

void CDCharOption::onOptionStateChanged(){
	reprint();
}

void CDCharOption::printArea(LCD* lcd, Rectangle* area){
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

void CDCharOption::validate(){

}
