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

TaskContainer::TaskContainer(std::vector<Task*> tasks){
	this->tasks = tasks;
	if(tasks.size()>0)
		setSelectedTaskIndex(0);
}

TaskContainer::~TaskContainer() {
	// TODO Auto-generated destructor stub
}

const uint8_t TaskContainer::getSize() const{
	return tasks.size();
}

bool TaskContainer::insertTask(Task* task){
	if(task){
		tasks.push_back(task);
		notifyActionPerformed(
				TaskContainer::ACTION_TASK_INSERTED, getSize()-1);
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

const vector<Task*> TaskContainer::getTasks() const{
	return this->tasks;
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

void TaskContainer::addActionListener(IActionListener* listener){
	if(listener!=nullptr)
		this->actionListeners.push_back(listener);
}

void TaskContainer::removeActionListener(IActionListener* listener){
	if(listener!=nullptr)
		for(int i=0; i<actionListeners.size(); i++){
			IActionListener* cl = *(actionListeners.begin() + i);
			if(cl==listener)
				actionListeners.erase(actionListeners.begin() + i);
		}
}

void TaskContainer::removeActionListenerAt(uint8_t index){
	if(index<actionListeners.size())
		actionListeners.erase(actionListeners.begin() + index);
}

std::vector<IActionListener*>* TaskContainer::getActionListeners(){
	return &this->actionListeners;
}

void TaskContainer::notifyActionPerformed(
		unsigned int actionId, uint8_t index){
	for(int i=0; i<actionListeners.size(); i++){
		IActionListener* cl = *(actionListeners.begin() + i);
		Action action = Action(this, actionId, nullptr, &index);
		cl->actionPerformed(action);

	}
}


