#include "Aplikacja.h"

using namespace std;


//KONSTRUKTOR RENDER WINDOW//
Aplikacja::Aplikacja() : okno(sf::VideoMode(1280, 800), "BAZA DANYCH - PRZYCHODNIA",
                              sf::Style::Titlebar | sf::Style::Close) {

    WczytajDane();
    logowanie.UstawCzcionke(czcionka);
    szukanie.UstawCzcionke(czcionka);
    dodawanie.UstawCzcionke(czcionka);
    szukanie.UstawWektory(Pielegniarki, Lekarze, Pacjenci);
    czyLogowanie = true;
    logowanieOkno1 = false;
    logowanieOkno2 = false;

    admin = false;

    czySzukanie = false;

    czyDodawanie = false;

    dodawanieImie = false;
    dodawanieNazwisko = false;
    dodawanieNumerTelefonu = false;
    dodawanieAdres = false;
    dodawaniePesel = false;
    dodawanieNumerPrac = false;
    dodawaniePokoj = false;
    dodawanieGodziny = false;
    dodawanieDataUr = false;
    dodawanieNumerNFZ = false;
    dodawanieSpecjalizacja = false;

    GlownaPetla();

}

//WCZYTYWANIE DANYCH Z PLIKU//
void Aplikacja::WczytajDane() {

    if (!czcionka.loadFromFile("Lato-Regular.ttf")) {
        std::cout << "Wystapil blad z wczytaniem czcionki" << std::endl;
        return;
    }

    filesystem::path sciezka = std::filesystem::current_path();

    sciezka = sciezka.parent_path();

    filesystem::path sciezkaLekarz = sciezka / "\Lekarze.txt";
    filesystem::path sciezkaPacjent = sciezka / "\Pacjenci.txt";
    filesystem::path sciezkaPielegniarka = sciezka / "\Pielegniarki.txt";


    ifstream lekarze(sciezkaLekarz);
    ifstream pacjenci(sciezkaPacjent);
    ifstream pielegniarki(sciezkaPielegniarka);
    if (!lekarze.is_open()) {
        cout << "Nie otwarto Lekarze.txt" << endl;
        return;
    }
    if (!pacjenci.is_open()) {
        cout << "Nie otwarto Pacjenci.txt" << endl;
        return;
    }
    if (!pielegniarki.is_open()) {
        cout << "Nie otwarto Pielegniarki.txt" << endl;
        return;
    }

    WczytajLekarzy l;
    WczytajPielegniarki p1;
    WczytajPacjentow p2;

    thread wczytLekarzy(l, ref(lekarze), ref(Lekarze));
    thread wczytPiel(p1, ref(pielegniarki), ref(Pielegniarki));
    thread wczytPacj(p2, ref(pacjenci), ref(Pacjenci));

    wczytLekarzy.join();
    wczytPiel.join();
    wczytPacj.join();

    lekarze.close();
    pielegniarki.close();
    pacjenci.close();

    CzyIstniejeLekarz();
    CzyIstniejePielegniarka();
    CzyIstniejePacjent();
}

void Aplikacja::GlownaPetla() {

    while (okno.isOpen()) {
        ObsluzZdarzenia();
        Rysuj();
    }
}

