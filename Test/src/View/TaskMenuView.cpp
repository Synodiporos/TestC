/*
 * TaskMenuView.cpp
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#include "TaskMenuView.h"
#include "ViewActionIds.h"
#include "ViewAssets.h"

TaskMenuView::~TaskMenuView() {
	// TODO Auto-generated destructor stub
}

TaskMenuView::TaskMenuView() {
	// TODO Auto-generated constructor stub

}

void TaskMenuView::init(){
	uint8_t width = getBounds()->getWidth();

	CDOption* opStart = new CDOption(0, 0,
				width, LABEL_TASK_MENU_START,
				VIEW_ACION_TASK_START);
	CDOption* opDetails = new CDOption(0, 1,
				width, LABEL_TASK_MENU_DETAILS,
				VIEW_ACION_TASK_DETAILS);
	CDOption* opModify = new CDOption(0, 2,
				width, LABEL_TASK_MENU_MODIFY,
				VIEW_ACION_TASK_MODIFY);
	CDOption* opDelete = new CDOption(0, 3,
				width, LABEL_TASK_MENU_DELETE,
				VIEW_ACION_TASK_DELETE);
	CDOption* opReturn = new CDOption(0, 4,
				width, LABEL_TASK_MENU_DELETE,
				VIEW_ACION_RETURN);

	this->insertOption(opStart);
	this->insertOption(opDetails);
	this->insertOption(opModify);
	this->insertOption(opDelete);
	this->insertOption(opReturn);
}
