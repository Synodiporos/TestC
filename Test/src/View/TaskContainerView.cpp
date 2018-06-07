/*
 * TaskContainerView.cpp
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#include "TaskContainerView.h"

TaskContainerView::TaskContainerView(uint8_t w, uint8_t h) :
	CDOptionPane(w, h){
	// TODO Auto-generated constructor stub
}

TaskContainerView::~TaskContainerView() {
	// TODO Auto-generated destructor stub
}

bool TaskContainerView::insertTaskOption(uint8_t width, char* name,
		unsigned int seconds, bool editable){
	uint8_t y = getSize();
	CDOption* option = new CDOption(0, y, width, name, y);
	return this->insertOption(option);
}
