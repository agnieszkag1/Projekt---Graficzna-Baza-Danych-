#pragma once
#include "string"

class Osoba {


public:
    //KONSTRUKTOR//
    Osoba(std::string imie, std::string nazwisko,
          std::string numerTelefonu, std::string adres);

    //METODY//
    std::string PobierzImie();
    std::string PobierzNazwisko();
    std::string PobierzTelefon();
    std::string PobierzAdres();

    virtual std::string JakoString()=0;

protected:
    //ZMIENNE//
    std::string imie;
    std::string nazwisko;
    std::string numerTelefonu;
    std::string adres;

};