#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "OperationsController.h"

class MenuManager {
private:
    void displayMainMenu();
    void displaySearchOptionsMenu();
    void displayDeleteByOptionsMenu();
    void displayWarningMessageDataDeletion();
    void handleUserChoice(std::vector<City>& cityRecords, OperationsController& opController);
public :
    void run(std::vector<City>& cityRecords, OperationsController& opController);
};

#endif //MENUMANAGER_H
