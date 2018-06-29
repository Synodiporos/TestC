/*
 * CDTextAreaController.cpp
 *
 *  Created on: Jun 11, 2018
 *      Author: sgeorgiadis
 */
#include <iostream>
using namespace std;
#include "CDTextAreaController.h"
#include "../View/ViewAssets.h"

CDTextAreaController::CDTextAreaController() {
	init();
}

CDTextAreaController::CDTextAreaController(CDTextArea* view) :
	view(view){
	init();
}

CDTextAreaController::~CDTextAreaController() {

}

void CDTextAreaController::setView(CDTextArea* view){
	this->view = view;
}

CDTextArea* CDTextAreaController::getView(){
	return this->view;
}

void CDTextAreaController::setRootFrame(CDFrame* frame){
	this->frame = frame;
}

CDFrame* CDTextAreaController::getRootFrame(){
	return this->frame;
}

void CDTextAreaController::init(){
	CDKeyboard* keyboardView = new CDKeyboard(SCREEN_WIDTH);
	keyboardView->appendCharSet(LOWER_CASE_LETTERS);
	keyboardView->appendCharSet(UPPER_CASE_LETTERS);
	keyboardView->appendCharSet(TEXT_SYMBOLS);
	keyboardView->appendCharSet(NUMBERS);
	keyboardView->appendCharSet(SYMBOLS);

	keyboardView->setActionListener(this);
	this->keyboardCtrl.setView(keyboardView);
}

void CDTextAreaController::onActivate(){

}

void CDTextAreaController::onDeactivate(){

}

bool CDTextAreaController::setActiveScreen(AbstractCDElement* screen){
	if(getRootFrame()){
		bool res = getRootFrame()->setPage(screen);
		cout << "SET ACTIVE SCREEN " << screen
				<< " ? " << res << endl;
		return res;
	}
	return false;
}

void CDTextAreaController::onActiveControllerChanged(
		AbstractController* activeCntrl){
	cout << "ActiveControllerChanged! " << activeCntrl << endl;
}

void CDTextAreaController::forwardPressed(){

}

void CDTextAreaController::forwardReleased(){

}

void CDTextAreaController::forwardHolded(){

}

void CDTextAreaController::forwardClicked(){
	if(getView()->getOptionPane()->hasNextOption()){
		getView()->selectNext();
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
	if(getView()->getOptionPane()->hasPreviousOption()){
		getView()->selectPrevious();
		cout << "   HERE " << getView()->getRootFrame() << endl;
	}
	else{

	}
}

void CDTextAreaController::enterPressed(){

}

void CDTextAreaController::enterReleased(){

}

void CDTextAreaController::enterHolded(){

}

void CDTextAreaController::enterClicked(){
	setActiveScreen(keyboardCtrl.getView());
	setActiveController(&keyboardCtrl);
}

void CDTextAreaController::backPressed(){

}

void CDTextAreaController::backReleased(){

}

void CDTextAreaController::backHolded(){

}

void CDTextAreaController::backClicked(){
	if(getParent())
		getParent()->setActiveController(nullptr);
}

void CDTextAreaController::actionPerformed(Action action){
	unsigned short int actionId = action.getActionId();
	//cout << "ActionPerformed: " << actionId << endl;
	switch(actionId){
		case CDOptionPane::SELECTION_CHANGE:{
			break;
		}
		case CDOptionPane::SELECTION_CONFIRM:{
			CDOptionPane* op = (CDOptionPane*)action.getSource();
			CDOptionChar* oc = (CDOptionChar*)op->getSelectedOption();
			char c = oc->getCharacter();
			keyboardCtrl.getView()->closePane();
			cout << "Selected Char: " << c << endl;
			view->setCharAndAppend(c);
			break;
		}
		case CDOptionPane::PANE_CLOSE:{
			setActiveController(nullptr);
			setActiveScreen(view);
			break;
		}
	}
}
