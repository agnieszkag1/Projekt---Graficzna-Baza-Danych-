#include "Szukanie.h"

Szukanie::Szukanie() {
    admin=false;
    osobaWyszukana= nullptr;
}

void Szukanie::Rysuj(sf::RenderWindow &okno) {

    okno.draw(kolorNaglowek);
    okno.draw(szukanie_gora);
    okno.draw(wyszukiwanie);
    okno.draw(szukajka);
    okno.draw(wynikoweOkno);
    if(admin) {
        okno.draw(przyciskDodajPacjenta);

        okno.draw(przyciskDodajLekarza);
        okno.draw(tekstDodajLekarza);

        okno.draw(przyciskDodajPielegniarke);
        okno.draw(tekstDodajPielegniarke);

        okno.draw(przyciskDodajPacjenta);
        okno.draw(tekstDodajPacjenta);

        okno.draw(przyciskUsun);
        okno.draw(tekstUsun);

    }
}

void Szukanie::UstawTeksty() {
    szukajka.setFont(czcionka);
    szukajka.setString("");
    szukajka.setCharacterSize(40);
    szukajka.setFillColor(sf::Color(60, 86, 99, 255));
    szukajka.setPosition(270, 150);

    kolorNaglowek.setSize(sf::Vector2f(3000, 50));
    kolorNaglowek.setFillColor(sf::Color(228, 214, 189, 255));
    kolorNaglowek.setPosition(0, 0);

    szukanie_gora.setFont(czcionka);
    szukanie_gora.setString("Aby szukac, wpisz numer lekarza / pielegniarki lub pesel pacjenta i kliknij ENTER");
    szukanie_gora.setCharacterSize(30);
    szukanie_gora.setFillColor(sf::Color(60, 86, 99, 255));
    szukanie_gora.setPosition(70, 5);

    wyszukiwanie.setSize(sf::Vector2f(800, 50));
    wyszukiwanie.setFillColor(sf::Color(228, 214, 189, 255));
    wyszukiwanie.setPosition(230, 150);

    wynikoweOkno.setFont(czcionka);
    wynikoweOkno.setString("");
    wynikoweOkno.setCharacterSize(30);
    wynikoweOkno.setFillColor(sf::Color(255, 255, 255, 255));
    wynikoweOkno.setPosition(250, 210);

    przyciskUsun.setSize(sf::Vector2f(200, 50));
    przyciskUsun.setFillColor(sf::Color(162, 148, 135, 255));
    przyciskUsun.setPosition(800, 700);

    tekstUsun.setFont(czcionka);
    tekstUsun.setString("SKASUJ");
    tekstUsun.setCharacterSize(30);
    tekstUsun.setFillColor(sf::Color(255, 255, 255, 255));
    tekstUsun.setPosition(845, 705);

    przyciskDodajPacjenta.setSize(sf::Vector2f(200, 50));
    przyciskDodajPacjenta.setFillColor(sf::Color(162, 148, 135, 255));
    przyciskDodajPacjenta.setPosition(1050, 700);

    tekstDodajPacjenta.setFont(czcionka);
    tekstDodajPacjenta.setString("+ PACJENT");
    tekstDodajPacjenta.setCharacterSize(30);
    tekstDodajPacjenta.setFillColor(sf::Color(255, 255, 255, 255));
    tekstDodajPacjenta.setPosition(1075, 705);

    przyciskDodajLekarza.setSize(sf::Vector2f(200, 50));
    przyciskDodajLekarza.setFillColor(sf::Color(162, 148, 135, 255));
    przyciskDodajLekarza.setPosition(1050, 640);

    tekstDodajLekarza.setFont(czcionka);
    tekstDodajLekarza.setString("+ LEKARZ");
    tekstDodajLekarza.setCharacterSize(30);
    tekstDodajLekarza.setFillColor(sf::Color(255, 255, 255, 255));
    tekstDodajLekarza.setPosition(1075, 645);

    przyciskDodajPielegniarke.setSize(sf::Vector2f(200, 50));
    przyciskDodajPielegniarke.setFillColor(sf::Color(162, 148, 135, 255));
    przyciskDodajPielegniarke.setPosition(1050, 580);

    tekstDodajPielegniarke.setFont(czcionka);
    tekstDodajPielegniarke.setString("+ PIELEG.");
    tekstDodajPielegniarke.setCharacterSize(30);
    tekstDodajPielegniarke.setFillColor(sf::Color(255, 255, 255, 255));
    tekstDodajPielegniarke.setPosition(1075, 585);

}

