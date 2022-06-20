#include "Logowanie.h"

Logowanie::Logowanie() {
    poprawneDane.push_back(std::make_tuple("ADMIN", "ADMIN", 1));
    poprawneDane.push_back(std::make_tuple("RECEPCJA", "RECEPCJA", 0));
    admin = 0;
}

void Logowanie::Rysuj(sf::RenderWindow &okno) {
    okno.draw(rectangle);
    okno.draw(loginwpis);
    okno.draw(haslowpis);
    okno.draw(NaglowekTekst);
    okno.draw(loginTekst);
    okno.draw(hasloTekst);
    okno.draw(loginZawartosc);
    okno.draw(hasloZawartosc);

}


void Logowanie::SprawdzPoprawnosc() {

}

void Logowanie::UstawTeksty() {

    NaglowekTekst.setFont(czcionka);
    NaglowekTekst.setString("BAZA DANYCH PRZYCHODNIA");
    NaglowekTekst.setCharacterSize(60);
    NaglowekTekst.setFillColor(sf::Color(255, 255, 255, 255));
    NaglowekTekst.setPosition(200, 40);

    loginTekst.setFont(czcionka);
    loginTekst.setString("Login:");
    loginTekst.setCharacterSize(45);
    loginTekst.setFillColor(sf::Color(255, 255, 255, 255));
    loginTekst.setPosition(200, 200);

    hasloTekst.setFont(czcionka);
    hasloTekst.setString("Haslo:");
    hasloTekst.setCharacterSize(45);
    hasloTekst.setFillColor(sf::Color(255, 255, 255, 255));
    hasloTekst.setPosition(200, 300);

    loginZawartosc.setFont(czcionka);
    loginZawartosc.setString("");
    loginZawartosc.setCharacterSize(45);
    loginZawartosc.setFillColor(sf::Color(60, 86, 99, 255));
    loginZawartosc.setPosition(360, 200);

    hasloZawartosc.setFont(czcionka);
    hasloZawartosc.setString("");
    hasloZawartosc.setCharacterSize(45);
    hasloZawartosc.setFillColor(sf::Color(60, 86, 99, 255));
    hasloZawartosc.setPosition(360, 300);

    rectangle.setSize(sf::Vector2f(1000, 80));
    rectangle.setFillColor(sf::Color(162, 148, 135, 255));
    rectangle.setPosition(130, 40);

    loginwpis.setSize(sf::Vector2f(300, 45));
    loginwpis.setFillColor(sf::Color(228, 214, 189, 255));
    loginwpis.setPosition(350, 208);

    haslowpis.setSize(sf::Vector2f(300, 45));
    haslowpis.setFillColor(sf::Color(228, 214, 189, 255));
    haslowpis.setPosition(350, 308);
}

void Logowanie::DodajZnak(std::string znak, int okno) {
    switch (okno) {
        case 1: {
            std::string tmp = loginZawartosc.getString();
            tmp += znak;
            loginZawartosc.setString(tmp);
        }
            break;
        case 2: {
            std::string tmp = hasloZawartosc.getString();
            tmp += znak;
            hasloZawartosc.setString(tmp);
        }
            break;
    }
}

void Logowanie::UsunZnak(int okno) {
    switch (okno) {
        case 1: {
            std::string tmp = loginZawartosc.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            loginZawartosc.setString(tmp);
        }
            break;
        case 2: {
            std::string tmp = hasloZawartosc.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            hasloZawartosc.setString(tmp);
        }
            break;
    }
}

bool Logowanie::CzyPoprawneLogowanie() {
    for (auto dane: poprawneDane) {
        if (loginZawartosc.getString() == std::get<0>(dane)) {
            if (hasloZawartosc.getString() == std::get<1>(dane)) {
                admin = std::get<2>(dane);
                return true;
            }
        }
    }
    return false;
}

bool Logowanie::CzyAdmin() {
    return admin;
}