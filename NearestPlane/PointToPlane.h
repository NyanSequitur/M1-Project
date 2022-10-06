#ifndef POINT_TO_PLANE_H
#define POINT_TO_PLANE_H
#include "Plane.h"
#include <vector>
/*
 * Point to Plane
 * Requires: vector of planes
 * Modifies: nothing
 * Effects: locates the closest plane to user-provided latitude and longitude values 
 */
 
void pointToPlane(vector<Plane>& planes);

/*
 * Valid lat / Valid long
 * Requires: value
 * Modifies: nothing
 * Effects: Determines whether a double is a valid latitude or longitude respectively
 */
bool validLat(double num);
bool validLong(double num);

#endif