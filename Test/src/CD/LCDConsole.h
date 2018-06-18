/*
 * LCDConsole.h
 *
 *  Created on: 16 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CD_LCDCONSOLE_H_
#define CD_LCDCONSOLE_H_
#include "LCD.h"
#include "../Geometry/Point.h"

class LCDConsole : public LCD{
public:
	LCDConsole(uint8_t width, uint8_t height);
	LCDConsole(int8_t x, int8_t y, uint8_t width, uint8_t height);
	virtual ~LCDConsole();

	virtual bool settingCursor(Point* sursor);
	virtual uint8_t getCharBufferAddress();
	virtual bool createChar(uint8_t id, const uint8_t[8]);
	virtual bool printChar(uint8_t id);
	virtual bool print(char* str);
	virtual bool print(char ch);
	virtual bool clear();
	virtual bool refresh();

private:
	void sentCursorCoords();
};

#endif /* CD_LCDCONSOLE_H_ */
