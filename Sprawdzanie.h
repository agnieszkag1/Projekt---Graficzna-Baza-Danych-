//
// Created by Agnieszka on 13.06.2022.
//

#ifndef BAZA_PRZYCHODNIA_SPRAWDZANIE_H
#define BAZA_PRZYCHODNIA_SPRAWDZANIE_H

#include <iostream>
#include <regex>

class Sprawdzanie {
public:
    static bool SprawdzPesel(std::string pesel);
    static bool SprawdzDate(std::string data);
    static bool SprawdzNumer(std::string numer);
    static bool SprawdzCzySameLitery(std::string nazwa);
};


#endif //BAZA_PRZYCHODNIA_SPRAWDZANIE_H
