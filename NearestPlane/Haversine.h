#ifndef HAVERSINE_H
#define HAVERSINE_H
#include "LatLong.h"

/*
 * Haversine
 * Requires: a number
 * Modifies: nothing
 * Effects: Finds the haversine of a number 
 */
static double haversine(double num);

/*
 * Plane ICAO Pair
 * Requires: two latitude or longitude values
 * Modifies: nothing
 * Effects: calculates the distance between a pair of latitude or a pair of longitude values
 */
static double latLongDistance(double num1, double num2);

/*
 * To radians
 * Requires: a number
 * Modifies: nothing
 * Effects: Converts the number into radians
 */
static void toRadians(double& num);

/*
 * Plane ICAO Pair
 * Requires: two latitude and longitude pairs
 * Modifies: nothing
 * Effects: calculates the distance between a pair of latitude and longitude values while accounting for the curvature of the earth by using the haversine distance formula
 */
 
double haversineDistance(double lat1, double lon1, double lat2, double lon2);

#endif