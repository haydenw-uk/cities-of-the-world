
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

    static double degreesToRadians(double degrees);
    static double haversine(double angle);

public:
    Coordinate(double lat, double lon);

    double getLatitude() const;
    double getLongitude() const;

    double calculateDistanceTo(const Coordinate &other) const;
};

#endif // COORDINATE_H