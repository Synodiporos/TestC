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
	TaskContainer(std::vector<Task*> tasks);
	virtual ~TaskContainer();

	const uint8_t getSize() const;
	bool insertTask(Task *task);
	bool removeTask(Task* task);
	bool removeTaskAt(uint8_t index);
	const vector<Task*> getTasks() const;
	Task* getTaskAt(uint8_t index);
	bool setSelectedTask(Task* task);
	bool setSelectedTaskIndex(uint8_t index);
	Task* getSelectedTask();
	void addActionListener(IActionListener* listener);
	void removeActionListener(IActionListener* listener);
	void removeActionListenerAt(uint8_t index);
	std::vector<IActionListener*>* getActionListeners();


private:
	typedef std::vector<Task*> container;
	container tasks;
	Task* selectedTask = nullptr;
	std::vector<IActionListener*> actionListeners;

	void notifyActionPerformed(unsigned int action, uint8_t index);
};

#endif /* MODEL_TASKCONTAINER_H_ */
