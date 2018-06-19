/*
 * TaskContrainerFactory.cpp
 *
 *  Created on: 6 Ιουν 2018
 *      Author: Synodiporos
 */

#include "TaskContainerFactory.h"
#include "../View/ViewAssets.h"

TaskContainerView* TaskContainerFactory::createView(TaskContainer &model){
	uint8_t s = model.getSize();
	uint8_t w = SCREEN_WIDTH-1;
	TaskContainerView* view = new TaskContainerView(w, s);

	vector<Task*> tasks = model.getTasks();
	for(unsigned int i=0; i<tasks.size(); i++){
		Task* task = *(tasks.begin()+i);
		view->insertTaskOption(w, task->getName(),
				task->getDuration(), task->isEditable());
	}
	return view;
}

TaskContainerController* TaskContainerFactory::createController(
		TaskContainer &model){
	TaskContainerView* view = createView(model);

	TaskContainerController* ctrl =
			new TaskContainerController(&model, view);

	return ctrl;
}
