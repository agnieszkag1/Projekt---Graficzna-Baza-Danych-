//
// Created by Agnieszka on 13.06.2022.
//

#include "Sprawdzanie.h"

//SPRAWDZANIE POPRAWNOŚCI KONKRETNYCH CZĘŚCI//
bool Sprawdzanie::SprawdzPesel(std::string pesel) {
    std::regex wzor_pesel("[0-9]{11}");
    if (regex_match(pesel, wzor_pesel)) return true;
    return false;

}

bool Sprawdzanie::SprawdzDate(std::string data) { //dd.mm.rrrr


    if (data.size() == 10 && data[2] == '.' && data[5] == '.') {
        if (isdigit(data[0]) && isdigit(data[1]) && isdigit(data[3]) && isdigit(data[4]) && isdigit(data[6]) &&
            isdigit(data[7]) && isdigit(data[8]) && isdigit(data[9])) {

            if ((data[0] == '1' || data[0] == '0' || data[0] == '2' || data[0] == '3') &&
                (data[3] == '0' || data[3] == '1') &&
                (data[6] == '1' || data[6] == '2')) {
                return true;
            } else return false;
        }

    }

    return false;

}

bool Sprawdzanie::SprawdzNumer(std::string numer) {

    if (numer.size() == 9 && isdigit(numer[0]) && isdigit(numer[1]) && isdigit(numer[2]) && isdigit(numer[3]) &&
        isdigit(numer[4]) && isdigit(numer[5]) && isdigit(numer[6]) && isdigit(numer[7]) && isdigit(numer[8])) {
        return true;
    } else return false;

}

bool Sprawdzanie::SprawdzCzySameLitery(std::string nazwa) {
    for (char znak: nazwa) {
        if (znak < 48 || znak > 57) return true;

        return false;
    }
    return true;
}