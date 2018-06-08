/*
 * TaskContainerController.h
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_TASKCONTAINERCONTROLLER_H_
#define CONTROLLER_TASKCONTAINERCONTROLLER_H_
#include "../Model/TaskContainer.h"
#include "../View/TaskContainerView.h"
#include "AbstractCompController.h"
#include "../Commons/IActionListener.h"
#include "../Commons/Action.h"

class TaskContainerController : public
	AbstractCompController, IActionListener{
public:
	TaskContainerController();
	TaskContainerController(TaskContainer* model, TaskContainerView* view);
	virtual ~TaskContainerController();

	void setModel(TaskContainer* model);
	void setView(TaskContainerView* view);
	TaskContainer* getModel();
	TaskContainerView* getView();

	void actionPerformed(Action action);

protected:
	virtual void onActivate();
	virtual void onDeactivate();
	virtual void onActiveControllerChanged();
	virtual void forwardPressed();
	virtual void forwardReleased();
	virtual void forwardHolded();
	virtual void forwardClicked();
	virtual void backwardPressed();
	virtual void backwardReleased();
	virtual void backwardHolded();
	virtual void backwardClicked();
	virtual void enterPressed();
	virtual void enterReleased();
	virtual void enterHolded();
	virtual void enterClicked();
	virtual void backPressed();
	virtual void backReleased();
	virtual void backHolded();
	virtual void backClicked();
	virtual void onOptionClicked(unsigned int id);

private:
	TaskContainer* model = nullptr;
	TaskContainerView* view = nullptr;

	//TaskMenuController* taskMenuCntr = nullptr;
};

#endif /* CONTROLLER_TASKCONTAINERCONTROLLER_H_ */
