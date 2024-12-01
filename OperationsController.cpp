//
// Created by Hayden Williams on 01/12/2024.
//

#include "OperationsController.h"
#include "City.h"

std::vector<City> OperationsController::cityRecords;

// Add a City
void OperationsController::addCity() {
    // Add a City
    std::cout << "[INFO] Answer the following questions on the city to add." << std::endl;

    // Get City Name
    std::cout << "Enter City Name (e.g. Oxford): " << std::endl;
    std::string cityName;
    std::cin.ignore();
    std::getline(std::cin, cityName);

    // Get City Short History
    std::cout << "Enter Brief History / Description (e.g. Historical university city): " << std::endl;
    std::string cityHistoryBrief;
    std::cin.ignore();
    std::getline(std::cin, cityHistoryBrief);

    // Get City Population
    int cityPopulation;
    std::cout << "Enter City Population (e.g. 1000; in number form): " << std::endl;
    std::cin >> cityPopulation;

    // Get City YearRecorded
    int cityYearRecorded;
    std::cout << "Enter current year (when City was added to program records): " << std::endl;
    std::cin >> cityYearRecorded;

    // Get City Coordinates
    int latitude;
    int longitude;
    // Get latitude
    std::cout << "-City Coordinates-\n" <<"Enter latitude: " << std::endl;
    std::cin >> latitude;
    // Get longitude
    std::cout <<"Enter longitude: " << std::endl;
    std::cin >> longitude;

    // Get City Mayor Fullname
    std::cout << "Enter City Mayor's Fullname (e.g. Mike Rowley) " << std::endl;
    std::string cityMayorFullname;
    std::cin.ignore();
    std::getline(std::cin, cityMayorFullname);

    // Get City Mayor Residences Address
    std::cout << "Enter City Mayor's Residences Address (e.g. Oxford Town Hall, St Aldate's) " << std::endl;
    std::string cityMayorResidencesAddress;
    std::cin.ignore();
    std::getline(std::cin, cityMayorResidencesAddress);

    //TODO Implement validation of inputs before adding new city (not empty, correct data type, not too long)

    /// Add the new city based on input
    std::cout << "Attempting to add : " << cityName << std::endl;

    Coordinate newCityCoordinates(latitude, longitude);
    Mayor newCityMayor(cityMayorFullname, cityMayorResidencesAddress);
    //TODO Implement proper uniqueID mechanism
    int uniqueID = 1;
    City newCity(uniqueID, cityName, cityHistoryBrief, cityPopulation, cityYearRecorded, newCityCoordinates,
                 newCityMayor);

    OperationsController::cityRecords.push_back(newCity);
    std::cout << "Added " << cityName << " SUCCESSFULLY to records." << std::endl;


}

// Delete a City
void OperationsController::deleteCity(const std::vector<City>& cityRecords) {
    // Implementation here
}

// Update a City
void OperationsController::updateCity(const std::vector<City>& cityRecords) {
    // Implementation here
}


// Search for a City
void OperationsController::searchCityByName(const std::string& cityName) {
    // Implementation here
}

void OperationsController::searchCityByID(int cityID) {
    if(cityID == 1) {
        std::cout << "Hello World!" << std::endl;
    }
    // Implementation here
}


// Display a single City
void OperationsController::displayCity(const std::vector<City>& cityRecords) {
    // Implementation here
}

// Display all cities
void OperationsController::displayAllCities() {
    if (cityRecords.size() == 0) {
        std::cout << "[INFO] NO CITIES HAVE BEEN RECORDED. PLEASE ADD A CITY AND TRY AGAIN!" << std::endl;
    }
    for (const auto& city  : cityRecords) {
        std::cout << city.getName() << std::endl;
    }
}

// Display a specific field of a City
void OperationsController::displaySpecificField(const std::vector<City>& cityRecords) {
    // Implementation here
}

// Load cities from a file
void OperationsController::loadCitiesFromFile(std::vector<City>& cityRecords) {
    // Implementation here
}

// Save cities to a file
void OperationsController::saveCitiesToFile(std::vector<City>& cityRecords) {
    // Implementation here
}

// Calculate distance between two cities
double OperationsController::calculateDistance(const std::vector<City>& cityRecords) {
    // Implementation here
    return 0.0;
}

// Utility Methods
int OperationsController::allocateUniqueID(std::vector<City>& cityRecords) {
    // Implementation here
    return 0;
}

void OperationsController::resolveDuplicatedCity(std::vector<City>& cityRecords) {
    // Implementation here
}