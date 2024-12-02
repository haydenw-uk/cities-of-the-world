//
// Created by Hayden Williams on 01/12/2024.
//

#include "OperationsController.h"
#include "City.h"

std::vector<City> OperationsController::cityRecords;

void OperationsController::addCity() {
    // Add a City
    std::cout << "[INFO] Answer the following questions on the city to add." << std::endl;

    // Clear any leftover input before starting
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get City Name
    std::cout << "Enter City Name (e.g. Oxford): " << std::endl;
    std::string cityName;
    std::getline(std::cin, cityName);

    // Get City Short History
    std::cout << "Enter Brief History / Description (e.g. Historical university city): " << std::endl;
    std::string cityHistoryBrief;
    std::getline(std::cin, cityHistoryBrief);

    // Get City Population
    int cityPopulation;
    std::cout << "Enter City Population (e.g. 1000; in number form): " << std::endl;
    std::cin >> cityPopulation;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer

    // Get City Year Recorded
    int cityYearRecorded;
    std::cout << "Enter current year (when City was added to program records): " << std::endl;
    std::cin >> cityYearRecorded;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer

    // Get City US State / Country Recorded
    std::cout << "Enter City Country OR State if located in the United States: " << std::endl;
    std::string cityUsStateOrCountry;
    std::getline(std::cin, cityUsStateOrCountry);

    // Get City Coordinates
    int latitude;
    int longitude;
    // Get latitude
    std::cout << "-City Coordinates-\n" << "Enter latitude: " << std::endl;
    std::cin >> latitude;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
    // Get longitude
    std::cout << "Enter longitude: " << std::endl;
    std::cin >> longitude;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer

    // Get City Mayor Fullname
    std::cout << "Enter City Mayor's Fullname (e.g. Mike Rowley): " << std::endl;
    std::string cityMayorFullname;
    std::getline(std::cin, cityMayorFullname);

    // Get City Mayor Residence Address
    std::cout << "Enter City Mayor's Residence Address (e.g. Oxford Town Hall, St Aldate's): " << std::endl;
    std::string cityMayorResidencesAddress;
    std::getline(std::cin, cityMayorResidencesAddress);

    // TODO: Implement validation of inputs before adding new city (not empty, correct data type, not too long)

    // Add the new city based on input
    std::cout << "Attempting to add: " << cityName << std::endl;

    Coordinate newCityCoordinates(latitude, longitude);
    Mayor newCityMayor(cityMayorFullname, cityMayorResidencesAddress);

    int uniqueID = allocateUniqueID();

    City newCity(uniqueID, cityName, cityHistoryBrief, cityPopulation, cityYearRecorded, cityUsStateOrCountry, newCityCoordinates, newCityMayor);

    OperationsController::cityRecords.push_back(newCity);
    std::cout << "Added " << cityName << " SUCCESSFULLY to records." << std::endl;
}

// Delete a City (by ID)
void OperationsController::deleteCityByID(int idToDelete) {
    bool cityFound = false;
    for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
        if(item->getUniqueID() == idToDelete) {
            //TODO Implement validation this action was a success
            std::cout << "[INFO] ATTEMPTING to delete City with ID: " << item->getName() << std::endl;
            cityRecords.erase(item);
            cityFound = true;
            std::cout << "[INFO] SUCCESSFULLY DELETED City with ID : " << item->getUniqueID() << std::endl;
            static std::vector<int> avaliableIDs;
            avaliableIDs.push_back(idToDelete);
            break;
        }
    }
    if(!cityFound) {
        std::cout << "CANNOT DELETE! No city exists with ID : " << idToDelete << " was found..." << std::endl;
    }
}

// Delete a City (by Name)
void OperationsController::deleteCityByName(std::string nameToDelete) {
    // TODO Rework this to check for duplicates before it removes and rework removal mechanism ensuring ID is added back to pool
    bool cityFound = false;

    for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
        if(item->getName() == nameToDelete) {
            cityRecords.erase(item);
            cityFound = true;
            std::cout << "Deleted city with ID : " << item->getUniqueID() << std::endl;
            static std::vector<int> avaliableIDs;
            //avaliableIDs.push_back(name);
            break;
        }
    }
    if(!cityFound) {
        //std::cout << "No city with ID : " << idToDelete << " was found." << std::endl;
    }
}

