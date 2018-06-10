/*
 * Settings.h
 *
 *  Created on: 9 Ιουν 2018
 *      Author: Synodiporos
 */

#ifndef MODEL_SETTINGS_H_
#define MODEL_SETTINGS_H_

class Settings {

private:
	static Settings* instance;
	Settings(){	};

public:
	bool buzzerEnabled = true;
	bool coverSensorEnabled = true;

	virtual ~Settings(){

	};

	static Settings* getInstance(){
		if(!instance)
			this->instance = new Settings();
		return instance;
	};

};

#endif /* MODEL_SETTINGS_H_ */
