/*
 * CDVScrollbar.h
 *
 *  Created on: May 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDVSCROLLBAR_H_
#define CD_CDVSCROLLBAR_H_

#include "AbstractCDElement.h"
#include "CDCharacters.h"

class CDVScrollbar: public AbstractCDElement {
public:
	CDVScrollbar();
	CDVScrollbar(uint8_t x, uint8_t height);
	virtual ~CDVScrollbar();

	void setValue(uint8_t value);
	uint8_t getValue();
	virtual void setParent(AbstractCDElement* parent);
	virtual AbstractCDElement* getParent();
	virtual const Rectangle getBounds() const;
	void setX(int8_t x);
	int8_t getX() const;
	void setHeight(uint8_t height) const;
	const uint8_t getHeight() const;
	virtual void printArea(LCD* lcd, const Rectangle* area);
	virtual void validate();

	static uint8_t scrollbarValue(AbstractCDElement* page,
			AbstractCDElement* frame);

private:
	AbstractCDElement* parent = nullptr;
	int8_t x = 0;
	mutable uint8_t height = 2;
	uint8_t value = 0;
	char* chars = nullptr;

	uint8_t calculateLevelValue();
	void printChar(LCD* lcd, uint8_t index, uint8_t value);
};

#endif /* CD_CDVSCROLLBAR_H_ */
