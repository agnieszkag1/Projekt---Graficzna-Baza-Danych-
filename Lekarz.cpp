#include "Lekarz.h"


//**KONSTRUKTOR**//
Lekarz::Lekarz( std::string imie, std::string nazwisko,
                std::string numerTelefonu, std::string adres,
                std::string specjalizacja, std::vector<std::string> godzPrac,
                std::string numerPrac)
                : Osoba (imie, nazwisko,numerTelefonu, adres),
                specjalizacja(specjalizacja),godzPrac(godzPrac),
                numerPrac(numerPrac)  {}


std::string Lekarz::PobierzSpecjalizacje() {
    return specjalizacja;
}
std::vector<std::string> Lekarz::PobierzGodzPrac() {
    return godzPrac;
}
std::string Lekarz::PobierzNumerPrac() {
    return numerPrac;
}

std::string Lekarz::JakoString() {
    std::string x="";

    x+="Numer pracownika:     ";
    x+=numerPrac;
    x+="\n";

    x+=imie;
    x+=" ";
    x+=nazwisko;

    x+=" - ";
    x+=specjalizacja;
    x+="\n";

    x+="Numer telefonu:     ";
    x+=numerTelefonu;
    x+="\n";

    x+="Adres:     ";
    x+=adres;
    x+="\n";
    x+="\n";

    x+="Godziny pracy (pn - wt - sr itd):    ";
    x+="\n";

    for(int i=0;i<godzPrac.size();i++)
    {
        if(i%3==1)
        {
            if(godzPrac[i]=="0")
            {
                x+="Nie pracuje";
                x+="\n";
                i+=2;
                continue;
            }
            x+=godzPrac[i];
            x+="-";
        }
        if(i%3==2)
        {
            x+=godzPrac[i];
            x+="\n";
        }
    }

    return x;
}
