//
// Created by Hayden Williams on 01/12/2024.
//

#ifndef MAYOR_H
#define MAYOR_H
#include <iostream>
#include <cstring>

// class Mayor
class Mayor {
private:
    std::string name;
    std::string residenceAddress;
public:
    // Constructor
    Mayor(const std::string& a_name, const std::string& a_residenceAddress)
        : name(a_name), residenceAddress(a_residenceAddress) {}

    const std::string& getName() const {return name;}
    const std::string& getResidenceAddress() const {return residenceAddress;}
};



#endif //MAYOR_H
