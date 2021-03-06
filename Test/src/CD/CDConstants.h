/*
 * CDConstants.h
 *
 *  Created on: 20 Ξ�Ξ±Ξ� 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDCONSTANTS_H_
#define CD_CDCONSTANTS_H_

//Speed: pixels interval in millis
#define CDLabelRollPI 500;
#define CDLabelRollingOffeset 1;
//Internal to start rolling;
#define CDLabelStartRollDelay 1000;
//Roll back to 0 after xx millis
#define CDLabelRollBackDelay 2000;

#define CDOptionAutoRolling_state 10;
#define CDOptionAutoRolling_Never  10;
#define CDOptionAutoRolling_OnHover  11;
#define CDOptionAutoRolling_OnPressed  12;

#define CDOptionLabel_UNHOVERED '-'
#define CDOptionLabel_HOVERED '='
#define CDOptionLabel_SELECTED '>'

#define CDKeyboard_SELECTION_INTERVAL 250
#define CDOptionChar_HOVER '_'
#define CDOptionChar_SELECTED 255

#endif /* CD_CDCONSTANTS_H_ */
