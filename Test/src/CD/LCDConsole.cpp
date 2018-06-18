/*
 * LCDConsole.cpp
 *
 *  Created on: 16 Ιουν 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "LCDConsole.h"

LCDConsole::LCDConsole(uint8_t width, uint8_t height)
	: LCD(0, 0, width, height){

}

LCDConsole::LCDConsole(int8_t x, int8_t y, uint8_t width, uint8_t height)
	: LCD(x, y, width, height){

}

LCDConsole::~LCDConsole() {
	// TODO Auto-generated destructor stub
}

bool LCDConsole::settingCursor(Point* sursor){
	sentCursorCoords();
}

uint8_t LCDConsole::getCharBufferAddress(){
	return 8;
}

bool LCDConsole::createChar(uint8_t id, const uint8_t[8]){

}

bool LCDConsole::printChar(uint8_t id){
	cout << "\t>>>   LCD: printChar[" << id << "]" << endl;
}

bool LCDConsole::print(char* str){
	cout << "\t>>>   LCD: print[" << str << "]" << endl;
}

bool LCDConsole::print(char ch){
	cout << "\t>>>   LCD: print[" << ch << "]" << endl;
}

bool LCDConsole::clear(){

}

bool LCDConsole::refresh(){

}

void LCDConsole::sentCursorCoords(){
	cout << "\t>>>   LCD: Set Cursor[" <<
		(int)getCursor()->getX() << ", "
		<< (int)getCursor()->getY() << "] " << endl;
}
