#include "Dodawanie.h"

Dodawanie::Dodawanie() {
    stan=0;
}

void Dodawanie::UstawTeksty() {
    ImiePole.setSize(sf::Vector2f(900, 45));
    ImiePole.setFillColor(sf::Color(228, 214, 189, 255));
    ImiePole.setPosition(350, 20);

    ImieWart.setFont(czcionka);
    ImieWart.setString("");
    ImieWart.setCharacterSize(45);
    ImieWart.setFillColor(sf::Color(60, 86, 99, 255));
    ImieWart.setPosition(360, 15);

    Imie.setFont(czcionka);
    Imie.setString("Imie:");
    Imie.setCharacterSize(45);
    Imie.setFillColor(sf::Color(255, 255, 255, 255));
    Imie.setPosition(10, 15);

    NazwiskoPole.setSize(sf::Vector2f(900, 45));
    NazwiskoPole.setFillColor(sf::Color(228, 214, 189, 255));
    NazwiskoPole.setPosition(350, 75);

    NazwiskoWart.setFont(czcionka);
    NazwiskoWart.setString("");
    NazwiskoWart.setCharacterSize(45);
    NazwiskoWart.setFillColor(sf::Color(60, 86, 99, 255));
    NazwiskoWart.setPosition(360, 70);//55

    Nazwisko.setFont(czcionka);
    Nazwisko.setString("Nazwisko:");
    Nazwisko.setCharacterSize(45);
    Nazwisko.setFillColor(sf::Color(255, 255, 255, 255));
    Nazwisko.setPosition(10, 70); //55

    NumerTelefonuPole.setSize(sf::Vector2f(900, 45));
    NumerTelefonuPole.setFillColor(sf::Color(228, 214, 189, 255));
    NumerTelefonuPole.setPosition(350, 130);

    NumerTelefonuWart.setFont(czcionka);
    NumerTelefonuWart.setString("");
    NumerTelefonuWart.setCharacterSize(45);
    NumerTelefonuWart.setFillColor(sf::Color(60, 86, 99, 255));
    NumerTelefonuWart.setPosition(360, 125);

    NumerTelefonu.setFont(czcionka);
    NumerTelefonu.setString("Numer tel:");
    NumerTelefonu.setCharacterSize(45);
    NumerTelefonu.setFillColor(sf::Color(255, 255, 255, 255));
    NumerTelefonu.setPosition(10, 125);

    AdresPole.setSize(sf::Vector2f(900, 45));
    AdresPole.setFillColor(sf::Color(228, 214, 189, 255));
    AdresPole.setPosition(350, 185);

    AdresWart.setFont(czcionka);
    AdresWart.setString("");
    AdresWart.setCharacterSize(45);
    AdresWart.setFillColor(sf::Color(60, 86, 99, 255));
    AdresWart.setPosition(360, 180);

    Adres.setFont(czcionka);
    Adres.setString("Adres:");
    Adres.setCharacterSize(45);
    Adres.setFillColor(sf::Color(255, 255, 255, 255));
    Adres.setPosition(10, 180);

    PeselPole.setSize(sf::Vector2f(900, 45));
    PeselPole.setFillColor(sf::Color(228, 214, 189, 255));
    PeselPole.setPosition(350, 240);

    PeselWart.setFont(czcionka);
    PeselWart.setString("");
    PeselWart.setCharacterSize(45);
    PeselWart.setFillColor(sf::Color(60, 86, 99, 255));
    PeselWart.setPosition(360, 235);

    Pesel.setFont(czcionka);
    Pesel.setString("Pesel:");
    Pesel.setCharacterSize(45);
    Pesel.setFillColor(sf::Color(255, 255, 255, 255));
    Pesel.setPosition(10, 235);

    NumerPracPole.setSize(sf::Vector2f(900, 45));
    NumerPracPole.setFillColor(sf::Color(228, 214, 189, 255));
    NumerPracPole.setPosition(350, 240);

    NumerPracWart.setFont(czcionka);
    NumerPracWart.setString("");
    NumerPracWart.setCharacterSize(45);
    NumerPracWart.setFillColor(sf::Color(60, 86, 99, 255));
    NumerPracWart.setPosition(360, 235);

    NumerPrac.setFont(czcionka);
    NumerPrac.setString("Numer prac:");
    NumerPrac.setCharacterSize(45);
    NumerPrac.setFillColor(sf::Color(255, 255, 255, 255));
    NumerPrac.setPosition(10, 235);

    PokojPole.setSize(sf::Vector2f(900, 45));
    PokojPole.setFillColor(sf::Color(228, 214, 189, 255));
    PokojPole.setPosition(350, 350);

    PokojWart.setFont(czcionka);
    PokojWart.setString("");
    PokojWart.setCharacterSize(45);
    PokojWart.setFillColor(sf::Color(60, 86, 99, 255));
    PokojWart.setPosition(360, 345);

    Pokoj.setFont(czcionka);
    Pokoj.setString("Numer pokoju:");
    Pokoj.setCharacterSize(45);
    Pokoj.setFillColor(sf::Color(255, 255, 255, 255));
    Pokoj.setPosition(10, 345);

    GodzinyPole.setSize(sf::Vector2f(900, 45));
    GodzinyPole.setFillColor(sf::Color(228, 214, 189, 255));
    GodzinyPole.setPosition(350, 295);

    GodzinyWart.setFont(czcionka);
    GodzinyWart.setString("");
    GodzinyWart.setCharacterSize(35);
    GodzinyWart.setFillColor(sf::Color(60, 86, 99, 255));
    GodzinyWart.setPosition(360, 295);

    Godziny.setFont(czcionka);
    Godziny.setString("Godz:");
    Godziny.setCharacterSize(45);
    Godziny.setFillColor(sf::Color(255, 255, 255, 255));
    Godziny.setPosition(10, 290);

    SpecjalizacjaPole.setSize(sf::Vector2f(900, 45));
    SpecjalizacjaPole.setFillColor(sf::Color(228, 214, 189, 255));
    SpecjalizacjaPole.setPosition(350, 350);

    SpecjalizacjaWart.setFont(czcionka);
    SpecjalizacjaWart.setString("");
    SpecjalizacjaWart.setCharacterSize(45);
    SpecjalizacjaWart.setFillColor(sf::Color(60, 86, 99, 255));
    SpecjalizacjaWart.setPosition(360, 345);

    Specjalizacja.setFont(czcionka);
    Specjalizacja.setString("Specjalizacja:");
    Specjalizacja.setCharacterSize(45);
    Specjalizacja.setFillColor(sf::Color(255, 255, 255, 255));
    Specjalizacja.setPosition(10, 345);

    DataUrPole.setSize(sf::Vector2f(900, 45));
    DataUrPole.setFillColor(sf::Color(228, 214, 189, 255));
    DataUrPole.setPosition(350, 295);

    DataUrWart.setFont(czcionka);
    DataUrWart.setString("");
    DataUrWart.setCharacterSize(45);
    DataUrWart.setFillColor(sf::Color(60, 86, 99, 255));
    DataUrWart.setPosition(360, 290);

    DataUr.setFont(czcionka);
    DataUr.setString("Data ur:");
    DataUr.setCharacterSize(45);
    DataUr.setFillColor(sf::Color(255, 255, 255, 255));
    DataUr.setPosition(10, 290);

    NumerNFZPole.setSize(sf::Vector2f(900, 45));
    NumerNFZPole.setFillColor(sf::Color(228, 214, 189, 255));
    NumerNFZPole.setPosition(350, 350);

    NumerNFZWart.setFont(czcionka);
    NumerNFZWart.setString("");
    NumerNFZWart.setCharacterSize(45);
    NumerNFZWart.setFillColor(sf::Color(60, 86, 99, 255));
    NumerNFZWart.setPosition(360, 345);

    NumerNFZ.setFont(czcionka);
    NumerNFZ.setString("Numer NFZ:");
    NumerNFZ.setCharacterSize(45);
    NumerNFZ.setFillColor(sf::Color(255, 255, 255, 255));
    NumerNFZ.setPosition(10, 345);

    InstrukcjaPacjent.setFont(czcionka);
    InstrukcjaPacjent.setString("PRZYKLADOWE WYPELNIENIE: \n Imie: Jan \n Nazwisko: Kowalski \n Numer tel: "
                                "123456789\n Adres: Ulica_23/2_00-00_Warszawa \n Pesel: 09876543211 \n Data ur: 30.04.1977 \n"
                                "Numer NFZ: 1234A");
    InstrukcjaPacjent.setCharacterSize(30);
    InstrukcjaPacjent.setFillColor(sf::Color(255, 255, 255, 255));
    InstrukcjaPacjent.setPosition(10, 450);

    InstrukcjaPielegniarka.setFont(czcionka);
    InstrukcjaPielegniarka.setString("PRZYKLADOWE WYPELNIENIE: \n Imie: Jan \n Nazwisko: Kowalski \n Numer tel: "
                                "123456789\n Adres: Ulica_23/2_00-00_Warszawa \n Numer prac: 00 \n"
                                " Godz: 1 00 00 2 00 00 3 00 00 4 00 00 5 00 00 6 00 00 7 00 00\n Numer pokoju: 5");
    InstrukcjaPielegniarka.setCharacterSize(30);
    InstrukcjaPielegniarka.setFillColor(sf::Color(255, 255, 255, 255));
    InstrukcjaPielegniarka.setPosition(10, 450);

    InstrukcjaLekarz.setFont(czcionka);
    InstrukcjaLekarz.setString("PRZYKLADOWE WYPELNIENIE: \n Imie: Jan \n Nazwisko: Kowalski \n Numer tel: "
                                     "123456789\n Adres: Ulica_23/2_00-00_Warszawa \n Numer prac: 0000 \n"
                                     " Godz: 1 00 00 2 00 00 3 00 00 4 00 00 5 00 00 6 00 00 7 00 00\n Specjalizacja: kardiolog");
    InstrukcjaLekarz.setCharacterSize(30);
    InstrukcjaLekarz.setFillColor(sf::Color(255, 255, 255, 255));
    InstrukcjaLekarz.setPosition(10, 450);


}


