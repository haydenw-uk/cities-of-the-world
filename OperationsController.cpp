
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "OperationsController.h"
#include "City.h"

void OperationsController::addCity(std::vector<City>& cityRecords, double latitude, double longitude, const std::string& cityMayorFullname, const std::string& cityMayorResidencesAddress, const std::string& cityName, const std::string& cityHistoryBrief, int cityPopulation, int cityYearRecorded, std::string& cityUsStateOrCountry) {
    // Add the new city based on input
    std::cout << "Attempting to add: " << cityName << std::endl;

    Coordinate newCityCoordinates(latitude, longitude);
    Mayor newCityMayor(cityMayorFullname, cityMayorResidencesAddress);

    City newCity(allocateUniqueID(), cityName, cityHistoryBrief, cityPopulation, cityYearRecorded, cityUsStateOrCountry, newCityCoordinates, newCityMayor);

    cityRecords.push_back(newCity);
    std::cout << "Added " << cityName << " SUCCESSFULLY to records." << std::endl;
}

// Delete a City (by ID)
void OperationsController::deleteCityByID(std::vector<City>& cityRecords, int idToDelete) {
    // Temporary vector to store IDs of deleted cities
    std::vector<int> deletedIDs;

    // Log the attempt to delete city
    std::cout << "[INFO] ATTEMPTING to delete City with ID: " << idToDelete << std::endl;

    // Use std::remove_if to partition the vector and remove matching cities
    auto newEnd = std::remove_if(cityRecords.begin(), cityRecords.end(),
                                 [&](const City& city) -> bool {
                                     if (city.getUniqueID() == idToDelete) {
                                         // Store the ID for availableIDs
                                         deletedIDs.push_back(city.getUniqueID());
                                         std::cout << "[INFO] SUCCESSFULLY DELETED City with ID: "
                                                   << city.getUniqueID() << " and Name: "
                                                   << city.getName() << std::endl;
                                         return true; // Mark for removal
                                     }
                                     return false; // Keep the city
                                 });

    // Calculate how many cities were removed
    size_t numDeleted = std::distance(newEnd, cityRecords.end());

    if (numDeleted > 0) {
        // Erase the removed elements from the vector
        cityRecords.erase(newEnd, cityRecords.end());

        // Add all deleted IDs to the available IDs pool
        availableIDs.insert(availableIDs.end(), deletedIDs.begin(), deletedIDs.end());
    } else {
        std::cout << "[INFO] No city with ID: " << idToDelete << " was found." << std::endl;
    }
}

// Delete a City (by Name)
void OperationsController::deleteCityByName(std::vector<City>& cityRecords, const std::string& nameToDelete) {
    // Temporary vector to store IDs of deleted cities
    std::vector<int> deletedIDs;

    // Log the attempt to delete cities
    std::cout << "[INFO] ATTEMPTING to delete City/Cities with name: " << nameToDelete << std::endl;

    // Use std::remove_if to partition the vector and remove matching cities
    auto newEnd = std::remove_if(cityRecords.begin(), cityRecords.end(),
                                 [&](const City& city) -> bool {
                                     if (city.getName() == nameToDelete) {
                                         // Store the ID for availableIDs
                                         deletedIDs.push_back(city.getUniqueID());
                                         std::cout << "[INFO] SUCCESSFULLY DELETED City with ID: "
                                                   << city.getUniqueID() << " and Name: "
                                                   << city.getName() << std::endl;
                                         return true; // Mark for removal
                                     }
                                     return false; // Keep the city
                                 });

    // Calculate how many cities were removed
    size_t numDeleted = std::distance(newEnd, cityRecords.end());

    if (numDeleted > 0) {
        // Erase the removed elements from the vector
        cityRecords.erase(newEnd, cityRecords.end());

        // Add all deleted IDs to the available IDs pool
        availableIDs.insert(availableIDs.end(), deletedIDs.begin(), deletedIDs.end());
    } else {
        std::cout << "[INFO] No city with name: " << nameToDelete << " was found." << std::endl;
    }
}

