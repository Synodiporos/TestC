/*
 * CDFrame.h
 *
 *  Created on: May 21, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDFRAME_H_
#define CD_CDFRAME_H_
//class AbstractCDElement;
#include "AbstractCDElement.h"

class CDFrame : public AbstractCDElement{
public:
	static const uint8_t SRCOLLBAR_STATE_NEVER = 0;
	static const uint8_t SRCOLLBAR_STATE_AUTO = 1;
	static const uint8_t SRCOLLBAR_STATE_ALWAYS = 2;

	CDFrame(uint8_t width, uint8_t height, uint8_t capacity);
	CDFrame(short int x, short int y,
			uint8_t width, uint8_t height, uint8_t capacity);
	virtual ~CDFrame();

	void setPage(AbstractCDElement* elem, uint8_t index);
	AbstractCDElement* getPage(uint8_t index);
	void removePage(uint8_t index);
	void setCurrentPageIndex(uint8_t index);
	AbstractCDElement* getCurrentPage();

	void setParent(AbstractCDElement* parent);
	AbstractCDElement* getParent();
	Rectangle* getBounds();
	void setPosition(short int x, short int y);
	bool isScrollbarVisible();
	void setScrollbarState(uint8_t state);
	uint8_t getScrollbarState();
	void print();
	void print(LCD* lcd);
	void reprint();
	void printArea(LCD* lcd, Rectangle* area);
	void printArea(Rectangle* area);
	void validate();
	void revalidate();

private:
	AbstractCDElement* parent = nullptr;
	LCD lcd ;
	AbstractCDElement** elements = nullptr;
	uint8_t currentIndex = -1;
	uint8_t capacity = 0;
	uint8_t scrollbarState = SRCOLLBAR_STATE_AUTO;
	uint8_t scrollbarValue = -1;

	void init();
	void updateScrollBarValue();
	void reprintScrollbar(uint8_t value, uint8_t pixels);
};

#endif /* CD_CDFRAME_H_ */
