/*
 * MainController.h
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_MAINCONTROLLER_H_
#define CONTROLLER_MAINCONTROLLER_H_
#include "AbstractCompController.h"
#include "../CD/CDOptionPane.h"

class MainController : public AbstractCompController{
public:
	MainController(CDOptionPane* view);
	~MainController();


protected:
	void onActivate();
	void onDeactivate();
	void forwardPressed();
	void forwardReleased();
	void forwardHolded();
	void forwardClicked();
	void backwardPressed();
	void backwardReleased();
	void backwardHolded();
	void backwardClicked();
	void enterPressed();
	void enterReleased();
	void enterHolded();
	void enterClicked();
	void backPressed();
	void backReleased();
	void backHolded();
	void backClicked();

private:
	CDOptionPane* view = nullptr;


};

#endif /* CONTROLLER_MAINCONTROLLER_H_ */
