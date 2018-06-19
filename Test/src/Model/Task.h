/*
 * Task.h
 *
 *  Created on: 27 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#ifndef MODEL_TASK_H_
#define MODEL_TASK_H_

class Task {
public:
	Task(const char* name, unsigned short duration);
	Task(const char* name, unsigned short duration, bool editable);
	virtual ~Task();
	void setName(const char* name);
	const char* getName();
	void setDuration(unsigned int duration);
	unsigned int getDuration();
	bool isEditable();
	void setEditable(bool editable);

private:
	const char* name;
	//Duration in seconds
	unsigned int duration = 0;
	bool editable = true;
};

#endif /* MODEL_TASK_H_ */