Lekarz Dodawanie::DodajLekarza() {

    std::vector<std::string> godziny;
    std::string godz=GodzinyWart.getString();
    std::stringstream ss(godz);
    while(ss>>godz)
    {
        godziny.push_back(godz);
    }

        return Lekarz(ImieWart.getString(), NazwiskoWart.getString(), NumerTelefonuWart.getString(),
                      AdresWart.getString(), SpecjalizacjaWart.getString(), godziny, NumerPracWart.getString());
}


Pacjent Dodawanie::DodajPacjenta() {
    return Pacjent(ImieWart.getString(), NazwiskoWart.getString(), NumerTelefonuWart.getString(),
                  AdresWart.getString(), NumerNFZWart.getString(), PeselWart.getString(), DataUrWart.getString());
}

Pielegniarka Dodawanie::DodajPielegniarka()  {

    std::vector<std::string> godziny;
    std::string godz=GodzinyWart.getString();
    std::stringstream ss(godz);
    while(ss>>godz)
    {
        godziny.push_back(godz);
    }
    std::stringstream ss2(PokojWart.getString());
    int x=0;
    ss2>>x;

    return Pielegniarka(ImieWart.getString(), NazwiskoWart.getString(), NumerTelefonuWart.getString(),
                  AdresWart.getString(), x, godziny, NumerPracWart.getString());
}

