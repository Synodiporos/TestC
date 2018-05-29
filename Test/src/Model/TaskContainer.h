/*
 * TaskContainer.h
 *
 *  Created on: 27 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef MODEL_TASKCONTAINER_H_
#define MODEL_TASKCONTAINER_H_
#include <vector>
using namespace std;
#include "Task.h"
#include "../Commons/IActionListener.h"
#include "../Commons/Action.h"
#include <stdint.h>

class TaskContainer {
public:
	static const uint8_t ACTION_SELECTEDTASK_CHANGED = 1;
	static const uint8_t ACTION_TASK_INSERTED = 2;
	static const uint8_t ACTION_TASK_REMOVED = 3;

	TaskContainer();
	virtual ~TaskContainer();

	uint8_t getSize();
	bool insertTask(Task *task);
	bool removeTask(Task* task);
	bool removeTaskAt(uint8_t index);
	Task* getTaskAt(uint8_t index);
	bool setSelectedTask(Task* task);
	bool setSelectedTaskIndex(uint8_t index);
	Task* getSelectedTask();
	void setActionListener(IActionListener* listener);


private:
	typedef std::vector<Task*> container;
	container tasks;
	Task* selectedTask = nullptr;
	IActionListener* actionListener = nullptr;
	void notifyActionPerformed(unsigned int action, uint8_t index);
};

#endif /* MODEL_TASKCONTAINER_H_ */