void Aplikacja::ObsluzZdarzenia() {
    sf::Event zdarzenie;
    while (okno.pollEvent(zdarzenie)) {
        if (zdarzenie.type == sf::Event::Closed) {
            ZapiszDoPlików(); // zapisanie danych zanim zamknie się okno
            okno.close();
        }
        if (czyLogowanie) {
            if (zdarzenie.type == sf::Event::MouseButtonPressed) {
                if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 650 &&
                    zdarzenie.mouseButton.y >= 208 &&
                    zdarzenie.mouseButton.y <= 253) {
                    logowanieOkno1 = true;
                    logowanieOkno2 = false;
                } else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 650 &&
                           zdarzenie.mouseButton.y >= 308 &&
                           zdarzenie.mouseButton.y <= 353) {
                    logowanieOkno1 = false;
                    logowanieOkno2 = true;
                } else {
                    logowanieOkno1 = false;
                    logowanieOkno2 = false;
                }
            }
            if (logowanieOkno1) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        logowanie.DodajZnak(tmp2, 1);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        logowanie.DodajZnak(tmp2, 1);
                    }
                    if (zdarzenie.key.code == 59) {
                        logowanie.UsunZnak(1);
                    }
                }
            }
            if (logowanieOkno2) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        logowanie.DodajZnak(tmp2, 2);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        logowanie.DodajZnak(tmp2, 2);
                    }
                    if (zdarzenie.key.code == 59) {
                        logowanie.UsunZnak(2);
                    }
                }
            }
            if (zdarzenie.type == sf::Event::KeyPressed) {
                if (zdarzenie.key.code == 58) {
                    if (logowanie.CzyPoprawneLogowanie()) {
                        admin = logowanie.CzyAdmin();
                        szukanie.UstawAdmin(admin);
                        czyLogowanie = false;
                        czySzukanie = true;
                    }
                }
            }
        }
        else if (czySzukanie) {
            if (zdarzenie.type == sf::Event::KeyPressed) {
                if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                    int tmp = zdarzenie.key.code - 26;
                    std::string tmp2 = to_string(tmp);
                    szukanie.DodajZnak(tmp2);
                }

                if (zdarzenie.key.code == 59) {
                    szukanie.UsunZnak();
                }
                if (zdarzenie.key.code == 58) {
                    szukanie.UstawWektory(Pielegniarki, Lekarze, Pacjenci);
                    szukanie.Wyszukaj();
                }
                if (zdarzenie.key.code == 36) {
                    czySzukanie = false;
                    czyLogowanie = true;
                }
            } else if (admin && zdarzenie.type == sf::Event::MouseButtonPressed) {
                if (zdarzenie.mouseButton.x >= 800 && zdarzenie.mouseButton.x <= 1000 &&
                    zdarzenie.mouseButton.y >= 700 &&
                    zdarzenie.mouseButton.y <= 750) {

                    Osoba *a = szukanie.WyszukanaOsoba();
                    if (a != nullptr) {
                        if (Lekarz *b = dynamic_cast<Lekarz *>(a);b != nullptr) // dopasowanie do lekarza
                        {
                            for (int i = 0; i < Lekarze.size(); i++) {
                                if (*b == Lekarze[i]) {
                                    Lekarze.erase(Lekarze.begin() + i);
                                }
                            }
                        }

                        if (Pielegniarka *c = dynamic_cast<Pielegniarka *>(a);c !=
                                                                              nullptr) // dopasowanie do pielegniarki
                        {
                            for (int i = 0; i < Pielegniarki.size(); i++) {
                                if (*c == Pielegniarki[i]) {
                                    Pielegniarki.erase(Pielegniarki.begin() + i);
                                }
                            }
                        }

                        if (Pacjent *d = dynamic_cast<Pacjent *>(a);d != nullptr) // dopasowanie do pielegniarki
                        {
                            for (int i = 0; i < Pacjenci.size(); i++) {
                                if (*d == Pacjenci[i]) {
                                    Pacjenci.erase(Pacjenci.begin() + i);
                                }
                            }
                        }


                    }
                } else if (zdarzenie.mouseButton.x >= 1050 && zdarzenie.mouseButton.x <= 1250 &&
                           zdarzenie.mouseButton.y >= 700 &&
                           zdarzenie.mouseButton.y <= 750) {
                    czyDodawanie = true;
                    czySzukanie = false;
                    // Dodawanie Pacjenta
                    dodawanie.UstawStan(2);
                } else if (zdarzenie.mouseButton.x >= 1050 && zdarzenie.mouseButton.x <= 1250 &&
                           zdarzenie.mouseButton.y >= 580 &&
                           zdarzenie.mouseButton.y <= 630) {
                    czyDodawanie = true;
                    czySzukanie = false;
                    // Dodawanie Pielegniarke
                    dodawanie.UstawStan(1);
                } else if (zdarzenie.mouseButton.x >= 1050 && zdarzenie.mouseButton.x <= 1250 &&
                           zdarzenie.mouseButton.y >= 640 &&
                           zdarzenie.mouseButton.y <= 690) {
                    czyDodawanie = true;
                    czySzukanie = false;
                    // Dodawanie Lekarza
                    dodawanie.UstawStan(0);
                }
            }
        }
        else if (czyDodawanie) {
            int stan=dodawanie.PobierzStan();

            //DLA DODAWANIA USTAWIENIE OKIEN TEKSTOWYCH//
            if (zdarzenie.type == sf::Event::MouseButtonPressed) {
                if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                    zdarzenie.mouseButton.y >= 20 &&
                    zdarzenie.mouseButton.y <= 65) {
                    dodawanieImie=true;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                           zdarzenie.mouseButton.y >= 75 &&
                           zdarzenie.mouseButton.y <= 120) {
                    dodawanieImie=false;
                    dodawanieNazwisko=true;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 130 &&
                         zdarzenie.mouseButton.y <= 175) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=true;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 185 &&
                         zdarzenie.mouseButton.y <= 230) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=true;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 240 &&
                         zdarzenie.mouseButton.y <= 285&&stan==2) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=true;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 240 &&
                         zdarzenie.mouseButton.y <= 285&&(stan==0||stan==1)) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=true;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 350 &&
                         zdarzenie.mouseButton.y <= 395&&stan==1) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=true;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 295 &&
                         zdarzenie.mouseButton.y <= 340&&(stan==0||stan==1)) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=true;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 295 &&
                         zdarzenie.mouseButton.y <= 340&&stan==2) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=true;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 350 &&
                         zdarzenie.mouseButton.y <= 395&&stan==2) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=true;
                    dodawanieSpecjalizacja=false;
                }
                else if (zdarzenie.mouseButton.x >= 350 && zdarzenie.mouseButton.x <= 1250 &&
                         zdarzenie.mouseButton.y >= 350 &&
                         zdarzenie.mouseButton.y <= 395&&stan==0) {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=true;
                }

                else {
                    dodawanieImie=false;
                    dodawanieNazwisko=false;
                    dodawanieNumerTelefonu=false;
                    dodawanieAdres=false;
                    dodawaniePesel=false;
                    dodawanieNumerPrac=false;
                    dodawaniePokoj=false;
                    dodawanieGodziny=false;
                    dodawanieDataUr=false;
                    dodawanieNumerNFZ=false;
                    dodawanieSpecjalizacja=false;
                }
            }

            if (dodawanieImie) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 1);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 1);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(1);
                    }
                }
            }
            else if (dodawanieNazwisko) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 2);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 2);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(2);
                    }
                }
            }else if (dodawanieNumerTelefonu) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 3);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 3);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(3);
                    }
                }
            }
            else if (dodawanieAdres) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code ==56) {
                        char tmp ='_';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 4);
                    }
                    if (zdarzenie.key.code ==52) {
                        char tmp ='/';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 4);
                    }
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 4);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 4);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(4);
                    }
                }
            }
            else if (dodawaniePesel) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 5);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 5);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(5);
                    }
                }
            }
            else if (dodawanieNumerPrac) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 6);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 6);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(6);
                    }
                }
            }
            else if (dodawaniePokoj) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 7);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 7);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(7);
                    }
                }
            }
            else if (dodawanieGodziny) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 8);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 8);
                    }
                    if(zdarzenie.key.code==57)
                    {
                        char tmp = ' ';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 8);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(8);
                    }
                }
            }
            else if (dodawanieDataUr) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 9);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 9);
                    }
                    if (zdarzenie.key.code ==50) {
                        char tmp = '.';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 9);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(9);
                    }
                }
            }
            else if (dodawanieNumerNFZ) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 10);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 10);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(10);
                    }
                }
            }
            else if (dodawanieSpecjalizacja) {
                if (zdarzenie.type == sf::Event::KeyPressed) {
                    if (zdarzenie.key.code >= 26 && zdarzenie.key.code <= 35) {
                        int tmp = zdarzenie.key.code - 26;
                        std::string tmp2 = to_string(tmp);
                        dodawanie.DodajZnak(tmp2, 11);
                    }
                    if (zdarzenie.key.code >= 0 && zdarzenie.key.code <= 25) {
                        char tmp = (char) (zdarzenie.key.code);
                        tmp += 'A';
                        std::string tmp2(1, tmp);
                        dodawanie.DodajZnak(tmp2, 11);
                    }
                    if (zdarzenie.key.code == 59) {
                        dodawanie.UsunZnak(11);
                    }
                }
            }

            if (zdarzenie.key.code == 58) {
                int stan = dodawanie.PobierzStan();
                if (stan == 0) {
                    Lekarze.push_back(dodawanie.DodajLekarza());
                    CzyIstniejeLekarz();
                    czySzukanie = true;
                    czyDodawanie = false;

                } else if (stan == 1) {
                    Pielegniarki.push_back(dodawanie.DodajPielegniarka());
                    CzyIstniejePielegniarka();
                    czySzukanie = true;
                    czyDodawanie = false;
                } else if (stan == 2) {
                    Pacjenci.push_back(dodawanie.DodajPacjenta());
                    CzyIstniejePacjent();
                    czySzukanie = true;
                    czyDodawanie = false;
                }
            }
            if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == 36) {
                czySzukanie = true;
                czyDodawanie = false;
            }
        }
    }
}

