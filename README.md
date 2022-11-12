This program pulls a list of planes from the opensky network (opensky-network.org/) and runs search functions on it, such as finding the closest plane to a given pair of latitude and longitude values, or finding the distance between two known planes. It can also just print the information of a known plane. It is written entirely in C++, and uses 

FUTURE PLANS:
- Convert the category property to be parsed into an enum, instead of storing it as an int and then having a lookup table printed.
- Search all planes to find the closest pair distance-wise, while respecting the curvature of the earth. This is a problem that has been solved already, so theoretically it shouldn't be too difficult.
- Introduce graphics and plotting a plane (or planes) on a projection of the earth.
- Introduce an iterative solution for my Plane.setFromJSON() function. It feels so doable, but I tried for a while and struggled with it due to the different ways I have to handle null and empty, and strings/doubles/bools.

CODE CITATIONS:

- JSONHandling.h used part of 
https://github.com/Microsoft/cpprestsdk/wiki/Getting-Started-Tutorial
and then used
https://stackoverflow.com/questions/31371659/set-basic-http-authentication-in-casablanca
for its http authentification. It also used https://json.nlohmann.me/ in order to parse JSON into managable objects.


- I wrote the implementation of the Haversine distance formula, but I did not derive it myself. See https://en.wikipedia.org/wiki/Haversine_formula for a more thorough explanation of the math going on here.

KNOWN BUGS:
- Crashes if ran while not connected to the internet.
- ~~(Presumably) crashes if the OpenSky API goes down~~
  - The OpenSky API had an outage and the API returns an empty JSON file instead of nothing. The program does not crash.
- Tracks ground vehicles and multilateration towers (both not air vehicles) if they have an ICAO24 code assigned to them, which happens at some airports.
- ICAO24 codes are *supposed* to be unique according to the International Civil Aviation Organization, but this is not verified in the code.

VIDEO:
(Unfortunately I hit the daily rate limit during development. As a result, the program will be pulling off the backup.json file as opposed to live updates.)
https://youtu.be/3P8STiwjq9M
