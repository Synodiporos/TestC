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
#include "CDCharOption.h"
#include "../Commons/IActionListener.h"
#include <string>

class CDTextArea : public AbstractCDElement, IActionListener{
public:

	CDTextArea();
	CDTextArea(int8_t w, unsigned int capacity);
	CDTextArea(uint8_t x, uint8_t y, int8_t w, unsigned int capacity);
	virtual ~CDTextArea();
	void init();
	void setCapacity(unsigned int capacity);
	unsigned int getCapacity();
	uint8_t getSize();
	CDCharOption* getSelected();
	bool setSelectedIndex(uint8_t index);
	bool setSelected(CDCharOption* option);
	bool selectNext();
	bool selectPrevious();
	CDOptionPane* getOptionPane();
	bool canAppendArea();
	bool appendArea();
	bool setCharAndAppend(char ch);
	bool eraseLastChar();
	std::string getText();

	virtual void setParent(AbstractCDElement* parent); //Implements
	virtual AbstractCDElement* getParent(); //Implements
	virtual Rectangle* getBounds(); //Implements
	virtual void printArea(LCD* lcd, Rectangle* area); //Implements
	virtual void validate(); //Implements

	void actionPerformed(Action action);

private:
	Rectangle* bounds = new Rectangle(0, 0, 1, 1);
	AbstractCDElement* parent = nullptr;
	CDOptionPane* optionPane = nullptr;
	unsigned int capacity = 0;
	//bool autoRollEnabled = true;

	virtual void printChildsArea(LCD* lcd, Rectangle* area);
	virtual void printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area);
	void validateCelectionChange();
};

#endif /* CD_CDTEXTAREA_H_ */
