#include "Plane.h"
#include "LatLong.h"
#include <string>
#include <nlohmann/json.hpp>


#include "Haversine.h"


using namespace std;



// This was just one of the planes at the time I wrote the default constructor. CPP complained if I gave it null/empty values.
Plane::Plane() :
icao24("a8aac8"),
callSign("DAL2918"),
originCountry("United States"),
timePosition(),
lastContact(1663387197),
longitude(-82.1503),
latitude(26.6572),
baroAltitude(2179.32),
onGround(false),
velocity(134.98),
trueTrack(139.33),
verticalRate(-8.78),
sensors(0),
geoAltitude(2301.24),
squawk("7207"),
spi(false),
positionSource(0),
category(5)
{ };

// This constructor exists, but is unused.
Plane::Plane(
	string icao24,
	string callSign,
	string originCountry,
	int timePosition,
	int lastContact,
	double longitude,
	double latitude,
	double baroAltitude,
	bool onGround,
	double velocity,
	double trueTrack,
	double verticalRate,
	int sensors,
	double geoAltitude,
	string squawk,
	bool spi,
	int positionSource,
	int category
) :
	icao24(icao24),
	callSign(callSign),
	originCountry(originCountry),
	timePosition(timePosition),
	lastContact(lastContact),
	longitude(longitude),
	latitude(latitude),
	baroAltitude(baroAltitude),
	onGround(onGround),
	velocity(velocity),
	trueTrack(trueTrack),
	verticalRate(verticalRate),
	sensors(sensors),
	geoAltitude(geoAltitude),
	squawk(squawk),
	spi(spi),
	positionSource(positionSource),
	category(category)
{ };

// GETTERS

string Plane::getICAO24() const
{
	return icao24;
}


string Plane::getCallSign() const
{
	return callSign;
}

string Plane::getOriginCountry() const
{
	return originCountry;
}

string Plane::getSquawk() const
{
	return squawk;
}

int Plane::getTimePosition() const
{
	return timePosition;
}

int Plane::getLastContact() const
{
	return lastContact;
}

int Plane::getPositionSource() const
{
	return positionSource;
}

int Plane::getCategory() const
{
	return category;
}


double Plane::getLongitude() const
{
	return longitude;
}

double Plane::getLatitude() const
{
	return latitude;
}

double Plane::getBaroAltitude() const
{
	return baroAltitude;
}

double Plane::getVelocity() const
{
	return velocity;
}

double Plane::getTrueTrack() const
{
	return trueTrack;
}

double Plane::getVerticalRate() const
{
	return verticalRate;
}

double Plane::getGeoAltitude() const
{
	return geoAltitude;
}

bool Plane::getOnGround() const
{
	return onGround;
}

bool Plane::getSPI() const
{
	return spi;
}

int Plane::getSensors() const
{
	return sensors;
}

// SETTERS

void Plane::setFromJSON(nlohmann::basic_json<> planeJSON)
{
	// I tried! I tried to do an iterator, but I couldn't get it to work. I'm sure there's a way to do it, but I couldn't figure it out.
	planeJSON[0].empty()	?	this->icao24			= "NO ICAO24"		: this->icao24			= planeJSON[0];
	planeJSON[1].empty()	?	this->callSign			= "NO CALL SIGN"	: this->callSign		= planeJSON[1];
	planeJSON[2].empty()	?	this->originCountry		= "NO COUNTRY"		: this->originCountry	= planeJSON[2];
	planeJSON[3].is_null()	?	this->timePosition		= 0					: this->timePosition	= planeJSON[3];
	planeJSON[4].is_null()	?	this->lastContact		= 0					: this->lastContact		= planeJSON[4];
	planeJSON[5].is_null()	?	this->longitude			= 0					: this->longitude		= planeJSON[5];
	planeJSON[6].is_null()	?	this->latitude			= 0					: this->latitude		= planeJSON[6];
	planeJSON[7].is_null()	?	this->baroAltitude		= 0					: this->baroAltitude	= planeJSON[7];
	planeJSON[8].is_null()	?	this->onGround			= false				: this->onGround		= planeJSON[8];
	planeJSON[9].is_null()	?	this->velocity			= 0					: this->velocity		= planeJSON[9];
	planeJSON[10].is_null() ?	this->trueTrack			= 0					: this->trueTrack		= planeJSON[10];
	planeJSON[11].is_null() ?	this->verticalRate		= 0					: this->verticalRate	= planeJSON[11];
	planeJSON[12].is_null() ?	this->sensors			= 0					: this->sensors			= planeJSON[12];
	planeJSON[13].is_null() ?	this->geoAltitude		= 0					: this->geoAltitude		= planeJSON[13];
	planeJSON[14].empty()	?	this->squawk			= "NO SQUAWK"		: this->squawk			= planeJSON[14];
	planeJSON[15].is_null() ?	this->spi				= false				: this->spi				= planeJSON[15];
	planeJSON[16].is_null() ?	this->positionSource	= 0					: this->positionSource	= planeJSON[16];
	planeJSON[17].is_null() ?	this->category			= 0					: this->category		= planeJSON[17];
}

