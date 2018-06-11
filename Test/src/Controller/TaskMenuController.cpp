/*
 * TaskMenuController.cpp
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#include <iostream>
using namespace std;
#include "../View/ViewActionIds.h"
#include "../View/ViewAssets.h"
#include "TaskMenuController.h"

TaskMenuController::TaskMenuController() {
	// TODO Auto-generated constructor stub
}

TaskMenuController::TaskMenuController(Task* model, TaskMenuView* view){
	// TODO Auto-generated constructor stub
	this->model = model;
	this->view = view;
}

TaskMenuController::~TaskMenuController() {
	// TODO Auto-generated destructor stub
}

Task* TaskMenuController::getModel(){
	return this->model;
}

void TaskMenuController::setModel(Task* model){
	this->model = model;
}

TaskMenuView* TaskMenuController::getView(){
	return this->view;
}

void TaskMenuController::setView(TaskMenuView* view){
	this->view = view;
}

void TaskMenuController::onActivate(){

}

void TaskMenuController::onDeactivate(){

}

void TaskMenuController::onActiveControllerChanged(AbstractController* activeCntrl){
	AbstractCompController* parent = getParent();
	if(parent)
		parent->onActiveControllerChanged(activeCntrl);
}

void TaskMenuController::forwardPressed(){

}

void TaskMenuController::forwardReleased(){

}

void TaskMenuController::forwardHolded(){

}

void TaskMenuController::forwardClicked(){
	if(this->view->hasNextOption())
		this->view->selectNextOption();
	else{

	}
}

void TaskMenuController::backwardPressed(){

}

void TaskMenuController::backwardReleased(){

}

void TaskMenuController::backwardHolded(){

}

void TaskMenuController::backwardClicked(){
	if(this->view->hasPreviousOption())
		this->view->selectPreviousOption();
	else{

	}
}

void TaskMenuController::enterPressed(){
	AbstractCDOption* selected = view->getSelectedOption();
	if(selected){
		selected->click();
	}
}

void TaskMenuController::enterReleased(){
	AbstractCDOption* selected = view->getSelectedOption();
	if(selected){
		selected->hover();
	}
}

void TaskMenuController::enterHolded(){

}

void TaskMenuController::enterClicked(){
	AbstractCDOption* selected = this->view->getSelectedOption();
	if(selected){
		unsigned short int action = selected->getActionId();
		onOptionClicked(action);
	}
	else{

	}
}

void TaskMenuController::backPressed(){

}

void TaskMenuController::backReleased(){

}

void TaskMenuController::backHolded(){
	AbstractCompController* parent = getRootParent();
	if(parent)
			parent->setActiveController(nullptr);
}

void TaskMenuController::backClicked(){
	AbstractCompController* parent = getParent();
	if(parent)
		parent->setActiveController(nullptr);
}

void TaskMenuController::onOptionClicked(unsigned int id){
	cout << "#Action: " << id << " : at TaskMenuController" << endl;
	switch(id){
		case VIEW_ACTION_TASK_START :{
			cout << "  START" << endl;
			break;
		}
		case VIEW_ACTION_TASK_DETAILS :{
			cout << "  DETAILS" << endl;
			break;
		}
		case VIEW_ACTION_TASK_MODIFY :{
			cout << "  MODIFY" << endl;
			break;
		}
		case VIEW_ACTION_TASK_DELETE :{
			cout << "  DELETE" << endl;
			break;
		}
		case VIEW_ACTION_RETURN :{
			cout << "  RETURN" << endl;
			break;
		}
	}
}
