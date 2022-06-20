#pragma once
#include "Osoba.h"

class Pacjent : public Osoba {

private:
    //ZMIENNE//
    std::string numerNFZ;
    std::string pesel;
    std::string dataUr;

public:
    //KONSTRUKTOR//
    Pacjent(std::string imie, std::string nazwisko,
            std::string numerTelefonu, std::string adres,
            std::string numerNFZ,
            std::string pesel,std::string dataUr);

    //MEDOTDY//
    std::string PobierzPesel();
    std::string PobierzDateUr();
    std::string PobierzNFZ();
    std::string JakoString() override;

    bool operator==(Pacjent &p)
    {
        if(imie==p.imie&& nazwisko==p.nazwisko&&numerTelefonu==p.numerTelefonu&&
        adres==p.adres&&numerNFZ==p.numerNFZ&&pesel==p.pesel&&dataUr==p.dataUr)
        {
            return true;
        }
        return false;
    }

};