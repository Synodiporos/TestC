/*
 * KeyboardListener.h
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_KEYBOARDLISTENER_H_
#define CONTROLLER_KEYBOARDLISTENER_H_

class KeyboardListener {
public:
	KeyboardListener();
	virtual ~KeyboardListener();

	virtual void onForwardPressed() = 0;
	virtual void onForwardReleased() = 0;
	virtual void onForwardHolded() = 0;
	virtual void onForwardClicked() = 0;
	virtual void onBackwardPressed() = 0;
	virtual void onBackwardReleased() = 0;
	virtual void onBackwardHolded() = 0;
	virtual void onBackwardClicked() = 0;
	virtual void onEnterPressed() = 0;
	virtual void onEnterReleased() = 0;
	virtual void onEnterHolded() = 0;
	virtual void onEnterClicked() = 0;
	virtual void onBackPressed() = 0;
	virtual void onBackReleased() = 0;
	virtual void onBackHolded() = 0;
	virtual void onBackClicked() = 0;
};

#endif /* CONTROLLER_KEYBOARDLISTENER_H_ */
