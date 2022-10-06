#ifndef PLANE_INFO_H
#define PLANE_INFO_H
#include "Plane.h"
#include <vector>
/*
 * Plane info
 * Requires: vector of planes
 * Modifies: nothing
 * Effects: Displays information about a plane whose ICAO24 value is provided by the user.
 */
 
void planeInfo(const vector<Plane>& planes);

#endif