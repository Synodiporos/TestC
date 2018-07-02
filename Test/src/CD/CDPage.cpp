/*
 * CDPage.cpp
 *
 *  Created on: 1 Ιουλ 2018
 *      Author: Synodiporos
 */

#include "CDPage.h"

CDPage::CDPage() {
	// TODO Auto-generated constructor stub

}

CDPage::CDPage(int8_t w, int8_t h) :
	CDElement(w, h){

}

CDPage::CDPage(uint8_t x, uint8_t y, int8_t w, int8_t h):
	CDElement(x, y, w, h){

}

CDPage::~CDPage() {
	// TODO Auto-generated destructor stub
}

std::vector<IActionListener*> CDPage::getPageListeners(){
	return this->pageListeners;
}

void CDPage::addPageListener(IActionListener* actionListener){
	this->pageListeners.push_back(actionListener);
}

void CDPage::removePageListener(IActionListener* actionListener){
	for (std::vector<IActionListener*>::iterator it = pageListeners.begin() ;
			it != pageListeners.end(); ++it){
		if( *it == actionListener)
			pageListeners.erase(it);
	}
}

IActionListener* CDPage::getPageListener(unsigned int index){
	return *(pageListeners.begin() + index);
}

bool CDPage::showAsPage(){
	SystemDisplay* display = SystemDisplayManager::getInstanse()
		->getDefaultSystemDisplay();
	if(display){
		bool res = display->setPage(this);
		notifyActionPerformed(PANE_SHOW);
		return res;
	}
	return false;
}

bool CDPage::showAsPopUp(){
	SystemDisplay* display = SystemDisplayManager::getInstanse()
		->getDefaultSystemDisplay();
	if(display){
		bool res = display->setPopUp(this);
		notifyActionPerformed(PANE_SHOW);
		return res;
	}
	return false;
}

bool CDPage::showAsToolTip(){
	SystemDisplay* display = SystemDisplayManager::getInstanse()
		->getDefaultSystemDisplay();
	if(display){
		bool res = display->setToolTip(this);
		notifyActionPerformed(PANE_SHOW);
		return res;
	}
	return false;
}

bool CDPage::close(){
	SystemDisplay* display = SystemDisplayManager::getInstanse()
		->getDefaultSystemDisplay();
	if(display){
		bool res = false;
		if(display->getPage() == this)
			res = display->setPage(nullptr);
		if(display->getPopUp() == this)
			res = display->setPopUp(nullptr);
		if(display->getToolTip() == this)
			res = display->setToolTip(nullptr);
		notifyActionPerformed(PANE_CLOSE);
		return res;
	}
	return false;
}

void CDPage::notifyActionPerformed(unsigned short int actionId){
	for (std::vector<IActionListener*>::iterator it = pageListeners.begin() ;
			it != pageListeners.end(); ++it){
		Action action = Action(this, actionId, nullptr, nullptr);
		(*it)->actionPerformed(action);
	}
}
