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
	: CDElement(){

}

CDOptionPane::CDOptionPane(int8_t w, int8_t h)
	: CDElement(0, 0, w, h){

}

CDOptionPane::CDOptionPane(uint8_t x, uint8_t y, int8_t w, int8_t h)
	: CDElement(x, y, w, h){

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
		if(selected==node)
			setSelectedOption(nullptr);
		Node* np = node->getPrev();
		Node* nn = node->getNext();

		if(tail==node){
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
		setSelectedOptionNode(nullptr);
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
		if(selected)
			selected->getValue()->unhover();
		if(node)
			node->getValue()->hover();
		this->selected = node;

		notifyActionPerformed(SELECTION_CHANGED);
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
	notifyActionPerformed(SELECTION_CONFIRM);
}

void CDOptionPane::closePane(){
	notifyActionPerformed(PANE_CLOSE);
}

void CDOptionPane::printArea(LCD* lcd, Rectangle* area){
	printComponentsArea(lcd, area);
	printChildsArea(lcd, area);
}

void CDOptionPane::printComponentsArea(LCD* lcd, Rectangle* area){
	if(label && label->isVisible())
		label->printArea(lcd, area);
}

void CDOptionPane::printChildsArea(LCD* lcd, Rectangle* area){
	cout << " childs[ " << endl;
	int ccx = lcd->getCursorX();
	int ccy = lcd->getCursorY();

	Node* n = tail;
	while(n->hasPrev()){
		printChild(n->getValue(), lcd, area);
		lcd->setCursor(ccx, ccy);
		n = n->getPrev();
	}
	printChild(n->getValue(), lcd, area);
	lcd->setCursor(ccx, ccy);

	cout << "]" << endl;
}

void CDOptionPane::printChild(AbstractCDElement* child, LCD* lcd, Rectangle* area){
	if(child && child->isVisible()){
		Rectangle r = area->intersection(
				child->getBounds());
		if(!r.isNull()){
			int cx =  0 + child->getBounds()->getX();
			int cy =  0 + child->getBounds()->getY();
			lcd->setCursorBy(cx, cy);
			r.setPointBy(-child->getBounds()->getX(),
					-child->getBounds()->getY());
			child->printArea(lcd, &r);
		}
	}
}

void CDOptionPane::validate(){

}

void CDOptionPane::validateChilds(){

}

void CDOptionPane::notifyActionPerformed(unsigned short int action){
	if(getActionListener()){
		Action action = Action(this, action, 0, getSelectedOption());
		getActionListener()->actionPerformed(action);
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
