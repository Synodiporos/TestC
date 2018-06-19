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

bool TaskContainerView::insertTaskOption(uint8_t width, const char* name,
		unsigned int seconds, bool editable){
	uint8_t s = getSize();
	CDOptionLabel* option = new CDOptionLabel(0, s, width, name, s);
	//Insert the new option
	if(this->insertOption(option)){
		//Increase the height of the pane
		if(getHeight()<s+1)
				setDimensions(getWidth(), getHeight()+1);
		return true;
	}
	return false;
}

