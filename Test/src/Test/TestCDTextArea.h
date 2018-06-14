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
#include <string>

class TestCDTextArea {
public:

	static void run() {
		bool res = false;
		cout << "Test TextArea!" << endl;

		CDFrame frame = CDFrame(16, 2);

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

		frame.setPage(&area, 0);

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
};

#endif /* TEST_TESTCDTEXTAREA_H_ */
