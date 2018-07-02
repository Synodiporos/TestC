/*
 * CDCharOption.h
 *
 *  Created on: 10 Ιουν 2018
 *      Author: Synodiporos
 */
#include <stdint.h>

#ifndef CD_CDCHAROPTION_H_
#define CD_CDCHAROPTION_H_
#include "AbstractCDOption.h"
#include "CDConstants.h"

class CDOptionChar : public AbstractCDOption{
public:

	CDOptionChar(char c);
	CDOptionChar(int8_t x, int8_t y, char c);
	virtual ~CDOptionChar();

	virtual void init();

	bool setCharacter(char c);
	char getCharacter();

	bool setStateVisible(bool visible);
	bool isStateVisible();
	bool toogleStateDiplay();

	virtual void printArea(LCD* lcd, const Rectangle* area); // Implements
	virtual void validate(); // Implements

protected:
	virtual void onOptionStateChanged(); // Implements

private:
	char character;
	bool stateVisible = true;
};

#endif /* CD_CDCHAROPTION_H_ */
