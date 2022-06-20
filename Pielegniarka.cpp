#include "Pielegniarka.h"


//**KONSTRUKTOR**//
Pielegniarka::Pielegniarka( std::string imie, std::string nazwisko, std::string numerTelefonu, std::string adres, int pokoj, std::vector<std::string> godzPrac, std::string numerPrac): Osoba (imie, nazwisko,numerTelefonu, adres),pokoj(pokoj), godzPrac(godzPrac), numerPrac(numerPrac)  {}


int Pielegniarka::PobierzPokoj() {
    return pokoj;
}

std::vector<std::string> Pielegniarka::PobierzGodzPrac() {
    return godzPrac;
}

std::string Pielegniarka::PobierzNumerPrac() {
    return numerPrac;
}

std::string Pielegniarka::JakoString() {
    std::string x="";

    x+="Numer pracownika:     ";
    x+=numerPrac;
    x+="\n";

    x+=imie;
    x+=" ";
    x+=nazwisko;
    x+="\n";

    x+="Numer pokoju:";
    x+=std::to_string(pokoj);
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