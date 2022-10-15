/***********************************************************************
 * Header File:
 *    Star : Represents a star in the lunar lander game
 * Author:
 *    Jessica Johnson
 * Summary:
 *    Where the star is located, and what phase of twinkling it's on.
 ************************************************************************/

#pragma once

#include "point.h"   // for Point
#include "uiDraw.h"  // for ogstream

/***********************************************************
 * STAR
 * The star class
 ***********************************************************/
class Star
{
public:
	Star();

	int updatePhase(char phase);

private:
	Point m_starPoint;
	unsigned char m_starPhase;
};