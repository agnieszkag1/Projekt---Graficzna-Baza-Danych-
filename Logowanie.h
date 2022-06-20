#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>

class Logowanie {
    bool admin;
    std::vector<std::tuple<std::string,std::string,bool>> poprawneDane;
    sf::Text loginTekst;
    sf::Text hasloTekst;
    sf::Text loginZawartosc;
    sf::Text hasloZawartosc;
    sf::Text NaglowekTekst;
    sf::Font czcionka;
    sf::RectangleShape rectangle;
    sf::RectangleShape loginwpis;
    sf::RectangleShape haslowpis;

    void UstawTeksty();
public:
    Logowanie();
    inline void UstawCzcionke(sf::Font &czcionka)
    {
        this->czcionka=czcionka;
        UstawTeksty();
    }
    void DodajZnak(std::string znak,int okno);
    void UsunZnak(int okno);
    void Rysuj(sf::RenderWindow &okno);
    bool CzyPoprawneLogowanie();
    bool CzyAdmin();
};


