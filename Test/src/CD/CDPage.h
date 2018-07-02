/*
 * CDPage.h
 *
 *  Created on: 1 Ιουλ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDPAGE_H_
#define CD_CDPAGE_H_
#include "CDElement.h"
#include "../Commons/IActionListener.h"
#include "../Display/SystemDisplayManager.h"
#include <vector>
using namespace std;

class CDPage : public CDElement{
public:
	static const unsigned short int PANE_SHOW = 31;
	static const unsigned short int PANE_CLOSE = 30;

	CDPage();
	CDPage(int8_t w, int8_t h);
	CDPage(uint8_t x, uint8_t y, int8_t w, int8_t h);
	virtual ~CDPage();

	std::vector<IActionListener*> getPageListeners();
	void addPageListener(IActionListener* actionListener);
	void removePageListener(IActionListener* actionListener);
	IActionListener* getPageListener(unsigned int index);

	bool showAsPage();
	bool showAsPopUp();
	bool showAsToolTip();
	bool close();

protected:
	std::vector<IActionListener*> pageListeners =
			vector<IActionListener*>();
	void notifyActionPerformed(unsigned short int actionId);

};

#endif /* CD_CDPAGE_H_ */
