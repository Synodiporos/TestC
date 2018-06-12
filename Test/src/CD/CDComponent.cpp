/*
 * CDComponent.cpp
 *
 *  Created on: 12 Ξ�οΏ½ΞΏΞ�Β½Ξ�οΏ½Ξ’Β±Ξ�οΏ½ΞΏΞ�Β½ 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "CDComponent.h"
#include "CDOption.h"


CDComponent::CDComponent() : CDElement(){
	this->elements = new AbstractCDElement*[0];
}

CDComponent::CDComponent(uint8_t capacity) : CDElement(){
	this->elements = new AbstractCDElement*[capacity];
	for(int i=0; i<capacity; i++)
		elements[i] = nullptr;
}

CDComponent::CDComponent(uint8_t x, uint8_t y, int8_t w, int8_t h) :
		CDElement(x, y, w, h){
	this->elements = new AbstractCDElement*[capacity];
	for(int i=0; i<capacity; i++)
			elements[i] = nullptr;
}

CDComponent::CDComponent(uint8_t x, uint8_t y,
		int8_t w, int8_t h, uint8_t capacity) :
				CDElement(x, y, w, h){
	this->capacity = capacity;
	this->elements = new AbstractCDElement*[capacity];
	for(int i=0; i<capacity; i++)
			elements[i] = nullptr;
}

CDComponent::~CDComponent() {
	// TODO Auto-generated destructor stub
}

uint8_t CDComponent::getSize(){
	return this->size;
}

uint8_t CDComponent::getCapacity(){
	return this->capacity;
}

void CDComponent::addElement(AbstractCDElement* element){
	if(size<capacity){
		setElementAt(element, size);
		size++;
	}
}

void CDComponent::setElementAt(AbstractCDElement* elem, uint8_t index){
	if(elem && index<capacity){
		AbstractCDElement* old = elements[index];
		if(old)
			old->setParent(nullptr);
		elements[index] = elem;
		elem->setParent(this);
	}
}

AbstractCDElement* CDComponent::getElementAt(uint8_t index){
	if(index<capacity)
		return elements[index];
	return nullptr;
}

AbstractCDElement* CDComponent::getElementAt(uint8_t x, uint8_t y){
	for(unsigned int i=0; i<capacity; i++){
		AbstractCDElement* elem = elements[i];
		if(elem->getBounds()->equals(x, y))
			return elem;
	}
	return nullptr;
}

AbstractCDElement** CDComponent::getElements(){
	return this->elements;
}


void CDComponent::removeElement(AbstractCDElement* element){
	if(element)
	for(unsigned int i=0; i<capacity; i++){
		AbstractCDElement* elem = elements[i];
		if(elem==element)
			removeElementAt(i);
	}
}

void CDComponent::removeElementAt(uint8_t index){
	if(index<capacity){
		AbstractCDElement* old = elements[index];
		if(old)
			old->setParent(nullptr);
		elements[index] = nullptr;
	}
}

void CDComponent::printArea(LCD* lcd, Rectangle* area){
	printComponentsArea(lcd, area);
	printChildsArea(lcd, area);
}

void CDComponent::printComponentsArea(LCD* lcd, Rectangle* area){
	CDElement::printArea(lcd, area);
}

void CDComponent::printChildsArea(LCD* lcd, Rectangle* area){
	//cout << " childs[ " << endl;

	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	for(int i=0; i<capacity; i++){
		AbstractCDElement* elem = elements[i];
		printChild(elem, lcd, area);
		lcd->setCursor(ccx, ccy);
	}
	//cout << "]" << endl;
}

void CDComponent::printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area){
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


void CDComponent::validate(){
	this->CDElement::validate();
	validateChilds();
}

void CDComponent::validateChilds(){
	for(int i=0; i<capacity; i++){
		AbstractCDElement* elem = elements[i];
		if(elem && elem->isVisible()){
			elem->validate();
		}
	}
}
