//
// Created by Hayden Williams on 01/12/2024.
//

#ifndef COORDINATE_H
#define COORDINATE_H



// class Coordinate
class Coordinate {
private:
    const double PI = 3.14159265358979323846;
    const double EARTH_RADIUS = 6371.0; // Earth's radius in kilometers

    double latitude;
    double longitude;

    double degreesToRadians(double degrees) const {
        return degrees * PI / 180.0;
    }

    double haversine(double angle) const {
        return sin(angle / 2) * sin(angle / 2);
    }

public:
    Coordinate(double lat, double lon) : latitude(lat), longitude(lon) {}

    double getLatitude() const {return latitude;}
    double getLongitude() const {return longitude;}

    double calculateDistanceTo(const Coordinate &other) const {
        double latOne = degreesToRadians(latitude);
        double lonOne = degreesToRadians(longitude);
        double latTwo = degreesToRadians(other.latitude);
        double longTwo = degreesToRadians(other.longitude);

        double dLat = latTwo - latOne;
        double dLong = longTwo - lonOne;

        double a = haversine(dLat) + cos(latOne) * cos(latTwo) * haversine(dLong);
        double c = 2 * atan2(sqrt(a), sqrt(1 - a));

        return EARTH_RADIUS * c;
    }
};



#endif //COORDINATE_H
