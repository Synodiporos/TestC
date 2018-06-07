//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "CD/AbstractCDElement.h"
#include "CD/CDElement.h"
#include "CD/CDComponent.h"
#include "CD/CDLabel.h"
#include "CD/CDOption.h"
#include "CD/CDOptionPane.h"
#include "CD/LCD.h"
#include "CD/CDFrame.h"
#include "CD/CDVScrollbar.h"
#include "Geometry/Point.h"
#include "Geometry/Rectangle.h"
#include "Utils/CharUtil.h"
#include "Model/Task.h"
#include "Model/TaskContainer.h"
#include "View/MainView.h"
#include "Controller/MainController.h"
#include "System/TaskLoader.h"

#include <ctime>

void test(int& i);
void printRect(Rectangle* rec);
void interRect(Rectangle* r1, Rectangle* r2);
void resizeText(std::string& str);
char* normalize(char* str, uint8_t size, uint8_t start);

int main() {
	cout << "Testing Started." << endl; // prints !!!Hello World!!!

	//char* str = "Stay tuned for Caturday – a project from tech fashion designer Anouk Wipprecht. Debuting Saturday";
	//char* str2 = "Arduino";

	//char* rrr = CharUtil::strFilling(str2, 7, 8, 0, '-');

	//cout << rrr << endl;

	//for(int i=-20; i<20; i++){
		//CharUtil::strFilling(str, 100, 100, i, '.');
	//}

	//uint8_t c


	//=============================================
	Rectangle r1 = Rectangle(0, 0, 16, 2);
	Rectangle r2 = Rectangle(0, 1, 16, 5);
	Rectangle res = r1.intersection(&r2);
	//printRect(&res);


	//==========================================

	/*CDComponent* comp1 =

			new CDComponent(0, 0, 4, 1);
	CDComponent* comp2 =
			new CDComponent(0, 1, 12, 2, 2);
	CDComponent* comp3 =
			new CDComponent(13, 1, 5, 2, 0);
	CDComponent* comp4 =
			new CDComponent(0, 3, 20, 5, 2);
	char lstr1[] = "Label 101 TEsting";
	char lstr2[] = "ArduinoArduino";
	CDOption* elem1 = new CDOption(0, 0, 7, lstr1);
	CDOption* elem2 = new CDOption(8, 0, 8, lstr2);
	CDLabel* l1 = new CDLabel(0, 0, 7, lstr1);
	CDLabel* l2 = new CDLabel(8, 0, 8, lstr2);
	CDComponent* comp =
			new CDComponent(0, 0, 16, 100, 4);

	cout << "comp1: " << comp1 << endl;
	cout << "comp2: " << comp2 << endl;
	cout << "comp3: " << comp3 << endl;
	cout << "comp4: " << comp4 << endl;
	cout << "elem1: " << elem1 << endl;
	cout << "elem2: " << elem2 << endl;
	cout << "l1: " << l1 << endl;
	cout << "12: " << l2 << endl;
	cout << "comp: " << comp << endl;

	comp4->addElement(elem1);
	comp4->addElement(elem2);
	comp2->addElement(l1);
	comp2->addElement(l2);
	comp->addElement(comp1);
	comp->addElement(comp2);
	comp->addElement(comp3);
	comp->addElement(comp4);*/


/*

	CDOption op1 = CDOption(0,0,4, (char*)"Op1");
	CDOption op2 = CDOption(7,0,4, "Op2");
	CDOption op3 = CDOption(0,1,12, "Op3");
	CDOption op4 = CDOption(0,2,4, "Op4");
	CDOption op5 = CDOption(7,2,4, "Op5");
	CDOption op6 = CDOption(0,3,12, "Op6");
	CDOptionPane op = CDOptionPane(0,0,12,5);
	op.insertOption(&op1);
	op.insertOption(&op2);
	op.insertOption(&op3);
	op.insertOption(&op4);
	op.insertOption(&op5);
	op.insertOptionAt(5, &op6);
	op.setSelectedOption(&op6);
	op.removeOptionAt(10);

	cout << "CDOptionPane: " << &op << " size: " <<
			(int)op.getSize()
			<< "[" << endl;
	if(op.getSelectedOption())
	cout << "   selected: " <<
			op.getSelectedOption()->getLabel()->getLabel()
			<< endl;
	while(op.hasPreviousOption()){
		op.selectPreviousOption();
		cout << "   selected: " <<
				op.getSelectedOption()->getLabel()->getLabel()
				<< endl;
	}
	cout << "]" << endl;
	for(int i=0; i<op.getSize(); i++){
		CDOption* o = op.getOptionAt(i);
		cout << "   -Option at "<< i << ": " <<
				o->getLabel()->getLabel()
				<< endl;
	}


	cout << "SetSelectedIndex(" << 0 << "): " <<
			op.setSelectedOptionIndex(0);
	cout << "   -- "<< 0 << ": " <<
			op.getSelectedOption()->getLabel()->getLabel()
			<< endl;

	for(int i=100; i<op.getSize()+2; i++){
		cout << "SetSelectedIndex(" << i << "): " <<
				op.setSelectedOptionIndex(i);
		cout << "   -- "<< i << ": " <<
				op.getSelectedOption()->getLabel()->getLabel()
				<< endl;
	}

	cout << "." << endl;*/


	CDFrame frame = CDFrame(16, 2, 1);
	//frame.setPage(&op, 0);
	//frame.setPosition(0,2);
	//frame.print();
	//for(int i=-1; i<=100; i++)
	//	frame.setPosition(0, i);
	//frame.print();


	//elem2->click();
	//l1->setLabelIndex(2);
	//l1->startRollingImmediately();

/*

	Task t1 = Task(*"Task1", 0);
	Task t2 = Task(*"Task2", 0);
	Task t3 = Task(*"Task3", 0);
	Task t4 = Task(*"Task4", 0);
	Task t5 = Task(*"Task5", 0);
	TaskContainer cont = TaskContainer();
	cout << "Task1: " << &t1 << endl;
	cout << "Task2: " << &t2 << endl;
	cout << "Task3: " << &t3 << endl;
	cout << "Task4: " << &t4 << endl;
	cout << "Task5: " << &t5 << endl;

	cont.insertTask(&t1);
	cont.insertTask(&t2);
	cont.insertTask(&t3);
	cont.insertTask(&t4);
	cont.insertTask(&t5);
	//cont.removeTaskAt(2);

	cout << "Container[" << endl;
	for(int i=0; i<cont.getSize(); i++)
		cout << "  " << cont.getTaskAt(i) << endl;
	cout << "]" << endl;


	Task* t = cont.getTaskAt(3);
	cout << "Retrieve: " << t << endl;

	for(int i=0; i<5; i++){
		cont.setSelectedTaskIndex(i);
		cout << "Selected at "<< i << ": " << cont.getSelectedTask() << endl;
	}
*/



	MainView* mainView = new MainView();
	mainView->init();
	MainController* mainCtrl = new MainController(mainView);


	mainCtrl->onEnterClicked();
	mainCtrl->onForwardClicked();
	mainCtrl->onEnterClicked();
	mainCtrl->onForwardClicked();
	mainCtrl->onEnterClicked();
	mainCtrl->onForwardClicked();
	mainCtrl->onEnterClicked();
	mainCtrl->onForwardClicked();
	mainCtrl->onEnterClicked();


	//mainCtrl->onForwardClicked();
	//mainCtrl->onBackwardClicked();
	//mainCtrl->onForwardClicked();

	//mainCtrl->onEnterClicked();


	clock_t start = clock();

/*
	while(clock()-start<10000){
		comp->validate();
		if(clock()-start>=2000){
			//elem2->hover();
		}
	}
*/

	//cout << "Size of comp: " << sizeof(*mainView) << endl;

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
	cout << "]" ;
	cout << " isNull?" << rec->isNull() << endl;
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
