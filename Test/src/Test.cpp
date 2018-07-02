//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "CD/AbstractCDElement.h"
#include "CD/CDElement.h"
#include "CD/CDComponent.h"
#include "CD/CDLabel.h"
#include "CD/CDOptionLabel.h"
#include "CD/CDOptionPane.h"
#include "CD/LCD.h"
#include "CD/CDFrame.h"
#include "CD/CDVScrollbar.h"
#include "Geometry/Point.h"
#include "Geometry/Rectangle.h"
#include "Utils/CharUtil.h"
#include "Model/Task.h"
#include "Model/TaskContainer.h"
#include "View/MainView.h"
#include "Controller/MainController.h"
#include "System/TaskLoader.h"
#include "Controller/TaskContainerController.h"
#include "Factories/TaskContainerFactory.h"
#include "System/Timer.h"
#include "CD/CDKeyboard.h"
#include "Test/TestCDTextArea.h"
#include "Test/TestCDOptionPane.h"
#include "Test/TestCDVScrollbar.h"
#include <ctime>

int main() {
	cout << "Testing Started." << endl; // prints !!!Hello World!!!
	cout << endl;


	TestCDTextArea::run();
	//TestCDOptionPane::run2();
	//TestCDVScrollbar::run();

	cout << endl;
	cout << "Finished!" << endl;
	return 0;
}

