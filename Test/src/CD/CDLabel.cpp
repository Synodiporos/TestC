/*
 * CDLabel.cpp
 *
 *  Created on: 18 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
 *      Author: Synodiporos
 */
#include <iostream>
using namespace std;
#include "CDLabel.h"
#include "../Utils/CharUtil.h"
#include "CDConstants.h"
#include <ctime>

CDLabel::CDLabel() {
	// TODO Auto-generated constructor stub

}

CDLabel::CDLabel(uint8_t width, char* label){
	setWidth(width);
	setLabel(label);
	recreateStr();
}

CDLabel::CDLabel(int8_t x, int8_t y, uint8_t width, char* label){
	setLocation(x, y);
	setWidth(width);
	setLabel(label);
	recreateStr();
}

CDLabel::~CDLabel() {
	// TODO Auto-generated destructor stub
}

void CDLabel::setLabel(char* label){
	this->label = label;
	int i = 0;
	while(label[i]!='\0')
		i++;

	this->lenght = i;
}

char* CDLabel::getLabel(){
	return this->label;
}

void CDLabel::startRolling(){
	this->millis = clock();
	this->rollState = CDLabelStartRolling;
}

void CDLabel::stopRolling(){
	this->millis = clock();
	this->rollState = CDLabelStopRolling;
}

bool CDLabel::isRolling(){
	uint8_t r = CDLabelStartRolling;
	if(this->rollState == r)
		return true;
	return false;
}

void CDLabel::setLabelIndex(uint8_t index){
	if(this->strIndex!=index){
		this->strIndex = index;
		//cout << "Label: " << label << " index: " << (int)strIndex << endl;
		//
		reprint();
	}
}

uint8_t CDLabel::getLabelIndex(){
	return this->strIndex;
}

void CDLabel::setWidth(uint8_t width){
	this->width = width;
}

uint8_t CDLabel::getWidth(){
	return this->width;
}

void CDLabel::setLocation(int8_t x, int8_t y){
	this->x = x;
	this->y = y;
}

Point* CDLabel::getLocation(){
	return new Point(this->x, this->y);
}

Rectangle* CDLabel::getBounds(){
	return new Rectangle(this->x, this->y, this->width, 1);
}

void CDLabel::setParent(ICDElement* parent){
	this->parent = parent;
}

ICDElement* CDLabel::getParent(){
	return this->parent;
}

/*void CDLabel::print(LCD* lcd){

}
*/
void CDLabel::reprint(){

	ICDElement::reprint();
	/*
	uint8_t x = strIndex;
	char* p = CharUtil::strFilling(
				label, lenght, width, x, ' ');
	cout << "Reprint: " << p << endl;*/
}

void CDLabel::printArea(LCD* lcd, Rectangle* area){
	if(area->getY()!=0)
		return;
	int8_t x = area->getX() + strIndex;
	char* p = CharUtil::strFilling(
			label, lenght, area->getWidth(), x, ' ');
	lcd->print(p);
}

void CDLabel::validate(){
	if(isRolling()){
		unsigned int m = clock() - millis;
		unsigned int interval = CDLabelRollPI;

		if(m >= interval){
			int8_t mvs = lenght - width - strIndex;
			//cout << "mvs: " << (int)mvs << endl;
			if(mvs>0){
				setLabelIndex( strIndex + 1);
				if(mvs==1)
					stopRolling();
			}
			millis = clock();
		}
	}
}

void CDLabel::recreateStr(){
	//norm = CharUtil::strFilling(label, width, start, '-');
}
