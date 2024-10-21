#include "../headers/Gracz.h"

Gracz::Gracz(Logowanie *logowanie) {
    ustalNazwe(logowanie->nazwa);
    ustalSrodki(logowanie->srodki);
    ustalNumer(logowanie->numerGracza);
}

Gracz::Gracz() {
    srodki = 0;
    numerGracza = 1;
    nazwaGracza = "Gracz";
}

void Gracz::ustalNazwe(string nazwa) {
    if (!nazwa.empty())
        Gracz::nazwaGracza = nazwa;
}

string Gracz::podajNazwe() {
    return nazwaGracza;
}

void Gracz::ustalSrodki(int srodki) {
    Gracz::srodki = srodki;
}

int Gracz::podajSrodki() {
    return Gracz::srodki;
}

void Gracz::ustalNumer(int numerGracza) {
    Gracz::numerGracza = numerGracza;
}
