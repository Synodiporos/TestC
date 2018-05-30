/*
 * CDCharacters.cpp
 *
 *  Created on: May 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDCharacters.h"

//CDOption Hover char
	const uint8_t CDCharacters::ch_hover[8] =
		{0x00, 0x10, 0x18, 0x14, 0x12, 0x14, 0x18, 0x10};

	const uint8_t CDCharacters::ch_click[8] =
		{0x00, 0x08, 0x0C, 0x0E, 0x0F, 0x0E, 0x0C, 0x08};

	const uint8_t CDCharacters::emptyChar[8] = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	uint8_t* CDCharacters::copyOfChar(const uint8_t c[8]){
		static uint8_t res[8];
		for(int i=0; i<8; i++)
			res[i] = c[i];
		return res;
	}

	uint8_t* CDCharacters::createScrollbarTopChar(uint8_t i){
		if(i==0 || i>5)
			return CDCharacters::copyOfChar(
					CDCharacters::emptyChar);
		else{
			static uint8_t* c = CDCharacters::copyOfChar(
					CDCharacters::emptyChar);
			c[i+3] = 0x1F;
			return c;
		}
	}

	uint8_t* CDCharacters::createScrollbarBottomChar(uint8_t i){
		if(i==0 || i>5)
			return CDCharacters::copyOfChar(
					CDCharacters::emptyChar);
		else{
			static uint8_t* c = CDCharacters::copyOfChar(
					CDCharacters::emptyChar);
			c[i] = 0x1F;
			return c;
		}
	}

	uint8_t* CDCharacters::createScrollbarMiddleChar(uint8_t i){
		if(i==0 || i>8)
			return CDCharacters::copyOfChar(
					CDCharacters::emptyChar);
		else{
			static uint8_t* c = CDCharacters::copyOfChar(
					CDCharacters::emptyChar);
			c[i] = 0x1F;
			return c;
		}
	}
