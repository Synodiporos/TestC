/*
 * CDTextArea.h
 *
 *  Created on: Jun 12, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDTEXTAREA_H_
#define CD_CDTEXTAREA_H_
#include "AbstractCDElement.h"
#include "CDOptionPane.h"
#include "../Commons/IActionListener.h"
#include <string>
#include "CDOptionChar.h"

class CDTextArea : public AbstractCDElement, IActionListener{
public:

	CDTextArea();
	CDTextArea(int8_t width, unsigned int capacity);
	CDTextArea(uint8_t x, uint8_t y, int8_t width, unsigned int capacity);
	virtual ~CDTextArea();
	void init();
	void setCapacity(unsigned int capacity);
	unsigned int getCapacity();
	uint8_t getSize();
	CDOptionChar* getSelected();
	bool setSelectedIndex(uint8_t index);
	bool setSelected(CDOptionChar* option);
	bool selectNext();
	bool selectPrevious();
	CDOptionPane* getOptionPane();
	bool canAppendArea();
	bool appendArea();
	bool setCharAndAppend(char ch);
	bool setChar(char ch);

	bool eraseLastChar();
	std::string getText();

	virtual void setParent(AbstractCDElement* parent); //Implements
	virtual AbstractCDElement* getParent(); //Implements
	virtual const Rectangle getBounds() const; //Implements
	virtual bool setPosition(int8_t x, uint8_t y);
	virtual bool setWidth(uint8_t width);
	virtual void printArea(LCD* lcd, const Rectangle* area); //Implements
	virtual void validate(); //Implements

	void actionPerformed(Action action);

private:
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	AbstractCDElement* parent = nullptr;
	CDOptionPane* optionPane = nullptr;
	unsigned int capacity = 0;
	//bool autoRollEnabled = true;

	virtual void printChildsArea(LCD* lcd, const Rectangle* area);
	virtual void printChild(
			AbstractCDElement* child, LCD* lcd, const Rectangle* area);
	void validateSelectionChange();
};

#endif /* CD_CDTEXTAREA_H_ */
