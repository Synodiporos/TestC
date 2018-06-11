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

class CDCharOption : public AbstractCDOption{
public:

	CDCharOption(char c);
	CDCharOption(int8_t x, int8_t y, char c);
	virtual ~CDCharOption();

	virtual void init();

	void setCharacter(char c);
	char getCharacter();

	bool setStateVisible(bool visible);
	bool isStateVisible();
	bool toogleStateDiplay();

	virtual void printArea(LCD* lcd, Rectangle* area); // Implements
	virtual void validate(); // Implements

protected:
	virtual void onOptionStateChanged(); // Implements

private:
	char character;
	bool stateVisible = true;
};

#endif /* CD_CDCHAROPTION_H_ */