// Update a City's information
void OperationsController::updateCity(std::vector<City>& cityRecords, const int updateFieldID, const int cityToUpdateID) {
    //TODO Implement input validation here
    switch(updateFieldID) {
        case 1: {
            // Update City Name field
            std::string newCityName;
            std::cout << "Enter city name to update to: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, newCityName);
            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update " << item->getName()  << std::endl;
                    item->setName(newCityName);
                    std::cout << "[INFO] SUCCESSFULLY updated city name to " << item->getName()  << std::endl;
                }
            }
            break;
        }

        case 2: {
            // Update City HistoryBrief field
            std::string newCityHistoryBrief;
            std::cout << "Enter history brief / description to update to: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, newCityHistoryBrief);
            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update " << item->getName()  << std::endl;
                    item->setHistoryBrief(newCityHistoryBrief);
                    std::cout << "[INFO] SUCCESSFULLY updated city brief history / description. " << std::endl;
                }
            }
            break;
        }

        case 3: {
            // Update City Population field
            int newCityPopulation;
            std::cout << "Enter city population to update to: " << std::endl;
            std::cin >> newCityPopulation;
            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update " << item->getName()  << std::endl;
                    item->setPopulation(newCityPopulation);
                    std::cout << "[INFO] SUCCESSFULLY updated city population. " << std::endl;
                }
            }
            break;
        }

        case 4: {
            // Update City Year Recorded field
            int newCityYearRecorded;
            std::cout << "Enter city year recorded in system to update to: " << std::endl;
            std::cin >> newCityYearRecorded;
            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update " << item->getName()  << std::endl;
                    item->setYearRecorded(newCityYearRecorded);
                    std::cout << "[INFO] SUCCESSFULLY updated city's year recorded. " << std::endl;
                }
            }
            break;
        }

        case 5: {
            // Update City US State / Country field
            std::string newCityUsCountry;
            std::cout << "Enter Country / US State to update to: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, newCityUsCountry);
            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update " << item->getName()  << std::endl;
                    item->setUsStateOrCountry(newCityUsCountry);
                    std::cout << "[INFO] SUCCESSFULLY updated Country / US State of city. " << std::endl;
                }
            }
            break;
        }
        case 6: {
            // Update City Coordinates - Latitude
            double newCityCoordinatesLat;
            std::cout << "Enter city coordinate latitude: " << std::endl;
            std::cin >> newCityCoordinatesLat;
            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update " << item->getName()  << std::endl;

                    Coordinate currentCoordinates = item->getCoordinates();
                    Coordinate updatedCoordinates(newCityCoordinatesLat, currentCoordinates.getLongitude());
                    item->setCoordinates(updatedCoordinates);

                    std::cout << "[INFO] SUCCESSFULLY updated city's coordinates. " << std::endl;
                }
            }
            break;
        }

        case 7: {
            // Update City Coordinates - Longitude
            double newCityCoordinatesLong;
            std::cout << "Enter city coordinate longitude: " << std::endl;
            std::cin >> newCityCoordinatesLong;
            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update " << item->getName()  << std::endl;

                    Coordinate currentCoordinates = item->getCoordinates();
                    Coordinate updatedCoordinates(currentCoordinates.getLatitude(), newCityCoordinatesLong);
                    item->setCoordinates(updatedCoordinates);

                    std::cout << "[INFO] SUCCESSFULLY updated city's coordinates. " << std::endl;
                }
            }
            break;
        }

        case 8: {
            // // Update City Mayor Name
            std::string newCityMayorName;
            std::cout << "Enter city new mayor name: " << std::endl;

            std::cin.ignore();
            std::getline(std::cin, newCityMayorName);

            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update mayor name of " << item->getName()  << std::endl;


                    Mayor currentMayor = item->getMayor();
                    Mayor updatedMayor(newCityMayorName, currentMayor.getResidenceAddress());
                    item->setMayor(updatedMayor);

                    std::cout << "[INFO] SUCCESSFULLY updated city mayor's name." << std::endl;
                }
            }
            break;
        }

        case 9: {
            // Update City Mayor Official Residences Address
            std::string newCityMayorResidenceAddress;
            std::cout << "Enter city new mayor residences address: " << std::endl;

            std::cin.ignore();
            std::getline(std::cin, newCityMayorResidenceAddress);

            for(auto item = cityRecords.begin(); item != cityRecords.end(); item++) {
                if(item->getUniqueID() == cityToUpdateID) {
                    std::cout << "[INFO] Attempting to update mayor residences address of " << item->getName()  << std::endl;

                    Mayor currentMayor = item->getMayor();
                    Mayor updatedMayor(currentMayor.getName(), newCityMayorResidenceAddress);
                    item->setMayor(updatedMayor);

                    std::cout << "[INFO] SUCCESSFULLY updated city mayor's official residences address." << std::endl;
                }
            }
            break;
        }

    }
}


// Search for a City
int OperationsController::searchCityByName(std::vector<City>& cityRecords, const std::string& cityName) {
    bool cityFound = false;
    std::cout << "--VIEW CITY INFORMATION--" << std::endl;
    for (const auto& city  : cityRecords) {
        if(city.getName() == cityName) {
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
            return city.getUniqueID();
        }
    }
    if(!cityFound) {
        std::cout << "No city with Name : " << cityName << " was found." << std::endl;
    }
    return -1;
}

