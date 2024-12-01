//
// Created by Hayden Williams on 01/12/2024.
//

#include "City.h"

// Constructor
City::City(const int uniqueID, const std::string& a_name, const std::string& a_historyBrief,
           uint32_t a_population, uint16_t a_yearRecorded, const Coordinate& a_coordinates,
           const Mayor& a_mayor)
    : uniqueId(uniqueID),
      name(a_name),
      historyBrief(a_historyBrief),
      population(a_population),
      yearRecorded(a_yearRecorded),
      coordinates(a_coordinates),
      mayor(a_mayor) {}

// Getter Methods
int City::getUniqueID() const {
    return uniqueId;
}

const std::string& City::getName() const {
    return name;
}

const std::string& City::getHistoryBrief() const {
    return historyBrief;
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

// Setter Methods
void City::setName(const std::string& a_name) {
    name = a_name;
}

void City::setHistoryBrief(const std::string& a_historyBrief) {
    historyBrief = a_historyBrief;
}

void City::setPopulation(uint32_t a_population) {
    population = a_population;
}

void City::setCoordinates(const Coordinate& a_coordinates) {
    coordinates = a_coordinates;
}

void City::setMayor(const Mayor& a_mayor) {
    mayor = a_mayor;
}