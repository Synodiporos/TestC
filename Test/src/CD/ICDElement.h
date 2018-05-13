/*
 * ICDElement.h
 *
 *  Created on: 12 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CD_ICDELEMENT_H_
#define CD_ICDELEMENT_H_
#include "../Geometry/Dimension.h"
#include "LCD.h"
#include <stdint.h>
#include "../Geometry/Point.h"

class ICDElement {
public:
	ICDElement();
	virtual ~ICDElement();

	virtual void setDimensions(uint8_t width, uint8_t height) = 0;
	virtual Dimension getDimensions();
	virtual void setPreferedDimensions(uint8_t width, uint8_t height) = 0;
	virtual Dimension getPreferedDimensions() = 0;
	virtual void setPosition(uint8_t x, uint8_t y) = 0;
	virtual Point getPosition() = 0;
	virtual void moveBy(uint8_t x, uint8_t y) = 0;

	virtual void print(LCD* lcd) = 0;
	virtual void validate() = 0;

};

#endif /* CD_ICDELEMENT_H_ */
