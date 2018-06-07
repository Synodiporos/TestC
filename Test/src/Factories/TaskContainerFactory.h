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

class TaskContainerFactory {

	static TaskContainerView* createView(const TaskContainer &model);
};

#endif /* FACTORIES_TASKCONTAINERFACTORY_H_ */
