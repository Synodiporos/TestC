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
	CDVScrollbar(uint8_t x, uint8_t height);
	virtual ~CDVScrollbar();

	void setValue(uint8_t value);
	uint8_t getValue();
	virtual void setParent(AbstractCDElement* parent);
	virtual AbstractCDElement* getParent();
	virtual Rectangle* getBounds();
	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();

private:
	AbstractCDElement* parent = nullptr;
	uint8_t x = 0;
	uint8_t height = 2;
	uint8_t value = 0;

	void recalculateValue();
};

#endif /* CD_CDVSCROLLBAR_H_ */
