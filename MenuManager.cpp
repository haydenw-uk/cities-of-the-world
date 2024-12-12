#include "MenuManager.h"
#include <iostream>
#include "OperationsController.h"

/// -- Important Implementation Notes from Author --
/// This class is solely for displaying menu options to the user, taking user input and related input validation
/// Operations on data must not be implemented here, use OperationsController.

void MenuManager::displayMainMenu() {
    std::cout << "\n-- MAIN MENU --\n" << std::endl;
    std::cout << "1. Add a new city\n" <<std::endl;
    std::cout << "2. Delete a city\n" <<std::endl;
    std::cout << "3. Search for a city, Update city fields\n" <<std::endl;
    std::cout << "4. Display all / cities, Specific city fields\n" <<std::endl;
    std::cout << "5. Calculate distance between two cities\n" <<std::endl;
    std::cout << "6. Save\n" <<std::endl;
    std::cout << "7. Exit\n" <<std::endl;
    std::cout << "*******************" <<std::endl;
    std::cout << "Enter your choice: " <<std::endl;
}

void MenuManager::displaySearchOptionsMenu() {
    std::cout << "-- SEARCH MENU --" <<std::endl;
    std::cout << "1. Search by City ID\n" <<std::endl;
    std::cout << "2. Search by City Name\n" <<std::endl;
    std::cout << "Enter your choice: " <<std::endl;
};

void MenuManager::displayDeleteByOptionsMenu() {
    std::cout << "-- DELETE MENU --" <<std::endl;
    std::cout << "1. Delete a city by ID\n" <<std::endl;
    std::cout << "2. Delete a city by Name\n" <<std::endl;
}

void MenuManager::displayUpdateOptionsMenu() {
    std::cout << "-- UPDATE [CURRENT] CITY MENU --" <<std::endl;
    std::cout << "1. Update Name field: \n" <<std::endl;
    std::cout << "2. Update History Brief / Description field: \n" <<std::endl;
    std::cout << "3. Update Population field: \n" <<std::endl;
    std::cout << "4. Update Year Recorded field: \n" <<std::endl;
    std::cout << "5. Update Country / US State Field: \n" <<std::endl;

    std::cout << "*Coordinates: \n" <<std::endl;
    std::cout << "\t6. Update Coordinate's latitude field: \n" <<std::endl;
    std::cout << "\t7. Update Coordinate's longitude field: \n" <<std::endl;

    std::cout << "*Mayor: \n" <<std::endl;
    std::cout << "\t8. Update Mayor's Name field: \n" <<std::endl;
    std::cout << "\t9. Update Mayor's Official Residences Address field: \n" <<std::endl;
}

void MenuManager::displayMainDisplayCityOptionsMenu() {
  std::cout << "-- DISPLAY CITY MENU --" <<std::endl;
  std::cout << "1. Display all cities and fields in records (unsorted)\n" <<std::endl;
  std::cout << "2. Display specific cities fields (sorted by user selected field)\n" <<std::endl;
}

void MenuManager::displayDisplaySpecificCityFieldsAndSortTypeOptionsMenu() {
    std::cout << "-- DISPLAY SPECIFIC CITY FIELDS MENU --\n" <<std::endl;
    std::cout << "--- CHOOSE FIELDS TO DISPLAY ---" <<std::endl;
    std::cout << "1. City Name" <<std::endl;
    std::cout << "2. City Brief Description / History" <<std::endl;
    std::cout << "3. City Population" <<std::endl;
    std::cout << "4. City Year Recorded" <<std::endl;
    std::cout << "5. City Country / US State" <<std::endl;
    std::cout << "6. City Coordinates (Latitude)" <<std::endl;
    std::cout << "7. City Coordinates (Longitude)" <<std::endl;
    std::cout << "8. City Mayor Name" <<std::endl;
    std::cout << "9. City Mayor Official Residences Address" <<std::endl;

}

void MenuManager::displayWarningMessageDataDeletion() {
    std::cout << "-- WARNING! THIS ACTION WILL DELETE DATA! --" <<std::endl;
}

// Validate input as a string within the appropriate length
bool MenuManager::validateStringInput(std::string& input, int minLength, int maxLength) {
    // Trim leading and trailing whitespace
    input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
    input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);

    if (input.empty()) {
        std::cout << "[INFO] Your input cannot be blank!" << std::endl;
        return false;
    }
    // Check string length
    if (input.length() < minLength) {
        std::cout << "[INFO] Your input is too short." << std::endl;
        return false;
    }

    if (input.length() > maxLength) {
        std::cout << "[INFO] Your input is too long." << std::endl;
        return false;
    }
    return true;
}

// Validate input as an int
bool MenuManager::validateIntInput(const std::string& input) {
    // Check if the input string is empty
    if (input.empty()) {
        return false;
    }

    // Check if the first character is not a digit, minus sign, or plus sign
    if (!isdigit(input[0]) && input[0] != '-' && input[0] != '+') {
        return false;
    }

    // Attempt to convert the string to a long integer
    char* end = nullptr;
    std::strtol(input.c_str(), &end, 10);

    // Check if the entire string was successfully converted
    return (*end == 0);
}