void Dodawanie::Rysuj(sf::RenderWindow &okno) {

    okno.draw(Imie);
    okno.draw(ImiePole);
    okno.draw(ImieWart);

    okno.draw(Nazwisko);
    okno.draw(NazwiskoPole);
    okno.draw(NazwiskoWart);

    okno.draw(NumerTelefonu);
    okno.draw(NumerTelefonuPole);
    okno.draw(NumerTelefonuWart);

    okno.draw(Adres);
    okno.draw(AdresPole);
    okno.draw(AdresWart);

    if(stan==2) {
        okno.draw(InstrukcjaPacjent);
        okno.draw(Pesel);
        okno.draw(PeselPole);
        okno.draw(PeselWart);

        okno.draw(DataUr);
        okno.draw(DataUrPole);
        okno.draw(DataUrWart);

        okno.draw(NumerNFZ);
        okno.draw(NumerNFZPole);
        okno.draw(NumerNFZWart);
    }

    if(stan==0||stan==1) {
        okno.draw(NumerPrac);
        okno.draw(NumerPracPole);
        okno.draw(NumerPracWart);

        okno.draw(Godziny);
        okno.draw(GodzinyPole);
        okno.draw(GodzinyWart);
    }

    if(stan==1) {
        okno.draw(InstrukcjaPielegniarka);
        okno.draw(Pokoj);
        okno.draw(PokojPole);
        okno.draw(PokojWart);
    }

    if(stan==0) {
        okno.draw(InstrukcjaLekarz);
        okno.draw(Specjalizacja);
        okno.draw(SpecjalizacjaPole);
        okno.draw(SpecjalizacjaWart);
    }

}

