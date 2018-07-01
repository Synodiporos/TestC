/*
 * SystemDisplayManager.h
 *
 *  Created on: 1 Ιουλ 2018
 *      Author: Synodiporos
 */

#ifndef DISPLAY_SYSTEMDISPLAYMANAGER_H_
#define DISPLAY_SYSTEMDISPLAYMANAGER_H_
#include "SystemDisplay.h"

class SystemDisplayManager {
public:
	virtual ~SystemDisplayManager();

	static SystemDisplayManager* getInstanse();

	void setDefaultSystemDisplay(SystemDisplay* defaultDisplay);
	SystemDisplay* getDefaultSystemDisplay();

private:
	static SystemDisplayManager* instance;
	SystemDisplay* defaultDisplay = nullptr;
	SystemDisplayManager();
	SystemDisplayManager(SystemDisplayManager const&);     // Don't Implement
	void operator=(SystemDisplayManager const&); // Don't implement
};

#endif /* DISPLAY_SYSTEMDISPLAYMANAGER_H_ */
