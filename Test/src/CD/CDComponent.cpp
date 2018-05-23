/*
 * CDComponent.cpp
 *
 *  Created on: 12 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "CDComponent.h"

CDComponent::CDComponent() : CDElement(){
	this->elements = new ICDElement*[0];
}

CDComponent::CDComponent(uint8_t capacity) : CDElement(){
	this->elements = new ICDElement*[capacity];
	for(int i=0; i<capacity; i++)
		elements[i] = nullptr;
}

CDComponent::CDComponent(uint8_t x, uint8_t y, int8_t w, int8_t h) :
		CDElement(x, y, w, h){
	this->elements = new ICDElement*[capacity];
	for(int i=0; i<capacity; i++)
			elements[i] = nullptr;
}

CDComponent::CDComponent(uint8_t x, uint8_t y,
		int8_t w, int8_t h, uint8_t capacity) :
				CDElement(x, y, w, h){
	this->capacity = capacity;
	this->elements = new ICDElement*[capacity];
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

void CDComponent::addElement(ICDElement* element){
	if(size<capacity){
		setElementAt(element, size);
		size++;
	}
}

void CDComponent::setElementAt(ICDElement* elem, uint8_t index){
	if(elem && index<capacity){
		ICDElement* old = elements[index];
		if(old)
			old->setParent(nullptr);
		elements[index] = elem;
		elem->setParent(this);
	}
}

ICDElement* CDComponent::getElementAt(uint8_t index){
	if(index<capacity)
		return elements[index];
	return nullptr;
}

ICDElement* CDComponent::getElementAt(uint8_t x, uint8_t y){
	for(unsigned int i=0; i<capacity; i++){
		ICDElement* elem = elements[i];
		if(elem->getBounds()->equals(x, y))
			return elem;
	}
	return nullptr;
}

ICDElement** CDComponent::getElements(){
	return this->elements;
}

void CDComponent::removeElement(ICDElement* element){
	if(element)
	for(unsigned int i=0; i<capacity; i++){
		ICDElement* elem = elements[i];
		if(elem==element)
			removeElementAt(i);
	}
}

void CDComponent::removeElementAt(uint8_t index){
	if(index<capacity){
		ICDElement* old = elements[index];
		if(old)
			old->setParent(nullptr);
		elements[index] = nullptr;
	}
}

void CDComponent::print(LCD* lcd){
	CDElement::print(lcd);
	printChilds(lcd);
}

void CDComponent::printChilds(LCD* lcd){
	for(int i=0; i<capacity; i++){
		ICDElement* elem = elements[i];
		if(elem){
			lcd->setCursor(elem->getBounds());
		}
	}
}

void CDComponent::printArea(LCD* lcd, Rectangle* area){
	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	printComponentsArea(lcd, area);
	printChildsArea(lcd, area);

	lcd->setCursor(ccx, ccy);
}

void CDComponent::printComponentsArea(LCD* lcd, Rectangle* area){
	CDElement::printArea(lcd, area);
}

void CDComponent::printChildsArea(LCD* lcd, Rectangle* area){
	cout << " childs[ " << endl;

	for(int i=0; i<capacity; i++){
		ICDElement* elem = elements[i];
		printChild(elem, lcd, area);
	}
	cout << "]" << endl;
}

void CDComponent::validate(){
	//
	this->CDElement::validate();
	validateChilds();
}

void CDComponent::validateChilds(){
	for(int i=0; i<capacity; i++){
		ICDElement* elem = elements[i];
		if(elem){
			elem->validate();
		}
	}
}

void CDComponent::printChild(ICDElement* child, LCD* lcd, Rectangle* area){
	if(child){
		Rectangle r = area->intersection(
				child->getBounds());
		if(!r.isNull()){
			int cx =  0 + child->getBounds()->getX();
			int cy =  0 + child->getBounds()->getY();

			lcd->setCursorBy(cx, cy);

			r.setPointBy(-child->getBounds()->getX(),
					-child->getBounds()->getY());
			child->printArea(lcd, &r);
		}
	}
}

