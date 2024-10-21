#ifndef CASINO_GRACZ_H
#define CASINO_GRACZ_H

#include "Logowanie.h"

using namespace std;

class Gracz : public Logowanie {
public:
    int srodki;
    string nazwaGracza;

    Gracz(Logowanie *logowanie);
    Gracz();

    void ustalNazwe(string nazwa);
    string podajNazwe();

    void ustalSrodki(int srodki);
    int podajSrodki();

    void ustalNumer(int numerGracza);
};

#endif

