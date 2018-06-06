/*
 * TaskLoader.h
 *
 *  Created on: Jun 5, 2018
 *      Author: sgeorgiadis
 */

#ifndef SYSTEM_TASKLOADER_H_
#define SYSTEM_TASKLOADER_H_
#include "../Model/Task.h"
#include <vector>
using namespace std;

class TaskLoader {
public:
	virtual ~TaskLoader();
	static TaskLoader* getInstance();
	static vector<Task*> getPredefinedTasks();
	static vector<Task*> loadStoredTasks();
	static vector<Task*> getAvailableTasks();

private:
	static TaskLoader* instance;
	TaskLoader();
	TaskLoader(TaskLoader const&);     // Don't Implement
	void operator=(TaskLoader const&); // Don't implement
};

#endif /* SYSTEM_TASKLOADER_H_ */
