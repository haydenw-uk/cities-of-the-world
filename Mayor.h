//
// Created by Hayden Williams on 01/12/2024.
//

#ifndef MAYOR_H
#define MAYOR_H

#include <string>

class Mayor {
private:
    std::string name;
    std::string residenceAddress;

public:
    // Constructor
    Mayor(const std::string& a_name, const std::string& a_residenceAddress);

    // Getter methods
    const std::string& getName() const;
    const std::string& getResidenceAddress() const;
};

#endif // MAYOR_H