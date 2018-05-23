/*
 * ICDElement.h
 *
 *  Created on: 12 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
 *      Author: Synodiporos
 */

#ifndef CD_ICDELEMENT_H_
#define CD_ICDELEMENT_H_
#include "../Geometry/Dimension.h"
//class LCD;
//class ICDElement;
#include "LCD.h"
#include <stdint.h>
#include "../Geometry/Point.h"

class ICDElement {
public:
	ICDElement();
	virtual ~ICDElement();
	virtual void setParent(ICDElement* parent) = 0;
	virtual ICDElement* getParent() = 0;
	virtual bool hasParent();
	virtual Rectangle* getBounds() = 0;
	virtual void print(LCD* lcd);
	virtual void reprint();
	virtual void printArea(LCD* lcd, Rectangle* area) = 0;
	virtual void printArea(Rectangle* area);
	virtual void validate() = 0;
};

#endif /* CD_ICDELEMENT_H_ */
