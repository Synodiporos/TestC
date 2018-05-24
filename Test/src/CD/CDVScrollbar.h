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
	virtual ~CDVScrollbar();

	virtual AbstractCDElement* getParent();
	virtual Rectangle* getBounds();
	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();

private:
	AbstractCDElement* parent = nullptr;
	uint8_t x = 0;
	uint8_t height = 2;
	double scrollPos = 0.0;
};

#endif /* CD_CDVSCROLLBAR_H_ */
