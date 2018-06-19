/*
 * Task.cpp
 *
 *  Created on: 27 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#include "Task.h"

Task::Task(const char* name, unsigned short duration)
	: name(name), duration(duration) {
	// TODO Auto-generated constructor stub

}

Task::Task(const char* name, unsigned short duration, bool editable)
	: name(name), duration(duration), editable(editable){

}

Task::~Task() {

}

void Task::setName(const char* name){
	this->name = name;
}

const char* Task::getName(){
	return this->name;
}

void Task::setDuration(unsigned int duration){
	this->duration = duration;
}

unsigned int Task::getDuration(){
	return this->duration;
}

bool Task::isEditable(){
	return this->editable;
}

void Task::setEditable(bool editable){
	this->editable = editable;
}
