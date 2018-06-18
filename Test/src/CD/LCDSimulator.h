/*
 * LCDSimulator.h
 *
 *  Created on: 16 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CD_LCDSIMULATOR_H_
#define CD_LCDSIMULATOR_H_
#include "LCD.h"
#include <string>
#include <vector>
using namespace std;
#include "../Geometry/Dimension.h"

class LCDSimulator : public LCD{
public:
	LCDSimulator(uint8_t width, uint8_t height);
	virtual ~LCDSimulator();

	void init();

	virtual bool settingCursor(Point* sursor);
	virtual uint8_t getCharBufferAddress();
	virtual bool createChar(uint8_t id, const uint8_t[8]);
	virtual bool printChar(uint8_t id);
	virtual bool print(char* str);
	virtual bool print(char ch);
	virtual bool clear();
	virtual bool refresh();

private:
	std::vector<string*> lines;

	void printing();
};

#endif /* CD_LCDSIMULATOR_H_ */
