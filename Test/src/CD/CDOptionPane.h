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
#include "CDPage.h"
#include "../Commons/IActionListener.h"
#include <vector>
using namespace std;
#include "../Geometry/GeometryUtil.h"
#include "../Display/SystemDisplayManager.h"

class CDOptionPane : public CDPage{
public:

	static const unsigned short int SELECTION_CHANGE = 1;
	static const unsigned short int SELECTION_CONFIRM = 2;

	static const uint8_t SCROLL_MODE_NONE = 1;
	static const uint8_t SCROLL_MODE_PAGE = 2;
	static const uint8_t SCROLL_MODE_ITEM = 3;

	CDOptionPane();
	CDOptionPane(int8_t w, int8_t h);
	CDOptionPane(uint8_t x, uint8_t y, int8_t w, int8_t h);
	virtual ~CDOptionPane();

	void setLabel(CDLabel* label);
	CDLabel* getLabel();
	uint8_t getSize();
	void setViewPort(Dimension* viewPort);
	void setViewPort(uint8_t width, uint8_t height);
	Dimension* getViewPort();
	void setScrollMode(uint8_t mode);
	uint8_t getScrollMode();

	bool insertOption(AbstractCDOption* option);
	bool insertOptionAt(uint8_t index, AbstractCDOption* option);
	bool removeOption(AbstractCDOption* option);
	bool removeOptionAt(uint8_t index);
	AbstractCDOption* getOptionAt(uint8_t index);
	AbstractCDOption* getLastOption();
	AbstractCDOption* getFirstOption();
	bool isLastOption(AbstractCDOption* option);
	bool isFirstOption(AbstractCDOption* option);
	bool setSelectedOption(AbstractCDOption* option);
	bool setSelectedOptionIndex(uint8_t index);
	AbstractCDOption* getSelectedOption();
	void setActionListener(IActionListener* listener);
	IActionListener* getActionListener();
	bool hasNextOption();
	bool hasPreviousOption();
	bool selectNextOption();
	bool selectPreviousOption();
	void confirmSelection();

	virtual void printArea(LCD* lcd, const Rectangle* area);
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

	CDOptionPane::Node* getLastOptionNode();

protected:
	uint8_t size = 0;
	Node* selected = nullptr;
	Node* tail = nullptr;
	CDLabel* label = nullptr;
	IActionListener* actionListener = nullptr;
	Dimension* viewPort = nullptr;
	uint8_t scrollMode = SCROLL_MODE_PAGE;

	Node* getOptionNodeAt(uint8_t index);
	Node* getOptionNode(AbstractCDOption* option);
	bool removeOptionNode(Node* node);
	bool setSelectedOptionNode(Node* node);
	void notifyActionPerformed(unsigned short int action);
	void onSelectionChanged(AbstractCDOption* selected);
	void performScrolling(int value, int dim);

	virtual void printComponentsArea(LCD* lcd, const Rectangle* area);
	virtual void printChildsArea(LCD* lcd, const Rectangle* area);
	virtual void printChild(
			AbstractCDElement* child, LCD* lcd, const Rectangle* area);
	virtual void validateChilds();

};

#endif /* CD_CDOPTIONPANE_H_ */
