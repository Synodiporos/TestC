/*
 * TaskContainerView.h
 *
 *  Created on: 2 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef VIEW_TASKCONTAINERVIEW_H_
#define VIEW_TASKCONTAINERVIEW_H_
#include "../CD/CDOptionPane.h"

class TaskContainerView: public CDOptionPane {
public:
	TaskContainerView(uint8_t w, uint8_t h);
	virtual ~TaskContainerView();
};

#endif /* VIEW_TASKCONTAINERVIEW_H_ */
