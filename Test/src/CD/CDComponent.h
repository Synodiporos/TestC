/*
 * CDComponent.h
 *
 *  Created on: 12 Ξ�οΏ½Ξ�Β±Ξ�οΏ½ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDCOMPONENT_H_
#define CD_CDCOMPONENT_H_
#include "AbstractCDElement.h"
#include "CDElement.h"

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
	void addElement(AbstractCDElement* element);
	void setElementAt(AbstractCDElement* elem, uint8_t index);
	AbstractCDElement* getElementAt(uint8_t index);
	AbstractCDElement* getElementAt(uint8_t x, uint8_t y);
	AbstractCDElement** getElements();
	void removeElement(AbstractCDElement* element);
	void removeElementAt(uint8_t index);

	virtual void printArea(LCD* lcd, const Rectangle* area);
	virtual void validate();

private:
	uint8_t size = 0;
	uint8_t capacity = 0;
	AbstractCDElement** elements = nullptr;

protected:
	virtual void printComponentsArea(LCD* lcd, const Rectangle* area);
	virtual void printChildsArea(LCD* lcd, const Rectangle* area);
	virtual void printChild(AbstractCDElement* child, LCD* lcd, const Rectangle* area);
	virtual void validateChilds();
};

#endif /* CD_CDCOMPONENT_H_ */
