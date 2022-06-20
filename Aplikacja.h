#pragma once
#include <regex>
#include <filesystem>
#include <fstream>
#include <thread>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Osoba.h"
#include "Lekarz.h"
#include "Pacjent.h"
#include "Pielegniarka.h"
#include "Logowanie.h"
#include "Szukanie.h"
#include "Dodawanie.h"
#include "Sprawdzanie.h"

using namespace std;

class Aplikacja {
private:
    //ZMIENNE//
    vector<Lekarz> Lekarze;
    vector<Pielegniarka> Pielegniarki;
    vector<Pacjent> Pacjenci;
    sf::RenderWindow okno;
    sf::Font czcionka;
    Logowanie logowanie;
    Szukanie szukanie;
    Dodawanie dodawanie;
    bool czyLogowanie;
    bool logowanieOkno1;
    bool logowanieOkno2;
    bool czySzukanie;
    bool czyDodawanie;
    bool dodawanieImie;
    bool dodawanieNazwisko;
    bool dodawanieNumerTelefonu;
    bool dodawanieAdres;
    bool dodawaniePesel;
    bool dodawanieNumerPrac;
    bool dodawaniePokoj;
    bool dodawanieGodziny;
    bool dodawanieDataUr;
    bool dodawanieNumerNFZ;
    bool dodawanieSpecjalizacja;
    bool admin;

public:

   Aplikacja();

    void WczytajDane();
    void GlownaPetla();
    void ObsluzZdarzenia();
    void Rysuj();
    void ZapiszDoPlików();
    void CzyIstniejeLekarz();
    void CzyIstniejePielegniarka();
    void CzyIstniejePacjent();
};

    //OBIEKTY FUNKCYJNE//
    class WczytajLekarzy {
    public:
        void operator()(ifstream &file, vector<Lekarz> &Lekarze) {

            std::string imie, nazwisko, numerTelefonu, adres, specjializacja, numerLekarza;

            while (file >> imie >> nazwisko >> numerTelefonu >> adres >> specjializacja >> numerLekarza) {
                if (Sprawdzanie::SprawdzCzySameLitery(imie) == true && Sprawdzanie::SprawdzCzySameLitery(nazwisko) == true &&
                    Sprawdzanie::SprawdzNumer(numerTelefonu) == true) {
                    string dzienTygodnia, godzinaRozpoczecia, godzinaZakonczenia;

                    std::vector<string> zmiany;

                    //teraz pobiera godziny pracy
                    for (int i = 0; i < 7; i++) {
                        file >> dzienTygodnia >> godzinaRozpoczecia >> godzinaZakonczenia;
                        zmiany.push_back(dzienTygodnia);
                        zmiany.push_back(godzinaRozpoczecia);
                        zmiany.push_back(godzinaZakonczenia);
                    }

                    Lekarze.push_back(Lekarz(imie, nazwisko, numerTelefonu, adres, specjializacja, zmiany, numerLekarza));
                }
            }
        }
    };
    class WczytajPacjentow {
    public:
        void operator()(ifstream &file, vector<Pacjent> &Pacjenci) {
            std::string imie, nazwisko, numerTel, adres, numerNFZ, pesel, dataUrodzenia;
            while (file >> imie >> nazwisko >> pesel >> dataUrodzenia >> numerTel >> adres >> numerNFZ)
            {

                if (Sprawdzanie::SprawdzCzySameLitery(imie) == true &&
                    Sprawdzanie::SprawdzCzySameLitery(nazwisko) == true &&
                    Sprawdzanie::SprawdzNumer(numerTel) == true &&
                    Sprawdzanie::SprawdzPesel(pesel) == true &&
                    Sprawdzanie::SprawdzDate(dataUrodzenia)==true)
                {
                    Pacjent pacjent{imie, nazwisko, numerTel, adres, numerNFZ, pesel, dataUrodzenia};
                    Pacjenci.push_back(pacjent);
                }
            }
        }
    };
    class WczytajPielegniarki {

    public:
        void operator()(ifstream &file, vector<Pielegniarka> &Pielegniarki) {
            std::string imie, nazwisko, numerTelefonu, adres, numerPracownika;
            int numerPokoju;

            while (file >> imie >> nazwisko >> numerTelefonu >> adres >> numerPracownika >> numerPokoju) {

                if (Sprawdzanie::SprawdzCzySameLitery(imie) == true && Sprawdzanie::SprawdzCzySameLitery(nazwisko) == true &&
                    Sprawdzanie::SprawdzNumer(numerTelefonu) == true ) {
                    string dzienTygodnia, godzinaRozpoczecia, godzinaZakonczenia;

                    std::vector<string> zmiany;

                    //teraz pobiera godziny pracy
                    for (int i = 0; i < 7; i++) {
                        file >> dzienTygodnia >> godzinaRozpoczecia >> godzinaZakonczenia;
                        zmiany.push_back(dzienTygodnia);
                        zmiany.push_back(godzinaRozpoczecia);
                        zmiany.push_back(godzinaZakonczenia);
                    }
                    Pielegniarki.push_back(Pielegniarka(imie, nazwisko, numerTelefonu, adres, numerPokoju, zmiany, numerPracownika));
                }
            }
        }

    };