int OperationsController::searchCityByID(std::vector<City>& cityRecords, int cityID) {
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
            return city.getUniqueID();
        }
    }
    if(!cityFound) {
        std::cout << "No city with ID : " << cityID << " was found." << std::endl;
    }
    return -1;
}

// Display all cities
void OperationsController::displayAllCities(std::vector<City>& cityRecords) {
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

void OperationsController::outputSpecificCityFieldSortedByField(const std::vector<City>& cityRecords, int fieldDisplayID) {
    std::cout << "\n-*- SORTED CITY NAMES -*- " << std::endl;
    switch (fieldDisplayID) {
        default:
            std::cout << "[ERROR] An error occurred. Exiting now to main menu ..." << fieldDisplayID << std::endl;
            break;
        case 1: {
            // City Name
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getName() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }

        case 2: {
            // City Brief Description / History
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getHistoryBrief() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }

        case 3: {
            // City Population
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getPopulation() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }

        case 4: {
            // City Year Recorded
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getYearRecorded() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }

        case 5: {
            // City Year Recorded
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getYearRecorded() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }

        case 6: {
            // City Coordinates (Latitude)
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getCoordinates().getLatitude() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }

        case 7: {
            // City Coordinates (Longitude)
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getCoordinates().getLongitude() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }

        case 8: {
            // City Mayor Name
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getMayor().getName() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }

        case 9: {
            // City Mayor Official Residences Address
            for (size_t k = 0; k < cityRecords.size(); k++) {
                std::cout << cityRecords.at(k).getMayor().getResidenceAddress() << " (CityID:" << cityRecords.at(k).getUniqueID() << "" << ")" << std::endl;
            }
            break;
        }
    }

}

// Display a specific field of a City
void OperationsController::displaySpecificField(const std::vector<City>& cityRecords, const int fieldToDisplayID, const std::string& sortDirection) {
    if (cityRecords.empty()) {
        std::cout << "[INFO] No cities recorded. Please add cities and try again!" << std::endl;
        return;
    }

    // Copy cityRecords to temporary vector structure for sorting
    std::vector<City> sortedRecords = cityRecords;

    // Manual Bubble Sort algorithm
    bool ascending = false;
    if (sortDirection == "asc") {
        ascending = true;
    }
    else {
        ascending = false;
    }
    for (size_t i = 0; i < sortedRecords.size(); i++) {
        bool swapped = false; // To optimize and break early if no swaps occur
        for (size_t j = 0; j < sortedRecords.size() - i - 1; j++) { // Reduce the inner loop range
            bool shouldSwap = false;

            switch (fieldToDisplayID) {
                case 1: { // City Name
                    shouldSwap = ascending ?
                        (sortedRecords[j].getName() > sortedRecords[j + 1].getName()) :
                        (sortedRecords[j].getName() < sortedRecords[j + 1].getName());
                    break;
                }
                case 2: { // City Brief Description / History
                    shouldSwap = ascending ?
                        (sortedRecords[j].getHistoryBrief() > sortedRecords[j + 1].getHistoryBrief()) :
                        (sortedRecords[j].getHistoryBrief() < sortedRecords[j + 1].getHistoryBrief());
                    break;
                }
                case 3: { // City Population
                    shouldSwap = ascending ?
                        (sortedRecords[j].getPopulation() > sortedRecords[j + 1].getPopulation()) :
                        (sortedRecords[j].getPopulation() < sortedRecords[j + 1].getPopulation());
                    break;
                }
                // ... handle other cases similarly
                default: {
                    std::cout << "[INFO] Invalid field ID for sorting." << std::endl;
                    return;
                }
            }

            if (shouldSwap) {
                std::swap(sortedRecords[j], sortedRecords[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // No swaps means the vector is already sorted
        }
    }
    // Determine type of sort, Output relevant field
    outputSpecificCityFieldSortedByField(sortedRecords, fieldToDisplayID);

}

// Load cities from a file
void OperationsController::loadCitiesFromFile(std::vector<City>& cityRecords, const std::string& fileNameToLoad) {
    // Open file

    std::ifstream loadFile(fileNameToLoad);
    if (!loadFile.is_open()) {
        std::cerr << "File not found OR cannot be opened: " << fileNameToLoad << std::endl;
        return;
    }

    for (std::string line; std::getline(loadFile, line);) {
        std::istringstream ss(line);

        std::string cityName, cityHistoryBrief, cityPopulation, cityYearRecorded, cityUsStateOrCountry, cityCoordinateLat, cityCoordinateLong, cityMayorName, cityMayorResidenceAddress;

        // Split current line by commas
        if (std::getline(ss, cityName, ',') &&
            std::getline(ss, cityHistoryBrief, ',') &&
            std::getline(ss, cityPopulation, ',') &&
            std::getline(ss, cityYearRecorded, ',') &&
            std::getline(ss, cityUsStateOrCountry, ',') &&
            std::getline(ss, cityCoordinateLat, ',') &&
            std::getline(ss, cityCoordinateLong, ',') &&
            std::getline(ss, cityMayorName, ',') &&
            std::getline(ss, cityMayorResidenceAddress, ','))
            {
                Coordinate newCityCoordinates(std::stod(cityCoordinateLat), std::stod(cityCoordinateLong));
                Mayor newCityMayor(cityMayorName, cityMayorResidenceAddress);

                City newCity(allocateUniqueID(), cityName, cityHistoryBrief, std::stoi(cityPopulation), std::stoi(cityYearRecorded), cityUsStateOrCountry, newCityCoordinates, newCityMayor);

                cityRecords.push_back(newCity);
                std::cout << "[INFO] " << cityName << " loaded SUCCESSFULLY from file ..." << std::endl;
            }

    }

}

// Save cities to a file
void OperationsController::saveCitiesToFile(const std::vector<City>& cityRecords, const std::string& fileNameToSave) {
    // Open file for writing
    std::ofstream saveFile(fileNameToSave);
    if (!saveFile.is_open()) {
        std::cerr << "Error: Could not open cities file for saving " << fileNameToSave << std::endl;
        return;
    }

    // Iterate through city records and write to file
    for (const auto& city : cityRecords) {
        saveFile << city.getName() << ","
                 << city.getHistoryBrief() << ","
                 << city.getPopulation() << ","
                 << city.getYearRecorded() << ","
                 << city.getUsStateOrCountry() << ","
                 << city.getCoordinates().getLatitude() << ","
                 << city.getCoordinates().getLongitude() << ","
                 << city.getMayor().getName() << ","
                 << city.getMayor().getResidenceAddress()
                 << "\n";

        std::cout << "[INFO] " << city.getName() << " was saved SUCCESSFULLY ..." << std::endl;
    }
}
double OperationsController::calculateDistanceBetweenCities(std::vector<City>& cityRecords, const std::string& cityNameOne, const std::string& cityNameTwo) {
    try {
        // Search for the first city by name
        auto cityOneItem = std::find_if(cityRecords.begin(), cityRecords.end(), [&cityNameOne](const City& city) {
            return city.getName() == cityNameOne;
        });

        // Check if the first city was found
        if (cityOneItem == cityRecords.end()) {
            throw std::runtime_error("City not found: " + cityNameOne);
        }

        // Search for the second city by name
        auto cityTwoItem = std::find_if(cityRecords.begin(), cityRecords.end(), [&cityNameTwo](const City& city) {
            return city.getName() == cityNameTwo;
        });

        // Check if the second city was found
        if (cityTwoItem == cityRecords.end()) {
            throw std::runtime_error("City not found: " + cityNameTwo);
        }

        // Calculate and return the distance
        return cityOneItem->getCoordinates().calculateDistanceTo(cityTwoItem->getCoordinates());
    } catch (const std::exception& e) {
        // Log the error and return a default value
        std::cerr << "Error calculating distance: " << e.what() << std::endl;
        return -1.0; // Indicates an error
    }
}


// ID-related methods for cities
int OperationsController::allocateUniqueID() {
    if(!availableIDs.empty()) {
        int id = availableIDs.back();
        availableIDs.pop_back();
        return id;
    }
    return ++currentID;
}

void OperationsController::releaseUniqueID(int idToRelease) {
    // Release ID back into ID pool
    availableIDs.push_back(idToRelease);
}

void OperationsController::resolveDuplicatedCities(std::vector<City>& cityRecords) {
    // Iterate over city records
    for (size_t i = 0; i < cityRecords.size(); i++) {
        for (size_t j = i + 1; j < cityRecords.size(); j++) {
            const City& firstCity = cityRecords[i];
            const City& secondCity = cityRecords[j];

            if (firstCity.getName() == secondCity.getName() &&
                firstCity.getUsStateOrCountry() == secondCity.getUsStateOrCountry()) {
                std::cout << "[INFO] Duplicate detected (EXACT city name and US State/Country match)...\n[INFO] REMOVING " << secondCity.getName() << " with ID " << secondCity.getUniqueID() << std::endl;

                // Duplicate second city removed from records
                cityRecords.erase(cityRecords.begin() + j);

                // ID of removed city released back into pool of available IDs for future use
                releaseUniqueID(secondCity.getUniqueID());

                // IMPORTANT! Decrement essential to ensure the next entry check is not skipped!
                j -= 1;
            }
        }
    }
}