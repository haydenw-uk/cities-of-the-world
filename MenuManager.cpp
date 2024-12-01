//
// Created by Hayden Williams on 01/12/2024.
//

#include "MenuManager.h"
#include <iostream>
#include "OperationsController.h"

void MenuManager::displayMainMenu() {
    std::cout << "-- MAIN MENU --\n" << std::endl;
    std::cout << "1. Add a new city\n" <<std::endl;
    std::cout << "2. Delete a city\n" <<std::endl;
    std::cout << "3. Update city information\n" <<std::endl;
    std::cout << "4. Search for a city\n" <<std::endl;
    std::cout << "5. Display city information\n" <<std::endl;
    std::cout << "6. Display all (stored) cities\n" <<std::endl;
    std::cout << "7. Calculate distance between two cities\n" <<std::endl;
    std::cout << "8. Exit\n" <<std::endl;
    std::cout << "*******************" <<std::endl;
    std::cout << "Enter your choice: " <<std::endl;
}

void MenuManager::handleUserChoice() {
    OperationsController opController;
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            // Add a new city
            opController.addCity();
            break;
        case 2:
            // Delete a city
            std::cout << std::endl;
            break;
        case 3:
            // Update city information
            break;
        case 4:
            // Search for a city
            break;
        case 5:
            // Display city information
            break;
        case 6:
            // Display all (stored) city information
            break;
        case 7:
            // Calculate the distance between two cities
            break;
        case 8:
            std::cout << "Clearing-up and exiting." << std::endl;
            exit(0);
    }
}

void MenuManager::run() {
    while(true) {
        std::cout << "*** WELCOME TO CITIES OF THE WORLD IN C++ ***\n" << std::endl;
        displayMainMenu();
        handleUserChoice();
    }
}