/*
 * CDOption.h
 *
 *  Created on: May 23, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDOPTION_H_
#define CD_CDOPTION_H_
#include "CDOptionIndicator.h"
#include "CDLabel.h"
#include "../Commons/IStateListener.h"
#include <stdint.h>

class CDOption : public AbstractCDElement{
public:
	static const uint8_t AutoRolling_Never = 10;
	static const uint8_t AutoRolling_OnHover = 11;
	static const uint8_t AutoRolling_OnClick = 12;
	static const uint8_t AutoRolling_state = AutoRolling_OnClick;

	CDOption(uint8_t width, char* label);
	CDOption(int8_t x, int8_t y, uint8_t width, char* label);
	CDOption(int8_t x, int8_t y, uint8_t width, char* label, unsigned int actionId);

	virtual ~CDOption();

	virtual void setParent(AbstractCDElement* parent);
	void setActionId(unsigned int actionId);
	unsigned int getActionId();
	virtual AbstractCDElement* getParent();
	virtual Rectangle* getBounds();
	CDLabel* getLabel();
	CDOptionIndicator* getIndicator();
	void setWidth(uint8_t width);
	uint8_t getWidth();
	void setLocation(int8_t x, int8_t y);
	Point* getLocation();

	void setOptionState(uint8_t state);
	uint8_t getOptionState();
	void hover();
	void unhover();
	void click();
	void setStateListener(IStateListener* l);
	void removeStateListener(IStateListener* l);
	IStateListener* getStateListener();

	virtual void printIndicator();
	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();

protected:
	AbstractCDElement* parent = nullptr;
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	IStateListener* stateListener = nullptr;
	CDOptionIndicator indicator = CDOptionIndicator();
	CDLabel label;
	unsigned int actionId = 0;
	void init();
	void notifyStateChanged();
	virtual void printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area);

};

#endif /* CD_CDOPTION_H_ */
