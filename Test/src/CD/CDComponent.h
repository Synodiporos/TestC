/*
 * CDComponent.h
 *
 *  Created on: 12 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDCOMPONENT_H_
#define CD_CDCOMPONENT_H_
#include "CDElement.h"
#include "ICDElement.h"

class CDComponent : public CDElement{
public:
	CDComponent();
	CDComponent(uint8_t capacity);
	CDComponent(uint8_t x, uint8_t y, int8_t w, int8_t h);
	CDComponent(uint8_t x, uint8_t y,
			int8_t w, int8_t h, uint8_t capacity);
	virtual ~CDComponent();

	uint8_t getSize();
	uint8_t getCapacity();
	void addElement(ICDElement* element);
	void setElementAt(ICDElement* elem, uint8_t index);
	ICDElement* getElementAt(uint8_t index);
	ICDElement* getElementAt(uint8_t x, uint8_t y);
	ICDElement** getElements();
	void removeElement(ICDElement* element);
	void removeElementAt(uint8_t index);

	virtual void print(LCD* lcd);
	virtual void printArea(LCD* lcd, Rectangle area);
	virtual void validate();

private:
	uint8_t size = 0;
	uint8_t capacity = 0;
	ICDElement** elements = nullptr;

	void printChilds(LCD* lcd);
	void validateChilds();
};

#endif /* CD_CDCOMPONENT_H_ */
