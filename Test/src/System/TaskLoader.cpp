/*
 * TaskLoader.cpp
 *
 *  Created on: Jun 5, 2018
 *      Author: sgeorgiadis
 */

#include "TaskLoader.h"
#include "PredefinedTasks.h"

TaskLoader::TaskLoader() {
	// TODO Auto-generated constructor stub

}

TaskLoader::~TaskLoader() {
	// TODO Auto-generated destructor stub
}

Task* TaskLoader::getPredefinedTasks(){
	Task* t1 = new TASK_1;
	Task* t2 = new TASK_2;
	Task* t3 = new TASK_3;

	Task* tasks[3] = {t1,t2,t3};
	return *tasks;
}

Task* TaskLoader::loadStoredTasks(){
	Task* t1 = new Task((char*)"Task 4", 45);
	Task* t2 = new Task((char*)"Task 4", 45);
	return {t1,t2};
}

Task* TaskLoader::getAvailableTasks(){
	Task* l1 = getPredefinedTasks();
	l1[3] = loadStoredTasks();
	return l1;
}