void Aplikacja::Rysuj() {
    if (okno.isOpen()) {
        okno.clear(sf::Color(13, 41, 61, 255));
        if (czyLogowanie) {
            logowanie.Rysuj(okno);
        } else if (czySzukanie) {
            szukanie.Rysuj(okno);
        } else if (czyDodawanie) {
            dodawanie.Rysuj(okno);
        }

        okno.display();
    }
}

void Aplikacja::ZapiszDoPlików() {
    std::ofstream plik;
    std::string linia;

    filesystem::path sciezka = std::filesystem::current_path();

    //sciezka = sciezka.parent_path();

    filesystem::path sciezkaLekarz = sciezka / "Lekarze.txt";
    filesystem::path sciezkaPacjent = sciezka / "Pacjenci.txt";
    filesystem::path sciezkaPielegniarka = sciezka / "Pielegniarki.txt";

    plik.open(sciezkaLekarz);
    if (!plik.good()) {
        std::cout << "PLIK NIE ZOSTAŁ OTWARTY POPRAWNIE1";
        return;
    }


    for (auto lekarz: Lekarze) {
        std::string tmp = lekarz.PobierzAdres();
        plik << lekarz.PobierzImie() << " " << lekarz.PobierzNazwisko() << " " << tmp << " "
             << lekarz.PobierzSpecjalizacje() << " " << lekarz.PobierzNumerPrac() << "\n";
        int i = 0;
        for (auto godziny: lekarz.PobierzGodzPrac()) {
            i++;
            plik << godziny << " ";
            if (i >= 3) {
                plik << "\n";
                i = 0;
            }
        }
    }
    plik.close();

    plik.open(sciezkaPielegniarka);
    if (!plik.good()) {
        std::cout << "PLIK NIE ZOSTAŁ OTWARTY POPRAWNIE2";
        return;
    }
    for (auto p: Pielegniarki) {
        plik << p.PobierzImie() << " " << p.PobierzNazwisko() << " " << p.PobierzTelefon() << " " << p.PobierzAdres()
             << " " << p.PobierzNumerPrac() << " " << p.PobierzPokoj() << "\n";
        int i = 0;
        for (auto g: p.PobierzGodzPrac()) {
            i++;
            plik << g << " ";
            if (i >= 3) {
                plik << "\n";
                i = 0;
            }
        }
    }

    plik.close();

    plik.open(sciezkaPacjent);
    if (!plik.good()) {
        std::cout << "PLIK NIE ZOSTAŁ OTWARTY POPRAWNIE3";
        return;
    }
    for (auto p: Pacjenci) {
        plik << p.PobierzImie() << " " << p.PobierzNazwisko() << " " << p.PobierzPesel() << " " << p.PobierzDateUr()
             << " " << p.PobierzTelefon() << " " << p.PobierzAdres() << " " << p.PobierzNFZ() << "\n";
    }

    plik.close();
}

