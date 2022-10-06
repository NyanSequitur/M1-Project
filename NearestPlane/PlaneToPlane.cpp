#include <iostream>
#include "PlaneToPlane.h"
#include "PlaneICAOPair.h"


void planeToPlane(vector<Plane>& planes)
{
	bool invalidInput = true;

	PlaneICAOPair planeOne, planeTwo;

	
	while (invalidInput)
	{
		// get user ICAO values
		cout << "Enter a plane ICAO value: ";
		getline(cin, planeOne.icao);
		cin.clear();
		cout << "Enter another plane ICAO value: ";
		getline(cin, planeTwo.icao);
		cin.clear();

		// yeah sure I *could* do some fancy iteration, but this is simple enough that it isn't worth it.

		for (Plane plane : planes)
		{
			if (plane.getICAO24() == planeOne.icao)
			{
				planeOne.plane = plane;
				planeOne.found = true;
			}

			if (plane.getICAO24() == planeTwo.icao)
			{
				planeTwo.plane = plane;
				planeTwo.found = true;
			}
		}

		// check if both planes exist

		if (planeOne.found && planeTwo.found)
		{
			invalidInput = false;
		}
		else
		{
			// ICAO values can't be easily verified at input, so the vector needs to be iterated over first.
			cout << "One or both of those planes were not found. ";
		}
	}

	// print out distance between planes

	cout << "The distance between " << planeOne.plane.getICAO24() << " and " << planeTwo.plane.getICAO24() << " is: " << planeOne.plane.distanceTo(planeTwo.plane) << "km" << endl;
	
}
