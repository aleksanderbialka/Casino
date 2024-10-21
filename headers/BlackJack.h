#ifndef CASINO_BLACKJACK_H
#define CASINO_BLACKJACK_H

#include "Gracz.h"
#include <vector>

using namespace std;

class BlackJack : public Gracz {
private:
    int stawka;
    Gracz *gracz;
    int wybor;

    struct Karta {
        int wartosc;
        string kolor;
        string typ;
    };

public:
    BlackJack();
    BlackJack(Gracz *gracz);
    vector<Karta> talia;
    vector<Karta> rekaGracza;
    vector<Karta> rekaKrupiera;

    void stworzTalie();
    void tasujTalie();
    void rozdajKarty();
    void wyswietlKartyGracza();
    void wyswietlKartyKrupiera();
    void wyswietlWartoscGracza();
    void wyswietlWartoscKrupiera();
    void graj();

    bool czyWygranaKrupiera();
    bool czyRemisKrupiera();
    bool czyWygranaGracza();
    bool czyRemis();
    bool czyWygrana();
    bool czyPrzegrana();
};

#endif //CASINO_BLACKJACK_H
