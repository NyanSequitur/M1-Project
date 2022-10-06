#include <iostream>
#include <vector>

#include "Plane.h"
#include "JSONHandling.h"
#include "PlaneToPlane.h"
#include "PointToPlane.h"
#include "PlaneInfo.h"
#include "CategoryDictionary.h"

enum Mode { pointToPlaneMode, planeToPlaneMode, planeInfoMode, categoryDictionaryMode, menuMode };


int main(int argc, char* argv[])
{
	bool invalidInput = true, continueRunning = true;

	cout << "Pulling plane data, please be patient." << endl;
	nlohmann::json planeJson = pullPlaneData();
	cout << "Pulling complete." << endl;
	Mode mode = menuMode;

	// vector instead of list for easy iteration/random access
	vector<Plane> planes = parsePlaneJson(planeJson);

	while (continueRunning)
	{

		// get mode of operation

		while(invalidInput)
		{
			int modeInt;
			cout << "Enter 1 for point to plane distance, 2 for plane to plane distance, 3 for plane info, or 4 to view plane category definitions: ";

			// assign mode to correct mode of operation if user input falls between accepted values.
			if (cin >> modeInt && modeInt >= 1 && modeInt <= 4)
			{
				switch(modeInt)
				{
				case 1:
					mode = pointToPlaneMode;
					break;
				case 2:
					mode = planeToPlaneMode;
					break;
				case 3:
					mode = planeInfoMode;
					break;
				case 4:
					mode = categoryDictionaryMode;
					break;
				}
				invalidInput = false;
			}
			else
			{
				cout << "Invalid input, please try again." << endl;
			}
			cin.clear(); cin.ignore(INT_MAX, '\n');
		}

		invalidInput = true;






		// mode switch, core of the program
		switch (mode)
		{
		case pointToPlaneMode:
			pointToPlane(planes);
			break;
		case planeToPlaneMode:
			planeToPlane(planes);
			break;
		case planeInfoMode:
			planeInfo(planes);
			break;
		case categoryDictionaryMode:
			categoryDictionary();
			break;
			
		}

		// prompt if user wants to continue, check if valid
		while (invalidInput)
		{
			
			cout << "Would you like to continue? (y/n): ";
			string input;
			cin >> input;

			// cin keeps \n
			if (input.length() > 2)
			{
				cout << "Invalid input, please try again." << endl;
			}
			else if (input == "y" || input == "Y")
			{
				invalidInput = false;
				mode = menuMode;
			}
			else if (input == "n" || input == "N")
			{
				continueRunning = false;
				invalidInput = false;
			}

			else
			{
				cout << "Invalid input, please try again." << endl;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
		}
		invalidInput = true;

		// if user wants to continue, ask if they want to refresh the plane data.

		if (continueRunning)
		{
			while (invalidInput)
			{
				cout << "Would you like to refresh plane data? (y/n): ";
				string input;
				cin >> input;

				// cin keeps \n
				if (input.length()>2)
				{
					cout << "Invalid input, please try again." << endl;
				}
				else if (input == "y" || input == "Y")
				{
					planeJson = pullPlaneData();
					planes = parsePlaneJson(planeJson);
					invalidInput = false;
				}
				else if (input == "n" || input == "N")
				{
					invalidInput = false;
				}
				else
				{
					cout << "Invalid input, please try again." << endl;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.clear();
				
			}

			invalidInput = true;
		}

	}

	return 0;
}
