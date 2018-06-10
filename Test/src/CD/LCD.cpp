/*
 * LCD.cpp
 *
 *  Created on: 12 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "LCD.h"
#include "CDCharacters.h"

LCD::LCD(int8_t x, int8_t y) : Rectangle(x, y){

}

LCD::LCD(int8_t x, int8_t y, uint8_t width, uint8_t height)
	: Rectangle(x, y, width, height){
}

LCD::~LCD() {

}

void LCD::createCustomCharacters(){
	createChar(0, CDCharacters::ch_hover);
	createChar(1, CDCharacters::ch_click);
	createChar(2, CDCharacters::createScrollbarTopChar(0));
	createChar(3, CDCharacters::createScrollbarBottomChar(0));
	//createChar(4, CDCharacters::ch_hover);
	//createChar(5, CDCharacters::ch_hover);
	//createChar(6, CDCharacters::ch_hover);
	//createChar(7, CDCharacters::ch_hover);
}

void LCD::setCursor(uint8_t x, uint8_t y){
	if(!cursor.equals(x, y)){
		this->cursor.setPoint(x, y);

		/*cout << "\t>>>   LCD: Set Cursor[" <<
				(int)x << ", "
				<< (int)y << "] " << endl;*/
	}
}

void LCD::setCursorBy(uint8_t x, uint8_t y){
	setCursorBy(new Point(x, y));
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
	return this->cursor.getX();
}

uint8_t LCD::getCursorY(){
	return this->cursor.getY();
}

Point* LCD::getCursor(){
	return &this->cursor;
}

void LCD::createChar(uint8_t id, const uint8_t[8]){
	//LCD Create Char.
}

void LCD::printChar(uint8_t id){

}

void LCD::writeChar(uint8_t ch[8]){

}

void LCD::print(char* str){
	if(str){
		sentCursorCoords();
		cout << "\t>>>   LCD Print -> " << str << endl;
	}
}

void LCD::print(char ch){
	if(ch){
		sentCursorCoords();
		cout << "\t>>>   LCD Print -> " << ch << endl;
	}
}

void LCD::sentCursorCoords(){
	cout << "\t>>>   LCD: Set Cursor[" <<
					(int)cursor.getX() << ", "
					<< (int)cursor.getY() << "] " << endl;
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

void LCD::clear(){

}

void LCD::refresh(){

}
