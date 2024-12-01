#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <cstring>
#include "Coordinate.h"
#include "Mayor.h"

class City {
private:
    int uniqueId;
    char* name;
    uint32_t population;
    uint16_t yearRecorded;
    Coordinate coordinates;
    Mayor mayor;

public:
    // Constructor
    City(const int uniqueID, const char* a_name, uint32_t a_population, uint16_t a_yearRecorded, const Coordinate& a_coordinates, const Mayor& a_mayor);

    // Destructor
    ~City();

    // GETTER Methods
    uint32_t getUniqueID() const;
    const char* getName() const;
    uint32_t getPopulation() const;
    uint16_t getYearRecorded() const;
    const Coordinate& getCoordinates() const;
    const Mayor& getMayor() const;

    // SETTER Methods
    void setUniqueID(const int uniqueID);
    void setName(const char* a_name);
    void setPopulation(const uint32_t a_population);
    void setCoordinates(const Coordinate& a_coordinates);
    void setMayor(const Mayor& a_mayor);
};

#endif //CITY_H