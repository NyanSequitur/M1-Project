#ifndef PLANE_TO_PLANE_H
#define PLANE_TO_PLANE_H

#include "Plane.h"
#include <vector>

/*
 * Plane to Plane
 * Requires: vector of planes
 * Modifies: nothing
 * Effects: Determines the distance between two planes whose ICAO24 value is provided by the user.
 */
void planeToPlane(vector<Plane>& planes);

#endif