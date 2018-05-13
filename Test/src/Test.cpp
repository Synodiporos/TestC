//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "CD/CDElement.h"
#include "CD/CDComponent.h"
#include "CD/LCD.h"
#include "Geometry/Point.h"
#include "Geometry/Rectangle.h"

void test(int& i);
void printRect(Rectangle* rec);
void interRect(Rectangle* r1, Rectangle* r2);
void resizeText(std::string& str);
char* normalize(char* str, uint8_t size, uint8_t start);

int main() {
	cout << "Testing Started." << endl; // prints !!!Hello World!!!

	char str[] = "This str!";
	int size = sizeof(str);

	cout << "The size of str: ";
	cout << str;
	cout << " is ";
	cout << size <<endl;

	/*int i = 5;
	test(i);

	string t = "Test";
	string tt = t.substr(2);
	string* ss = new string("Arduino");
	resizeText(t);
	resizeText(tt);
	resizeText(*ss);*/


	char* c = "Arduino UV Lamp";
	size = 16;
	//normalize(c, size, 0);
	//normalize(c, size, 5);
	//normalize(c, size, 10);
	//normalize(c, size, 15);


	//==========================================
	//CDElement* elem1 = new CDElement();

	//CDComponent* comp1 = new CDComponent();

	//comp1->addElement(elem1);
	//comp1->setPosition(1, 1);

	//=============================================
	/*
	Rectangle* rec1 = new Rectangle(0, 0, 10, 10);
	Rectangle* rec2 = new Rectangle(-2, -2, 5, 5);
	Rectangle* rec3 = new Rectangle(2, 2, 4, 4);
	Rectangle* rec4 = new Rectangle(8, 8, 5, 5);
	Rectangle* rec5 = new Rectangle(6, 12, 10, 5);
	Rectangle* rec6 = new Rectangle(-5, -5, 20, 20);
	Rectangle* rec7 = new Rectangle(0, 5, 10, 10);
	Rectangle* rec8 = new Rectangle(-5, 15, 2, 2);

	printRect(rec1);

	Rectangle r1 = Rectangle::intersection(*rec1, *rec2);
	printRect(&r1);
	interRect(rec1, rec2);
	Rectangle r2 = Rectangle::intersection(*rec1, *rec3);
	printRect(&r2);
	interRect(rec1, rec3);
	Rectangle r3 = Rectangle::intersection(*rec1, *rec4);
	printRect(&r3);
	interRect(rec1, rec4);
	Rectangle r4 = Rectangle::intersection(*rec1, *rec5);
	printRect(&r4);
	interRect(rec1, rec5);
	Rectangle r5 = Rectangle::intersection(*rec1, *rec6);
	printRect(&r5);
	interRect(rec1, rec6);
	Rectangle r6 = Rectangle::intersection(*rec1, *rec7);
	printRect(&r6);
	interRect(rec1, rec7);
	Rectangle r7 = Rectangle::intersection(*rec1, *rec8);
	printRect(&r7);
	interRect(rec1, rec8);
*/


	return 0;
}

void printRect(Rectangle* rec){
	cout << "Rectangle[";
	cout << (int)rec->getX();
	cout << ", ";
	cout << (int)rec->getY();
	cout << ", ";
	cout << (int)rec->getWidth();
	cout << ", ";
	cout << (int)rec->getHeight();
	cout << "]" << endl;
}

void interRect(Rectangle* r1, Rectangle* r2){
	cout << Rectangle::intersects(*r1, *r2) << endl;
}

void test(int &s){

}

void resizeText(std::string& str){
	str.resize(16, '.');

	cout << "The size of str: ";
	cout << str;
	cout << " is ";
	cout << str.size() <<endl;
}

char* normalize(char* str, uint8_t size, uint8_t start){
	if(start>=size)
		return nullptr;

	char* res = new char[size];
	int h = size;

	for(int i=0; i<size; i++){
		res[i] = str[i+start];
		if(str[i+start]=='\0'){
			h = i;
			break;
		}
	}
	for(int i=h; i<size; i++)
		res[i] = '.';

	res[size] = '\0';

	cout << "Normalize of str: \'";
	cout << str;
	cout << "\' is \'";
	cout << res;
	cout << "\' size=";
	int s = sizeof(*res);
	cout << s <<endl;

	return res;
}
