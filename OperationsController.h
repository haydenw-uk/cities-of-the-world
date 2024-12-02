//
// Created by Hayden Williams on 01/12/2024.
//

#ifndef OPERATIONSCONTROLLER_H
#define OPERATIONSCONTROLLER_H

#include <iostream>
#include <vector>
#include "City.h"

class OperationsController {
private:
    static std::vector<City> cityRecords;
public:
    // Add a City
    void addCity();

    // Delete a City
    void deleteCityByID(int id);
    void deleteCityByName(std::string name);

    // Update a City
    void updateCity(const int updateFieldID);

    // Search for a City
    void searchCityByName(const std::string& cityName);
    void searchCityByID(const int cityID);

    // Display all cities
    void displayAllCities();

    // Display a specific field of a City
    void displaySpecificField(const std::vector<City>& cityRecords);

    // Load cities from a file
    void loadCitiesFromFile(std::vector<City>& cityRecords);

    // Save cities to a file
    void saveCitiesToFile(std::vector<City>& cityRecords);

    // Calculate distance between two cities
    double calculateDistanceBetweenCities(const std::string& cityNameOne, const std::string& cityNameTwo);

    // Utility Methods
    int allocateUniqueID();
    void resolveDuplicatedCity(std::vector<City>& cityRecords);


};



#endif //OPERATIONSCONTROLLER_H
