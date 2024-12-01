//
// Created by Hayden Williams on 01/12/2024.
//

#ifndef OPERATIONSCONTROLLER_H
#define OPERATIONSCONTROLLER_H

#include <iostream>

class OperationsController {
public:
    // Add a City
    void addCity();

    // Delete a City
    void deleteCity();

    // Update a City
    void updateCity();

    // Search for a City
    void searchCityByName();
    void searchCityByID();

    // Display a single City
    void displayCity();

    // Display all cities
    void displayAllCities();

    // Display a specific field of a City
    void displaySpecificField();

    // Load cities from a file
    void loadCitiesFromFile();

    // Save cities to a file
    void saveCitiesToFile();

    // Calculate distance between two cities
    double calculateDistance();

    // Utility Methods
    int allocateUniqueID();
    void resolveDuplicatedCity();

    // Example static method
    static void staticMethod();


};



#endif //OPERATIONSCONTROLLER_H
