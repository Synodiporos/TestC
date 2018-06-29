/*
 * CDFrame.h
 *
 *  Created on: May 21, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDFRAME_H_
#define CD_CDFRAME_H_
#include "AbstractCDElement.h"
#include "CDVScrollbar.h"
#include "../Commons/IPropertyListener.h"

class CDFrame : public AbstractCDElement, IPropertyListener{
public:
	static const uint8_t SRCOLLBAR_STATE_NEVER = 0;
	static const uint8_t SRCOLLBAR_STATE_AUTO = 1;
	static const uint8_t SRCOLLBAR_STATE_ALWAYS = 2;

	CDFrame(uint8_t width, uint8_t height, LCD* lcd);
	CDFrame(short int x, short int y,
			uint8_t width, uint8_t height, LCD* lcd);
	virtual ~CDFrame();

	void setLCD(LCD* lcd);
	LCD* getLCD();
	bool setPage(AbstractCDElement* elem);
	AbstractCDElement* getPage();

	void setParent(AbstractCDElement* parent);
	AbstractCDElement* getParent();
	CDFrame* getRootFrame();
	const Rectangle getBounds() const;
	void setPosition(short int x, short int y);
	bool isScrollbarVisible();
	void setScrollbarState(uint8_t state);
	uint8_t getScrollbarState();
	void print();
	void print(LCD* lcd);
	void reprint();
	void printArea(LCD* lcd, const Rectangle* area);
	void printArea(const Rectangle* area);
	void clean();
	void validate();
	void revalidate();

	void propertyChanged(
			void* source, unsigned short int propertyId, const void* oldPropery);

private:
	//AbstractCDElement* parent = nullptr;
	LCD* lcd;
	AbstractCDElement* page = nullptr;
	uint8_t scrollbarState = SRCOLLBAR_STATE_AUTO;
	CDVScrollbar scrollbar = CDVScrollbar();

	void init();
	void revalidateScrollbar();
	//void updateScrollBarValue();
	//void reprintScrollbar(uint8_t value, uint8_t pixels);
	void printChild(AbstractCDElement* child, LCD* lcd, const Rectangle* area);
};

#endif /* CD_CDFRAME_H_ */
