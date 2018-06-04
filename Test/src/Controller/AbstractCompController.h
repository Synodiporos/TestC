/*
 * AbstractCompController.h
 *
 *  Created on: 3 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_ABSTRACTCOMPCONTROLLER_H_
#define CONTROLLER_ABSTRACTCOMPCONTROLLER_H_
#include "AbstractController.h"

class AbstractCompController : AbstractController{
public:
	AbstractCompController();
	virtual ~AbstractCompController();
	AbstractController* getActiveController();
	virtual bool setActiveController(AbstractController* active);
	virtual void onForwardPressed();
	virtual void onForwardReleased();
	virtual void onForwardHolded();
	virtual void onForwardClicked();
	virtual void onBackwardPressed();
	virtual void onBackwardReleased();
	virtual void onBackwardHolded();
	virtual void onBackwardClicked();
	virtual void onEnterPressed();
	virtual void onEnterReleased();
	virtual void onEnterHolded();
	virtual void onEnterClicked();
	virtual void onBackPressed();
	virtual void onBackReleased();
	virtual void onBackHolded();
	virtual void onBackClicked();

protected:
	//virtual void onActivate() = 0;
	//virtual void onDeactivate() = 0;
	virtual void forwardPressed() = 0;
	virtual void forwardReleased() = 0;
	virtual void forwardHolded() = 0;
	virtual void forwardClicked() = 0;
	virtual void backwardPressed() = 0;
	virtual void backwardReleased() = 0;
	virtual void backwardHolded() = 0;
	virtual void backwardClicked() = 0;
	virtual void enterPressed() = 0;
	virtual void enterReleased() = 0;
	virtual void enterHolded() = 0;
	virtual void enterClicked() = 0;
	virtual void backPressed() = 0;
	virtual void backReleased() = 0;
	virtual void backHolded() = 0;
	virtual void backClicked() = 0;

private:
	AbstractController* activeCtlr = nullptr;
};

#endif /* CONTROLLER_ABSTRACTCOMPCONTROLLER_H_ */
