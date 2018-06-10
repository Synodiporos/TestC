/*
 * TaskContainerController.cpp
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "TaskContainerController.h"
#include "../Factories/TaskFactory.h"

TaskContainerController::TaskContainerController() :
		AbstractCompController(){
	// TODO Auto-generated constructor stub

}

TaskContainerController::TaskContainerController(
		TaskContainer* model, TaskContainerView* view) :
			view(view), model(model),
			AbstractCompController(){
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


void TaskContainerController::onActiveControllerChanged(AbstractController* activeCntrl){
	AbstractCompController* parent = getParent();
	if(parent)
		parent->onActiveControllerChanged(activeCntrl);
}

void TaskContainerController::forwardPressed(){

}

void TaskContainerController::forwardReleased(){

}

void TaskContainerController::forwardHolded(){

}

void TaskContainerController::forwardClicked(){
	if(this->view->hasNextOption())
		this->view->selectNextOption();
	else{
		//this->view->setSelectedOptionIndex(0);
	}
}

void TaskContainerController::backwardPressed(){

}

void TaskContainerController::backwardReleased(){

}

void TaskContainerController::backwardHolded(){

}

void TaskContainerController::backwardClicked(){
	if(this->view->hasPreviousOption())
		this->view->selectPreviousOption();
	else{
		//this->view->setSelectedOptionIndex(view->getSize()-1);
	}
}

void TaskContainerController::enterPressed(){
	AbstractCDOption* selected = view->getSelectedOption();
	if(selected){
		selected->click();
	}
}

void TaskContainerController::enterReleased(){
	AbstractCDOption* selected = view->getSelectedOption();
	if(selected){
		selected->hover();
	}
}

void TaskContainerController::enterHolded(){

}

void TaskContainerController::enterClicked(){
	AbstractCDOption* selected = this->view->getSelectedOption();
	//cout<<selected->getLabel()->getLabel()<<endl;
	if(selected){
		unsigned short int action = selected->getActionId();
		onOptionClicked(action);
	}
	else{

	}
}

void TaskContainerController::backPressed(){

}

void TaskContainerController::backReleased(){

}

void TaskContainerController::backHolded(){
	AbstractCompController* parent = getRootParent();
	if(parent)
			parent->setActiveController(nullptr);
}

void TaskContainerController::backClicked(){
	AbstractCompController* parent = getParent();
	if(parent)
		parent->setActiveController(nullptr);
}

void TaskContainerController::onOptionClicked(unsigned int id){
	cout << "#Action: " << id << " : at TaskContainerController" << endl;
	cout << "  SELECT TASK " << id << endl;
	Task* task = model->getTaskAt(id);
	TaskMenuController* ctrl =
			TaskFactory::createMenuController(task);

	setActiveController(ctrl);
}

void TaskContainerController::actionPerformed(Action action){

}

