/*
 * SystemDisplayManager.cpp
 *
 *  Created on: 1 Ιουλ 2018
 *      Author: Synodiporos
 */

#include "SystemDisplayManager.h"

SystemDisplayManager* SystemDisplayManager::instance = 0;

SystemDisplayManager::SystemDisplayManager() {
	// TODO Auto-generated constructor stub

}

SystemDisplayManager::~SystemDisplayManager() {
	delete instance;
}

SystemDisplayManager* SystemDisplayManager::getInstanse(){
	if(instance)
		instance = new SystemDisplayManager();

	return instance;
}

void SystemDisplayManager::setDefaultSystemDisplay(SystemDisplay* defaultDisplay){
	this->defaultDisplay = defaultDisplay;
}

SystemDisplay* SystemDisplayManager::getDefaultSystemDisplay(){
	return this->defaultDisplay;
}
