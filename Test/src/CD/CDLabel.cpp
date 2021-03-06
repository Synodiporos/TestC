/*
 * CDLabel.cpp
 *
 *  Created on: 18 Ξ�οΏ½ΞΏΞ�Β½Ξ�οΏ½Ξ’Β±Ξ�οΏ½ΞΏΞ�Β½ 2018
 *      Author: Synodiporos
 */
#include <iostream>
using namespace std;
#include "CDLabel.h"
#include "../Utils/CharUtil.h"
#include "CDConstants.h"
#include <ctime>

CDLabel::CDLabel(uint8_t width, const char* label){
	setWidth(width);
	setLabel(label);
	recreateStr();
}

CDLabel::CDLabel(int8_t x, int8_t y, uint8_t width, const char* label){
	setPosition(x, y);
	setWidth(width);
	setLabel(label);
	recreateStr();
}

CDLabel::~CDLabel() {
	// TODO Auto-generated destructor stub
}

void CDLabel::setLabel(const char* label){
	this->label = label;
	int i = 0;
	while(label[i]!='\0')
		i++;

	this->lenght = i;
}

const char* CDLabel::getLabel(){
	return this->label;
}

void CDLabel::startRolling(){
	setRollingState(CDLabel::ROLLING_BEGIN);
}

void CDLabel::startRollingImmediately(){
	setRollingState(CDLabel::ROLLING_ROLL);
}

void CDLabel::stopRolling(){
	setRollingState(CDLabel::ROLLING_STOP);
	setLabelIndex(0);
}

void CDLabel::setRollingState(uint8_t state){
	//cout << getLabel() << " getRollingState()=" << (int)getRollingState() << endl;
	if(this->rollState!=state){
		this->rollState = state;
		this->millis = clock();
	}
}

uint8_t CDLabel::getRollingState(){
	return this->rollState;
}

bool CDLabel::isRolling(){
	if(this->rollState > 0)
		return true;
	return false;
}

void CDLabel::setLabelIndex(uint8_t index){
	if(this->strIndex!=index){
		this->strIndex = index;
		//cout << "Label: " << label << " index: " << (int)strIndex << endl;
		reprint();
	}
}

uint8_t CDLabel::getLabelIndex(){
	return this->strIndex;
}

bool CDLabel::setWidth(uint8_t width){
	if(this->width!=width){
		Rectangle old = getBounds();
		this->width = width;
		notifyPropertyChanged(AbstractCDElement::DIMENSIONS_PROPERTY,
				&old);
		return true;
	}
	return false;
}

const uint8_t CDLabel::getWidth() const{
	return this->width;
}

bool CDLabel::setPosition(int8_t x, int8_t y){
	if(this->x!=x || this->y!=y){
		Rectangle old = getBounds();
		this->x = x;
		this->y = y;
		notifyPropertyChanged(AbstractCDElement::POSITION_PROPERTY,
				&old);
				return true;
	}
	return false;
}

const Rectangle CDLabel::getBounds() const{
	return Rectangle(this->x, this->y, this->width, 1);
}

void CDLabel::setParent(AbstractCDElement* parent){
	this->parent = parent;
}

AbstractCDElement* CDLabel::getParent(){
	return this->parent;
}

/*void CDLabel::print(LCD* lcd){

}
*/
/*void CDLabel::reprint(){
	AbstractCDElement::reprint();

	uint8_t x = strIndex;
	char* p = CharUtil::strFilling(
				label, lenght, width, x, ' ');
	cout << "Reprint: " << p << endl;
}*/

void CDLabel::printArea(LCD* lcd, const Rectangle* area){
	if(area->getY()!=0)
		return;

	//Cursor

	int8_t x = area->getX() + strIndex;
	char* p = CharUtil::strFilling(
			label, lenght, area->getWidth(), x, ' ');
	lcd->print(p);
}

void CDLabel::validate(){
	//cout << "VALIDATE LABEL" << endl;
	if(isRolling()){
		unsigned int m = clock() - millis;

		if(getRollingState()==CDLabel::ROLLING_BEGIN){
			unsigned short int srd = CDLabelStartRollDelay;
			if(m>=srd)
				setRollingState(CDLabel::ROLLING_ROLL);
		}
		else if(getRollingState()==CDLabel::ROLLING_ROLL){
			unsigned short int pi = CDLabelRollPI;
			int8_t mvs = lenght - width - strIndex
										+ CDLabelRollingOffeset;
			if(m >= pi){
				if(mvs>0)
					setLabelIndex( strIndex + 1);
				else
					setRollingState(CDLabel::ROLLING_END);
				millis = clock();
			}
		}
		else{
			unsigned short int gbd = CDLabelRollBackDelay;
			if(m >= gbd){
				setRollingState(CDLabel::ROLLING_BEGIN);
				setLabelIndex(0);
				millis = clock();
			}
		}
	}
}

void CDLabel::recreateStr(){
	//norm = CharUtil::strFilling(label, width, start, '-');
}
