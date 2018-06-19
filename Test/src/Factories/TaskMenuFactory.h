/*
 * TaskFactory.h
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#ifndef FACTORIES_TASKMENUFACTORY_H_
#define FACTORIES_TASKMENUFACTORY_H_
#include "../View/TaskMenuView.h"
#include "../Model/Task.h"
#include "../Controller/TaskMenuController.h"

class TaskMenuFactory {
public:
	static TaskMenuView* createTaskMenuView(Task* model);
	static TaskMenuController* createTaskMenuController(Task* model);
};

#endif /* FACTORIES_TASKMENUFACTORY_H_ */
