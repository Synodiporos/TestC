/*
 * Dimension.h
 *
 *  Created on: Apr 19, 2018
 *      Author: sgeorgiadis
 */

#ifndef GEOMETRY_DIMENSION_H_
#define GEOMETRY_DIMENSION_H_

class Dimension {
public:
	Dimension();
	Dimension(unsigned short int width, unsigned short int height);
	virtual ~Dimension();

	void setDimensions(unsigned short int w, unsigned short h);
	void setWidth(unsigned short int width);
	unsigned short int getWidth();
	void setHeight(unsigned short int height);
	unsigned short int getHeight();
	Dimension copy();

	bool equals(Dimension c);
	bool equals(short int w, short int h);

private:
	unsigned short int width = 0;
	unsigned short int height = 0;
};

#endif /* GEOMETRY_DIMENSION_H_ */
