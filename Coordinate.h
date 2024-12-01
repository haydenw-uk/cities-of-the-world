//
// Created by Hayden Williams on 01/12/2024.
//

#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>

class Coordinate {
private:
    // Constants for calculations
    static constexpr double PI = 3.14159265358979323846;
    static constexpr double EARTH_RADIUS = 6371.0; // Earth's radius in kilometers

    double latitude;
    double longitude;


    static double degreesToRadians(double degrees) {
        return degrees * PI / 180.0;
    }


    static double haversine(double angle) {
        return std::sin(angle / 2) * std::sin(angle / 2);
    }

public:
    Coordinate(double lat, double lon);

    double getLatitude() const;


    double getLongitude() const;


    double calculateDistanceTo(const Coordinate &other) const;
};

#endif // COORDINATE_H