/*
 * CDTextArea.h
 *
 *  Created on: Jun 12, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDTEXTAREA_H_
#define CD_CDTEXTAREA_H_
#include "CDOptionPane.h"
#include "CDCharOption.h"

class CDTextArea : public CDOptionPane{
public:
	CDTextArea();
	CDTextArea(int8_t w, unsigned int capacity);
	CDTextArea(uint8_t x, uint8_t y, int8_t w, unsigned int capacity);
	virtual ~CDTextArea();
	void init();
	void setCapacity(unsigned int capacity);
	unsigned int getCapacity();
	void setLabelIndex(uint8_t index);
	uint8_t getLabelIndex();
	bool canAppendArea();
	bool appendArea();
	bool setCharAndAppend(char ch);
	bool erase();


private:
	unsigned int capacity = 0;
	int8_t strIndex = 0;

};

#endif /* CD_CDTEXTAREA_H_ */
