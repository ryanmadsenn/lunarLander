/***********************************************************************
 * Source File:
 *    Star : Represents a star in the lunar lander game
 * Author:
 *    Jessica Johnson
 * Summary:
 *    Where the star is located, and what phase of twinkling it's on.
 ************************************************************************/

#include "star.h"
#include "uiDraw.h"

/************************************************************************
 * STAR constructor
 * Create a new star object
 ************************************************************************/
Star::Star() { 
	// Initialize the star with a random position and phase
	m_starPoint = Point(random(0, 400), random(100, 500));
	m_starPhase = random(0, 255);
}

/************************************************************************
 * UPDATE PHASE
 * Update a star's phase
 ************************************************************************/
int Star::updatePhase(char phase) {
	// if it goes over 255 start over
	if (phase++ > 255) {
		return 0;
	}
	else {
		return phase++;
	}
}
