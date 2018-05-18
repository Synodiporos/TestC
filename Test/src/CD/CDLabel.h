/*
 * CDLabel.h
 *
 *  Created on: 18 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDLABEL_H_
#define CD_CDLABEL_H_
#include "ICDElement.h"
//#include "../Geometry/Rectangle.h"

class CDLabel {
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
	Rectangle* getBounds();
	void print(LCD* lcd);
	void printArea(LCD* lcd, Rectangle* area);
	void validate();

private:
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	char* label = nullptr;
};

#endif /* CD_CDLABEL_H_ */
