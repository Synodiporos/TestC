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

MainController::MainController(MainView* view) :
	view(view){
	// TODO Auto-generated constructor stub
	timer.setActionListener(this);
}

MainController::~MainController() {
	// TODO Auto-generated destructor stub
}

void MainController::init(){

	//taskContCtrl = TaskContainerFactory::createController();
}

void MainController::setFrame(CDFrame* frame){
	this->frame = frame;
}

CDFrame* MainController::getFrame(){
	return this->frame;
}

void MainController::setView(MainView* view){
	this->view = view;
}

MainView* MainController::getView(){
	return this->view;
}

void MainController::setTaskContainerController(
		TaskContainerController* taskContCntrl){
	this->taskContCtrl = taskContCntrl;
}

void MainController::onActivate(){
	if(view)
		view->setActionListener(this);
	if(taskContCtrl)
		taskContCtrl->activate();
}

void MainController::onDeactivate(){
	if(view)
		view->setActionListener(nullptr);
	if(taskContCtrl)
			taskContCtrl->deactivate();
}

void MainController::onActiveControllerChanged(AbstractController* activeCntrl){
	AbstractController* active = activeCntrl;
	if(!active)
		active = this;
	cout << "-ActiveControllerChanged to " << active << endl;
}

bool MainController::setActiveScreen(AbstractCDElement* screen){
	bool res = AbstractController::setActiveScreen(screen);
	cout << "View Changed!" << endl;
	if(frame)
		frame->setPage(screen);
	return res;
}

void MainController::forwardPressed(){

}

void MainController::forwardReleased(){
	resetTimer();
}

void MainController::forwardHolded(){
	timer.setActionId(41);
	timer.start();
}

void MainController::forwardClicked(){
	if(this->view->hasNextOption()){
		this->view->selectNextOption();
	}
	else{
		this->view->setSelectedOptionIndex(0);
	}
}

void MainController::backwardPressed(){

}

void MainController::backwardReleased(){
	resetTimer();
}

void MainController::backwardHolded(){
	timer.setActionId(42);
	timer.start();
}

void MainController::backwardClicked(){
	if(this->view->hasPreviousOption())
		this->view->selectPreviousOption();
	else{
		this->view->setSelectedOptionIndex(view->getSize()-1);
	}
}

void MainController::enterPressed(){
	AbstractCDOption* selected = view->getSelectedOption();
	if(selected){
		selected->click();
	}
}

void MainController::enterReleased(){
	AbstractCDOption* selected = view->getSelectedOption();
	if(selected){
		selected->hover();
	}
	resetTimer();
}

void MainController::enterHolded(){
	timer.setActionId(43);
	timer.start();
}

void MainController::enterClicked(){
	if(view){
		view->confirmSelection();
	}
}

void MainController::backPressed(){

}

void MainController::backReleased(){
	resetTimer();
}

//Override
void MainController::onBackReleased(){
	if(view)
		view->close();
}

void MainController::backHolded(){
	//timer.setActionId(44);
	//timer.start();
}

void MainController::backClicked(){

}

void MainController::actionPerformed(Action action){
	unsigned int actionId = action.getActionId();
	if(timer.getIterationsPerformed()==KEYBOARD_HOLDED_CCL)
		timer.setInterval(KEYBOARD_HOLDED_ACC_SPEED);

	//cout << "TIC " << actionId << endl;
	switch(actionId){
		case 41:{
			onForwardClicked();
			break;
		}
		case 42:{
			onBackwardClicked();
			break;
		}
		case 43:{
			onBackClicked();
			break;
		}
		case 44:{
			onEnterClicked();
			break;
		}

		case CDOptionPane::SELECTION_CHANGE:{
			break;
		}
		case CDOptionPane::SELECTION_CONFIRM:{
			AbstractCDOption* selected = this->view->getSelectedOption();
			if(selected){
				unsigned short int action = selected->getActionId();
				onOptionClicked(action);
			}
			break;
		}
		case CDOptionPane::PANE_CLOSE:{
			setActiveController(nullptr);
			break;
		}
	}
}


void MainController::onOptionClicked(unsigned int id){
	cout << "#Action: " << id << " : at MainController" <<endl;
	switch(id){
		case VIEW_ACTION_AUTO :{
			cout << "  AUTO" << endl;
			//if(taskContCtrl)
			setActiveScreen(taskContCtrl->getView());
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

void MainController::validate(){
	timer.validate();
}

void MainController::resetTimer(){
	timer.stop();
	timer.setInterval(KEYBOARD_HOLDED_SPEED);
}
