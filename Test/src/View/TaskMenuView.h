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
	TaskMenuView();
	TaskMenuView(uint8_t width, bool editable);
	virtual ~TaskMenuView();
	void init();
	void setEditable(bool editable);
	bool getEditable();

private:
	bool editable = true;
};

#endif /* VIEW_TASKMENUVIEW_H_ */
