#ifndef PLANE_ICAO_PAIR_H
#define PLANE_ICAO_PAIR_H

#include "Plane.h"

/*
 * Plane ICAO Pair
 * Requires: nothing
 * Modifies: nothing
 * Effects: stores a plane and a ICAO24 value that is assigned to user input, as well as a boolean value indicating whether the ICAO24 successfully found a plane.
 */
struct PlaneICAOPair
{
	bool found = false;
	Plane plane;
	string icao;
};

#endif