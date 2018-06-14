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

class TestCDTextArea {
public:

	static void run() {
		cout << "Test TextArea!" << endl;

		CDFrame frame = CDFrame(16, 2);

		CDTextArea area = CDTextArea(6, 10);
		area.setCharAndAppend('S');
		area.setCharAndAppend('t');
		area.setCharAndAppend('a');
		area.setCharAndAppend('v');
		area.setCharAndAppend('r');
		area.setCharAndAppend('o');
		area.setCharAndAppend('s');
		//area.getOptionPane()->setPosition(-1, 0);

		//area.setSelectedIndex(6);

		frame.setPage(&area, 0);

		frame.print();

		area.setCharAndAppend('!');
		//area.getBounds()->print();
		//frame.print();
		//area.setCharAndAppend('s');
		frame.print();

		area.setSelectedIndex(2);
		//frame.print();
		area.setSelectedIndex(10);
		//frame.print();
		cout << "ERASE" << endl;
		area.eraseLastChar();

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
};

#endif /* TEST_TESTCDTEXTAREA_H_ */
