/*
 * MainController.h
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_MAINCONTROLLER_H_
#define CONTROLLER_MAINCONTROLLER_H_
#include "AbstractCompController.h"
//#include "../CD/CDOptionPane.h"
#include "../View/MainView.h"
#include "../CD/CDFrame.h"
#include "TaskContainerController.h"
#include "../System/Timer.h"
#include "../Commons/IActionListener.h"
#include "../Commons/Action.h"
#include "../System/SystemConstants.h"
#include "../Factories/TaskContainerFactory.h"

class MainController : public AbstractCompController, IActionListener{
public:
	MainController(MainView* view);
	~MainController();

	void init();
	void setFrame(CDFrame* frame);
	CDFrame* getFrame();
	void setView(MainView* view);
	MainView* getView();
	void setTaskContainerController(TaskContainerController* taskContCntrl);
	void actionPerformed(Action action);
	void validate();

protected:
	void onActivate();
	void onDeactivate();
	void onActiveControllerChanged(AbstractController* activeCntrl);
	bool setActiveScreen(AbstractCDElement* screen);
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
	void onBackReleased(); // Override
	void backHolded();
	void backClicked();
	void onOptionClicked(unsigned int id);

private:
	CDFrame* frame = nullptr;
	MainView* view = nullptr;
	TaskContainerController* taskContCtrl = nullptr;
	Timer timer = Timer(KEYBOARD_HOLDED_SPEED, 0, 0);

	void resetTimer();
};

#endif /* CONTROLLER_MAINCONTROLLER_H_ */
