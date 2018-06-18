/*
 * MainView.h
 *
 *  Created on: 4 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef VIEW_MAINVIEW_H_
#define VIEW_MAINVIEW_H_
#include "../CD/CDOptionPane.h"
#include "../CD/CDOptionLabel.h"

class MainView: public CDOptionPane {
public:
	MainView(uint8_t width, uint8_t height);
	virtual ~MainView();
	void init();

	AbstractCDOption* getOptionAuto();
	AbstractCDOption* getOptionManul();
	AbstractCDOption* getOptionSettings();
	AbstractCDOption* getOptionStatistics();

private:

};

#endif /* VIEW_MAINVIEW_H_ */
