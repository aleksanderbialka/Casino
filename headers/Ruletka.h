#ifndef CASINO_RULETKA_H
#define CASINO_RULETKA_H

#include "Gracz.h"

using namespace std;

class Ruletka : public Gracz {
private:
    Gracz *gracz;
    int stawka;
    int wybor;
    int wylosowanyNumer;

public:
    Ruletka();
    Ruletka(Gracz *gracz);
    void graj();
    int losujLiczbe();
    bool ustalKolor(int liczba, string &nazwaKoloru);
    void postawNaKolory();
    void postawLiczbe();
    void postawParzystosc();
    void wyborZakresu(int liczba);
};

#endif //CASINO_RULETKA_H
