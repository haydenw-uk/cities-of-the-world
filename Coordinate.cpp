
#include "Coordinate.h"

#include <iostream>
#include <ostream>

Coordinate::Coordinate(double lat, double lon) : latitude(lat), longitude(lon) {}


double Coordinate::getLatitude() const {
    return latitude;
}

double Coordinate::getLongitude() const {
    return longitude;
}

double Coordinate::degreesToRadians(double angles) {
    return angles * PI / 180.0;
}

double Coordinate::haversine(double angle) {
    return std::sin(angle / 2) * std::sin(angle / 2);
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