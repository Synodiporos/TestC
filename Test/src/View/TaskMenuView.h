/*
 * TaskMenuView.h
 *
 *  Created on: Jun 8, 2018
 *      Author: sgeorgiadis
 */

#ifndef VIEW_TASKMENUVIEW_H_
#define VIEW_TASKMENUVIEW_H_
#include "../CD/CDOptionPane.h"

class TaskMenuView : public CDOptionPane{
public:
	virtual ~TaskMenuView();
	TaskMenuView();

	void init();

};

#endif /* VIEW_TASKMENUVIEW_H_ */
