//
// Created by Hayden Williams on 01/12/2024.
//

#ifndef OPERATIONSCONTROLLER_H
#define OPERATIONSCONTROLLER_H

#include <iostream>

class OperationsController {
public:
    // Add a City
    static void addCity();

    // Delete a City
    static void deleteCity();

    // Update a City
    static void updateCity();

    // Search for a City
    static void searchCityByName();
    static void searchCityByID();

    // Display a single City
    static void displayCity();

    // Display all cities
    static void displayAllCities();

    // Display a specific field of a City
    static void displaySpecificField();

    // Load cities from a file
    static void loadCitiesFromFile();

    // Save cities to a file
    static void saveCitiesToFile();

    // Calculate distance between two cities
    static double calculateDistance();

    // Utility Methods
    static int allocateUniqueID();
    static void resolveDuplicatedCity();


};



#endif //OPERATIONSCONTROLLER_H
