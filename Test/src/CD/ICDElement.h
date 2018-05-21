/*
 * ICDElement.h
 *
 *  Created on: 12 Ξ�Ξ±Ξ� 2018
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

	//virtual void setDimensions(uint8_t width, uint8_t height) = 0;
	//virtual Dimension getDimensions() = 0;
	//virtual void setPreferedDimensions(uint8_t width, uint8_t height) = 0;
	//virtual Dimension getPreferedDimensions() = 0;
	//virtual void setPosition(uint8_t x, uint8_t y) = 0;
	//virtual Point getPosition() = 0;
	//virtual void moveBy(uint8_t x, uint8_t y) = 0;
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
