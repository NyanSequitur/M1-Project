#include "PointToPlane.h"

#include <iostream>

#include "Plane.h"

using namespace std;


// modified versions of https://www.geeksforgeeks.org/how-to-check-whether-a-number-is-in-the-rangea-b-using-one-comparison/
// because its only ever comparing against two numbers, those can be hardcoded and the calculations can be simplified.

// -90 <= valid latitude <= 90
// 90^2 = 8100
bool validLat(const double num) { return pow(num, 2) <= 8100; }

// -180 <= valid longitude <= 180
// 90^2 = 8100
bool validLong(const double num) { return pow(num, 2) <= 32400; }


void pointToPlane(vector<Plane>& planes)
{
	bool invalidInput = true;
	LatLong userLatLong{};
	Plane closestPlane;


	// get user latitude
	while (invalidInput)
	{
		cout << "Enter a latitude value: ";
		if (cin >> userLatLong.latitude && validLat(userLatLong.latitude))
		{
			invalidInput = false;
		}
		else
		{
			cout << "That was an invalid input. ";
		}
		cin.clear(); cin.ignore(INT_MAX, '\n');

	}
	invalidInput = true;


	// get user longitude
	while (invalidInput)
	{
		cout << "Enter a longitude value: ";
		if (cin >> userLatLong.longitude && validLong(userLatLong.longitude))
		{
			invalidInput = false;
		}
		else
		{
			cout << "That was an invalid input. ";
		}

		cin.clear(); cin.ignore(INT_MAX, '\n');
	}
	invalidInput = true;


	// iterate over planes, find the closest one to the user's location
	for (Plane plane : planes)
	{
		if (plane.distanceTo(userLatLong) < closestPlane.distanceTo(userLatLong) && !plane.getOnGround())
		{
			closestPlane = plane;
			cout << "New closest plane: " << plane.getCallSign() << " with distance of: " << plane.distanceTo(userLatLong) << "km" << endl;
		}
	}
	// 19 because no preceding \n character
	cout << "Closest plane is:\n" << closestPlane << setw(19) << "with distance of:" << closestPlane.distanceTo(userLatLong) << "km" << endl;
}