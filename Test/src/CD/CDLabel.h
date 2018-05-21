/*
 * CDLabel.h
 *
<<<<<<< Upstream, based on origin/master
 *  Created on: 18 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDLABEL_H_
#define CD_CDLABEL_H_
#include "ICDElement.h"
#include "CDConstants.h"
//#include "../Geometry/Rectangle.h"

class CDLabel : public ICDElement{
public:
	CDLabel();
	CDLabel(uint8_t width, char* label);
	CDLabel(int8_t x, int8_t y, uint8_t width, char* label);
	virtual ~CDLabel();
	void setLabel(char* label);
	char* getLabel();
	void setRolling();
	void stopRolling();
	bool isRolling();

	void setWidth(uint8_t width);
	uint8_t getWidth();
	void setLocation(int8_t x, int8_t y);
	Point* getLocation();
	Rectangle* getBounds();
	void print(LCD* lcd);
	void printArea(LCD* lcd, Rectangle* area);
	void validate();

private:
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	uint8_t lenght = 0;
	int8_t start = 0;
	int8_t strIndex = 0;
	char* label = '\0';
	uint8_t rollState = CDLabelStopRolling;
=======
 *  Created on: 18 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDLABEL_H_
#define CD_CDLABEL_H_
#include "ICDElement.h"
#include "CDConstants.h"
//#include "../Geometry/Rectangle.h"

class CDLabel : public ICDElement{
public:
	CDLabel();
	CDLabel(uint8_t width, char* label);
	CDLabel(int8_t x, int8_t y, uint8_t width, char* label);
	virtual ~CDLabel();
	void setLabel(char* label);
	char* getLabel();
	void startRolling();
	void stopRolling();
	bool isRolling();

	void setWidth(uint8_t width);
	uint8_t getWidth();
	void setLocation(int8_t x, int8_t y);
	Point* getLocation();
	Rectangle* getBounds();
	void print(LCD* lcd);
	void printArea(LCD* lcd, Rectangle* area);
	void validate();

private:
	int8_t x = 0;
	int8_t y = 0;
	uint8_t width = 0;
	uint8_t lenght = 0;
	//int8_t start = 0;
	int8_t strIndex = 0;
	char* label = '\0';
	uint8_t rollState = CDLabelStopRolling;
	long millis = 0;
>>>>>>> 8a34775 Clock
	//char* norm = '\0';

	void recreateStr();
};

#endif /* CD_CDLABEL_H_ */
