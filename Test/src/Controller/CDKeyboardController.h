/*
 * CDKeyboardController.h
 *
 *  Created on: Jun 11, 2018
 *      Author: sgeorgiadis
 */

#ifndef CONTROLLER_CDKEYBOARDCONTROLLER_H_
#define CONTROLLER_CDKEYBOARDCONTROLLER_H_

class CDKeyboardController : public AbstractController{
public:
	CDKeyboardController();
	CDKeyboardController(CDKeyboard* view);
	virtual ~CDKeyboardController();

	void setView(CDKeyboard* view);
	CDKeyboard* getView();

	void onForwardPressed();
	void onForwardReleased();
	void onForwardHolded();
	void onForwardClicked();
	void onBackwardPressed();
	void onBackwardReleased();
	void onBackwardHolded();
	void onBackwardClicked();
	void onEnterPressed();
	void onEnterReleased();
	void onEnterHolded();
	void onEnterClicked();
	void onBackPressed();
	void onBackReleased();
	void onBackHolded();
	void onBackClicked();

private:
	CDKeyboard* view = nullptr;

};

#endif /* CONTROLLER_CDKEYBOARDCONTROLLER_H_ */
