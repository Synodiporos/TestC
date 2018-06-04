/*
 * CDCharacters.h
 *
 *  Created on: May 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDCHARACTERS_H_
#define CD_CDCHARACTERS_H_

#include <stdint.h>

class CDCharacters {
public:
	//CDOption Hover char (0)
	static const uint8_t ch_hover[8];
	//CDOption Click char (1)
	static const uint8_t ch_click[8];

	static const uint8_t emptyChar[8];

	static uint8_t* copyOfChar(const uint8_t c[8]);

	static uint8_t* createScrollbarTopChar(uint8_t i);
	static uint8_t* createScrollbarBottomChar(uint8_t i);
	static uint8_t* createScrollbarMiddleChar(uint8_t i);

};

#endif /* CD_CDCHARACTERS_H_ */
