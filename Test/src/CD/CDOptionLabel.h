/*
 * CDOptionLabel.h
 *
 *  Created on: 15 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDOPTIONLABEL_H_
#define CD_CDOPTIONLABEL_H_
#include "CDOption.h"

class CDOptionLabel : public CDOption{
public:
	static const uint8_t AutoRolling_Never = 10;
	static const uint8_t AutoRolling_OnHover = 11;
	static const uint8_t AutoRolling_OnClick = 12;
	static const uint8_t AutoRolling_state = AutoRolling_OnHover;

	CDOptionLabel(uint8_t width, const char* text);
	CDOptionLabel(int8_t x, int8_t y, uint8_t width, const char* text);
	CDOptionLabel(int8_t x, int8_t y, uint8_t width, const char* text,
			unsigned int actionId);
	virtual ~CDOptionLabel();

protected:
	virtual void onOptionStateChanged(); // Implement

};

#endif /* CD_CDOPTIONLABEL_H_ */
