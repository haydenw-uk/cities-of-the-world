//
// Created by Hayden Williams on 01/12/2024.
//

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
    std::cout << "3. Update city information\n" <<std::endl;
    std::cout << "4. Search for a city\n" <<std::endl;
    std::cout << "5. Display (specific) city information\n" <<std::endl;
    std::cout << "6. Display all (stored) cities\n" <<std::endl;
    std::cout << "7. Calculate distance between two cities\n" <<std::endl;
    std::cout << "8. Exit\n" <<std::endl;
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

void MenuManager::handleUserChoice(std::vector<City>& cityRecords, OperationsController& opController) {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            // Add a new city
            opController.addCity();
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
                    break;
                case 2:
                    // Delete a city by Name
                    break;
            }
            //opController.deleteCity();
            break;
        case 3:
            // Update city information
            opController.updateCity(cityRecords);
            break;
        case 4:
            // Search for a city
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
                opController.searchCityByID(id);
                break;
                case 2:
                    std::cout << "Enter City Name: " <<std::endl;
                std::string name;
                std::cin.ignore();
                std::getline(std::cin, name);
                opController.searchCityByName(name);
                break;

            }
            break;
        case 5:
            // Display specific city information
            opController.displayCity(cityRecords);
            break;
        case 6:
            // Display all (stored) city information
            opController.displayAllCities();
            break;
        case 7:
            // Calculate the distance between two cities
            opController.calculateDistance(cityRecords);
            break;
        case 8:
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