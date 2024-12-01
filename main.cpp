//
// Created by Hayden Williams on 18/10/2024.
//

#include <iostream>
#include <cstring>
#include "Coordinate.cpp"
#include "Mayor.cpp"
#include "City.cpp"
#include "OperationsController.cpp"

// Cities - Distance Calculation Program

int main() {
    //Coordinate londonEngland(51.5072, -0.1276);

    Coordinate oxfordCoordinates(51.7520, -1.2577);
    Mayor oxfordMayor("Alice Bob", "City Hall");

    City city("Oxford", 30000, 2024, oxfordCoordinates, oxfordMayor);
    std::cout << city.getName() << oxfordMayor.getName() << std::endl;

    // double distance = londonEngland.calculateDistanceTo(oxfordEngland);
    //
    // std::cout << "The distance between London, England and Oxford, England is "
    //          << distance << " km." << std::endl;
    //
    // City exampleCity("Oxford", 3000, 2024);
    // std::cout << exampleCity.getName() << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}