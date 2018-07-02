/*
 * CDOptionPane.cpp
 *
 *  Created on: 27 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#include <iostream>
using namespace std;
#include "CDOptionPane.h"

CDOptionPane::CDOptionPane()
	: CDPage(){

}

CDOptionPane::CDOptionPane(int8_t w, int8_t h)
	: CDPage(w, h){

}

CDOptionPane::CDOptionPane(uint8_t x, uint8_t y, int8_t w, int8_t h)
	: CDPage(x, y, w, h){

}

CDOptionPane::~CDOptionPane() {
	// TODO Auto-generated destructor stub
}

void CDOptionPane::setLabel(CDLabel* label){
	this->label = label;
}

CDLabel* CDOptionPane::getLabel(){
	return this->label;
}

uint8_t CDOptionPane::getSize(){
	return this->size;
}

void CDOptionPane::setViewPort(Dimension* viewPort){
	this->viewPort = viewPort;
}

void CDOptionPane::setViewPort(uint8_t width, uint8_t height){
	this->viewPort = new Dimension(width, height);
}

Dimension* CDOptionPane::getViewPort(){
	return this->viewPort;
}

void CDOptionPane::setScrollMode(uint8_t mode){
	this->scrollMode = mode;
}

uint8_t CDOptionPane::getScrollMode(){
	return this->scrollMode;
}

bool CDOptionPane::insertOption(AbstractCDOption* option){
	return insertOptionAt(size, option);
}

bool CDOptionPane::insertOptionAt(uint8_t index, AbstractCDOption* option){
	if(option==nullptr)
		return false;

	if(index>size)
		return false;
	else {
		Node* opt = new Node(option);
		if(index==size){
			if(tail!=nullptr){
				tail->setNext(opt);
			}
			opt->setPrev(tail);
			opt->setNext(nullptr);
			tail = opt;
		}
		else{
			Node* cur = getOptionNodeAt(index);
			Node* curn = cur->getPrev();
			opt->setNext(cur);
			cur->setPrev(opt);
			opt->setPrev(curn);
			if(curn)
				curn->setNext(opt);
		}
		size++;
		if(selected==nullptr)
			setSelectedOptionNode(opt);
		option->setParent(this);
		return true;
	}
}

bool CDOptionPane::removeOptionNode(Node* node){
	if(node){

		Node* np = node->getPrev();
		Node* nn = node->getNext();
		if(tail==node){
			if(np)
				np->setNext(nullptr);
			tail = np;
		}
		else if(np==nullptr){
			nn->setPrev(nullptr);
		}
		else{
			nn->setPrev(np);
			np->setNext(nn);
		}
		size--;
		node->getValue()->setParent(nullptr);

		if(selected==node )
			if(size>0)
				//setSelectedOption(nullptr);
				setSelectedOptionIndex(getSize()-1);
			else
				setSelectedOption(nullptr);

		return true;
	}
	return false;
}

bool CDOptionPane::removeOption(AbstractCDOption* option){
	Node* n = getOptionNode(option);
	return removeOptionNode(n);
}

bool CDOptionPane::removeOptionAt(uint8_t index){
	return removeOptionNode(getOptionNodeAt(index));
}

AbstractCDOption* CDOptionPane::getOptionAt(uint8_t index){
	return getOptionNodeAt(index)->getValue();
}

AbstractCDOption* CDOptionPane::getLastOption(){
	Node* n = getOptionNodeAt(getSize()-1);
	if(n)
		return n->getValue();
	return nullptr;
}

CDOptionPane::Node* CDOptionPane::getLastOptionNode(){
	return getOptionNodeAt(getSize()-1);
}

AbstractCDOption* CDOptionPane::getFirstOption(){
	Node* n = getOptionNodeAt(0);
	if(n)
		return n->getValue();
	return nullptr;
}

bool CDOptionPane::isLastOption(AbstractCDOption* option){
	return option==getLastOption();
}

bool CDOptionPane::isFirstOption(AbstractCDOption* option){
	return option==getFirstOption();
}

CDOptionPane::Node* CDOptionPane::getOptionNodeAt(uint8_t index){
	if(index>=size)
		return nullptr;
	Node* cur = tail;
	for(int i=size-1; i>(index); i--)
		cur = cur->getPrev();
	return cur;
}

CDOptionPane::Node* CDOptionPane::getOptionNode(AbstractCDOption* option){
	if(option==nullptr)
		return nullptr;
	Node* cur = tail;
	while(cur->hasPrev()){
		if(cur->getValue()==option)
			return cur;
		cur = cur->getPrev();
	}
	if(cur->getValue()==option)
		return cur;
	return nullptr;
}

bool CDOptionPane::setSelectedOption(AbstractCDOption* option){
	if(size==0)
		return false;
	if(option==nullptr)
		return setSelectedOptionNode(nullptr);
	if(tail->getValue()==option)
		return setSelectedOptionNode(tail);

	Node* n = tail;
	while(n->hasPrev()){
		if(n->getValue()==option)
			return setSelectedOptionNode(n);
		n = n->getPrev();
	}
	if(n->getValue()==option)
		return setSelectedOptionNode(n);
	return false;
}

bool CDOptionPane::setSelectedOptionIndex(uint8_t index){
	if(size<=0)
		return false;
	if(index>=size)
		return false;

	Node* n = tail;
	int c = size - index - 1;
	while(n->hasPrev()){
		if(c--==0)
			return setSelectedOptionNode(n);
		n = n->getPrev();
	}
	if(c==0)
		return setSelectedOptionNode(n);
	return false;
}

bool CDOptionPane::setSelectedOptionNode(Node* node){
	if(selected!=node){
		if(selected){
			selected->getValue()->unhover();
		}
		if(node){
			node->getValue()->hover();
		}
		this->selected = node;

		notifyActionPerformed(SELECTION_CHANGE);
		onSelectionChanged(selected->getValue());
		return true;
	}
	return false;
}

AbstractCDOption* CDOptionPane::getSelectedOption(){
	if(this->selected==nullptr)
		return nullptr;
	return this->selected->getValue();
}

void CDOptionPane::setActionListener(IActionListener* listener){
	this->actionListener = listener;
}

IActionListener* CDOptionPane::getActionListener(){
	return this->actionListener;
}

bool CDOptionPane::hasNextOption(){
	if(selected==nullptr)
		return false;
	return selected->hasNext();
}

bool CDOptionPane::hasPreviousOption(){
	if(selected==nullptr)
		return false;
	return selected->hasPrev();
}

bool CDOptionPane::selectNextOption(){
	if(selected!=nullptr)
		return setSelectedOptionNode(selected->getNext());
	return false;
}

bool CDOptionPane::selectPreviousOption(){
	if(selected!=nullptr)
		return setSelectedOptionNode(selected->getPrev());
	return false;
}

void CDOptionPane::confirmSelection(){
	if(getSelectedOption())
		notifyActionPerformed(SELECTION_CONFIRM);
}

void CDOptionPane::printArea(LCD* lcd, const Rectangle* area){
	printComponentsArea(lcd, area);
	printChildsArea(lcd, area);
}

void CDOptionPane::printComponentsArea(LCD* lcd, const Rectangle* area){
	if(label && label->isVisible())
		label->printArea(lcd, area);
}

void CDOptionPane::printChildsArea(LCD* lcd, const Rectangle* area){
	//cout << " childs[ " << endl;
	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	Node* n = tail;
	if(n){
		while(n->hasPrev()){
			printChild(n->getValue(), lcd, area);
			lcd->setCursor(ccx, ccy);
			n = n->getPrev();
		}
		printChild(n->getValue(), lcd, area);
		lcd->setCursor(ccx, ccy);
	}
	//cout << "]" << endl;
}

void CDOptionPane::printChild(
		AbstractCDElement* child, LCD* lcd, const Rectangle* area){
	if(child && child->isVisible()){
		Rectangle cb = child->getBounds();
		Rectangle r = area->intersection(&cb);
		if(!r.isNull()){
			int cx =  0 + child->getBounds().getX();
			int cy =  0 + child->getBounds().getY();
			lcd->setCursorBy(cx, cy);
			r.setPointBy(-child->getBounds().getX(),
					-child->getBounds().getY());
			child->printArea(lcd, &r);
		}
	}
}

void CDOptionPane::validate(){
	AbstractCDOption* selected = getSelectedOption();
	if(selected)
		selected->validate();
}

void CDOptionPane::validateChilds(){

}

void CDOptionPane::notifyActionPerformed(unsigned short int actionId){
	if(getActionListener()){
		Action action = Action(this, actionId, 0, getSelectedOption());
		getActionListener()->actionPerformed(action);
	}
}

void CDOptionPane::onSelectionChanged(AbstractCDOption* selected){
	if(getViewPort() && getScrollMode()!=SCROLL_MODE_NONE &&
			getSelectedOption()){
		Dimension* viewPort = getViewPort();
		AbstractCDOption* selected = getSelectedOption();

		int oX = selected->getLocation()->getX() + getPosition()->getX();
		int oY = selected->getLocation()->getY() + getPosition()->getY();

		int inRangeX = GeometryUtil::inRange(oX, 0, viewPort->getWidth()-1);
		int inRangeY = GeometryUtil::inRange(oY, 0, viewPort->getHeight()-1);

		/*cout << "onSelectionChanged: oX=" << oX <<
				" dimW=" << viewPort->getWidth() <<
				" inRangeX=" << inRangeX <<
				" oY=" << oY <<
				" dimH=" << viewPort->getHeight() <<
				" inRangeY=" << inRangeY <<
				endl;*/

		if(inRangeX!=0){
			performScrolling(inRangeX, 0);
		}
		if(inRangeY!=0){
			performScrolling(inRangeY, 1);
		}
	}
}

