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
#include "TaskContainerController.h"

class MainController : public AbstractCompController{
public:
	MainController(CDOptionPane* view);
	~MainController();

	void setTaskContainerController(TaskContainerController* taskContCntrl);

protected:
	void onActivate();
	void onDeactivate();
	void onActiveControllerChanged();
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
	void onOptionClicked(unsigned int id);

private:
	CDOptionPane* view = nullptr;
	TaskContainerController* taskContCtrl = nullptr;

};

#endif /* CONTROLLER_MAINCONTROLLER_H_ */
