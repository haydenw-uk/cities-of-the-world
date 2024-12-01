//
// Created by Hayden Williams on 01/12/2024.
//

#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <cstring>
#include "Coordinate.h"
#include "Mayor.h"

// class City
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



#endif //CITY_H
