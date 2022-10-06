# M1OEP-jwvassal
Joe Vassallo's Open-ended project

This program pulls a list of planes from the opensky network (opensky-network.org/) and runs search functions on it, such as finding the closest plane to a given pair of latitude and longitude values, or finding the distance between two known planes. It can also just print the information of a known plane.

The module one concepts used are:

Classes:
- Plane class
  - Split into header and .cpp file
  - Contains many more than 2 fields
  - distanceTo() method is not a construcor, getter, setter, or destructor
    - Content of method was getting overly complex, so moved into its own file.

Overloaded operators:
- Plane class constructor
- Insertion (<<) in Plane class
- Plane distanceTo() method

Enum:
- Mode (keeps track of operation mode selected by user)

Struct:
- LatLong (stores a pair of latitude and longitude values)
- PlaneICAOPair (stores a theoretical ICAO24 value, then later a Plane that matches the value, if it exists. Also a bool whether said Plane was actually found or not.)

FUTURE PLANS:
-Convert the category property to be parsed into an enum, instead of storing it as an int and then having a lookup table printed.
- Search all planes to find the closest pair distance-wise, while respecting the curvature of the earth. This is a problem that has been solved already, so theoretically it shouldn't be too difficult.
- Introduce graphics and plotting a plane (or planes) on a projection of the earth.
- Introduce an iterative solution for my Plane.setFromJSON() function. It feels so doable, but I tried for a while and struggled with it due to the different ways I have to handle null and empty, and strings/doubles/bools.

CODE CITATIONS:


- JSONHandling.h used part of 
https://github.com/Microsoft/cpprestsdk/wiki/Getting-Started-Tutorial
and then used
https://stackoverflow.com/questions/31371659/set-basic-http-authentication-in-casablanca
for its http authentification.

- I wrote the implementation of the Haversine distance formula, but I did not derive it myself. See https://en.wikipedia.org/wiki/Haversine_formula for a more thorough explanation of the math going on here.

KNOWN BUGS:
- Crashes if ran while not connected to the internet.
- (Presumably) crashes if the OpenSky API goes down
- Tracks ground vehicles and multilateration towers (both not air vehicles) if they have an ICAO24 code assigned to them, which happens at some airports.
- ICAO24 codes are *supposed* to be unique according to the International Civil Aviation Organization, but this is not verified in the code.

VIDEO:
(Unfortunately I hit my daily rate limit during development, and it is Sunday, so I don't have time to wait for the rollover. As a result, the program will be pulling off the backup.json file as opposed to live updates.)
https://youtu.be/3P8STiwjq9M


I think I earned all 110 points for this project.

- Main program uses all of the concepts, most of them multiple times and with multiple implementations

- C++ Class
  - A vector of Plane classes is the core of the program, and used independently such as when being stored in PlaneICAOPair structs.
- Other concepts
  - Overloaded operators
    - distanceTo() is overloaded twice, taking in either a LatLong struct, two doubles, or another Plane object.
    - << operator is overloaded to return a formatted string.
  -Enum
    - Mode enum is used in order to keep track of which mode of operation the user selected.
  -Struct
    - LatLong struct holds a pair of latitude and longitude values.
    - PlaneICAOPair holds an ICAO24 value provided by the user, as well as its corresponding plane, and a boolean of whether the plane corresponding to the ICAO24 value was found or not.
- Style and documentation
  - Everything confusing has been documented, and the project is split into many seperate files and headers in order to improve organization. 
- Video
  - Demonstrates multiple runs, all the features, and shows robust input validation.
- Lifespan of project
  - Initial commit dates back to Sep 9th, with significant commits on the 11th, 15th, 16th, 17th, and 18th. (I unfortunately got taken out with COVID so larger commits took a little while to get going)
