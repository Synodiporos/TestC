/*
 * TaskLoader.h
 *
 *  Created on: Jun 5, 2018
 *      Author: sgeorgiadis
 */

#ifndef SYSTEM_TASKLOADER_H_
#define SYSTEM_TASKLOADER_H_
#include "../Model/Task.h"

class TaskLoader {
public:
	TaskLoader();
	virtual ~TaskLoader();

	static Task* getPredefinedTasks();
	static Task* loadStoredTasks();
	static Task* getAvailableTasks();

};

#endif /* SYSTEM_TASKLOADER_H_ */
