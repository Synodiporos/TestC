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

	AbstractCDOption* getOptionAuto();
	AbstractCDOption* getOptionManul();
	AbstractCDOption* getOptionSettings();
	AbstractCDOption* getOptionStatistics();

private:

};

#endif /* VIEW_MAINVIEW_H_ */
