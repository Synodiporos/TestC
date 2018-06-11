/*
 * CDOption.h
 *
 *  Created on: May 23, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDOPTION_H_
#define CD_CDOPTION_H_
#include "AbstractCDOption.h"
#include "CDLabel.h"
#include "../Commons/IStateListener.h"
#include <stdint.h>

class CDOption : public AbstractCDOption{
public:
	static const uint8_t AutoRolling_Never = 10;
	static const uint8_t AutoRolling_OnHover = 11;
	static const uint8_t AutoRolling_OnClick = 12;
	static const uint8_t AutoRolling_state = AutoRolling_OnClick;

	CDOption(uint8_t width, char* label);
	CDOption(int8_t x, int8_t y, uint8_t width, char* label);
	CDOption(int8_t x, int8_t y, uint8_t width, char* label, unsigned int actionId);
	virtual ~CDOption();

	CDLabel* getLabel();
	virtual void printIndicator(LCD* lcd);
	virtual void reprintIndicator();
	virtual void reprintLabel();
	virtual void printArea(LCD* lcd, Rectangle* area); // Implement
	virtual void validate(); // Implement

protected:
	AbstractCDElement* parent = nullptr;
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	IStateListener* stateListener = nullptr;
	CDLabel label;
	unsigned int actionId = 0;

	virtual void init();
	virtual void onOptionStateChanged(); // Implement
	virtual void printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area);
};

#endif /* CD_CDOPTION_H_ */