// Update a City's information
void OperationsController::updateCity(const int updateFieldID) {
    //TODO Comment this method
    // TODO Implementation
}


// Search for a City
void OperationsController::searchCityByName(const std::string& cityName) {
    // TODO Implementation
}

void OperationsController::searchCityByID(int cityID) {
    bool cityFound = false;
    std::cout << "--VIEW CITY INFORMATION--" << std::endl;
    for (const auto& city  : cityRecords) {
        if(city.getUniqueID() == cityID) {
            cityFound = true;
            std::cout << city.getName() << " (" << city.getUniqueID() << ")" << std::endl;
            std::cout << "\tCountry / US State: " << city.getUsStateOrCountry() << std::endl;
            std::cout << "\tBrief History / Description: " << city.getHistoryBrief() << std::endl;
            std::cout << "\tPopulation: " << city.getPopulation() << std::endl;
            std::cout << "\tYear Recorded In Program: " << city.getYearRecorded() << std::endl;
            std::cout << "\tCoordinates: " << city.getCoordinates().getLatitude() << ", " << city.getCoordinates().getLongitude() << std::endl;

            std::cout << "\t-Mayor- "<< std::endl;
            std::cout << "\t\tFull Name: " << city.getMayor().getName() << std::endl;
            std::cout << "\t\tOfficial Address: " << city.getMayor().getResidenceAddress() << "\n--" << std::endl;
        }
    }
    if(!cityFound) {
        std::cout << "No city with ID : " << cityID << " was found." << std::endl;
    }
}


// Display a single City - TODO METHOD REDUNDANT; REMOVE
void OperationsController::displayCityByID(int cityID) {
    //TODO Rework this to spec requirement ...
    // Display a part or all of the information stored, e.g. just the coordinates, or the
    // name of the Mayor, etc.
    // The user needs to have the option to select/ specify the field which to display
}


// Display all cities
void OperationsController::displayAllCities() {
    if (cityRecords.size() == 0) {
        std::cout << "[INFO] NO CITIES HAVE BEEN RECORDED. PLEASE ADD A CITY AND TRY AGAIN!" << std::endl;
    }
    std::cout << "--VIEW ALL RECORDED CITIES--" << std::endl;
    for (const auto& city  : cityRecords) {
        std::cout << city.getName() << " (" << city.getUniqueID() << ")" << std::endl;
        std::cout << "\tCountry / US State: " << city.getUsStateOrCountry() << std::endl;
        std::cout << "\tBrief History / Description: " << city.getHistoryBrief() << std::endl;
        std::cout << "\tPopulation: " << city.getPopulation() << std::endl;
        std::cout << "\tYear Recorded In Program: " << city.getYearRecorded() << std::endl;
        std::cout << "\tCoordinates: " << city.getCoordinates().getLatitude() << ", " << city.getCoordinates().getLongitude() << std::endl;

        std::cout << "\t-Mayor- "<< std::endl;
        std::cout << "\t\tFull Name: " << city.getMayor().getName() << std::endl;
        std::cout << "\t\tOfficial Address: " << city.getMayor().getResidenceAddress() << "\n--" << std::endl;

    }
}


// Display a specific field of a City
void OperationsController::displaySpecificField(const std::vector<City>& cityRecords) {
    // TODO Implementation
}

// Load cities from a file
void OperationsController::loadCitiesFromFile(std::vector<City>& cityRecords) {
    // TODO Implementation
}

// Save cities to a file
void OperationsController::saveCitiesToFile(std::vector<City>& cityRecords) {
    // TODO Implementation
}

// Calculate distance between two cities
double OperationsController::calculateDistance(const std::vector<City>& cityRecords) {
    // TODO Implementation
    return 0.0;
}

// Utility Methods
int OperationsController::allocateUniqueID() {
    static int currentID = 0;
    static std::vector<int> avaliableIDs;

    if(!avaliableIDs.empty()) {
        int id = avaliableIDs.back();
        avaliableIDs.pop_back();
        return id;
    }
    currentID++;
    return currentID;
}

void OperationsController::resolveDuplicatedCity(std::vector<City>& cityRecords) {
    // TODO Implementation
}