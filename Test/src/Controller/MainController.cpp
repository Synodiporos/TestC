/*
 * MainController.cpp
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "MainController.h"

MainController::MainController(CDOptionPane* view) :
	view(view){
	// TODO Auto-generated constructor stub

}

MainController::~MainController() {
	// TODO Auto-generated destructor stub
}

void MainController::onActivate(){

}

void MainController::onDeactivate(){

}

void MainController::forwardPressed(){

}

void MainController::forwardReleased(){

}

void MainController::forwardHolded(){

}

void MainController::forwardClicked(){
	cout << "hasNext: " << this->view->hasNextOption() << endl;
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
	cout << "hasPrev: " << this->view->hasPreviousOption() << endl;
	if(this->view->hasPreviousOption())
		this->view->selectPreviousOption();
	else{

	}
}

void MainController::enterPressed(){

}

void MainController::enterReleased(){

}

void MainController::enterHolded(){

}

void MainController::enterClicked(){
	cout << "enterClicked" << endl;
	CDOption* selected = this->view->getSelectedOption();
	if(selected){
		unsigned short int action = selected->getActionId();
		cout << "Action: " << action << endl;
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
