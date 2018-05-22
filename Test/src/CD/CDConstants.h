/*
 * CDConstants.h
 *
 *  Created on: 20 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CD_CDCONSTANTS_H_
#define CD_CDCONSTANTS_H_

#define CDLabelStartRolling 1;
#define CDLabelStopRolling 0;
//Speed: pixels per second
#define CDLabelRollPPS 4;
//Speed: pixels interval in millis
#define CDLabelRollPI 400;

#define CDLabelRollingOffeset 0;
#define CDLabelRollingStartFrom0 21;
#define CDLabelRollingStopToEnd 22;
#define CDLabelRollingEndState 0;



//Internal to start rolling;
#define CDOptionStartRollDelay 500;
//Roll back to 0 after xx millis
#define CDOptionRollBackInterval 1000;

#define CDLabelRolling_NEVER  10;
#define CDLabelRolling_WHENSELECTED  11;
#define CDLabelRolling_WHENPRESSED  12;

#endif /* CD_CDCONSTANTS_H_ */
