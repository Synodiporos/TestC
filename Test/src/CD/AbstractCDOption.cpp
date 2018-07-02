/*
 * AbstractAbstractCDOption.cpp
 *
 *  Created on: 10 Ιουν 2018
 *      Author: Synodiporos
 */
#include <iostream>
using namespace std;
#include "AbstractCDOption.h"

AbstractCDOption::AbstractCDOption(uint8_t width){
	setWidth(width);
}

AbstractCDOption::AbstractCDOption(int8_t x, int8_t y, uint8_t width){
	setWidth(width);
	setLocation(x, y);
}

AbstractCDOption::AbstractCDOption(int8_t x, int8_t y,
		uint8_t width, unsigned int actionId){
	setWidth(width);
	setLocation(x, y);
	setActionId(actionId);
}

AbstractCDOption::~AbstractCDOption() {
	// TODO Auto-generated destructor stub
}

void AbstractCDOption::setParent(AbstractCDElement* parent){
	this->parent = parent;
}

AbstractCDElement* AbstractCDOption::getParent(){
	return this->parent;
}

void AbstractCDOption::setActionId(unsigned int actionId){
	this->actionId = actionId;
}

unsigned int AbstractCDOption::getActionId(){
	return this->actionId;
}


const Rectangle AbstractCDOption::getBounds() const{
	return Rectangle(x, y, width, 1);
}

void AbstractCDOption::setWidth(uint8_t width){
	this->width = width;
}

const uint8_t AbstractCDOption::getWidth() const{
	return this->width;
}

void AbstractCDOption::setLocation(int8_t x, int8_t y){
	this->x = x;
	this->y = y;
}

const Point* AbstractCDOption::getLocation(){
	return new Point(this->x, this->y);
}

void AbstractCDOption::setOptionState(uint8_t state){
	if(getOptionState()!=state){
		this->state = state;
		onOptionStateChanged();
		notifyStateChanged();
	}
}

void AbstractCDOption::onOptionStateChanged(){

}

uint8_t AbstractCDOption::getOptionState(){
	return this->state;
}

void AbstractCDOption::hover(){
	setOptionState(HOVERED);
}

void AbstractCDOption::unhover(){
	setOptionState(UNHOVERED);
}

void AbstractCDOption::click(){
	setOptionState(CLICKED);
}

void AbstractCDOption::setStateListener(IStateListener* l){
	this->stateListener = l;
}

void AbstractCDOption::removeStateListener(IStateListener* l){
	this->stateListener = nullptr;
}

IStateListener* AbstractCDOption::getStateListener(){
	return this->stateListener;
}

void AbstractCDOption::notifyStateChanged(){
	if(this->stateListener){
		State* s = new State(this,'\0', nullptr);
		this->stateListener->stateChanged(s);
	}
}
