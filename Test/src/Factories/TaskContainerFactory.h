/*
 * TaskContrainerFactory.h
 *
 *  Created on: 6 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef FACTORIES_TASKCONTAINERFACTORY_H_
#define FACTORIES_TASKCONTAINERFACTORY_H_
#include "../Model/TaskContainer.h"
#include "../View/TaskContainerView.h"
#include "../Controller/TaskContainerController.h"

class TaskContainerFactory {

	static TaskContainerView* createView(TaskContainer &model);
	static TaskContainerController* createController(TaskContainer &model);
};

#endif /* FACTORIES_TASKCONTAINERFACTORY_H_ */
