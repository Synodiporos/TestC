/*
 * CDOptionPane.h
 *
 *  Created on: 27 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDOPTIONPANE_H_
#define CD_CDOPTIONPANE_H_
#include "CDElement.h"
#include "CDOption.h"
#include <vector>
using namespace std;

class CDOptionPane : public CDElement{
public:
	CDOptionPane();
	CDOptionPane(int8_t w, int8_t h);
	CDOptionPane(uint8_t x, uint8_t y, int8_t w, int8_t h);
	virtual ~CDOptionPane();

	void setLabel(CDLabel* label);
	CDLabel* getLabel();
	uint8_t getSize();
	bool insertOption(AbstractCDOption* option);
	bool insertOptionAt(uint8_t index, AbstractCDOption* option);
	bool removeOption(AbstractCDOption* option);
	bool removeOptionAt(uint8_t index);
	AbstractCDOption* getOptionAt(uint8_t index);
	bool setSelectedOption(AbstractCDOption* option);
	bool setSelectedOptionIndex(uint8_t index);
	AbstractCDOption* getSelectedOption();
	bool hasNextOption();
	bool hasPreviousOption();
	bool selectNextOption();
	bool selectPreviousOption();

	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();

	class Node{
	public :
		Node(AbstractCDOption* value);
		virtual ~Node();
		AbstractCDOption* getValue();
		void setNext(Node* next);
		void setPrev(Node* prev);
		Node* getNext();
		Node* getPrev();
		bool hasNext();
		bool hasPrev();
		bool isEmpty();
	private:
		AbstractCDOption* value;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

private:
	uint8_t size = 0;
	Node* selected = nullptr;
	Node* tail = nullptr;
	CDLabel* label = nullptr;

	Node* getOptionNodeAt(uint8_t index);
	Node* getOptionNode(AbstractCDOption* option);
	bool removeOptionNode(Node* node);
	bool setSelectedOptionNode(Node* node);

protected:
	virtual void printComponentsArea(LCD* lcd, Rectangle* area);
	virtual void printChildsArea(LCD* lcd, Rectangle* area);
	virtual void printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area);
	virtual void validateChilds();

};

#endif /* CD_CDOPTIONPANE_H_ */
