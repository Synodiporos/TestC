/*
 * CDKeyboard.h
 *
 *  Created on: 10 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDKEYBOARD_H_
#define CD_CDKEYBOARD_H_
#include "CDOptionPane.h"
#include "CDOptionChar.h"
#include "../System/Timer.h"
#include "../Commons/IActionListener.h"
#include "../Commons/Action.h"
#include "CDConstants.h"

#define LOWER_CASE_LETTERS (char*)"abcdefghijklmnopqrstuvwxyz "
#define UPPER_CASE_LETTERS (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ "
#define TEXT_SYMBOLS (char*) ",.:;!?-' _"
#define NUMBERS (char*)"1234567890"
#define SYMBOLS (char*)"!@#$%^&*()-+=/\\"

class CDKeyboard : public CDOptionPane, IActionListener{
public:
	CDKeyboard(uint8_t width);
	virtual ~CDKeyboard();
	void init();
	void appendCharSet(char* set);
	virtual void validate();
	void actionPerformed(Action action);

private:
	Timer* timer = new Timer(CDKeyboard_SELECTION_INTERVAL, 0);

};

#endif /* CD_CDKEYBOARD_H_ */
