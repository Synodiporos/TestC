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
#include "AbstractController.h"
#include "../Commons/IActionListener.h"
#include "../Commons/Action.h"

class TaskContainerController : public
	AbstractController, IActionListener{
public:
	TaskContainerController();
	virtual ~TaskContainerController();
	bool setActivated(bool activate);

	virtual void onForwardPressed() ;
	virtual void onForwardReleased() ;
	virtual void onForwardHolded() ;
	virtual void onForwardClicked() ;
	virtual void onBackwardPressed() ;
	virtual void onBackwardReleased() ;
	virtual void onBackwardHolded() ;
	virtual void onBackwardClicked() ;
	virtual void onEnterPressed() ;
	virtual void onEnterReleased() ;
	virtual void onEnterHolded() ;
	virtual void onEnterClicked() ;
	virtual void onBackPressed() ;
	virtual void onBackReleased() ;
	virtual void onBackHolded() ;
	virtual void onBackClicked() ;

	void actionPerformed(Action action);


private:
	TaskContainer* model = nullptr;
	TaskContainerView* view = nullptr;

};

#endif /* CONTROLLER_TASKCONTAINERCONTROLLER_H_ */
