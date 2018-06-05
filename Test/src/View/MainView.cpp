/*
 * MainView.cpp
 *
 *  Created on: 4 Ιουν 2018
 *      Author: Synodiporos
 */

#include "MainView.h"
#include "ViewAssets.h"
#include "ViewActionIds.h"

MainView::MainView() : CDOptionPane(16, 2){
	// TODO Auto-generated constructor stub

}

MainView::~MainView() {
	// TODO Auto-generated destructor stub
}

void MainView::init(){
	char* c = LABEL_MAIN_MENU_AUTO;
	CDOption* optionAuto = new CDOption(0, 0, 5, c, VIEW_ACTION_AUTO);
	this->insertOption(optionAuto);

	char* c2 = LABEL_MAIN_MENU_MANUAL;
	CDOption* optionManual = new CDOption(8, 0, 6, c2, VIEW_ACTION_MANUAL);
	this->insertOption(optionManual);

	char* c3 = LABEL_MAIN_MENU_SETTINGS;
	CDOption* optionSettings = new CDOption(0, 1, 9, c3, VIEW_ACTION_SETTINGS);
	this->insertOption(optionSettings);

	char* c4 = LABEL_MAIN_MENU_STATISTICS;
	CDOption* optionStats = new CDOption(8, 1, 9, c4, VIEW_ACTION_STATISTICS);
	this->insertOption(optionStats);

	//setSelectedOptionIndex(0);
	setSelectedOption(optionAuto);
}

CDOption* MainView::getOptionAuto(){
	return getOptionAt(0);
}

CDOption* MainView::getOptionManul(){
	return getOptionAt(1);
}

CDOption* MainView::getOptionSettings(){
	return getOptionAt(2);
}

CDOption* MainView::getOptionStatistics(){
	return getOptionAt(3);
}
