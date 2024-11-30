//
// Created by Hayden Williams on 18/10/2024.
//

#include <iostream>
#include <cstring>

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

// class Mayor
class Mayor {
private:
    std::string name;
    std::string residenceAddress;
public:
    // Constructor
    Mayor(const std::string& a_name, const std::string& a_residenceAddress)
        : name(a_name), residenceAddress(a_residenceAddress) {}

    const std::string& getName() const {return name;}
    const std::string& getResidenceAddress() const {return residenceAddress;}
};

class City {
private:
    char* name;
    uint32_t population;
    uint16_t yearRecorded;
    Coordinate coordinates;
    Mayor mayor;

    // TODO Implement Mayor class
public:
    // Constructor
    City(const char* a_name, uint32_t a_population, uint16_t a_yearRecorded, const Coordinate& a_coordinates, const Mayor& a_mayor): coordinates(a_coordinates), mayor(a_mayor) {
        this->name = new char[strlen(a_name) + 1];
        strcpy(this->name, a_name);
        population = a_population;
        yearRecorded = a_yearRecorded;
    }

    // Destructor
    ~City() {
        delete[] name;
    }

    // GETTER Methods
    const char* getName() const {return name;}
    const uint32_t getPopulation() const {return population;}
    const uint16_t getYearRecorded() const {return yearRecorded;}

    // SETTER Methods


};

// Cities - Distance Calculation Program

int main() {
    //Coordinate londonEngland(51.5072, -0.1276);

    Coordinate oxfordCoordinates(51.7520, -1.2577);
    Mayor oxfordMayor("Alice Bob", "City Hall");

    City city("Oxford", 30000, 2024, oxfordCoordinates, oxfordMayor);
    std::cout << city.getName() << oxfordMayor.getName() << std::endl;

    // double distance = londonEngland.calculateDistanceTo(oxfordEngland);
    //
    // std::cout << "The distance between London, England and Oxford, England is "
    //          << distance << " km." << std::endl;
    //
    // City exampleCity("Oxford", 3000, 2024);
    // std::cout << exampleCity.getName() << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}