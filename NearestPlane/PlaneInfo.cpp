#include "PlaneInfo.h"
#include <iostream>
#include "PlaneICAOPair.h"
#include "Plane.h"


// Heavily based off of the PlaneToPlane class
void planeInfo(const vector<Plane>& planes)
{
	PlaneICAOPair planeICAOPair;
	bool invalidInput = true;
	while (invalidInput)
	{
		// get user ICAO value
		cout << "Enter a plane ICAO value: ";
		getline(cin, planeICAOPair.icao);
		cin.clear();

		// iterate over planes to find matching ICAO value
		for (const Plane& plane : planes)
		{
			if (plane.getICAO24() == planeICAOPair.icao)
			{
				planeICAOPair.plane = plane;
				planeICAOPair.found = true;
			}
		}
		
		if (planeICAOPair.found)
		{
			// exit loop if plane found
			invalidInput = false;
		}
		else
		{
			cout << "The plane could not be found. ";
		}
	}
	// print out plane
	cout << planeICAOPair.plane << endl;
}