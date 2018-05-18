/*
 * CharUtil.cpp
 *
 *  Created on: 9 Μαΐ 2018
 *      Author: Synodiporos
 */

#include "CharUtil.h"
#include <iostream>
using namespace std;

CharUtil::CharUtil() {
	// TODO Auto-generated constructor stub

}

CharUtil::~CharUtil() {
	// TODO Auto-generated destructor stub
}

char* CharUtil::strFilling(char* str,
		uint8_t size, int8_t start, char appender){
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
		res[i] = appender;

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
