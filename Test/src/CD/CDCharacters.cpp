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

	/*uint8_t* CDCharacters::copyOfChar(const uint8_t c[8]){
		static uint8_t res[8];
		for(int i=0; i<8; i++)
			res[i] = c[i];
		return res;
	}*/

	void CDCharacters::createScrollbarTopChar(uint8_t value, uint8_t c[8]){
		if(value==0 || value>5)
			return ;
		else{
			c[0] = 0x04;
			c[1] = 0x0A;
			c[2] = 0x11;

			for(int i=3; i<8; i++)
				if(i == value + 2)
					c[i] = 0x1F;
				else
					c[i] = 0x00;
		}
	}

	void CDCharacters::createScrollbarBottomChar(uint8_t value, uint8_t c[8]){
		if(value==0 || value>5)
			return ;
		else{
			c[5] = 0x11;
			c[6] = 0x0A;
			c[7] = 0x04;

			for(int i=0; i<8; i++)
				if(i == value - 1)
					c[i] = 0x1F;
				else
					c[i] = 0x00;
		}
	}

	void CDCharacters::createScrollbarMiddleChar(uint8_t value, uint8_t c[8]){
		if(value==0 || value>8)
			return;
		else{
			for(int i=0; i<8; i++)
				if(i == value - 1)
					c[i] = 0x1F;
				else
					c[i] = 0x00;
		}
	}