void CDOptionPane::performScrolling(int value, int dim){
	if(value!=0){
		if(value>0){
			if(dim==0){
				int x;
				if(getScrollMode()==SCROLL_MODE_PAGE){
					int vXY = getViewPort()->getWidth() + value;
					x = getPosition()->getX() - vXY + getSelectedOption()->getWidth();
				}
				else
					x = getPosition()->getX() - value + getSelectedOption()->getWidth();

				int help = -(getWidth() - getViewPort()->getWidth());
				if( x < help)
					x = help;
				setPosition(x, getPosition()->getY());
			}
			else{
				int y;
				if(getScrollMode()==SCROLL_MODE_PAGE){
					int vXY = getViewPort()->getHeight() + value;
					y = getPosition()->getY() - vXY + getSelectedOption()->getHeight();
				}
				else
					y = getPosition()->getY() - value + getSelectedOption()->getHeight();

				int help = -(getHeight() - getViewPort()->getHeight());
				if( y < help)
					y = help;
				setPosition( getPosition()->getX(), y);
			}
		}
		else{
			if(dim==0){
				int x ;
				if(getScrollMode()==SCROLL_MODE_PAGE)
					x = getPosition()->getX() - value + getViewPort()->getWidth()
								- getSelectedOption()->getWidth();
				else
					x = getPosition()->getX() - value ;
				if(x>0)
					x = 0;
				setPosition(x, getPosition()->getY());
			}
			else{
				int y;
				if(getScrollMode()==SCROLL_MODE_PAGE)
					y = getPosition()->getY() - value + getViewPort()->getHeight()
								- getSelectedOption()->getHeight();
				else
					y = getPosition()->getY() - value ;
				if(y>0)
					y = 0;
				setPosition(getPosition()->getX(), y);
			}
		}
	}
}

//==================================================================
CDOptionPane::Node::Node(AbstractCDOption* value) : value(value){

}

CDOptionPane::Node::~Node(){
	//delete value;
}

AbstractCDOption* CDOptionPane::Node::getValue(){
	return this->value;
}

void CDOptionPane::Node::setNext(Node* next){
	this->next = next;
}

void CDOptionPane::Node::setPrev(Node* prev){
	this->prev = prev;
}

CDOptionPane::Node* CDOptionPane::Node::getNext(){
	return this->next;
}

CDOptionPane::Node* CDOptionPane::Node::getPrev(){
	return this->prev;
}

bool CDOptionPane::Node::hasNext(){
	return getNext()!=nullptr;
}

bool CDOptionPane::Node::hasPrev(){
	return getPrev()!=nullptr;
}

bool CDOptionPane::Node::isEmpty(){
	return value==nullptr;
}
