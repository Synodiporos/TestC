/*
 * TaskContrainerFactory.cpp
 *
 *  Created on: 6 Ιουν 2018
 *      Author: Synodiporos
 */

#include "TaskContainerFactory.h"

TaskContainerView* TaskContainerFactory::createView(const TaskContainer &model){
	uint8_t s = model.getSize();
	TaskContainerView* view = new TaskContainerView(16, s);

	vector<Task*> tasks = model.getTasks();
	for(int i=0; i<tasks.size(); i++){
		Task* task = *(tasks.begin()+i);
		view->insertTaskOption( 16, task->getName(),
				task->getDuration(), task->isEditable());
	}
	return view;
}