void Aplikacja::CzyIstniejeLekarz() {

    std::sort(Lekarze.begin(), Lekarze.end(), [](Lekarz a, Lekarz b) {
        return a.PobierzNumerPrac() < b.PobierzNumerPrac();
    });

    for (int i = 0; i < Lekarze.size() - 1; i++) {

        if (Lekarze[i].PobierzNumerPrac() == Lekarze[i + 1].PobierzNumerPrac()) {
            Lekarze.erase(Lekarze.begin() + i + 1);
        }
    }
}

void Aplikacja::CzyIstniejePielegniarka() {

    std::sort(Pielegniarki.begin(), Pielegniarki.end(), [](Pielegniarka a, Pielegniarka b) {
        return a.PobierzNumerPrac() < b.PobierzNumerPrac();
    });

    for (int i = 0; i < Pielegniarki.size() - 1; i++) {

        if (Pielegniarki[i].PobierzNumerPrac() == Pielegniarki[i + 1].PobierzNumerPrac()) {
            Pielegniarki.erase(Pielegniarki.begin() + i + 1);
        }
    }

}

void Aplikacja::CzyIstniejePacjent() {
    std::sort(Pacjenci.begin(), Pacjenci.end(), [](Pacjent a, Pacjent b) {
        return a.PobierzPesel() < b.PobierzPesel();
    });


    for (int i = 0; i < Pacjenci.size() - 1; i++) {
        if (Pacjenci[i].PobierzPesel() == Pacjenci[i + 1].PobierzPesel()) {
            Pacjenci.erase(Pacjenci.begin() + i + 1);
        }
    }

}

