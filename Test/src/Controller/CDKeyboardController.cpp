/*
 * CDKeyboardController.cpp
 *
 *  Created on: Jun 11, 2018
 *      Author: sgeorgiadis
 */

#include "CDKeyboardController.h"

CDKeyboardController::CDKeyboardController() {
	// TODO Auto-generated constructor stub

}

CDKeyboardController::CDKeyboardController(CDKeyboard* view) : view(view){

}

CDKeyboardController::~CDKeyboardController() {
	// TODO Auto-generated destructor stub
}

void CDKeyboardController::onForwardPressed(){

}

void CDKeyboardController::onForwardReleased(){

}

void CDKeyboardController::onForwardHolded(){

}

void CDKeyboardController::onForwardClicked(){
	if(this->view->hasNextOption()){
		this->view->selectNextOption();
	}
	else{
		//this->view->setSelectedOptionIndex(0);
	}
}

void CDKeyboardController::onBackwardPressed(){

}

void CDKeyboardController::onBackwardReleased(){

}

void CDKeyboardController::onBackwardHolded(){

}

void CDKeyboardController::onBackwardClicked(){
	if(this->view->hasPreviousOption())
		this->view->selectPreviousOption();
	else{
		//this->view->setSelectedOptionIndex(view->getSize()-1);
	}
}

void CDKeyboardController::onEnterPressed(){

}

void CDKeyboardController::onEnterReleased(){

}

void CDKeyboardController::onEnterHolded(){

}

void CDKeyboardController::onEnterClicked(){
	view->confirmSelection();
}

void CDKeyboardController::onBackPressed(){

}

void CDKeyboardController::onBackReleased(){

}

void CDKeyboardController::onBackHolded(){

}

void CDKeyboardController::onBackClicked(){
	view->closePane();
	//AbstractCompController* parent = getParent();
	//if(parent)
	//	parent->setActiveController(nullptr);
}
