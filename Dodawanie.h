#pragma once

#include <SFML/Graphics.hpp>
#include "Lekarz.h"
#include "Pacjent.h"
#include "Pielegniarka.h"
#include <vector>
#include <sstream>
#include "Sprawdzanie.h"

class Dodawanie {

    int stan; // 0 - Lekarz, 1 - Pielegnierka, 2 - Pacjent
    sf::Font czcionka;

    sf::Text Imie;
    sf::Text ImieWart;

    sf::Text Nazwisko;
    sf::Text NazwiskoWart;

    sf::Text NumerTelefonu;
    sf::Text NumerTelefonuWart;

    sf::Text Adres;
    sf::Text AdresWart;

    sf::Text Pesel;
    sf::Text PeselWart;

    sf::Text NumerPrac;
    sf::Text NumerPracWart;

    sf::Text Pokoj;
    sf::Text PokojWart;

    sf::Text Godziny;
    sf::Text GodzinyWart;

    sf::Text DataUr;
    sf::Text DataUrWart;

    sf::Text NumerNFZ;
    sf::Text NumerNFZWart;

    sf::Text Specjalizacja;
    sf::Text SpecjalizacjaWart;

    sf::Text InstrukcjaPacjent;
    sf::Text InstrukcjaLekarz;
    sf::Text InstrukcjaPielegniarka;

    sf::RectangleShape ImiePole;
    sf::RectangleShape NazwiskoPole;
    sf::RectangleShape NumerTelefonuPole;
    sf::RectangleShape AdresPole;
    sf::RectangleShape PeselPole;
    sf::RectangleShape NumerPracPole;
    sf::RectangleShape PokojPole;
    sf::RectangleShape GodzinyPole;
    sf::RectangleShape DataUrPole;
    sf::RectangleShape NumerNFZPole;
    sf::RectangleShape SpecjalizacjaPole;

    void UstawTeksty();
public:
    Dodawanie();
    void UstawStan(int wartosc)
    {
        stan=wartosc;
    }
     Lekarz DodajLekarza();
     Pacjent DodajPacjenta();
     Pielegniarka DodajPielegniarka();

    int PobierzStan()
    {
        return stan;
    }
    inline void UstawCzcionke(sf::Font &czcionka)
    {
        this->czcionka=czcionka;
        UstawTeksty();
    }
    void DodajZnak(std::string znak,int okno);
    void UsunZnak(int okno);
    void Rysuj(sf::RenderWindow &okno);
};

