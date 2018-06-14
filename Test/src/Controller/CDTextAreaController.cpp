/*
 * CDTextAreaController.cpp
 *
 *  Created on: Jun 11, 2018
 *      Author: sgeorgiadis
 */

#include "CDTextAreaController.h"
#include "../View/ViewAssets.h"

CDTextAreaController::CDTextAreaController() {
	// TODO Auto-generated constructor stub

}

CDTextAreaController::~CDTextAreaController() {
	// TODO Auto-generated destructor stub
}

void CDTextAreaController::setView(CDTextArea* view){
	this->view = *view;
}

CDTextArea* CDTextAreaController::getView(){
	return &this->view;
}

void CDTextAreaController::init(){
	CDKeyboard* keyboardView = new CDKeyboard(SCREEN_WIDTH);
	this->keyboardCtrl = new CDKeyboardController(keyboardView);
}

void CDTextAreaController::onActivate(){

}

void CDTextAreaController::onDeactivate(){

}

void CDTextAreaController::onActiveControllerChanged(AbstractController* activeCntrl){

}

void CDTextAreaController::forwardPressed(){

}

void CDTextAreaController::forwardReleased(){

}

void CDTextAreaController::forwardHolded(){

}

void CDTextAreaController::forwardClicked(){
	if(getView()->getOptionPane()->hasNextOption()){
		getView()->setSelectedIndex();
	}
	else{

	}

}

void CDTextAreaController::backwardPressed(){

}

void CDTextAreaController::backwardReleased(){

}

void CDTextAreaController::backwardHolded(){

}

void CDTextAreaController::backwardClicked(){

}

void CDTextAreaController::enterPressed(){

}

void CDTextAreaController::enterReleased(){

}

void CDTextAreaController::enterHolded(){

}

void CDTextAreaController::enterClicked(){

}

void CDTextAreaController::backPressed(){

}

void CDTextAreaController::backReleased(){

}

void CDTextAreaController::backHolded(){

}

void CDTextAreaController::backClicked(){

}
