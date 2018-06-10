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
	char* chars = CHARS;
	uint8_t width = getDimensions().getWidth();
	uint8_t height = 0;
	int i = 0;
	Point* p = new Point();

	while(chars[i]!='\0'){
		p = GeometryUtil::indexToCoordinates(i, width);
		insertOption(new CDCharOption(p->getX(), p->getY(), chars[i]));
		i++;
		height = p->getY();
	}

	char* numbers = NUMBERS;
	i = 0;
	while(numbers[i]!='\0'){
		p = GeometryUtil::indexToCoordinates(i, width);
		p->setPointBy(0, height+1);
		insertOption(new CDCharOption(p->getX(), p->getY(), numbers[i]));
		i++;
	}
	setDimensions(width, height+1);

	setSelectedOptionIndex(0);

	this->timer->setActionListener(this);
	this->timer->start();
}

void CDKeyboard::validate(){
	this->timer->validate();
}

void CDKeyboard::actionPerformed(Action action){
	CDCharOption* op = (CDCharOption*)getSelectedOption();
	if(op)
		op->toogleStateDiplay();
	//cout << "TIC " << endl;
}
