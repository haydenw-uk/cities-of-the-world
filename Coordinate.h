
#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>

class Coordinate {
private:
    // Constants for calculations

    // 'constexpr' used because it can be evaluated at
    // compile time (quicker)
    static constexpr double PI = 3.14159265358979323846;
    static constexpr double EARTH_RADIUS = 6371.0; // Earth's radius in kilometers

    static double degreesToRadians(double degrees);
    static double haversine(double angle);

    double latitude;
    double longitude;

public:
    Coordinate(double lat, double lon);

    double getLatitude() const;
    double getLongitude() const;

    void setLatitude(double newLatitude);
    void setLongitude(double newLongitude);

    double calculateDistanceTo(const Coordinate &other) const;


};

#endif // COORDINATE_H