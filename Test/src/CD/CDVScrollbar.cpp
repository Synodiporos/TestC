/*
 * CDVScrollbar.cpp
 *
 *  Created on: May 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDVScrollbar.h"

CDVScrollbar::CDVScrollbar() {
	// TODO Auto-generated constructor stub

}

CDVScrollbar::~CDVScrollbar() {
	// TODO Auto-generated destructor stub
}

virtual AbstractCDElement* CDVScrollbar::getParent(){
	return this->parent;
}

virtual Rectangle* CDVScrollbar::getBounds(){
	return new Rectangle(x, 0, 1, height);
}

virtual void CDVScrollbar::printArea(LCD* lcd, Rectangle* area){

}

virtual void CDVScrollbar::validate(){

}
