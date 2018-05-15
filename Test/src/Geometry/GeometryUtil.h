/*
 * GeometryUtil.h
 *
 *  Created on: 27 Απρ 2018
 *      Author: Synodiporos
 */

#ifndef GEOMETRY_GEOMETRYUTIL_H_
#define GEOMETRY_GEOMETRYUTIL_H_
#include <stdint.h>
#include "Point.h"

class GeometryUtil {
public:
	GeometryUtil();
	virtual ~GeometryUtil();

	static Point* indexToCoordinates(
			unsigned short int i, uint8_t columns){
		return new Point(i%columns, i/columns);
	}

	static unsigned short int coordinatesToIndex(
			Point* coords, uint8_t columns){
		return coords->getX() + (columns*coords->getY());
	}

	static int max(int a, int b){
		if(a>=b)
			return a;
		return b;
	}

	static int min(int a, int b){
		if(a<=b)
			return a;
		return b;
	}

	static int positive(int a){
		if(a>=0)
			return a;
		return 0;
	}

	static int negative(int a){
		if(a<=0)
			return a;
		return 0;
	}

	static bool valueInRangeOrEqual(int value, int min, int max){
		return (value >= min) && (value <= max);
	}

	static bool valueInRange(int value, int min, int max){
		return (value >= min) && (value <= max);
	}
};

#endif /* GEOMETRY_GEOMETRYUTIL_H_ */
