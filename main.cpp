
#include <iostream>
#include <cstring>
#include "Coordinate.h"
#include "Mayor.h"
#include "City.h"
#include "OperationsController.h"
#include "MenuManager.h"


// Cities of the World - Distance Calculation Program

int main() {
    std::vector<City> cityRecords;
    OperationsController operationsController;
    MenuManager menuManager;

    menuManager.run(cityRecords, operationsController);

    return 0;
}