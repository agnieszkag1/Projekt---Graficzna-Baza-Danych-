#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Lekarz.h"
#include "Pielegniarka.h"
#include "Pacjent.h"

class Szukanie {
    bool admin;
    sf::RectangleShape kolorNaglowek;
    sf::Text szukanie_gora;
    sf::RectangleShape wyszukiwanie;

    sf::Text tekstDodajLekarza;
    sf::Text tekstDodajPacjenta;
    sf::Text tekstDodajPielegniarke;

    sf::RectangleShape przyciskDodajPacjenta;
    sf::RectangleShape przyciskDodajLekarza;
    sf::RectangleShape przyciskDodajPielegniarke;

    sf::Text tekstUsun;
    sf::RectangleShape przyciskUsun;

    sf::Text szukajka;
    sf::Text wynikoweOkno;
    sf::Font czcionka;
    void UstawTeksty();
    Lekarz* SzukajLekrza(std::string numer_lek);
    Pielegniarka* SzukajPielegniarki (std::string numer_piel);
    Pacjent* SzukajPacjenta(std::string pesel);
    std::vector<Pielegniarka> pielegniarki_baza;
    std::vector<Lekarz> lekarze_baza;
    std::vector<Pacjent> pacjenci_baza;
    Osoba* osobaWyszukana;

public:
    Szukanie();
    inline void UstawCzcionke(sf::Font &czcionka)
    {
        this->czcionka=czcionka;
        UstawTeksty();
    }
    inline void UstawWektory(std::vector<Pielegniarka> a1,std::vector<Lekarz> a2,std::vector<Pacjent> a3)
    {
        pielegniarki_baza=a1;
        lekarze_baza=a2;
        pacjenci_baza=a3;
    }
    void DodajZnak(std::string znak);
    void UsunZnak();
    void Rysuj(sf::RenderWindow &okno);
    void Wyszukaj();
    void UstawAdmin(bool admin);
    Osoba* WyszukanaOsoba();
};

