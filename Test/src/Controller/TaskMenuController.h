/*
 * TaskMenuController.h
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#ifndef CONTROLLER_TASKMENUCONTROLLER_H_
#define CONTROLLER_TASKMENUCONTROLLER_H_

#include "AbstractCompController.h"
#include "../Model/Task.h"
#include "../View/TaskMenuView.h"

class TaskMenuController: public AbstractCompController {
public:
	TaskMenuController();
	TaskMenuController(Task* model, TaskMenuView* view);
	virtual ~TaskMenuController();

	Task* getModel();
	void setModel(Task* model);
	TaskMenuView* getView();
	void setView(TaskMenuView* view);

protected:
	void onActivate();
	void onDeactivate();
	void onActiveControllerChanged(AbstractController* activeCntrl);
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
	Task* model = nullptr;
	TaskMenuView* view = nullptr;
};

#endif /* CONTROLLER_TASKMENUCONTROLLER_H_ */
