/*
 * CDComponent.cpp
 *
 *  Created on: 12 Μαΐ 2018
 *      Author: Synodiporos
 */

#include "CDComponent.h"

CDComponent::CDComponent() {
	// TODO Auto-generated constructor stub

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

}

void CDComponent::setElementAt(ICDElement* elem, uint8_t index){

}

ICDElement* CDComponent::getElementAt(uint8_t index){

}

ICDElement* CDComponent::getElementAt(uint8_t x, uint8_t y){

}

ICDElement** CDComponent::getElements(){
	return this->elements;
}

void CDComponent::removeElement(ICDElement* element){

}

void CDComponent::removeElementAt(uint8_t index){

}

void CDComponent::print(LCD* lcd){
	//
	printChilds(lcd);
}

void CDComponent::validate(){
	//
	validateChilds();
}

void CDComponent::printChilds(LCD* lcd){
	for(int i=0; i<size; i++){
		ICDElement* elem = elements[i];
		if(elem){
			lcd->setCursor(elem->getPosition());
		}
	}
}

void CDComponent::validateChilds(){
	for(int i=0; i<size; i++){
		ICDElement* elem = elements[i];
		if(elem){
			elem->validate();
		}
	}
}

