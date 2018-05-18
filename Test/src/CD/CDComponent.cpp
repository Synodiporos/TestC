/*
 * CDComponent.cpp
 *
 *  Created on: 12 Μαΐ 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "CDComponent.h"

CDComponent::CDComponent() : CDElement(){
	this->elements = new ICDElement*[capacity];
}

CDComponent::CDComponent(uint8_t capacity) : CDElement(){
	this->elements = new ICDElement*[capacity];
}

CDComponent::CDComponent(uint8_t x, uint8_t y, int8_t w, int8_t h) :
		CDElement(x, y, w, h){
	this->elements = new ICDElement*[capacity];
}

CDComponent::CDComponent(uint8_t x, uint8_t y,
		int8_t w, int8_t h, uint8_t capacity) :
				CDElement(x, y, w, h){
	this->capacity = capacity;
	this->elements = new ICDElement*[capacity];
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
	if(element!=nullptr && size<capacity){
		elements[size] = element;
		size++;
	}
}

void CDComponent::setElementAt(ICDElement* elem, uint8_t index){
	if(index<capacity){
		elements[index] = elem;
		size++;
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
	for(unsigned int i=0; i<capacity; i++){
		ICDElement* elem = elements[i];
		if(elem==element)
			elements[i] = nullptr;
	}
}

void CDComponent::removeElementAt(uint8_t index){
	if(index<capacity)
		elements[index] = nullptr;
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

	printComponentsArea(lcd, area);
	printChildsArea(lcd, area);
}

void CDComponent::printComponentsArea(LCD* lcd, Rectangle* area){
	//lcd->setCursor(area);
	cout << "PrintArea: [";
	cout << (int)area->getX();
	cout << ", ";
	cout << (int)area->getY();
	cout << ", ";
	cout << (int)area->getWidth();
	cout << ", ";
	cout << (int)area->getHeight();
	cout << "] of" ;
	cout << this << endl;
}

void CDComponent::printChildsArea(LCD* lcd, Rectangle* area){
	cout << " childs[ " << endl;
	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	for(int i=0; i<capacity; i++){
		ICDElement* elem = elements[i];
		if(elem){

			if(area->intersects(elem->getBounds())){
				Rectangle r = area->intersection(elem->getBounds());


				int cx =  ccx + r.getX() + 0;
				int cy =  ccy + r.getY() + 0;

				lcd->setCursor(cx, cy);
				cout << "Set Cursor[" << cx << ", " << cy << "] " << endl;

				r.setPointBy(-elem->getBounds()->getX(),
						-elem->getBounds()->getY());
				elem->printArea(lcd, &r);
			}
		}
	}
	cout << "]" << endl;
}

void CDComponent::validate(){
	//
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

