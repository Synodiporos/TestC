/*
 * CDLabel.h
 *
 *  Created on: 18 Ξ�οΏ½ΞΏΞ�Β½Ξ�οΏ½Ξ’Β±Ξ�οΏ½ΞΏΞ�Β½ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDLABEL_H_
#define CD_CDLABEL_H_
#include "ICDElement.h"
#include "CDConstants.h"
#include <stdint.h>
//#include "../Geometry/Rectangle.h"

class CDLabel : public ICDElement{
public:
	static const uint8_t ROLLING_BEGIN = 1;
	static const uint8_t ROLLING_ROLL = 2;
	static const uint8_t ROLLING_END = 3;
	static const uint8_t ROLLING_STOP = 0;

	CDLabel(uint8_t width, char* label);
	CDLabel(int8_t x, int8_t y, uint8_t width, char* label);
	virtual ~CDLabel();
	void setLabel(char* label);
	char* getLabel();
	void startRolling();
	void startRollingImmediately();
	void stopRolling();
	void setRollingState(uint8_t state);
	uint8_t getRollingState();
	bool isRolling();
	void setLabelIndex(uint8_t index);
	uint8_t getLabelIndex();
	void setWidth(uint8_t width);
	uint8_t getWidth();
	void setLocation(int8_t x, int8_t y);
	Point* getLocation();
	Rectangle* getBounds();
	void setParent(ICDElement* parent);
	ICDElement* getParent();

	virtual void reprint();
	virtual void printArea(LCD* lcd, Rectangle* area);
	virtual void validate();

private:
	ICDElement* parent = nullptr;
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	uint8_t lenght = 0;
	int8_t strIndex = 0;
	char* label = '\0';
	uint8_t rollState = ROLLING_STOP;
	long millis = 0;

	void recreateStr();
};

#endif /* CD_CDLABEL_H_ */
