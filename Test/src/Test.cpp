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
#include "CD/CDLabel.h"
#include "CD/LCD.h"
#include "Geometry/Point.h"
#include "Geometry/Rectangle.h"
#include "Utils/CharUtil.h"
<<<<<<< Upstream, based on origin/master
=======
#include <ctime>
>>>>>>> 8a34775 Clock

void test(int& i);
void printRect(Rectangle* rec);
void interRect(Rectangle* r1, Rectangle* r2);
void resizeText(std::string& str);
char* normalize(char* str, uint8_t size, uint8_t start);

int main() {
	cout << "Testing Started." << endl; // prints !!!Hello World!!!

	char* str = "Stay tuned for Caturday – a project from tech fashion designer Anouk Wipprecht. Debuting Saturday";
	//char* str2 = "Arduino";

	//char* rrr = CharUtil::strFilling(str2, 7, 8, 0, '-');

	//cout << rrr << endl;

	//for(int i=-20; i<20; i++){
		//CharUtil::strFilling(str, 100, 100, i, '.');
	//}




	//==========================================
	LCD* lcd = new LCD();

	CDComponent* comp1 = new CDComponent(0, 0, 15, 0);
	CDComponent* comp2 = new CDComponent(0, 1, 10, 1, 2);
	CDComponent* comp3 = new CDComponent(11, 1, 5, 1, 0);
	CDComponent* comp4 = new CDComponent(-1, 2, 20, 5, 2);
	CDElement* elem1 = new CDElement(0, 0, 7, 3);
	CDElement* elem2 = new CDElement(8, 0, 8, 3);
	char lstr1[] = "Label 101";
	char lstr2[] = "ArduinoArduino";
	CDLabel* l1 = new CDLabel(0, 0, 8, lstr1);
	CDLabel* l2 = new CDLabel(8, 0, 8, lstr2);
	CDComponent* comp = new CDComponent(0, 0, 16, 40, 4);

	cout << "comp1: " << comp1 << endl;
	cout << "comp2: " << comp2 << endl;
	cout << "comp3: " << comp3 << endl;
	cout << "comp4: " << comp3 << endl;
	cout << "elem1: " << elem1 << endl;
	cout << "elem2: " << elem2 << endl;
	cout << "comp: " << comp << endl;

	comp4->addElement(elem1);
	comp4->addElement(elem2);

	comp2->addElement(l1);
	comp2->addElement(l2);

	comp->addElement(comp1);
	comp->addElement(comp2);
	comp->addElement(comp3);
	comp->addElement(comp4);

	Rectangle sc = Rectangle(0, 1, 16, 1);
	sc.setPointBy(-comp->getBounds()->getX(), -comp->getBounds()->getY());
	//Rectangle isc = comp->getBounds()->intersection(&sc);
	lcd->setCursor(0, 0);
	comp->printArea(lcd, &sc);

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

	Rectangle* rec10 = new Rectangle(0, 0, 16, 2);
	Rectangle* rec11 = new Rectangle(0, 0, 5, 2);
	Rectangle* rec12 = new Rectangle(0, 1, 18, 2);
	Rectangle r10 = Rectangle::intersection(*rec10, *rec11);
	printRect(&r10);
	interRect(rec10, rec11);
	Rectangle r11 = Rectangle::intersection(*rec10, *rec12);
	printRect(&r11);
	interRect(rec10, rec12);
*/


	l1->startRolling();

	clock_t start = clock();


	while(clock()-start<10000){
		comp->validate();
	}

	cout<< "Finished!" << endl;
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
	cout << Rectangle::intersects(r1, r2) << endl;
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
