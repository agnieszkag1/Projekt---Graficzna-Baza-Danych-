#include "Osoba.h"


Osoba::Osoba(std::string imie, std::string nazwisko,
             std::string numerTelefonu,  std::string adres)
        : imie(std::move(imie)), nazwisko(std::move(nazwisko)),
        numerTelefonu(std::move(numerTelefonu)),
        adres(std::move(adres)) {}


std::string Osoba::PobierzNazwisko() {
    return nazwisko;
}
std::string Osoba::PobierzImie() {
    return imie;
}
std::string Osoba::PobierzTelefon() {
    return numerTelefonu;
}
std::string Osoba::PobierzAdres() {
    return adres;
}