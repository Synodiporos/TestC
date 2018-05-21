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

char* CharUtil::strFilling(const char* str,
		uint8_t lenght,	uint8_t size,
		int8_t start, char appender){
	//if(start>=size)
	//	return nullptr;

	char* res = new char[size+1];
	int h = size;


	if(start>=lenght){
		for(int i=0; i<size; i++){
			res[i] = appender;
		}
	}
	else{
		int ii = start;
		for(int i=0; i<size; i++){
			ii = i+start;
			if(ii<0)
				res[i] = appender;
			else{
				res[i] = str[ii];
				if(str[ii]=='\0'){
					h = i;
					break;
				}
			}
		}
		for(int i=h; i<size; i++)
			res[i] = appender;
	}

	res[size] = '\0';
/*
	cout << "Normalize of str: \'";
	cout << str;
	cout << "\' is \'";
	cout << res ;
	cout << "\'" << endl;*/
	return res;
}
