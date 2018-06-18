/*
 * MainFactory.h
 *
 *  Created on: 16 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef FACTORIES_MAINFACTORY_H_
#define FACTORIES_MAINFACTORY_H_
#include "../Controller/MainController.h"
#include "../View/MainView.h"
#include "../View/ViewAssets.h"
class MainFactory {
public:

	static MainController* createController(){
		MainView* view = createView();
		MainController* ctrl = new MainController(view);
		return ctrl;
	}

	static MainView* createView(){
		MainView* view = new MainView(SCREEN_WIDTH, SCREEN_HEIGHT);
		return view;
	}
};

#endif /* FACTORIES_MAINFACTORY_H_ */
