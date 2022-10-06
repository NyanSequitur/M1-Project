#ifndef JSONHANDLING_H
#define JSONHANDLING_H


#include <nlohmann/json.hpp>
#include "plane.h"

using nlohmann::json;

/*
 * Pull plane data
 * Requires: nothing
 * Modifies: backup.json
 * Effects: Pulls plane data from the OpenSky database, and sends it to a json object, while storing a copy in backup.json
 */
nlohmann::json pullPlaneData();

/*
 * Parse Plane JSON
 * Requires: JSON object of plane data
 * Modifies: nothing
 * Effects: converts a JSON object of plane data into a vector of Plane objects
 */
 
vector<Plane> parsePlaneJson(nlohmann::json planeJson);

#endif
