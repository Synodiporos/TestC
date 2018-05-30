/*
 * Task.h
 *
 *  Created on: 27 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef MODEL_TASK_H_
#define MODEL_TASK_H_

class Task {
public:
	Task(char name, unsigned short duration);
	Task(char name, unsigned short duration, bool editable);
	virtual ~Task();
	void setName(char name);
	char getName();
	void setDuration(unsigned int duration);
	unsigned short getDuration();
	bool isEditable();
	void setEditable(bool editable);

private:
	char name;
	//Duration in seconds
	unsigned int duration = 0;
	bool editable = false;
};

#endif /* MODEL_TASK_H_ */
