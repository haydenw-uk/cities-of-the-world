//
// Created by Hayden Williams on 01/12/2024.
//

#include "City.h"

// Constructor
City::City(const int uniqueID, const char* a_name, uint32_t a_population, uint16_t a_yearRecorded, const Coordinate& a_coordinates, const Mayor& a_mayor)
    : uniqueId(uniqueID), coordinates(a_coordinates), mayor(a_mayor) {
    name = new char[strlen(a_name) + 1];
    strcpy(name, a_name);
    population = a_population;
    yearRecorded = a_yearRecorded;
}

// Destructor
City::~City() {
    delete[] name;
}

// GETTER Methods
uint32_t City::getUniqueID() const {
    return uniqueId;
}

const char* City::getName() const {
    return name;
}

uint32_t City::getPopulation() const {
    return population;
}

uint16_t City::getYearRecorded() const {
    return yearRecorded;
}

const Coordinate& City::getCoordinates() const {
    return coordinates;
}

const Mayor& City::getMayor() const {
    return mayor;
}

// SETTER Methods
void City::setUniqueID(const int uniqueID) {
    uniqueId = uniqueID;
}

void City::setName(const char* a_name) {
    delete[] name;
    name = new char[strlen(a_name) + 1];
    strcpy(name, a_name);
}

void City::setPopulation(const uint32_t a_population) {
    population = a_population;
}

void City::setCoordinates(const Coordinate& a_coordinates) {
    coordinates = Coordinate(a_coordinates);
}

void City::setMayor(const Mayor& a_mayor) {
    mayor = a_mayor;
}