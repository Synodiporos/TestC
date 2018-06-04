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
#include "LCD.h"
#include <string>
#include "../Geometry/Point.h"
#include "../Geometry/Rectangle.h"
#include "AbstractCDElement.h"

class CDElement : public AbstractCDElement{
public:
	CDElement();
	CDElement(int8_t w, int8_t h);
	CDElement(uint8_t x, uint8_t y, int8_t w, int8_t h);
	virtual ~CDElement();

	void setDimensions(uint8_t width, uint8_t height);
	Dimension getDimensions();
	//void setPreferedDimensions(uint8_t width, uint8_t height);
	//Dimension getPreferedDimensions();
	void setPosition(uint8_t x, uint8_t y);
	Point* getPosition();
	void moveBy(uint8_t x, uint8_t y);
	virtual Rectangle* getBounds();
	virtual void setBounds(Rectangle bounds);
	virtual void setBounds(uint8_t x, uint8_t y, int8_t w, int8_t h);

	virtual void setParent(AbstractCDElement* parent);
	virtual AbstractCDElement* getParent();

	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();
	virtual void revalidate();

private:
	//Dimensions in pixels
	Rectangle bounds;
	AbstractCDElement* parent = nullptr;
};

#endif /* CD_CDELEMENT_H_ */
