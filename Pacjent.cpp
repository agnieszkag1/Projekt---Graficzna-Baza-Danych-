#include "Pacjent.h"


//**KONSTRUKTOR**//
Pacjent::Pacjent(std::string imie, std::string nazwisko,
                 std::string numerTelefonu, std::string adres,
                 std::string numerNFZ, std::string pesel, std::string dataUr)
                 : Osoba (imie, nazwisko,numerTelefonu, adres),
                 pesel(pesel), dataUr(dataUr), numerNFZ(numerNFZ)  {}

std::string Pacjent::PobierzPesel() {
    return pesel;
}
std::string Pacjent::PobierzDateUr() {
    return dataUr;
}
std::string Pacjent::PobierzNFZ() {
    return numerNFZ;
}

std::string Pacjent::JakoString() {
    std::string x="";

    x+="Pesel:   ";
    x+=pesel;
    x+=" ||  Numer NFZ:    ";
    x+=numerNFZ;
    x+="\n";
    x+="\n";

    x+=imie;
    x+=" ";
    x+=nazwisko;
    x+="\n";

    x+="Data urodzenia:     ";
    x+=dataUr;
    x+="\n";

    x+="Numer telefonu:     ";
    x+=numerTelefonu;
    x+="\n";

    x+="Adres:     ";
    x+=adres;
    x+="\n";



    return x;
}