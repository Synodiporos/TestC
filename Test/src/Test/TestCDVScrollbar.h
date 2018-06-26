/*
 * TestCDVScrollbar.h
 *
 *  Created on: 18 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef TEST_TESTCDVSCROLLBAR_H_
#define TEST_TESTCDVSCROLLBAR_H_
#include <iostream>
#include <ctime>
using namespace std;
#include "../CD/LCDConsole.h"
#include "../View/ViewAssets.h"
#include <string>

class TestCDVScrollbar {
public:

	static void run() {
		bool res = false;
		cout << "Test CDVScrollbar!" << endl;


		LCD* lcd = new LCDConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
		LCD* lcd2 = new LCDSimulator(SCREEN_WIDTH, SCREEN_HEIGHT);
		CDFrame frame = CDFrame((int)SCREEN_WIDTH, 2, lcd2);


		TaskContainer* taskCont = new TaskContainer(TaskLoader::getAvailableTasks());
		TaskContainerController* taskContCtrl =
				TaskContainerFactory::createController(*taskCont);
		TaskContainerView* taskContView = taskContCtrl->getView();



		MainController* mainCtrl = MainFactory::createController();
		mainCtrl->setTaskContainerController(taskContCtrl);
		mainCtrl->setFrame(&frame);
		mainCtrl->activate();
		frame.setPage(mainCtrl->getView());

		for(int i=0; i<10; i++){
			std::string* name = new std::string("Task_");
			*name = *name + std::to_string(i);
			taskCont->insertTask(new Task(name->c_str(), 1000));
		}

		cout << "View size: " << (int)taskContView->getSize() << endl;
		cout << "View height: " << (int)taskContView->getHeight() << endl;




		//frame.print();

		mainCtrl->onForwardClicked();
		mainCtrl->onForwardClicked();
		mainCtrl->onForwardClicked(); // Stats
		mainCtrl->onForwardClicked();
		mainCtrl->onEnterClicked();


		cout << "SET POSITION "<<endl;
		taskContView->setPosition(0, -8);

		cout << "SET POSITION "<<endl;
		taskContView->setPosition(0, -0);
/*

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
		*/
	}


};

#endif /* TEST_TESTCDVSCROLLBAR_H_ */
