/*
 * MainView.cpp
 *
 *  Created on: 4 Ιουν 2018
 *      Author: Synodiporos
 */

#include "MainView.h"
#include "ViewAssets.h"
#include "ViewActionIds.h"

MainView::MainView(uint8_t width, uint8_t height) :
	CDOptionPane(width, height){
	init();
}

MainView::~MainView() {
	// TODO Auto-generated destructor stub
}

void MainView::init(){
	char* c = LABEL_MAIN_MENU_AUTO;
	CDOptionLabel* optionAuto = new CDOptionLabel(0, 0, 5, c, VIEW_ACTION_AUTO);
	this->insertOption(optionAuto);

	char* c2 = LABEL_MAIN_MENU_MANUAL;
	CDOptionLabel* optionManual = new CDOptionLabel(8, 0, 7, c2, VIEW_ACTION_MANUAL);
	this->insertOption(optionManual);

	char* c3 = LABEL_MAIN_MENU_SETTINGS;
	CDOptionLabel* optionSettings = new CDOptionLabel(0, 1, 7, c3, VIEW_ACTION_SETTINGS);
	this->insertOption(optionSettings);

	char* c4 = LABEL_MAIN_MENU_STATISTICS;
	CDOptionLabel* optionStats = new CDOptionLabel(8, 1, 7, c4, VIEW_ACTION_STATISTICS);
	this->insertOption(optionStats);

	//setSelectedOptionIndex(0);
	//setSelectedOption(optionAuto);
}

AbstractCDOption* MainView::getOptionAuto(){
	return getOptionAt(0);
}

AbstractCDOption* MainView::getOptionManul(){
	return getOptionAt(1);
}

AbstractCDOption* MainView::getOptionSettings(){
	return getOptionAt(2);
}

AbstractCDOption* MainView::getOptionStatistics(){
	return getOptionAt(3);
}
