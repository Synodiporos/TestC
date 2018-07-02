/*
 * TestCDTextArea.h
 *
 *  Created on: Jun 12, 2018
 *      Author: sgeorgiadis
 */

#ifndef TEST_TESTCDTEXTAREA_H_
#define TEST_TESTCDTEXTAREA_H_

#include <iostream>
#include <ctime>
using namespace std;
#include "../CD/CDFrame.h"
#include "../CD/CDTextArea.h"
#include "TestCDTextArea.h"
#include "../Controller/CDTextAreaController.h"
#include "../Factories/MainFactory.h"
#include "../Model/TaskContainer.h"
#include "../System/TaskLoader.h"
#include "../View/ViewAssets.h"
#include "../CD/LCDConsole.h"
#include "../CD/LCDSimulator.h"
#include "../Display/SystemDisplayManager.h"
#include <string>

class TestCDTextArea {
public:

	static void run() {
		bool res = false;
		cout << "Test TextArea!" << endl;

		LCDConsole* lcd = new LCDConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
		LCD* lcd2 = new LCDSimulator(SCREEN_WIDTH, SCREEN_HEIGHT);
		CDFrame frame = CDFrame((int)SCREEN_WIDTH, 2, lcd2);
    
		SystemDisplayManager::getInstanse()->
				setDefaultSystemDisplay(&frame);

		cout << "FRAME: " << &frame << endl;
		//TEST REPO 2

		CDTextAreaController taCtrl = CDTextAreaController();
		CDTextArea* area = taCtrl.getView();

		cout << "AREA: " << area << endl;

		/*res = area->setCharAndAppend('S');
		cout << "Adding S res=" << res << endl;
		res = area->setCharAndAppend('t');
		cout << "Adding t res=" << res << endl;
		res = area->setCharAndAppend('a');
		cout << "Adding a res=" << res << endl;
		res = area->setCharAndAppend('v');
		cout << "Adding v res=" << res << endl;
		res = area->setCharAndAppend('r');
		cout << "Adding r res=" << res << endl;
		res = area->setCharAndAppend('o');
		cout << "Adding o res=" << res << endl;
		res = area->setCharAndAppend('s');
		cout << "Adding s res=" << res << endl;*/
		//area.getOptionPane()->setPosition(-1, 0);

		for(int i=0; i<20; i++){
			char c = std::to_string(i).c_str()[0];
			if(i>9){
				c = (char)( 'A' + i-10);
			}
			area->setCharAndAppend(c);
		}

		area->getOptionPane()->setScrollMode(CDOptionPane::SCROLL_MODE_ITEM);
		area->getOptionPane()->setPosition(0,0);
		area->setSelectedIndex(0);
		area->setSelectedIndex(6);

		//area->setSelectedIndex(0);
		//area->setChar('a', 19);

		//area->setCharAndAppend('a');

		//area.setSelectedIndex(6);
		cout<< "SEt Page"<<endl;
		frame.setPage(area);

		cout<< "Size: "<< (int)area->getSize() << endl;

		/*res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();*/

		std::string str ("Test string");

		str = area->getText();
		cout << "TEXT: " << str << endl;




		bool run = true;
		clock_t start = clock();
		//int i = 1;
		char c = '.';
		while (clock() - start < 60000 && run && c!='s') {
			//unsigned long millis = clock() - start;

			cout << "Please enter an char value: ";
			cin >> c;

			switch(c){
				case 'x':{
					cout << "Left" << endl;
					taCtrl.onForwardClicked();
					break;
				}
				case 'z':{
					cout << "Right" << endl;
					taCtrl.onBackwardClicked();
					break;
				}
				case 'c':{
					cout << "OK" << endl;
					taCtrl.onEnterClicked();
					break;
				}
				case 'v':{
					cout << "Back" << endl;
					taCtrl.onBackClicked();
					break;
				}
			}
		}

		cout << "Test TextArea: Finished!" << endl;
	}

	static void run2() {
		bool res = false;
		cout << "Test TextAreaController!" << endl;

		LCD* lcd = new LCDConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
		LCD* lcd2 = new LCDSimulator(SCREEN_WIDTH, SCREEN_HEIGHT);
		CDFrame frame = CDFrame((int)SCREEN_WIDTH, 2, lcd2);

		CDKeyboard keyboard = CDKeyboard(SCREEN_WIDTH-1);
		keyboard.appendCharSet(UPPER_CASE_LETTERS);
		keyboard.appendCharSet(LOWER_CASE_LETTERS);
		keyboard.appendCharSet(TEXT_SYMBOLS);
		keyboard.appendCharSet(NUMBERS);
		keyboard.appendCharSet(SYMBOLS);
		CDKeyboardController keybCntr = CDKeyboardController(&keyboard);

		frame.setPage(&keyboard);

		//frame.print();

		keybCntr.onForwardClicked();
		keybCntr.onForwardClicked();

		//keyboard.setPosition(0, -1);

		bool run = true;
		clock_t start = clock();
		int i = 1;
		while (clock() - start < 10000 && run) {
			unsigned long millis = clock() - start;
			if (millis >= 4000 && i == 1) {
				cout << "=================" << endl;

				i++;
			}
			if (millis >= 5000 && i == 2) {

				i++;
			}
			frame.validate();
			keyboard.validate();
		}
	}

	static void run3() {


		bool run = true;
		clock_t start = clock();
		//int i = 1;
		char c = '.';
		while (clock() - start < 30000 && run && c!='s') {
			//unsigned long millis = clock() - start;

			cout << "Please enter an char value: ";
			cin >> c;

			switch(c){
				case 'z':{
					cout << "Left" << endl;
					break;
				}
				case 'x':{
					cout << "Right" << endl;
					break;
				}
				case 'c':{
					cout << "OK" << endl;
					break;
				}
				case 'v':{
					cout << "Back" << endl;
					break;
				}
			}
		}
	}

};



#endif /* TEST_TESTCDTEXTAREA_H_ */
