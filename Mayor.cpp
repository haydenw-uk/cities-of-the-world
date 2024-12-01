//
// Created by Hayden Williams on 01/12/2024.
//

#include "Mayor.h"

// Constructor
Mayor::Mayor(const std::string& a_name, const std::string& a_residenceAddress)
    : name(a_name), residenceAddress(a_residenceAddress) {}

// Get the name of the mayor
const std::string& Mayor::getName() const {
    return name;
}

// Get the residence address of the mayor
const std::string& Mayor::getResidenceAddress() const {
    return residenceAddress;
}