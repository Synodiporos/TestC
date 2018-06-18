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
#include <string>

class TestCDTextArea {
public:

	static void run() {
		bool res = false;
		cout << "Test TextArea!" << endl;

		LCDConsole* lcd = new LCDConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
		CDFrame frame = CDFrame((int)SCREEN_WIDTH, 2, lcd);

		CDTextArea area = CDTextArea(4, 20);
		res = area.setCharAndAppend('S');
		cout << "Adding S res=" << res << endl;
		res = area.setCharAndAppend('t');
		cout << "Adding t res=" << res << endl;
		res = area.setCharAndAppend('a');
		cout << "Adding a res=" << res << endl;
		res = area.setCharAndAppend('v');
		cout << "Adding v res=" << res << endl;
		res = area.setCharAndAppend('r');
		cout << "Adding r res=" << res << endl;
		res = area.setCharAndAppend('o');
		cout << "Adding o res=" << res << endl;
		res = area.setCharAndAppend('s');
		cout << "Adding s res=" << res << endl;
		//area.getOptionPane()->setPosition(-1, 0);

		//area.setSelectedIndex(6);

		frame.setPage(&area);

		//frame.print();

		area.setCharAndAppend('!');
		//area.getBounds()->print();
		//frame.print();
		//area.setCharAndAppend('s');
		frame.print();

		//area.setSelectedIndex(2);
		//frame.print();
		//area.setSelectedIndex(10);
		//frame.print();
		cout << "ERASE" << endl;

		//res = area.eraseLastChar();
		//res = area.eraseLastChar();
		//res = area.eraseLastChar();
		/*res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();
		res = area.eraseLastChar();*/
		cout << "Erases res: " << res << endl;
		area.reprint();

		std::string str ("Test string");

		str = area.getText();
		cout << "TEXT: " << str << endl;
/*

		clock_t start = clock();
		int i = 1;
		while (clock() - start < 4000) {
			unsigned long millis = clock() - start;
			if (millis >= 1000 && i == 1) {

				i++;
			}
			if (millis >= 2000 && i == 2) {

				i++;
			}
		}
*/


		cout << "Test TextArea: Finished!" << endl;
	}

	static void run2() {
		bool res = false;
		cout << "Test TextAreaController!" << endl;

		LCD* lcd = new LCDConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
		LCD* lcd2 = new LCDSimulator(SCREEN_WIDTH, SCREEN_HEIGHT);
		CDFrame frame = CDFrame((int)SCREEN_WIDTH, 2, lcd2);

		TaskContainer* taskCont = new TaskContainer(TaskLoader::getAvailableTasks());
		TaskContainerController* taskContCtrl =
				TaskContainerFactory::createController(*taskCont);

		MainController* mainCtrl = MainFactory::createController();
		mainCtrl->setTaskContainerController(taskContCtrl);
		mainCtrl->setFrame(&frame);
		mainCtrl->activate();
		frame.setPage(mainCtrl->getView());


		frame.print();

		mainCtrl->onForwardClicked();
		mainCtrl->onForwardClicked();
		/*mainCtrl->onEnterClicked();// AUTO
		frame.print();

		mainCtrl->onForwardClicked();
		mainCtrl->onForwardClicked();
		mainCtrl->onForwardClicked();// TASK
		mainCtrl->onEnterClicked();
		frame.print();*/


		/*CDTextArea view = CDTextArea(10, 20);
		CDTextAreaController* cntr = new CDTextAreaController(&view);


		mainCtrl->onForwardClicked();
		mainCtrl->onEnterClicked();
		mainCtrl->onEnterClicked();

		mainCtrl->onEnterClicked();
		for(int i=0; i<12; i++)
			mainCtrl->onForwardClicked();
		mainCtrl->onEnterClicked();

		frame.print();

		mainCtrl->onEnterClicked();
		for(int i=0; i<92; i++)
			mainCtrl->onForwardClicked();
		mainCtrl->onEnterClicked();

		std::string txt = view.getText();
		cout << "Text: " << txt << endl;*/

		clock_t start = clock();
		int i = 1;
		while (clock() - start < 10000) {
			unsigned long millis = clock() - start;
			if (millis >= 4000 && i == 1) {
				cout << "=================" << endl;
				mainCtrl->onForwardClicked();
				i++;
			}
			if (millis >= 5000 && i == 2) {

				i++;
			}
			frame.validate();
		}
	}

};

#endif /* TEST_TESTCDTEXTAREA_H_ */
