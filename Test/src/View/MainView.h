/*
 * MainView.h
 *
 *  Created on: 4 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef VIEW_MAINVIEW_H_
#define VIEW_MAINVIEW_H_
#include "../CD/CDOptionPane.h"
#include "../CD/CDOption.h"

class MainView: public CDOptionPane {
public:
	MainView();
	virtual ~MainView();
	void init();

	CDOption* optionAuto = nullptr;
	CDOption* optionManual = nullptr;
	CDOption* optionSettings = nullptr;
	CDOption* optionStatistics = nullptr;


private:

};

#endif /* VIEW_MAINVIEW_H_ */
