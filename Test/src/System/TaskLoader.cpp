/*
 * TaskLoader.cpp
 *
 *  Created on: Jun 5, 2018
 *      Author: sgeorgiadis
 */

#include "TaskLoader.h"
#include "PredefinedTasks.h"

TaskLoader* TaskLoader::instance = 0;

TaskLoader::TaskLoader() {
	// TODO Auto-generated constructor stub

}

TaskLoader::~TaskLoader() {
	delete instance;
}

TaskLoader* TaskLoader::getInstance(){
	if (instance == 0)
		instance = new TaskLoader();
	return instance;
}

vector<Task*> TaskLoader::getPredefinedTasks(){
	Task* t1 = new TASK_1;
	Task* t2 = new TASK_2;
	Task* t3 = new TASK_3;

	vector<Task*> list = vector<Task*>();
	list.push_back(t1);
	list.push_back(t2);
	list.push_back(t3);
	return list;
}

vector<Task*> TaskLoader::loadStoredTasks(){
	Task* t1 = new Task((char*)"Task 4", 30);
	Task* t2 = new Task((char*)"Task 5", 45);

	vector<Task*> list = vector<Task*>();
	list.push_back(t1);
	list.push_back(t2);
	return list;
}

vector<Task*> TaskLoader::getAvailableTasks(){
	vector<Task*> prefList = getPredefinedTasks();
	vector<Task*> loadList = loadStoredTasks();
	prefList.insert(prefList.end(),
			loadList.begin(), loadList.end());
	return prefList;
}
