/*
 * CDOptionIndicator.h
 *
 *  Created on: May 23, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDOPTIONINDICATOR_H_
#define CD_CDOPTIONINDICATOR_H_
#include "ICDElement.h"

class CDOptionIndicator : public ICDElement{
public:
	static const uint8_t UNHOVERED = 0;
	static const uint8_t HOVERED = 1;
	static const uint8_t CLICKED = 2;

	CDOptionIndicator();
	virtual ~CDOptionIndicator();
	void setState(uint8_t state);
	uint8_t getState();

	virtual void setParent(ICDElement* parent);
	virtual ICDElement* getParent();
	virtual Rectangle* getBounds();
	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();

private:
	uint8_t state = UNHOVERED;
	ICDElement* parent = nullptr;

};

#endif /* CD_CDOPTIONINDICATOR_H_ */
