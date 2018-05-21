/*
 * LCD.cpp
 *
 *  Created on: 12 Μαΐ 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "LCD.h"

LCD::LCD() {
	// TODO Auto-generated constructor stub

}

LCD::~LCD() {
	delete cursor;
}

void LCD::init(uint8_t width, uint8_t height){
	this->width = width;
	this->height = height;
}

void LCD::setCursor(uint8_t x, uint8_t y){
	this->cursor->setPoint(x, y);

	cout << "\t>>>   LCD: Set Cursor[" <<
			(int)x << ", "
			<< (int)y << "] " << endl;
}

void LCD::setCursor(Point* cords){
	if(cords)
		setCursor(cords->getX(), cords->getY());
}

uint8_t LCD::getCursorX(){
	return this->cursor->getX();
}

uint8_t LCD::getCursorY(){
	return this->cursor->getY();
}

Point* LCD::getCursor(){
	return this->cursor;
}

void LCD::print(char* str){
	if(str)
	cout << "\t>>>   LCD Print -> " << str << endl;
}