void Dodawanie::DodajZnak(std::string znak, int okno) {
    switch (okno) {
        case 1: {
            std::string tmp = ImieWart.getString();
            tmp += znak;
            ImieWart.setString(tmp);
        }
            break;
        case 2: {
            std::string tmp = NazwiskoWart.getString();
            tmp += znak;
            NazwiskoWart.setString(tmp);
        }
            break;
        case 3: {
            std::string tmp = NumerTelefonuWart.getString();
            tmp += znak;
            NumerTelefonuWart.setString(tmp);
        }
            break;
        case 4: {
            std::string tmp = AdresWart.getString();
            tmp += znak;
            AdresWart.setString(tmp);
        }
            break;
        case 5: {
            std::string tmp = PeselWart.getString();
            tmp += znak;
            PeselWart.setString(tmp);
        }
            break;
        case 6: {
            std::string tmp = NumerPracWart.getString();
            tmp += znak;
            NumerPracWart.setString(tmp);
        }
            break;
        case 7: {
            std::string tmp = PokojWart.getString();
            tmp += znak;
            PokojWart.setString(tmp);
        }
            break;
        case 8: {
            std::string tmp = GodzinyWart.getString();
            tmp += znak;
            GodzinyWart.setString(tmp);
        }
            break;
        case 9: {
            std::string tmp = DataUrWart.getString();
            tmp += znak;
            DataUrWart.setString(tmp);
        }
            break;
        case 10: {
            std::string tmp = NumerNFZWart.getString();
            tmp += znak;
            NumerNFZWart.setString(tmp);
        }
            break;
        case 11: {
            std::string tmp = SpecjalizacjaWart.getString();
            tmp += znak;
            SpecjalizacjaWart.setString(tmp);
        }
            break;
    }
}

void Dodawanie::UsunZnak(int okno) {
    switch (okno) {
        case 1: {
            std::string tmp = ImieWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            ImieWart.setString(tmp);
        }
            break;
        case 2: {
            std::string tmp = NazwiskoWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            NazwiskoWart.setString(tmp);
        }
            break;
        case 3: {
            std::string tmp = NumerTelefonuWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            NumerTelefonuWart.setString(tmp);
        }
            break;
        case 4: {
            std::string tmp = AdresWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            AdresWart.setString(tmp);
        }
            break;
        case 5: {
            std::string tmp = PeselWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            PeselWart.setString(tmp);
        }
            break;
        case 6: {
            std::string tmp = NumerPracWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            NumerPracWart.setString(tmp);
        }
            break;
        case 7: {
            std::string tmp = PokojWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            PokojWart.setString(tmp);
        }
            break;
        case 8: {
            std::string tmp = GodzinyWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            GodzinyWart.setString(tmp);
        }
            break;
        case 9: {
            std::string tmp = DataUrWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            DataUrWart.setString(tmp);
        }
            break;
        case 10: {
            std::string tmp = NumerNFZWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            NumerNFZWart.setString(tmp);
        }
            break;
        case 11: {
            std::string tmp = SpecjalizacjaWart.getString();
            if (tmp.empty()) {
                return;
            }
            tmp.pop_back();
            SpecjalizacjaWart.setString(tmp);
        }
            break;
    }
}