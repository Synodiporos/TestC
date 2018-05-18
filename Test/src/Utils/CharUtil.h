/*
 * CharUtil.h
 *
 *  Created on: 9 Μαΐ 2018
 *      Author: Synodiporos
 */

#ifndef CHARUTIL_H_
#define CHARUTIL_H_

#include <stdint.h>

class CharUtil {
public:
	CharUtil();
	virtual ~CharUtil();

	static char* strFilling(char* str, uint8_t size, int8_t start);
};

#endif /* CHARUTIL_H_ */
