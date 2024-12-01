#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <cstring>
#include "Coordinate.h"
#include "Mayor.h"

class City {
private:
    int uniqueId;
    std::string name;
    std::string historyBrief;
    uint32_t population;
    uint16_t yearRecorded;
    Coordinate coordinates;
    Mayor mayor;

public:
    // Constructor
    City(const int uniqueID, const std::string& a_name, const std::string& a_historyBrief,
         uint32_t a_population, uint16_t a_yearRecorded, const Coordinate& a_coordinates,
         const Mayor& a_mayor);

    // Destructor
    ~City() = default;

    // GETTER Methods
    int getUniqueID() const;
    const std::string& getName() const;        // Return C-style string for name
    const std::string& getHistoryBrief() const; // Return C-style string for historyBrief
    uint32_t getPopulation() const;
    uint16_t getYearRecorded() const;
    const Coordinate& getCoordinates() const;
    const Mayor& getMayor() const;

    // SETTER Methods
    void setName(const std::string& a_name);
    void setHistoryBrief(const std::string& a_historyBrief);
    void setPopulation(uint32_t a_population);
    void setCoordinates(const Coordinate& a_coordinates);
    void setMayor(const Mayor& a_mayor);
};

#endif //CITY_H