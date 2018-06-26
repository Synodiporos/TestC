/*
 * AbstractCDOption.h
 *
 *  Created on: 10 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CD_ABSTRACTCDOPTION_H_
#define CD_ABSTRACTCDOPTION_H_
#include "AbstractCDElement.h"
#include "../Commons/IStateListener.h"
#include <stdint.h>

class AbstractCDOption : public AbstractCDElement{
public:
	static const uint8_t UNHOVERED = 0;
	static const uint8_t HOVERED = 1;
	static const uint8_t CLICKED = 2;

	AbstractCDOption();
	AbstractCDOption(uint8_t width);
	AbstractCDOption(int8_t x, int8_t y, uint8_t width);
	AbstractCDOption(int8_t x, int8_t y, uint8_t width, unsigned int actionId);
	virtual ~AbstractCDOption();

	virtual void setParent(AbstractCDElement* parent);
	void setActionId(unsigned int actionId);
	unsigned int getActionId();
	virtual AbstractCDElement* getParent();
	virtual const Rectangle getBounds() const;
	void setWidth(uint8_t width);
	const uint8_t getWidth() const;
	void setLocation(int8_t x, int8_t y);
	const Point* getLocation();

	void setOptionState(uint8_t state);
	uint8_t getOptionState();
	void hover();
	void unhover();
	void click();
	void setStateListener(IStateListener* l);
	void removeStateListener(IStateListener* l);
	IStateListener* getStateListener();

	//virtual void printIndicator();
	virtual void printArea(LCD* lcd, const Rectangle* area) = 0;
	virtual void validate() = 0;

protected:
	virtual void onOptionStateChanged() = 0;

private:
	AbstractCDElement* parent = nullptr;
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	uint8_t state = UNHOVERED;
	IStateListener* stateListener = nullptr;
	unsigned int actionId = 0;
	void notifyStateChanged();
};

#endif /* CD_ABSTRACTCDOPTION_H_ */
