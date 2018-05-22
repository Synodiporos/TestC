/*
 * LCD.cpp
 *
 *  Created on: 12 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "LCD.h"

LCD::LCD(int8_t x, int8_t y) : Rectangle(x, y){

}

LCD::LCD(int8_t x, int8_t y, uint8_t width, uint8_t height)
	: Rectangle(x, y, width, height){

}

LCD::~LCD() {
	delete cursor;
}

void LCD::setCursor(uint8_t x, uint8_t y){
	short int rx = x ;//- getX();
	short int ry = y ;//- getY();

	this->cursor->setPoint(x, y);

	cout << "\t>>>   LCD: Set Cursor[" <<
			(int)rx << ", "
			<< (int)ry << "] " << endl;
}

void LCD::setCursor(Point* cords){
	if(cords)
		setCursor(cords->getX(), cords->getY());
}

void LCD::setCursorBy(Point* cords){
	if(cords)
		setCursor(getCursor()->getX() + cords->getX(),
				getCursor()->getY() + cords->getY());
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

void LCD::fillArea(Rectangle* area, char c){

	char str[area->getWidth()+1];
	for(short int i=0; i<area->getWidth(); i++)
		str[i] = c;
	str[area->getWidth()] = '\0';

	for(short int y = 0; y<area->getHeight(); y++){
		print(str);
	}

}
