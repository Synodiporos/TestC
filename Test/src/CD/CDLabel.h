/*
 * CDLabel.h
 *
 *  Created on: 18 Ξ�οΏ½ΞΏΞ�Β½Ξ�οΏ½Ξ’Β±Ξ�οΏ½ΞΏΞ�Β½ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDLABEL_H_
#define CD_CDLABEL_H_
#include "CDConstants.h"
#include <stdint.h>

#include "AbstractCDElement.h"
//#include "../Geometry/Rectangle.h"

class CDLabel : public AbstractCDElement{
public:
	static const uint8_t ROLLING_BEGIN = 1;
	static const uint8_t ROLLING_ROLL = 2;
	static const uint8_t ROLLING_END = 3;
	static const uint8_t ROLLING_STOP = 0;

	CDLabel(uint8_t width, const char* label);
	CDLabel(int8_t x, int8_t y, uint8_t width, const char* label);
	virtual ~CDLabel();
	void setLabel(const char* label);
	const char* getLabel();
	void startRolling();
	void startRollingImmediately();
	void stopRolling();
	void setRollingState(uint8_t state);
	uint8_t getRollingState();
	bool isRolling();
	void setLabelIndex(uint8_t index);
	uint8_t getLabelIndex();
	bool setWidth(uint8_t width);
	const uint8_t getWidth() const;
	bool setPosition(int8_t x, int8_t y);
	const Rectangle getBounds() const;
	void setParent(AbstractCDElement* parent);
	AbstractCDElement* getParent();

	//virtual void reprint();
	virtual void printArea(LCD* lcd, const Rectangle* area);
	virtual void validate();

private:
	AbstractCDElement* parent = nullptr;
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	uint8_t lenght = 0;
	int8_t strIndex = 0;
	const char* label = '\0';
	uint8_t rollState = ROLLING_STOP;
	long millis = 0;

	void recreateStr();
};

#endif /* CD_CDLABEL_H_ */
