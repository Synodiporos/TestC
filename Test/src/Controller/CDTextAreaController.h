/*
 * CDTextAreaController.h
 *
 *  Created on: Jun 11, 2018
 *      Author: sgeorgiadis
 */

#ifndef CONTROLLER_CDTEXTAREACONTROLLER_H_
#define CONTROLLER_CDTEXTAREACONTROLLER_H_
#include "AbstractCompController.h"
#include "CDKeyboardController.h"
#include "../CD/CDTextArea.h"

class CDTextAreaController : public AbstractCompController{
public:
	CDTextAreaController();
	virtual ~CDTextAreaController();

	void setView(CDTextArea* view);
	CDTextArea* getView();

	virtual void onActiveControllerChanged(AbstractController* activeCntrl) = 0;

protected:
	virtual void onActivate() = 0;
	virtual void onDeactivate() = 0;
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
	CDKeyboardController* keyboardCtrl = nullptr;
	CDTextArea view = CDTextArea();
	void init();
};

#endif /* CONTROLLER_CDTEXTAREACONTROLLER_H_ */
