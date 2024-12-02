#ifndef OPERATIONSCONTROLLER_H
#define OPERATIONSCONTROLLER_H

#include <iostream>
#include <vector>
#include "City.h"

class OperationsController {
public:
    // Add a City
    void addCity(std::vector<City>& cityRecords);

    // Delete a City
    void deleteCityByID(std::vector<City>& cityRecords, int id);
    void deleteCityByName(std::vector<City>& cityRecords, const std::string name);

    // Update a City
    void updateCity(const int updateFieldID);

    // Search for a City
    void searchCityByName(std::vector<City>& cityRecords, const std::string& cityName);
    void searchCityByID(std::vector<City>& cityRecords, const int cityID);

    // Display all cities
    void displayAllCities(std::vector<City>& cityRecords);

    // Display a specific field of a City
    void displaySpecificField(const std::vector<City>& cityRecords);

    // Load cities from a file
    void loadCitiesFromFile(std::vector<City>& cityRecords);

    // Save cities to a file
    void saveCitiesToFile(std::vector<City>& cityRecords);

    // Calculate distance between two cities
    double calculateDistanceBetweenCities(std::vector<City>& cityRecords, const std::string& cityNameOne, const std::string& cityNameTwo);

    // Utility Methods
    int allocateUniqueID();
    void resolveDuplicatedCity(std::vector<City>& cityRecords);


};



#endif //OPERATIONSCONTROLLER_H