void Szukanie::DodajZnak(std::string znak) {
    std::string tmp = szukajka.getString();
    tmp += znak;
    szukajka.setString(tmp);
}

void Szukanie::UsunZnak() {
    std::string tmp = szukajka.getString();
    if (tmp.empty()) {
        return;
    }
    tmp.pop_back();
    szukajka.setString(tmp);
}


Lekarz *Szukanie::SzukajLekrza(std::string numer_lek) {
    auto aaa = [&](Lekarz lekarz) {
        if (lekarz.PobierzNumerPrac() == numer_lek) {
            return true;
        } else {
            return false;
        }
    };
    auto wynik = std::ranges::find_if(lekarze_baza.begin(), lekarze_baza.end(), aaa);
    if (wynik != lekarze_baza.end()) {
        return new Lekarz(wynik->PobierzImie(), wynik->PobierzNazwisko(), wynik->PobierzTelefon(),
                          wynik->PobierzAdres(), wynik->PobierzSpecjalizacje(), wynik->PobierzGodzPrac(),
                          wynik->PobierzNumerPrac());
    }
    return nullptr;
}

Pielegniarka *Szukanie::SzukajPielegniarki(std::string numerPrac) {
    auto aaa = [&](Pielegniarka pielegniarka) {
        if (pielegniarka.PobierzNumerPrac() == numerPrac) {
            return true;
        } else {
            return false;
        }
    };
    auto wynik = std::ranges::find_if(pielegniarki_baza.begin(), pielegniarki_baza.end(), aaa);

    if (wynik != pielegniarki_baza.end()) {
        return new Pielegniarka(wynik->PobierzImie(), wynik->PobierzNazwisko(), wynik->PobierzTelefon(),
                                wynik->PobierzAdres(), wynik->PobierzPokoj(), wynik->PobierzGodzPrac(),
                                wynik->PobierzNumerPrac());
    }
    return nullptr;
}

Pacjent *Szukanie::SzukajPacjenta(std::string pesel) {
    auto aaa = [&](Pacjent pacjent) {
        if (pacjent.PobierzPesel() == pesel) {
            return true;
        } else {
            return false;
        }
    };

    auto wynik = std::ranges::find_if(pacjenci_baza.begin(), pacjenci_baza.end(), aaa);
    if (wynik != pacjenci_baza.end()) {
        return new Pacjent(wynik->PobierzImie(), wynik->PobierzNazwisko(), wynik->PobierzTelefon(),
                           wynik->PobierzAdres(), wynik->PobierzNFZ(), wynik->PobierzPesel(), wynik->PobierzDateUr());
    }
    return nullptr;

}

void Szukanie::Wyszukaj() {
    osobaWyszukana = nullptr;
    std::string tmp = szukajka.getString();

    if (szukajka.getString().getSize() == 4) {
        osobaWyszukana = SzukajLekrza(tmp);
    }
    else if(szukajka.getString().getSize() ==2)
    {
        osobaWyszukana = SzukajPielegniarki(tmp);
    }
    else if (szukajka.getString().getSize() == 11) {
        osobaWyszukana = SzukajPacjenta(tmp);
    }
    if (osobaWyszukana != nullptr) {
        wynikoweOkno.setString(osobaWyszukana->JakoString());
    } else {
        wynikoweOkno.setString("");
    }
}

void Szukanie::UstawAdmin(bool admin) {
    this->admin=admin;
}

Osoba* Szukanie::WyszukanaOsoba() {
    return osobaWyszukana;
}