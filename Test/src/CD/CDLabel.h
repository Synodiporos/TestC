/*
 * CDLabel.h
 *
 *  Created on: 18 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDLABEL_H_
#define CD_CDLABEL_H_
#include "ICDElement.h"
#include "../Geometry/Rectangle.h"

class CDLabel : public ICDElement{
public:
	CDLabel();
	CDLabel(uint8_t width, char* label);
	CDLabel(int8_t x, int8_t y, uint8_t width, char* label);
	virtual ~CDLabel();
	void setLabel(char* label);
	char* getLabel();
	void setWidth(uint8_t width);
	uint8_t getWidth();
	void setLocation(int8_t x, int8_t y);
	Point* getLocation();
	virtual Rectangle* getBounds();
	virtual void print(LCD* lcd);
	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();

private:
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	char* label;
};

#endif /* CD_CDLABEL_H_ */
