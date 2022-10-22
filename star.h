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

using namespace std;

class Star
{
public:
    Star() {
        m_starPoint = Point(random(0, 400), random(200, 400));
        m_starPhase = random(0, 255);
    };
    
    void updatePhase() {
        if (m_starPhase++ > 255) {
            m_starPhase = 0;
        }
        else {
            m_starPhase++;
        }
    };
    
    Point getStarPoint() {
        return m_starPoint;
    };
    
    unsigned char getStarPhase() {
        return m_starPhase;
    };

private:
	Point m_starPoint;
	unsigned char m_starPhase;
};
