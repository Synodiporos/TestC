/*
 * TestCDOptionPane.h
 *
 *  Created on: 15 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef TEST_TESTCDOPTIONPANE_H_
#define TEST_TESTCDOPTIONPANE_H_
#include <iostream>
#include <ctime>
using namespace std;
#include "../CD/LCDConsole.h"

class TestCDOptionPane {
public:

	static void run() {
		bool res = false;
		cout << "Test TextArea!" << endl;

		LCD* lcd = new LCDConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
		CDFrame frame = CDFrame(SCREEN_WIDTH, 2, lcd);

		CDOptionLabel op1 = CDOptionLabel(0, 0, 4, (char*) "Op1");
		CDOptionLabel op2 = CDOptionLabel(7, 0, 4, "Op2");
		CDOptionLabel op3 = CDOptionLabel(0, 1, 12, "Op3");
		CDOptionLabel op4 = CDOptionLabel(0, 2, 4, "Op4");
		CDOptionLabel op5 = CDOptionLabel(7, 2, 4, "Op5");
		CDOptionLabel op6 = CDOptionLabel(0, 3, 12, "Op6");
		CDOptionPane op = CDOptionPane(0, 0, 12, 5);
		op.insertOption(&op1);
		op.insertOption(&op2);
		op.insertOption(&op3);
		op.insertOption(&op4);
		op.insertOption(&op5);
		op.insertOptionAt(5, &op6);

		frame.setPage(&op);
		frame.print();
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
		mainCtrl->onForwardClicked(); // Stats
		mainCtrl->onForwardClicked();
		mainCtrl->onEnterClicked();
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
		bool run = false;
		while ( run && (clock() - start < 10000)) {
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

#endif /* TEST_TESTCDOPTIONPANE_H_ */
