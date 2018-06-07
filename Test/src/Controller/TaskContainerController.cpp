/*
 * TaskContainerController.cpp
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

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

}

void TaskContainerController::onBackwardPressed(){

}

void TaskContainerController::onBackwardReleased(){

}

void TaskContainerController::onBackwardHolded(){

}

void TaskContainerController::onBackwardClicked(){

}

void TaskContainerController::onEnterPressed(){

}

void TaskContainerController::onEnterReleased(){

}

void TaskContainerController::onEnterHolded(){

}

void TaskContainerController::onEnterClicked(){

}

void TaskContainerController::onBackPressed(){

}

void TaskContainerController::onBackReleased(){

}

void TaskContainerController::onBackHolded(){

}

void TaskContainerController::onBackClicked(){

}

void TaskContainerController::actionPerformed(Action action){

}

void TaskContainerController::onActiveControllerChanged(){

}
