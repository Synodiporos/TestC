/*
 * TaskMenuView.cpp
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#include "TaskMenuView.h"
#include "ViewActionIds.h"
#include "ViewAssets.h"



TaskMenuView::TaskMenuView() {
	// TODO Auto-generated destructor stub
}

TaskMenuView::TaskMenuView(uint8_t width, bool editable) {
	// TODO Auto-generated constructor stub
	setDimensions(width, 3);
	this->editable = editable;
}

void TaskMenuView::setEditable(bool editable){
	if(this->editable!=editable){
		this->editable = editable;
	}
}

bool TaskMenuView::getEditable(){
	return this->editable;
}

TaskMenuView::~TaskMenuView() {
	// TODO Auto-generated destructor stub
}

void TaskMenuView::init(){
	uint8_t width = getBounds().getWidth();

	CDOptionLabel* opStart = new CDOptionLabel(0, 0,
				width, LABEL_TASK_MENU_START,
				VIEW_ACTION_TASK_START);
	CDOptionLabel* opDetails = new CDOptionLabel(0, 1,
				width, LABEL_TASK_MENU_DETAILS,
				VIEW_ACTION_TASK_DETAILS);
	this->insertOption(opStart);
	this->insertOption(opDetails);
	setDimensions(width, 3);

	if(editable){
		CDOptionLabel* opModify = new CDOptionLabel(0, 2,
					width, LABEL_TASK_MENU_MODIFY,
					VIEW_ACTION_TASK_MODIFY);
		CDOptionLabel* opDelete = new CDOptionLabel(0, 3,
					width, LABEL_TASK_MENU_DELETE,
					VIEW_ACTION_TASK_DELETE);
		this->insertOption(opModify);
		this->insertOption(opDelete);
		setDimensions(width, 5);
	}

	CDOptionLabel* opReturn = new CDOptionLabel(0, 4,
				width, LABEL_TASK_MENU_DELETE,
				VIEW_ACTION_RETURN);
	this->insertOption(opReturn);
}
