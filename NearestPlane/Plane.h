#ifndef PLANE_H
#define PLANE_H
#include <nlohmann/json.hpp>


#include <string>
#include "LatLong.h"

using namespace std;

class Plane {
public:
	/*
	 * Default Constructor
	 * Requires: nothing
	 * Modifies: all fields
	 * Effects: Sets plane equal to a default plane
	 */
	Plane();

	/*
	 * Overloaded Constructor
	 * Requires: all fields
	 * Modifies: all fields
	 * Effects: Sets winning_numbers to given fields
	 */
	Plane(
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
	);


	/*
	 * GETTERS
	 * Require: nothing
	 * Modifies: nothing
	 * Effects: Returns their respective fields
	 */

	string getICAO24() const;
	string getCallSign() const;
	string getOriginCountry() const;
	string getSquawk() const;

	int getTimePosition() const;
	int getLastContact() const;
	int getPositionSource() const;
	int getCategory() const;

	double getLongitude() const;
	double getLatitude() const;
	double getBaroAltitude() const;
	double getVelocity() const;
	double getTrueTrack() const;
	double getVerticalRate() const;
	double getGeoAltitude() const;

	bool getOnGround() const;
	bool getSPI() const;

	int getSensors() const;

	/*
	 * SETTERS
	 * Require: field value
	 * Modifies: their respective fields
	 * Effects: Sets their respective fields to given value
	 */

	void setFromJSON(nlohmann::basic_json<> planeJSON);

	void setICAO24(string icao24);
	void setCallSign(string callsign);
	void setOriginCountry(string originCountry);
	void setSquawk(string squawk);

	void setTimePosition(int timePosition);
	void setLastContact(int lastContact);
	void setPositionSource(int positionSource);
	void setCategory(int category);

	void setLongitude(double longitude);
	void setLatitude(double latitude);
	void setBaroAltitude(double baroAltitude);
	void setVelocity(double velocity);
	void setTrueTrack(double trueTrack);
	void setVerticalRate(double verticalRate);
	void setGeoAltitude(double geoAltitude);

	void setOnGround(bool onGround);
	void setSPI(bool spi);

	void setSensors(int sensors);


	/*
	 * Distance to
	 * Require: LatLong struct, or latitude and longitude doubles, or another plane
	 * Modifies: nothing
	 * Effects: returns the distance between this plane and another location/plane
	 */

	double distanceTo(LatLong givenLatLong);
	double distanceTo(double latitudeIn, double longitudeIn);
	double distanceTo(const Plane& plane);

	/*
	 * << overload
	 * Require: nothing
	 * Modifies: <<
	 * Effects: overloads << to return plane data
	 */

	friend std::ostream& operator<<(std::ostream& os, const Plane& plane);

private:
	string icao24, callSign, originCountry, squawk;
	int timePosition, lastContact, positionSource, category, sensors;
	double longitude, latitude, baroAltitude, velocity, trueTrack, verticalRate, geoAltitude;
	bool onGround, spi;
};

#endif



