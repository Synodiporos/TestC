/*
 * TaskFactory.cpp
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#include "TaskFactory.h"
#include "../View/ViewAssets.h"

TaskMenuView* TaskFactory::createMenuView(Task* model){
	bool editable = model->isEditable();
	TaskMenuView* view = new TaskMenuView(
			SCREEN_WIDTH, editable);
	view->init();
	return view;
}

TaskMenuController* TaskFactory::createMenuController(Task* model){
	TaskMenuView* view = createMenuView(model);
	view->init();
	TaskMenuController* ctrl = new TaskMenuController(model, view);
	return ctrl;
}
