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

TaskContainerController::~TaskContainerController() {
	// TODO Auto-generated destructor stub
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
