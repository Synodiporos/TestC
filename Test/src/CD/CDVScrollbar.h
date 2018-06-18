/*
 * CDVScrollbar.h
 *
 *  Created on: May 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDVSCROLLBAR_H_
#define CD_CDVSCROLLBAR_H_

#include "AbstractCDElement.h"

class CDVScrollbar: public AbstractCDElement {
public:
	CDVScrollbar();
	CDVScrollbar(uint8_t x, uint8_t height);
	virtual ~CDVScrollbar();

	void setValue(uint8_t value);
	uint8_t getValue();
	virtual void setParent(AbstractCDElement* parent);
	virtual AbstractCDElement* getParent();
	virtual Rectangle* getBounds();
	void setX(int8_t x);
	int8_t getX();
	void setHeight(uint8_t height);
	uint8_t getHeight();
	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();

private:
	AbstractCDElement* parent = nullptr;
	int8_t x = 0;
	uint8_t height = 2;
	uint8_t value = 0;
	char* chard = nullptr;

	void recalculateValue();
};

#endif /* CD_CDVSCROLLBAR_H_ */
