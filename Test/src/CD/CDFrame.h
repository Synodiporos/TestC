/*
 * CDFrame.h
 *
 *  Created on: May 21, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDFRAME_H_
#define CD_CDFRAME_H_
#include "ICDElement.h"

class CDFrame : public ICDElement{
public:

	CDFrame(uint8_t width, uint8_t height);
	CDFrame(uint8_t width, uint8_t height, uint8_t capacity);
	virtual ~CDFrame();

	void setPage(ICDElement* elem, uint8_t index);
	ICDElement* getPage(uint8_t index);
	void removePage(uint8_t index);
	void setCurrentPageIndex(uint8_t index);
	ICDElement* getCurrentPage();

	Rectangle* getBounds();
	void setParent(ICDElement* parent);
	ICDElement* getParent();

	void print();
	void print(LCD* lcd);
	void reprint();
	void printArea(LCD* lcd, Rectangle* area);
	void printArea(Rectangle* area);
	void validate();

private:
	LCD lcd = LCD();
	Rectangle* bounds  = new Rectangle();
	ICDElement** elements = nullptr;
	uint8_t currentIndex = -1;
	uint8_t capacity = 0;

	void init();

};

#endif /* CD_CDFRAME_H_ */