// INDIVIDUAL SETTERS, UNUSED, BANISHED TO THE COMMENT REALM FOR THEIR CRIMES

/*

void Plane::setICAO24(string icao24)
{
	this->icao24 = icao24;
}

void Plane::setCallSign(string callSign)
{
	this->callSign = callSign;
}

void Plane::setOriginCountry(string originCountry)
{
	this->originCountry = originCountry;
}

void Plane::setSquawk(string squawk)
{
	this->squawk = squawk;
}

void Plane::setTimePosition(int timePosition)
{
	this->timePosition = timePosition;
}

void Plane::setLastContact(int lastContact)
{
	this->lastContact = lastContact;
}

void Plane::setPositionSource(int positionSource)
{
	this->positionSource = positionSource;
}

void Plane::setCategory(int category)
{
	this->category = category;
}

void Plane::setLongitude(double longitude)
{
	this->longitude = longitude;
}

void Plane::setLatitude(double latitude)
{
	this->latitude = latitude;
}

void Plane::setBaroAltitude(double baroAltitude)
{
	this->baroAltitude = baroAltitude;
}

void Plane::setVelocity(double velocity)
{
	this->velocity = velocity;
}

void Plane::setTrueTrack(double trueTrack)
{
	this->trueTrack = trueTrack;
}

void Plane::setVerticalRate(double verticalRate)
{
	this->verticalRate = verticalRate;
}

void Plane::setGeoAltitude(double geoAltitude)
{
	this->geoAltitude = geoAltitude;
}

void Plane::setOnGround(bool onGround)
{
	this->onGround = onGround;
}

void Plane::setSPI(bool spi)
{
	this->spi = spi;
}

void Plane::setSensors(int sensors)
{
	this->sensors = sensors;
}


*/

// FUNCTIONS
// distance from this plane to given latitute and longitude
// Most of this function is in the Haversine.cpp file, because it uses a couple sub-functions and I didn't want to clutter this file.

double Plane::distanceTo(const LatLong givenLatLong)
{
	return haversineDistance(this->latitude, this->longitude, givenLatLong.latitude, givenLatLong.longitude);
}

double Plane::distanceTo(const double latitudeIn, const double longitudeIn)
{
	return haversineDistance(this->latitude, this->longitude, latitudeIn, longitudeIn);
}

double Plane::distanceTo(const Plane& plane)
{
	return haversineDistance(this->latitude, this->longitude, plane.getLatitude(), plane.getLongitude());
}

// overload << operator to print plane info
ostream& operator<<(ostream& os, const Plane& plane)
{
	// 19 because of the \n character starting from the second line
	os << left << setw(19) << boolalpha
		<< "ICAO 24:"			<< setw(20) << plane.icao24			<< setw(20)
		<< "\nCall Sign:"		<< setw(20) << plane.callSign		<< setw(20)
		<< "\nOrigin Country:"	<< setw(20) << plane.originCountry	<< setw(20)
		<< "\nTime Position:"	<< setw(20) << plane.timePosition	<< setw(20)
		<< "\nLast Contact:"	<< setw(20) << plane.lastContact	<< setw(20)
		<< "\nLongitude:"		<< setw(20) << plane.longitude		<< setw(20)
		<< "\nLatitude:"		<< setw(20) << plane.latitude		<< setw(20)
		<< "\nBaro Altitude:"	<< setw(20) << plane.baroAltitude	<< setw(20)
		<< "\nOn Ground:"		<< setw(20) << plane.onGround		<< setw(20)
		<< "\nVelocity:"		<< setw(20) << plane.velocity		<< setw(20)
		<< "\nTrue Track:"		<< setw(20) << plane.trueTrack		<< setw(20)
		<< "\nVertical Rate:"	<< setw(20) << plane.verticalRate	<< setw(20)
		<< "\nSensors:"			<< setw(20) << plane.sensors		<< setw(20)
		<< "\nGeo Altitude:"	<< setw(20) << plane.geoAltitude	<< setw(20)
		<< "\nSquawk:"			<< setw(20) << plane.squawk			<< setw(20)
		<< "\nSpi:"				<< setw(20) << plane.spi			<< setw(20)
		<< "\nPosition Source:"	<< setw(20) << plane.positionSource	<< setw(20)
		<< "\nCategory:"		<< setw(20) << plane.category		<< noboolalpha << endl;
	return os;
}