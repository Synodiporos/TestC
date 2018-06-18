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

LCD::LCD(uint8_t width, uint8_t height) : Rectangle(0, 0, width, height){

}

LCD::LCD(int8_t x, int8_t y, uint8_t width, uint8_t height)
	: Rectangle(x, y, width, height){
}

LCD::~LCD() {

}
/*
void LCD::createCustomCharacters(){
	createChar(0, CDCharacters::ch_hover);
	createChar(1, CDCharacters::ch_click);
	createChar(2, CDCharacters::createScrollbarTopChar(0));
	createChar(3, CDCharacters::createScrollbarBottomChar(0));
	//createChar(4, CDCharacters::ch_hover);
	//createChar(5, CDCharacters::ch_hover);
	//createChar(6, CDCharacters::ch_hover);
	//createChar(7, CDCharacters::ch_hover);
}*/


bool LCD::setCursor(Point* cords){
	if(this->cursor.setPoint(cords)){
		return settingCursor(cords);
	}
	return false;
}

bool LCD::setCursor(uint8_t x, uint8_t y){
	return setCursor(new Point(x,y));
}

bool LCD::setCursorBy(uint8_t x, uint8_t y){
	return setCursorBy(new Point(x, y));
}


bool LCD::setCursorBy(Point* cords){
	if(cords)
		return setCursor(getCursor()->getX() + cords->getX(),
				getCursor()->getY() + cords->getY());
	return false;
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

bool LCD::writeChar(uint8_t ch[8]){
	uint8_t add = getCharBufferAddress();
	return createChar(add, ch) && printChar(add);
}
/*
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
}*/
/*
void LCD::sentCursorCoords(){
	cout << "\t>>>   LCD: Set Cursor[" <<
					(int)cursor.getX() << ", "
					<< (int)cursor.getY() << "] " << endl;
}*/

void LCD::fillArea(Rectangle* area, char c){

	char str[area->getWidth()+1];
	for(short int i=0; i<area->getWidth(); i++)
		str[i] = c;
	str[area->getWidth()] = '\0';

	for(short int y = 0; y<area->getHeight(); y++){
		print(str);
	}
}
/*
void LCD::clear(){

}

void LCD::refresh(){

}*/




