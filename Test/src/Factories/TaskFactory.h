/*
 * TaskFactory.h
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#ifndef FACTORIES_TASKFACTORY_H_
#define FACTORIES_TASKFACTORY_H_
#include "../View/TaskMenuView.h"
#include "../Model/Task.h"
#include "../Controller/TaskMenuController.h"

class TaskFactory {
public:
	static TaskMenuView* createMenuView(Task* model);
	static TaskMenuController* createMenuController(Task* model);
};

#endif /* FACTORIES_TASKFACTORY_H_ */
