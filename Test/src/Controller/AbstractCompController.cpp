/*
 * AbstractCompController.cpp
 *
 *  Created on: 3 Ιουν 2018
 *      Author: Synodiporos
 */

#include "AbstractCompController.h"

AbstractCompController::AbstractCompController() {
	// TODO Auto-generated constructor stub

}

AbstractCompController::~AbstractCompController() {
	// TODO Auto-generated destructor stub
}


AbstractController* AbstractCompController::getActiveController(){
	return this->activeCtlr;
}

bool AbstractCompController::setActiveController(AbstractController* active){
	if(this->activeCtlr!=active){
		if(active)
			active->setParent(this);
		if(this->activeCtlr)
			this->activeCtlr->setParent(nullptr);
		this->activeCtlr = active;
		return true;
	}
	return false;
}

void AbstractCompController::onForwardPressed(){
	if(getActiveController()){
		getActiveController()->onForwardPressed();
	}
	else{
		forwardPressed();
	}
}

void AbstractCompController::onForwardReleased(){
	if(getActiveController()){
		getActiveController()->onForwardReleased();
	}
	else{
		forwardReleased();
	}
}

void AbstractCompController::onForwardHolded(){
	if(getActiveController()){
		getActiveController()->onForwardHolded();
	}
	else{
		forwardHolded();
	}
}

void AbstractCompController::onForwardClicked(){
	if(getActiveController()){
		getActiveController()->onForwardClicked();
	}
	else{
		forwardClicked();
	}
}

void AbstractCompController::onBackwardPressed(){
	if(getActiveController()){
		getActiveController()->onBackwardPressed();
	}
	else{
		backPressed();
	}
}

void AbstractCompController::onBackwardReleased(){
	if(getActiveController()){
		getActiveController()->onBackwardReleased();
	}
	else{
		backwardReleased();
	}
}

void AbstractCompController::onBackwardHolded(){
	if(getActiveController()){
		getActiveController()->onBackwardHolded();
	}
	else{
		backwardHolded();
	}
}

void AbstractCompController::onBackwardClicked(){
	if(getActiveController()){
		getActiveController()->onBackwardClicked();
	}
	else{
		backwardClicked();
	}
}

void AbstractCompController::onEnterPressed(){
	if(getActiveController()){
		getActiveController()->onEnterPressed();
	}
	else{
		enterPressed();
	}
}

void AbstractCompController::onEnterReleased(){
	if(getActiveController()){
		getActiveController()->onEnterReleased();
	}
	else{
		enterReleased();
	}
}

void AbstractCompController::onEnterHolded(){
	if(getActiveController()){
		getActiveController()->onEnterHolded();
	}
	else{
		enterHolded();
	}
}

void AbstractCompController::onEnterClicked(){
	if(getActiveController()){
		getActiveController()->onEnterClicked();
	}
	else{
		enterClicked();
	}
}

void AbstractCompController::onBackPressed(){
	if(getActiveController()){
		getActiveController()->onBackPressed();
	}
	else{
		backPressed();
	}
}

void AbstractCompController::onBackReleased(){
	if(getActiveController()){
		getActiveController()->onBackReleased();
	}
	else{
		backReleased();
	}
}

void AbstractCompController::onBackHolded(){
	if(getActiveController()){
		getActiveController()->onBackHolded();
	}
	else{
		backHolded();
	}
}

void AbstractCompController::onBackClicked(){
	if(getActiveController()){
		getActiveController()->onBackClicked();
	}
	else{
		backClicked();
	}
}
