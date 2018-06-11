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

void CDTextAreaController::init(){
	CDKeyboard* keyboardView = new CDKeyboard(SCREEN_WIDTH);
	this->keyboardCtrl = new CDKeyboardController(keyboardView);
}

void onActivate(){

}

void onDeactivate(){

}

void onActiveControllerChanged(AbstractController* activeCntrl){

}

void forwardPressed(){

}

void forwardReleased(){

}

void forwardHolded(){

}

void forwardClicked(){

}

void backwardPressed(){

}

void backwardReleased(){

}

void backwardHolded(){

}

void backwardClicked(){

}

void enterPressed(){

}

void enterReleased(){

}

void enterHolded(){

}

void enterClicked(){

}

void backPressed(){

}

void backReleased(){

}

void backHolded(){

}

void backClicked(){

}
