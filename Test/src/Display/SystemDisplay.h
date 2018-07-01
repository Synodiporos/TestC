/*
 * SystemDisplay.h
 *
 *  Created on: 1 Ιουλ 2018
 *      Author: Synodiporos
 */

#ifndef DISPLAY_SYSTEMDISPLAY_H_
#define DISPLAY_SYSTEMDISPLAY_H_
#include "../CD/AbstractCDElement.h"

class SystemDisplay {
public:
	//SystemDisplay(){};
	virtual ~SystemDisplay(){};

	virtual bool setPage(AbstractCDElement* elem) = 0;
	virtual AbstractCDElement* getPage() = 0;
	virtual bool setPopUp(AbstractCDElement* popUp) = 0;
	virtual AbstractCDElement* getPopUp() = 0;
	virtual bool setToolTip(AbstractCDElement* toolTip) = 0;
	virtual AbstractCDElement* getToolTip() = 0;

	virtual void print() = 0;
	virtual void printArea(const Rectangle* area) = 0;
	virtual void clean() = 0;

};

#endif /* DISPLAY_SYSTEMDISPLAY_H_ */
