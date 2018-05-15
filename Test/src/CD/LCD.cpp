/*
 * LCD.cpp
 *
 *  Created on: 12 Μαΐ 2018
 *      Author: Synodiporos
 */

#include "LCD.h"

LCD::LCD() {
	// TODO Auto-generated constructor stub

}

LCD::~LCD() {
	delete cursor;
}

void LCD::init(uint8_t width, uint8_t y){

}

void LCD::setCursor(uint8_t x, uint8_t y){

}

void LCD::setCursor(Point* cords){
	//if(cords)
	this->setCursor(cords->getX(), cords->getY());
}

uint8_t LCD::getCursorX(){

}

uint8_t LCD::getCursorY(){

}

Point* LCD::getCursor(){
	return this->cursor;
}
