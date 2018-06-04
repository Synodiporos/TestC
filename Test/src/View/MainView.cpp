/*
 * MainView.cpp
 *
 *  Created on: 4 Ιουν 2018
 *      Author: Synodiporos
 */

#include "MainView.h"
#include "ViewAssets.h"

MainView::MainView() : CDOptionPane(){
	// TODO Auto-generated constructor stub

}

MainView::~MainView() {
	// TODO Auto-generated destructor stub
}

void MainView::init(){
	char* c = LABEL_MAIN_MENU_AUTO;
	CDOption* optionAuto = new CDOption(0, 0, 5, c, 1);
	this->insertOption(optionAuto);

	char* c2 = LABEL_MAIN_MENU_MANUAL;
	CDOption* optionManual = new CDOption(8, 0, 6, c2, 2);
	this->insertOption(optionManual);

	char* c3 = LABEL_MAIN_MENU_SETTINGS;
	CDOption* optionSettings = new CDOption(0, 1, 9, c3, 3);
	this->insertOption(optionSettings);

	char* c4 = LABEL_MAIN_MENU_STATISTICS;
	CDOption* optionStats = new CDOption(8, 1, 9, c4, 4);
	this->insertOption(optionStats);
}
