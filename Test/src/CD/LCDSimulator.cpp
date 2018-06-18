/*
 * LCDSimulator.cpp
 *
 *  Created on: 16 Ιουν 2018
 *      Author: Synodiporos
 */
#include <iostream>
using namespace std;
#include "LCDSimulator.h"

LCDSimulator::LCDSimulator(uint8_t width, uint8_t height)
	: LCD(width, height){
	// TODO Auto-generated constructor stub
	init();
}

LCDSimulator::~LCDSimulator() {
	// TODO Auto-generated destructor stub
}

void LCDSimulator::init(){
	for(int i=0; i<getHeight(); i++){
		string* str = new string();
		for(int y=0; y<getWidth(); y++){
			*str += " ";
		}
		lines.push_back(str);
	}
}

bool LCDSimulator::settingCursor(Point* sursor){

}

uint8_t LCDSimulator::getCharBufferAddress(){

}

bool LCDSimulator::createChar(uint8_t id, const uint8_t[8]){

}

bool LCDSimulator::printChar(uint8_t id){

}

bool LCDSimulator::print(char* str){
	uint8_t y = getCursorY();
	uint8_t x = getCursorX();
	uint8_t i = 0;
	string ss = "";
	while(str[i]!=0){
		ss += str[i];
		i++;
	}
	string* l = *(lines.begin()+y);
	l->replace(x, ss.size(), ss);
	//cout << str << ": ss=" << ss << endl;
	printing();
	return true;
}

bool LCDSimulator::print(char ch){
	uint8_t y = getCursorY();
	uint8_t x = getCursorX();
	string* ss = new string;
	*ss += ch;
	string* l = *(lines.begin()+y);
		l->replace(x, ss->size(), *ss);
	printing();
	//cout << "char=" << ch << " ss=" <<  *ss << " = " << *l << endl;
	return true;
}

bool LCDSimulator::clear(){
	lines.clear();
	for(int i=0; i<getHeight(); i++){
		string* str = new string();
		for(int y=0; y<getWidth(); y++){
			*str += " ";
		}
		lines.push_back(str);
	}
	printing();
}

bool LCDSimulator::refresh(){

}

void LCDSimulator::printing(){
	string str = "+";
	for(int y=0; y<getWidth(); y++)
		str += "-";
	cout << str << "+" << endl;
	for (std::vector<string*>::iterator it = lines.begin() ;
			it != lines.end(); ++it){
		string* t = *it;
		cout << "|" << *t << "|" << endl;
	}
	str = "+";
	for(int y=0; y<getWidth(); y++)
			str += "-";
	cout << str << "+" << endl;
}
