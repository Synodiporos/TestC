/*
 * CDKeyboard.h
 *
 *  Created on: 10 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDKEYBOARD_H_
#define CD_CDKEYBOARD_H_
#include "CDOptionPane.h"
#include "CDCharOption.h"
#include "../System/Timer.h"
#include "../Commons/IActionListener.h"
#include "../Commons/Action.h"
#include "CDConstants.h"

#define CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ,.:;'!?-_";
#define NUMBERS "1234567890 !@#$%^&*()-+=/\\"

class CDKeyboard : public CDOptionPane, IActionListener{
public:
	CDKeyboard(uint8_t width);
	virtual ~CDKeyboard();
	void init();
	virtual void validate();
	void actionPerformed(Action action);

private:
	Timer* timer = new Timer(CDKeyboard_SELECTION_INTERVAL, 0);

};

#endif /* CD_CDKEYBOARD_H_ */
