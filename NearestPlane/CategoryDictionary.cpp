#include "CategoryDictionary.h"
#include <iostream>

using namespace std;


void categoryDictionary()
{
	// just prints what each category means
	cout
		<< "0 = No information"
		<< "\n1 = No ADS-B Emitter Category Information"
		<< "\n2 = Light (< 15500 lbs)"
		<< "\n3 = Small (15500 - 75000 lbs)"
		<< "\n4 = Large (75000 - 300000 lbs)"
		<< "\n5 = High Vortex Large (aircraft such as B-757)"
		<< "\n6 = Heavy (> 300000 lbs)"
		<< "\n7 = High Performance (> 5g acceleration and 400 kts)"
		<< "\n8 = Rotocraft"
		<< "\n9 = Glider / sailplane"
		<< "\n10 = Lighter-than-air"
		<< "\n11 = Parachutist / Skydiver"
		<< "\n12 = Ultralight / hang-glider / paraglider"
		<< "\n13 = Reserved"
		<< "\n14 = Unmanned Aerial Vehicle"
		<< "\n15 = Space / Trans-atmospheric vehicle"
		<< "\n16 = Surface Vehicle – Emergency Vehicle"
		<< "\n17 = Surface Vehicle – Service Vehicle"
		<< "\n18 = Point Obstacle (includes tethered balloons)"
		<< "\n19 = Cluster Obstacle"
		<< "\n20 = Line Obstacle"
	<< endl;
}
