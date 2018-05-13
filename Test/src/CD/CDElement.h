/*
 * CDElement.h
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDELEMENT_H_
#define CD_CDELEMENT_H_
//#include <string>
#include "../Geometry/Dimension.h"
#include "ICDElement.h"
#include "LCD.h"
#include <string>
#include "../Geometry/Point.h"

class CDElement : public ICDElement{
public:
	CDElement();
	CDElement(std::string label);
	virtual ~CDElement();

	void setDimensions(uint8_t width, uint8_t height);
	Dimension getDimensions();
	void setPreferedDimensions(uint8_t width, uint8_t height);
	Dimension getPreferedDimensions();
	void setPosition(uint8_t x, uint8_t y);
	Point getPosition();
	void moveBy(uint8_t x, uint8_t y);

	virtual void print(LCD* lcd);
	virtual void validate();

private:
	Point position = Point();
	//Dimensions in pixels
	Dimension dimensions = Dimension();
	Dimension pDimensions = Dimension();
};

#endif /* CD_CDELEMENT_H_ */
