/*
 * Controller.cpp
 *
 *  Created on: 27 Μαΐ 2018
 *      Author: Synodiporos
 */

#include "AbstractController.h"

AbstractController::AbstractController() {
	// TODO Auto-generated constructor stub

}

AbstractController::~AbstractController() {
	// TODO Auto-generated destructor stub
}

void AbstractController::activate(){
	if(setActivated(true))
		onActivate();
}

void AbstractController::deactivate(){
	if(setActivated(false))
		onDeactivate();
}

bool AbstractController::setActivated(bool activated){
	if(this->activated!=activated){
		this->activated = activated;
		return true;
	}
	return false;
}

bool AbstractController::isActivated(){
	return this->activated;
}

bool AbstractController::setParent(AbstractController* parent){
	if(this->parent!=parent){
		this->parent = parent;
		return true;
	}
	return false;
}

AbstractController* AbstractController::getParent(){
	return this->parent;
}
