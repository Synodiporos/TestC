/*
 * TaskContainerController.cpp
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "TaskContainerController.h"

TaskContainerController::TaskContainerController() {
	// TODO Auto-generated constructor stub

}

TaskContainerController::TaskContainerController(
		TaskContainer* model, TaskContainerView* view) :
			view(view), model(model){
}

TaskContainerController::~TaskContainerController() {
	// TODO Auto-generated constructor stub
}

void TaskContainerController::setModel(TaskContainer* model){
	this->model = model;
}

void TaskContainerController::setView(TaskContainerView* view){
	this->view = view;
}

TaskContainer* TaskContainerController::getModel(){
	return this->model;
}

TaskContainerView* TaskContainerController::getView(){
	return this->view;
}

void TaskContainerController::onActivate(){
	if(model)
		model->addActionListener(this);
}

void TaskContainerController::onDeactivate(){
	if(model)
		model->removeActionListener(this);
}

void TaskContainerController::onForwardPressed(){

}

void TaskContainerController::onForwardReleased(){

}

void TaskContainerController::onForwardHolded(){

}

void TaskContainerController::onForwardClicked(){
	if(this->view->hasNextOption())
		this->view->selectNextOption();
	else{

	}
}

void TaskContainerController::onBackwardPressed(){

}

void TaskContainerController::onBackwardReleased(){

}

void TaskContainerController::onBackwardHolded(){

}

void TaskContainerController::onBackwardClicked(){
	if(this->view->hasPreviousOption())
		this->view->selectPreviousOption();
	else{

	}
}

void TaskContainerController::onEnterPressed(){
	CDOption* selected = view->getSelectedOption();
	if(selected){
		selected->click();
	}
}

void TaskContainerController::onEnterReleased(){
	CDOption* selected = view->getSelectedOption();
	if(selected){
		selected->hover();
	}
}

void TaskContainerController::onEnterHolded(){

}

void TaskContainerController::onEnterClicked(){
	CDOption* selected = this->view->getSelectedOption();
	//cout<<selected->getLabel()->getLabel()<<endl;
	if(selected){
		unsigned short int action = selected->getActionId();
		onOptionClicked(action);
	}
	else{

	}
}

void TaskContainerController::onBackPressed(){

}

void TaskContainerController::onBackReleased(){

}

void TaskContainerController::onBackHolded(){

}

void TaskContainerController::onBackClicked(){

}

void TaskContainerController::onOptionClicked(unsigned int id){
	cout << "TaskContainerController Action: " << id << endl;
}

void TaskContainerController::actionPerformed(Action action){

}

void TaskContainerController::onActiveControllerChanged(){

}
