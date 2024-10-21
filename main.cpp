//
// Created by Hayden Williams on 18/10/2024.
//

#include <iostream>
#include <cstring>

// class Coordinates

// class Mayor
class Mayor {
private:
    char* name;
    char* residenceAddress;
public:
    // Constructor
    Mayor(char* a_name, char* a_residenceAddress) {
        name = a_name;
        residenceAddress = a_residenceAddress;
    }
    // Destructor
    ~Mayor() {
        delete[] name;
    }

    // GETTER Methods
    const char* getName() const {return name;}
    const char* getResidenceAddress() const {return residenceAddress;}

    // SETTER Methods
};

class City {
private:
    char* name;
    uint32_t population;
    uint16_t yearRecorded;
    // TODO Implement Coordinates class

    // TODO Implement Mayor class
public:
    // Constructor
    City(const char* a_name, uint32_t a_population, uint16_t a_yearRecorded) {
        this->name = new char[strlen(a_name) + 1];
        strcpy(this->name, a_name);
        population = a_population;
        yearRecorded = a_yearRecorded;
        //TODO Update constructor when classes implemented
    }
    // Destructor
    ~City() {
        delete[] name;
    }

    // GETTER Methods
    const char* getName() const {return name;}
    const uint32_t getPopulation() const {return population;}
    const uint16_t getYearRecorded() const {return yearRecorded;}

    // SETTER Methods


};

// Cities - Distance Calculation Program

int main() {
    City exampleCity("Oxford", 3000, 2024);
    std::cout << exampleCity.getName() << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}