/*
 * Controller.h
 *
 *  Created on: 27 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_ABSTRACTCONTROLLER_H_
#define CONTROLLER_ABSTRACTCONTROLLER_H_
#include "KeyboardListener.h"

class AbstractController : public KeyboardListener{
public:
	AbstractController();
	virtual ~AbstractController();

	virtual void activate();
	virtual void deactivate();
	virtual bool setActivated(bool activated);
	bool isActivated();
	bool setParent(AbstractController* parent);
	AbstractController* getParent();

protected:
	virtual void onActivate() = 0;
	virtual void onDeactivate() = 0;

private:
	bool activated = false;
	AbstractController* parent = nullptr;
};

#endif /* CONTROLLER_ABSTRACTCONTROLLER_H_ */
