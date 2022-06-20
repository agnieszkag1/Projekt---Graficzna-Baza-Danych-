#pragma once

#include "Osoba.h"
#include <vector>


class Lekarz : public Osoba {
public:
    //KONSTRUKTOR//
    Lekarz(std::string imie, std::string nazwisko, std::string numerTelefonu,
           std::string adres, std::string specjalizacja,
           std::vector<std::string> godzPrac, std::string numerPrac);

    //METODY//
    std::string PobierzSpecjalizacje();
    std::vector<std::string> PobierzGodzPrac();
    std::string PobierzNumerPrac();
    std::string JakoString() override;

    bool operator==(Lekarz &l) {
        if (imie == l.imie && nazwisko == l.nazwisko && numerTelefonu == l.numerTelefonu && adres == l.adres &&
            specjalizacja == l.specjalizacja && godzPrac == l.godzPrac && numerPrac == l.numerPrac) {
            return true;
        }
        return false;
    }

private:
    //ZMIENNE//
    std::string specjalizacja;
    std::vector<std::string> godzPrac;
    std::string numerPrac;
};