void MenuManager::handleUserChoice(std::vector<City>& cityRecords, OperationsController& opController) {
    std::string input;
    std::cin >> input;

    if (validateIntInput(input)) {
        int choice = std::stoi(input);
             switch (choice) {
        case 1: {
    // Add a new city
    std::cout << "[INFO] Answer the following questions to add a new city." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get City Name
    std::string cityName;
    while (true) {
        std::cout << "Enter City Name (e.g., Oxford): " << std::endl;
        std::getline(std::cin, cityName);
        if (validateStringInput(cityName, 2, 50)) {
            break;
        }
        std::cout << "[INFO] Invalid input for City Name! Please try again." << std::endl;
    }

    // Get Brief History/Description
    std::string cityHistoryBrief;
    while (true) {
        std::cout << "Enter Brief History/Description (e.g., Historical university city): " << std::endl;
        std::getline(std::cin, cityHistoryBrief);
        if (validateStringInput(cityHistoryBrief, 5, 200)) {
            break;
        }
        std::cout << "[INFO] Invalid input for City History! Please try again." << std::endl;
    }

    // Get City Population
    int cityPopulation;
    while (true) {
        std::cout << "Enter City Population (e.g., 1000): " << std::endl;
        std::string cityPopulationInput;
        std::getline(std::cin, cityPopulationInput);
        if (validateIntInput(cityPopulationInput)) {
            cityPopulation = std::stoi(cityPopulationInput);
            if (cityPopulation > 0) {
                break;
            }
        }
        std::cout << "[INFO] Invalid input for City Population! Please try again." << std::endl;
    }

    // Get Year Recorded
    int cityYearRecorded;
    while (true) {
        std::cout << "Enter the Year Recorded (e.g., 2024): " << std::endl;
        std::string cityYearRecordedInput;
        std::getline(std::cin, cityYearRecordedInput);
        if (validateIntInput(cityYearRecordedInput)) {
            cityYearRecorded = std::stoi(cityYearRecordedInput);
            if (cityYearRecorded >= 0) {
                break;
            }
        }
        std::cout << "[INFO] Invalid input for Year Recorded! Please try again." << std::endl;
    }

    // Get City Country/State
    std::string cityUsStateOrCountry;
    while (true) {
        std::cout << "Enter City Country or US State (e.g., United Kingdom): " << std::endl;
        std::getline(std::cin, cityUsStateOrCountry);
        if (validateStringInput(cityUsStateOrCountry, 3, 50)) {
            break;
        }
        std::cout << "[INFO] Invalid input for City Country/State! Please try again." << std::endl;
    }

    // Get Latitude
    double latitude;
    while (true) {
        std::cout << "-City Coordinates-\nEnter Latitude: " << std::endl;
        std::string latitudeInput;
        std::getline(std::cin, latitudeInput);
        if (validateIntInput(latitudeInput)) {
            latitude = std::stod(latitudeInput);
            break;
        }
        std::cout << "[INFO] Invalid input for Latitude! Please try again." << std::endl;
    }

    // Get Longitude
    double longitude;
    while (true) {
        std::cout << "Enter Longitude: " << std::endl;
        std::string longitudeInput;
        std::getline(std::cin, longitudeInput);
        if (validateIntInput(longitudeInput)) {
            longitude = std::stod(longitudeInput);
            break;
        }
        std::cout << "[INFO] Invalid input for Longitude! Please try again." << std::endl;
    }

    // Get Mayor's Full Name
    std::string cityMayorFullname;
    while (true) {
        std::cout << "Enter Mayor's Full Name (e.g., Mike Rowley): " << std::endl;
        std::getline(std::cin, cityMayorFullname);
        if (validateStringInput(cityMayorFullname, 3, 50)) {
            break;
        }
        std::cout << "[INFO] Invalid input for Mayor's Name! Please try again." << std::endl;
    }

    // Get Mayor's Residence Address
    std::string cityMayorResidencesAddress;
    while (true) {
        std::cout << "Enter Mayor's Residence Address (e.g., Oxford Town Hall): " << std::endl;
        std::getline(std::cin, cityMayorResidencesAddress);
        if (validateStringInput(cityMayorResidencesAddress, 5, 100)) {
            break;
        }
        std::cout << "[INFO] Invalid input for Mayor's Residence Address! Please try again." << std::endl;
    }

    // Add the validated city to the records
    opController.addCity(cityRecords, latitude, longitude, cityMayorFullname, cityMayorResidencesAddress,
                          cityName, cityHistoryBrief, cityPopulation, cityYearRecorded, cityUsStateOrCountry);

    // Resolve duplicates if any
    opController.resolveDuplicatedCities(cityRecords);

    std::cout << "[INFO] City successfully added!" << std::endl;
    break;
}
        case 2: {
            // Delete a city
            displayDeleteByOptionsMenu();
            int deleteByChoice;
            std::cin >> deleteByChoice;
            switch(deleteByChoice) {
                default: {
                    std::cout << "Invalid search choice.! Returning to the main menu ..." << std::endl;
                    break;
                }

                case 1: {
                    // Delete a city by ID
                    displayWarningMessageDataDeletion();
                    std::cout << "Enter the City ID to delete: " <<std::endl;
                    int deleteCityIDSelected;
                    std::cin >> deleteCityIDSelected;
                    opController.deleteCityByID(cityRecords, deleteCityIDSelected);
                    break;
                }
                case 2: {
                    // Delete a city by Name
                    displayWarningMessageDataDeletion();
                    std::cout << "Enter the City Name to delete: " <<std::endl;
                    std::string deleteCityNameSelected;
                    std::cin.ignore();
                    std::getline(std::cin, deleteCityNameSelected);
                    opController.deleteCityByName(cityRecords, deleteCityNameSelected);
                    break;
                }

            }
            break;
        }
        case 3: {
            // Search for a city [update fields asked later]
            int currentCityID = -1;
            displaySearchOptionsMenu();
            int searchChoice;
            std::cin >> searchChoice;
            switch(searchChoice) {
                default: {
                    std::cout << "Invalid search choice.! Returning to the main menu ..." << std::endl;
                    break;
                }

                case 1: {
                    // Search by City ID
                    std::cout << "Enter City ID: " <<std::endl;
                    int id;
                    std::cin >> id;
                    currentCityID = opController.searchCityByID(cityRecords, id);
                    break;
                }

                case 2: {
                    std::cout << "Enter City Name: " <<std::endl;
                    std::string name;
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    currentCityID = opController.searchCityByName(cityRecords, name);
                    break;
                }

            }
            // Ask user whether they want to update any items
            char updateCityFields;
            std::cout << "[INFO] Would you like to update any city fields? (y/n)" <<std::endl;
            std::cin >> updateCityFields;

            if(updateCityFields == 'y') {
                displayUpdateOptionsMenu();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                int updateFieldID;
                std::cout << "Enter your choice: " <<std::endl;
                std::cin >> updateFieldID;
                opController.updateCity(cityRecords, updateFieldID, currentCityID);

            }
            else if (updateCityFields == 'n') {
                std::cout << "Invalid option. Going back to the main menu." << std::endl;
            }
            break;
        }

        case 4: {
            // Ask user which fields to display
            displayMainDisplayCityOptionsMenu();

            int displayOptionID;
            std::cout << "Enter your choice: " <<std::endl;
            std::cin >> displayOptionID;

            switch(displayOptionID) {
                case 1: {
                    // Display all (stored) city information
                    opController.displayAllCities(cityRecords);
                    break;
                }
                case 2: {
                    // Display specific cities fields menu
                    int fieldID;
                    std::string sortDirection;

                    displayDisplaySpecificCityFieldsAndSortTypeOptionsMenu();
                    std::cin >> fieldID;

                    std::cout << "Enter sort direction (asc or desc): ";
                    std::cin >> sortDirection;

                    opController.displaySpecificField(cityRecords, fieldID, sortDirection);

                    //opController.displaySpecificField(cityRecords, 5, "desc");
                    break;
                }
                default: {
                    std::cout << "[INFO] Invalid selection." << std::endl;
                    break;
                }
            }
        }

        case 5: {
            // Calculate the distance between two cities
            std::cout << "- CALCULATE DISTANCE BETWEEN CITIES -" << std::endl;
            std::cin.ignore();

            std::cout << "Enter first City Name: " <<std::endl;

            std::string cityNameOne;
            std::getline(std::cin, cityNameOne);

            std::cout << "Enter second City Name: " <<std::endl;
            std::string cityNameTwo;
            std::getline(std::cin, cityNameTwo);

            double distanceAnswer = opController.calculateDistanceBetweenCities(cityRecords, cityNameOne, cityNameTwo);
            if (distanceAnswer == -1) {
                break;
            }

            std::cout << cityNameOne << " --> " << cityNameTwo << std::endl;
            std::cout << "The distance is approximately " << distanceAnswer << " km"<< std::endl;
            break;

        }
        case 6: {
            // Save current program's (RAM) cities to file
            std::cout << "- SAVE TO FILE -" << std::endl;
            opController.saveCitiesToFile(cityRecords, "cities.txt");
            break;
        }

        case 7: {
            // Save cities in RAM to disk before exiting
            opController.saveCitiesToFile(cityRecords, "cities.txt");
            // Exit program
            std::cout << "[INFO] Clearing-up and exiting." << std::endl;
            exit(0);
        }

         default: {
            std::cout << "[INFO] Invalid number entered. Try again or quit by entering 7.... " << std::endl;
            break;
         }
    }
    }
    else {
        std::cout << "[INFO] Invalid input! Please enter a valid integer." << std::endl;
    }


}


void MenuManager::run(std::vector<City>& cityRecords, OperationsController& opController) {
    std::cout << "*** WELCOME TO CITIES OF THE WORLD IN C++ ***\n" << std::endl;
    opController.loadCitiesFromFile(cityRecords, "cities.txt");
    opController.resolveDuplicatedCities(cityRecords);

    while(true) {
        displayMainMenu();
        handleUserChoice(cityRecords, opController);
    }
}