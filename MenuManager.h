#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "OperationsController.h"

class MenuManager {
public:
    void displayMainMenu();
    void displaySearchOptionsMenu();
    void displayDeleteByOptionsMenu();
    void displayUpdateOptionsMenu();
    void displayMainDisplayCityOptionsMenu();
    void displayDisplaySpecificCityFieldsAndSortTypeOptionsMenu();
    void displayWarningMessageDataDeletion();

    bool validateIntInput(const std::string& input);
    bool validateIntInputWithinRange(const std::string& input, int minLength, int maxLength);
    bool validateCoordinateInput(const std::string& input, double minLength, double maxLength);

    void run(std::vector<City>& cityRecords, OperationsController& opController);
    void handleUserChoice(std::vector<City>& cityRecords, OperationsController& opController);

    bool validateStringInput(std::string& input, int minLength, int maxLength);


};

#endif //MENUMANAGER_H
