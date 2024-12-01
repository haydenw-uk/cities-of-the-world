//
// Created by Hayden Williams on 01/12/2024.
//

#include "Coordinate.h"

Coordinate::Coordinate(double lat, double lon) : latitude(lat), longitude(lon) {}


double Coordinate::getLatitude() const {
    return latitude;
}

double Coordinate::getLongitude() const {
    return longitude;
}


double Coordinate::calculateDistanceTo(const Coordinate &other) const {
    double latOne = degreesToRadians(latitude);
    double lonOne = degreesToRadians(longitude);
    double latTwo = degreesToRadians(other.latitude);
    double lonTwo = degreesToRadians(other.longitude);

    double dLat = latTwo - latOne;
    double dLon = lonTwo - lonOne;

    double a = haversine(dLat) + std::cos(latOne) * std::cos(latTwo) * haversine(dLon);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    return EARTH_RADIUS * c;
}