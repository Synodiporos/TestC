/*
 * TaskFactory.cpp
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#include "TaskMenuFactory.h"
#include "../View/ViewAssets.h"

TaskMenuView* TaskMenuFactory::createTaskMenuView(Task* model){
	bool editable = model->isEditable();
	TaskMenuView* view = new TaskMenuView(
			SCREEN_WIDTH-1, editable);
	view->init();
	return view;
}

TaskMenuController* TaskMenuFactory::createTaskMenuController(Task* model){
	TaskMenuView* view = createTaskMenuView(model);
	view->init();
	TaskMenuController* ctrl = new TaskMenuController(model, view);
	return ctrl;
}
