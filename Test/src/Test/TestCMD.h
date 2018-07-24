/*
 * TestCMD.h
 *
 *  Created on: 23 Ιουλ 2018
 *      Author: Synodiporos
 */

#ifndef TEST_TESTCMD_H_
#define TEST_TESTCMD_H_

#include <iostream>
#include <ctime>
using namespace std;
#include "../CMD/AT.h"
#include "../CMD/CMD.h"
#include "../CMD/CMDErrorReport.h"
#include <string>

class TestCMD {
public:

	static void run() {
		cout << "Test CMD." << endl; // prints !!!Hello World!!!
		cout << endl;

		string command;
		vector<string> params;
		string com1 = "AT+BT";
		string com2 = "AT+SET=1,100";
		string com3 = "AT";

		AT::parse(com1, command, params);

		std::vector<string> vv ;
		vv.push_back("1");
		vv.push_back("2");
		vv.push_back("3");
		CMD* cmd = new CMDErrorReport();
		cmd->print();

		CMD* cmd1 = AT::toCMD(com1);
		cmd1->print();

		CMD* cmd2 = AT::toCMD(com2);
		cmd2->print();

		CMD* cmd3 = AT::toCMD(com3);
		cmd3->print();


		clock_t start = clock();
		int i = 1;
		bool run = false;
		while ( run && (clock() - start < 10000)) {
			unsigned long millis = clock() - start;


		}

	}

};

#endif /* TEST_TESTCMD_H_ */
