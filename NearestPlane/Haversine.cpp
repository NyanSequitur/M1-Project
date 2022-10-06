#define _USE_MATH_DEFINES

#include "Haversine.h"
#include <cmath>

constexpr int EARTH_RADIUS = 6371;

// Implementation of haversine
static double haversine(const double num)
{
	return pow(sin(num / 2), 2);
}


// Distance between lat/long points
static double latLongDistance(const double num1, const double num2)
{
	return (num2 - num1) * M_PI / 180;
}

static void toRadians(double& num)
{
	num *= M_PI / 180.0;
}


// Haversine distance formula
double haversineDistance(double lat1, double lon1, double lat2, double lon2)
{
	const double latDistance = latLongDistance(lat2, lat1);
	const double lonDistance = latLongDistance(lon2, lon1);


	toRadians(lat1);
	toRadians(lat2);


	double haversineValue = haversine(latDistance) + haversine(lonDistance) * cos(lat1) * cos(lat2);

	double doubleInverseHaversine = 2 * asin(sqrt(haversineValue));
	return EARTH_RADIUS * doubleInverseHaversine;
}


/*
 * Haversine(theta) = sin^2(theta/2)
 *
 * d/r = haversine(latitude2-latitude1) + cos(latitude1) * cos(latitude2) * haversine(longitude2 - longitude1)
 * d = r * inverse haversine(h) = 2 * r * arcsin(sqrt(h))
 *
 *
 *
 */