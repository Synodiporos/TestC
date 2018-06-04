/*
 * IRSensorListener.h
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef CONTROLLER_COVERSENSORLISTENER_H_
#define CONTROLLER_COVERSENSORLISTENER_H_

class CoverSensorListener {
public:
	CoverSensorListener();
	virtual ~CoverSensorListener();
	virtual void onCoverOpen() = 0;
	virtual void onCoverClose() = 0;
};

#endif /* CONTROLLER_COVERSENSORLISTENER_H_ */
