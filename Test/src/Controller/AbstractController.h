/*
 * Controller.h
 *
 *  Created on: 27 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_ABSTRACTCONTROLLER_H_
#define CONTROLLER_ABSTRACTCONTROLLER_H_

class AbstractController {
public:
	AbstractController();
	virtual ~AbstractController();

	void setActivated(bool activated);
	bool isActivated();

	virtual void onForwardPressed() = 0;
	virtual void onForwardReleased() = 0;
	virtual void onFastForward() = 0;
	virtual void onBackwardPressed() = 0;
	virtual void onBackwardReleased() = 0;
	virtual void onFastBackward() = 0;
	virtual void onEnterPressed() = 0;
	virtual void onEnterReleased() = 0;
	virtual void onOK() = 0;
	virtual void onBackPressed() = 0;
	virtual void onBackReleased() = 0;
	virtual void onReturn() = 0;

private:
	bool activate = false;
};

#endif /* CONTROLLER_ABSTRACTCONTROLLER_H_ */
