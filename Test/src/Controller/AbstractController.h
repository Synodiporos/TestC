/*
 * Controller.h
 *
 *  Created on: 27 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_ABSTRACTCONTROLLER_H_
#define CONTROLLER_ABSTRACTCONTROLLER_H_

class AbstractCompController;

#include "KeyboardListener.h"
//#include "AbstractCompController.h"

class AbstractController : public KeyboardListener{

public:
	AbstractController();
	virtual ~AbstractController();

	virtual void activate();
	virtual void deactivate();
	virtual bool setActivated(bool activated);
	virtual bool isActivated();
	virtual bool setParent(AbstractCompController* parent);
	virtual AbstractCompController* getParent();
	virtual AbstractCompController* getRootParent();

protected:
	virtual void onActivate() = 0;
	virtual void onDeactivate() = 0;
	virtual void onActiveControllerChanged() = 0;

private:
	bool activated = false;
	AbstractCompController* parent = nullptr;

};

#endif /* CONTROLLER_ABSTRACTCONTROLLER_H_ */

