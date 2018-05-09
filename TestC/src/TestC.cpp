//============================================================================
// Name        : TestC.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	cout << "Testing Started." << endl; // prints !!!Hello World!!!

	char str[] = "This str!";
	int size = sizeof(str);

	cout << "The size of str: ";
	cout << str;
	cout << " is ";
	cout << size <<endl;

	return 0;
}
