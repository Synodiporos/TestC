/*
 * CDOption.h
 *
 *  Created on: May 23, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDOPTION_H_
#define CD_CDOPTION_H_
#include "CDLabel.h"
#include "../Commons/IStateListener.h"
#include <stdint.h>

class CDOption : public CDLabel{
public:
	static const uint8_t UNHOVERED = 0;
	static const uint8_t HOVERED = 1;
	static const uint8_t CLICKED = 2;

	CDOption();
	virtual ~CDOption();
	void setOptionState(uint8_t state);
	uint8_t getOptionState();
	//void setStateListener(IStateListener* l);
	//void removeStateListener(IStateListener* l);
	//IStateListener* getStateListener();



private:
	uint8_t state = UNHOVERED;
	IStateListener* stateListener = nullptr;

	void notifyStateChanged();

};

#endif /* CD_CDOPTION_H_ */
