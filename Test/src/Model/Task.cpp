/*
 * Task.cpp
 *
 *  Created on: 27 Μαΐ 2018
 *      Author: Synodiporos
 */

#include "Task.h"

Task::Task(char name, unsigned short duration)
	: name(name), duration(duration) {
	// TODO Auto-generated constructor stub

}

Task::Task(char name, unsigned short duration, bool editable)
	: name(name), duration(duration), editable(editable){

}

Task::~Task() {

}

void Task::setName(char name){
	this->name = name;
}

char Task::getName(){
	return this->name;
}