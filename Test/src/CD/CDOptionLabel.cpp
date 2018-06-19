/*
 * CDOptionLabel.cpp
 *
 *  Created on: 15 Ιουν 2018
 *      Author: Synodiporos
 */

#include "CDOptionLabel.h"

CDOptionLabel::CDOptionLabel(uint8_t width, const char* text) :
	CDOption(width, new CDLabel(width, text)){

}

CDOptionLabel::CDOptionLabel(int8_t x, int8_t y, uint8_t width, const char* text) :
	CDOption(x, y, width, new CDLabel(width, text)){

}

CDOptionLabel::CDOptionLabel(int8_t x, int8_t y, uint8_t width, const char* text,
	unsigned int actionId):
	CDOption(x, y, width, new CDLabel(width, text), actionId){

}

CDOptionLabel::~CDOptionLabel() {
	// TODO Auto-generated destructor stub
}

void CDOptionLabel::onOptionStateChanged(){
	CDOption::onOptionStateChanged();

	CDLabel* label = (CDLabel*)getElement();
	if(label){
		if(AutoRolling_state==AutoRolling_Never){

		}
		else if(getOptionState()==HOVERED){
			if(AutoRolling_state==AutoRolling_OnHover)
				label->startRolling();
			else
				label->stopRolling();
		}
		else if(getOptionState()==CLICKED){
			if(AutoRolling_state==AutoRolling_OnClick)
				label->startRolling();
			else
				label->stopRolling();
		}
	}
}
