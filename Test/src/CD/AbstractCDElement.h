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
#include "../Commons/IPropertyListener.h"

class AbstractCDElement {
public:
	static const unsigned short int POSITION_PROPERTY = 111;
	static const unsigned short int DIMENSIONS_PROPERTY = 112;

	AbstractCDElement();
	virtual ~AbstractCDElement();
	virtual bool isVisible();
	virtual bool setVisible(bool visible);
	virtual void setParent(AbstractCDElement* parent) = 0;
	virtual AbstractCDElement* getParent() = 0;
	virtual bool hasParent();
	virtual const Rectangle getBounds() const = 0;
	virtual const uint8_t getWidth() const;
	virtual const uint8_t getHeight() const;
	virtual void print(LCD* lcd);
	virtual void reprint();
	virtual void printArea(LCD* lcd, const Rectangle* area) = 0;
	//Traverses to parent and prints the area.
	virtual void printArea(const Rectangle* area);
	virtual void validate() = 0;

	virtual void setPropertyListener(IPropertyListener* listener);
	virtual IPropertyListener* getPropertyListener();
	virtual void notifyPropertyChanged(
			unsigned short int propertyId, const void* property);

protected:
	bool visible = true;
	IPropertyListener* propertyListener = nullptr;
};

#endif /* CD_ABSTRACTCDELEMENT_H_ */
