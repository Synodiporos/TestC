/*
 * TaskContainer.cpp
 *
 *  Created on: 27 Μαΐ 2018
 *      Author: Synodiporos
 */

#include "TaskContainer.h"

TaskContainer::TaskContainer(){
	// TODO Auto-generated constructor stub

}

TaskContainer::~TaskContainer() {
	// TODO Auto-generated destructor stub
}

uint8_t TaskContainer::getSize(){
	return tasks.size();
}

bool TaskContainer::insertTask(Task* task){
	if(task){
		tasks.push_back(task);
		notifyActionPerformed(
				TaskContainer::ACTION_TASK_INSERTED, getSize());
		return true;
	}
	return false;
}

bool TaskContainer::removeTask(Task* task){
	int size = tasks.size();
	for(int i=0; i<size; i++){
		Task* ct = *(tasks.begin() + i);
		if(ct==task){
			tasks.erase(tasks.begin() + i);
			notifyActionPerformed(
					TaskContainer::ACTION_TASK_REMOVED, i);
			return true;
		}
	}
	return false;
}

bool TaskContainer::removeTaskAt(uint8_t index){
	int size = tasks.size();
	if(index<size){
		tasks.erase(tasks.begin() + index);
		notifyActionPerformed(
				TaskContainer::ACTION_TASK_REMOVED, index);
		return true;
	}
	return false;
}

Task* TaskContainer::getTaskAt(uint8_t index){
	int size = tasks.size();
	if(index<size){
		return *(tasks.begin() + index);
	}
	return nullptr;
}

bool TaskContainer::setSelectedTask(Task* task){
	if(this->selectedTask!=task){
		this->selectedTask = task;
		notifyActionPerformed(
				TaskContainer::ACTION_SELECTEDTASK_CHANGED, 0);
		return true;
	}
	return false;
}

bool TaskContainer::setSelectedTaskIndex(uint8_t index){
	return setSelectedTask(getTaskAt(index));
}

Task* TaskContainer::getSelectedTask(){
	return this->selectedTask;
}

void TaskContainer::setActionListener(IActionListener* listener){
	this->actionListener = listener;
}

void TaskContainer::notifyActionPerformed(
		unsigned int actionId, uint8_t index){
	if(actionListener){
		Action action = Action(this, actionId, nullptr, &index);
		actionListener->actionPerformed(action);
	}
}


