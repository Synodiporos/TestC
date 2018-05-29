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

void AbstractController::setActivated(bool activated){
	this->activate = activated;
}

bool AbstractController::isActivated(){
	return this->activate;
}
