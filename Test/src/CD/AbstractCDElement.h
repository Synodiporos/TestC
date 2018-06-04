/*
 * AbstractCDElement.h
 *
 *  Created on: 12 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
 *      Author: Synodiporos
 */

#ifndef CD_ABSTRACTCDELEMENT_H_
#define CD_ABSTRACTCDELEMENT_H_
#include "../Geometry/Dimension.h"
//class LCD;
//class AbstractCDElement;
#include "LCD.h"
#include <stdint.h>
#include "../Geometry/Point.h"

class AbstractCDElement {
public:
	AbstractCDElement();
	virtual ~AbstractCDElement();
	virtual bool isVisible();
	virtual bool setVisible(bool visible);
	virtual void setParent(AbstractCDElement* parent) = 0;
	virtual AbstractCDElement* getParent() = 0;
	virtual bool hasParent();
	virtual Rectangle* getBounds() = 0;
	virtual void print(LCD* lcd);
	virtual void reprint();
	virtual void printArea(LCD* lcd, Rectangle* area) = 0;
	virtual void printArea(Rectangle* area);
	virtual void validate() = 0;

protected:
	bool visible = true;
};

#endif /* CD_ABSTRACTCDELEMENT_H_ */
