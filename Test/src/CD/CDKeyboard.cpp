/*
 * CDKeyboard.cpp
 *
 *  Created on: 10 Ιουν 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "CDKeyboard.h"
#include "../Geometry/GeometryUtil.h"

CDKeyboard::CDKeyboard(uint8_t width){
	setDimensions(width, 0);
}

CDKeyboard::~CDKeyboard(){

}

void CDKeyboard::init(){
	this->timer->setActionListener(this);
	this->timer->start();
}

void CDKeyboard::appendCharSet(char* set){
	uint8_t width = getDimensions().getWidth();
	uint8_t height = 0;
	if(getLastOption())
		height = getLastOptionNode()->getValue()->getLocation()->getY();
	int i = 0;
	Point* p = new Point();

	while(set[i]!='\0'){
		p = GeometryUtil::indexToCoordinates(i, width);
		insertOption(new CDOptionChar(p->getX(), p->getY()+height, set[i]));
		i++;
	}
	setDimensions(width, height+0);
}

void CDKeyboard::validate(){
	this->timer->validate();
}

void CDKeyboard::actionPerformed(Action action){
	CDOptionChar* op = (CDOptionChar*)getSelectedOption();
	if(op)
		op->toogleStateDiplay();
	//cout << "TIC " << endl;
}
