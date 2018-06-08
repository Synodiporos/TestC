/*
 * MainController.cpp
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "MainController.h"
#include "../View/ViewActionIds.h"

MainController::MainController(CDOptionPane* view) :
	view(view){
	// TODO Auto-generated constructor stub

}

MainController::~MainController() {
	// TODO Auto-generated destructor stub
}

void MainController::setTaskContainerController(
		TaskContainerController* taskContCntrl){
	this->taskContCtrl = taskContCntrl;
}

void MainController::onActivate(){

}

void MainController::onDeactivate(){

}

void MainController::onActiveControllerChanged(){
	cout << " ActiveControllerChanged to " << getActiveController() << endl;
}

void MainController::forwardPressed(){

}

void MainController::forwardReleased(){

}

void MainController::forwardHolded(){

}

void MainController::forwardClicked(){
	if(this->view->hasNextOption())
		this->view->selectNextOption();
	else{

	}
}

void MainController::backwardPressed(){

}

void MainController::backwardReleased(){

}

void MainController::backwardHolded(){

}

void MainController::backwardClicked(){
	if(this->view->hasPreviousOption())
		this->view->selectPreviousOption();
	else{

	}
}

void MainController::enterPressed(){
	CDOption* selected = view->getSelectedOption();
	if(selected){
		selected->click();
	}
}

void MainController::enterReleased(){
	CDOption* selected = view->getSelectedOption();
	if(selected){
		selected->hover();
	}
}

void MainController::enterHolded(){

}

void MainController::enterClicked(){
	CDOption* selected = this->view->getSelectedOption();
	if(selected){
		unsigned short int action = selected->getActionId();
		onOptionClicked(action);
	}
	else{

	}
}

void MainController::backPressed(){

}

void MainController::backReleased(){

}

void MainController::backHolded(){

}

void MainController::backClicked(){

}

void MainController::onOptionClicked(unsigned int id){
	cout << "Action: " << id << endl;
	switch(id){
		case VIEW_ACTION_AUTO :{
			cout << "  AUTO" << endl;
			//if(taskContCtrl)
				setActiveController(taskContCtrl);
			break;
		}
		case VIEW_ACTION_MANUAL :{
			cout << "  MANUAL" << endl;
			break;
		}
		case VIEW_ACTION_SETTINGS :{
			cout << "  SETTINGS" << endl;
			break;
		}
		case VIEW_ACTION_STATISTICS :{
			cout << "  STATISTICS" << endl;
			break;
		}
	}
}
