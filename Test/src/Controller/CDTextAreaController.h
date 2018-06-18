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
#include "../Commons/IActionListener.h"
#include "../CD/CDTextArea.h"

class CDTextAreaController : public AbstractCompController, IActionListener{
public:
	CDTextAreaController();
	CDTextAreaController(CDTextArea* view);
	virtual ~CDTextAreaController();
	void init();
	void setView(CDTextArea* view);
	CDTextArea* getView();

	virtual void onActiveControllerChanged(AbstractController* activeCntrl);

protected:
	virtual void onActivate();
	virtual void onDeactivate();
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

	void actionPerformed(Action action);

private:
	CDKeyboardController keyboardCtrl = CDKeyboardController();
	CDTextArea view = CDTextArea();
};

#endif /* CONTROLLER_CDTEXTAREACONTROLLER_H_ */
