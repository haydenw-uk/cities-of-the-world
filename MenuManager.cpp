#include "MenuManager.h"
#include <iostream>
#include "OperationsController.h"


/// -- Important Implementation Notes from Author --
/// This class is solely for displaying menu options to the user, taking user input
/// Operations on data must not be implemented here, use OperationsController.

void MenuManager::displayMainMenu() {
    std::cout << "\n-- MAIN MENU --\n" << std::endl;
    std::cout << "1. Add a new city\n" <<std::endl;
    std::cout << "2. Delete a city\n" <<std::endl;
    std::cout << "3. Search for a city, Update city fields\n" <<std::endl;
    std::cout << "4. Display all cities\n" <<std::endl;
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
    std::cout << "-- UPDATE CITY MENU --" <<std::endl;
    std::cout << "1. Delete a city by ID\n" <<std::endl;
    std::cout << "2. Delete a city by Name\n" <<std::endl;
}

void MenuManager::displayWarningMessageDataDeletion() {
    std::cout << "-- WARNING! THIS ACTION WILL DELETE DATA! --" <<std::endl;
}

void MenuManager::handleUserChoice(std::vector<City>& cityRecords, OperationsController& opController) {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            // Add a new city
            opController.addCity(cityRecords);
            break;
        case 2:
            // Delete a city
            displayDeleteByOptionsMenu();
            int deleteByChoice;
            std::cin >> deleteByChoice;
            switch(deleteByChoice) {
                default:
                    std::cout << "Invalid search choice.! Returning to the main menu ..." << std::endl;
                    break;
                case 1:
                    // Delete a city by ID
                    displayWarningMessageDataDeletion();
                    std::cout << "Enter the City ID to delete: " <<std::endl;
                    int deleteCityIDSelected;
                    std::cin >> deleteCityIDSelected;
                    opController.deleteCityByID(cityRecords, deleteCityIDSelected);
                    break;
                case 2:
                    // Delete a city by Name
                    displayWarningMessageDataDeletion();
                    std::cout << "Enter the City Name to delete: " <<std::endl;
                    std::string deleteCityNameSelected;
                    std::cin.ignore();
                    std::getline(std::cin, deleteCityNameSelected);
                    opController.deleteCityByName(cityRecords, deleteCityNameSelected);
                    break;
            }
            break;
        case 3:
            // Search for a city [update fields asked later]
            displaySearchOptionsMenu();
            int searchChoice;
            std::cin >> searchChoice;
            switch(searchChoice) {
                default:
                    std::cout << "Invalid search choice.! Returning to the main menu ..." << std::endl;
                    break;
                case 1:
                    // Search by City ID
                    std::cout << "Enter City ID: " <<std::endl;
                    int id;
                    std::cin >> id;
                    opController.searchCityByID(cityRecords, id);
                    break;
                case 2:
                    std::cout << "Enter City Name: " <<std::endl;
                    std::string name;
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    opController.searchCityByName(cityRecords, name);
                    break;
            }
            // Ask user whether they want to update any items
            // Display
            std::string updateCityFields;
            std::cout << "[INFO] Would you like to update any city fields? (YES/NO)" <<std::endl;
            std::getline(std::cin, updateCityFields);

            if(updateCityFields == "YES") {
                displayUpdateOptionsMenu();
                // !!! LEFT-OFF !!!
                // [] Call updateCityMethod [OperationsController class]
                // [] Tweak updateCity method to determine update field inside it and remove updateFieldID parameter
                std::cout << "Enter the fields you want to update: " <<std::endl;
            }
            break;
        case 4:
            // Display all (stored) city information
            opController.displayAllCities(cityRecords);
            break;
        case 5: {
            // Calculate the distance between two cities
            std::cout << "- CALCULATE DISTANCE BETWEEN CITIES -" << std::endl;

            std::cin.ignore();
            std::cout << "Enter first City Name: " <<std::endl;

            std::string cityNameOne;
            std::getline(std::cin, cityNameOne);
            std::cin.ignore();

            std::cout << "Enter second City Name: " <<std::endl;
            std::string cityNameTwo;
            std::getline(std::cin, cityNameTwo);
            std::cin.ignore();

            //TODO Implement validation check to determine whether City name is shared with another City ... in which case ask user country, etc until sorted ...

            double distanceAnswer = opController.calculateDistanceBetweenCities(cityRecords, cityNameOne, cityNameTwo);
            std::cout << cityNameOne << " --> " << cityNameTwo << std::endl;
            std::cout << "The distance is approximately " << distanceAnswer << " km"<< std::endl;
            break;
        }
        case 6:
            // Save program cities to file
            //TODO Implement saving cities to file
            break;
        case 7:
            // Exit program
            std::cout << "Clearing-up and exiting." << std::endl;
            exit(0);
    }
}

void MenuManager::run(std::vector<City>& cityRecords, OperationsController& opController) {
    std::cout << "*** WELCOME TO CITIES OF THE WORLD IN C++ ***\n" << std::endl;
    while(true) {
        displayMainMenu();
        handleUserChoice(cityRecords, opController);
    }
}