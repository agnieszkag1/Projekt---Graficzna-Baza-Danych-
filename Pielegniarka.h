#pragma once
#include "Osoba.h"
#include <vector>

class Pielegniarka :public Osoba {
private:

    //ZMIENNE//
    int pokoj;
    std::vector<std::string> godzPrac;
    std::string numerPrac;

public:
    //KONSTRUKTOR//
    Pielegniarka( std::string imie, std::string nazwisko, std::string numerTelefonu,
                  std::string adres, int pokoj, std::vector<std::string> godzPrac,
                  std::string numerPrac);

    //METODY//
    int  PobierzPokoj();
    std::vector<std::string> PobierzGodzPrac();
    std::string PobierzNumerPrac();
    std::string JakoString() override;
    bool operator==(Pielegniarka &p) {
        if (imie == p.imie && nazwisko == p.nazwisko && numerTelefonu == p.numerTelefonu && adres == p.adres &&
            pokoj == p.pokoj && godzPrac == p.godzPrac && numerPrac == p.numerPrac) {
            return true;
        }
        return false;
    }
};