/*
 * IActionListener.h
 *
 *  Created on: 7 Απρ 2018
 *      Author: Synodiporos
 */

#ifndef COMMONS_IACTIONLISTENER_H_
#define COMMONS_IACTIONLISTENER_H_

class IActionListener {
public:
	IActionListener();
	virtual ~IActionListener();

	virtual void actionPerformed(void* source, void* action) = 0;
};

#endif /* COMMONS_IACTIONLISTENER_H_ */
