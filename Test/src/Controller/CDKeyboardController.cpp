/*
 * CDKeyboardController.cpp
 *
 *  Created on: Jun 11, 2018
 *      Author: sgeorgiadis
 */

#include "CDKeyboardController.h"
#include "../View/ViewAssets.h"

CDKeyboardController::CDKeyboardController() {
	// TODO Auto-generated constructor stub
	init();
}

CDKeyboardController::CDKeyboardController(CDKeyboard* view) : view(view){
	init();
}

CDKeyboardController::~CDKeyboardController() {
	// TODO Auto-generated destructor stub
}

void CDKeyboardController::init(){
	//this->view = new CDKeyboard(SCREEN_WIDTH);
}

void CDKeyboardController::setView(CDKeyboard* view){
	this->view = view;
}

CDKeyboard* CDKeyboardController::getView(){
	return this->view;
}

void CDKeyboardController::onActivate(){

}

void CDKeyboardController::onDeactivate(){

}

void CDKeyboardController::onForwardPressed(){

}

void CDKeyboardController::onForwardReleased(){

}

void CDKeyboardController::onForwardHolded(){

}

void CDKeyboardController::onForwardClicked(){
	if(view)
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
	if(view)
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
	if(view)
	view->confirmSelection();
	//CDOptionChar* oc = (CDOptionChar*)view->getSelectedOption();
	//char c = oc->getCharacter();
	//view->closePane();
}

void CDKeyboardController::onBackPressed(){

}

void CDKeyboardController::onBackReleased(){

}

void CDKeyboardController::onBackHolded(){

}

void CDKeyboardController::onBackClicked(){
	if(view)
	view->closePane();
	//AbstractCompController* parent = getParent();
	//if(parent)
	//	parent->setActiveController(nullptr);
}


