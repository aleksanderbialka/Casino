#ifndef CASINO_MENU_H
#define CASINO_MENU_H

#include "Gracz.h"
#include "JednorekiBandyta.h"
#include "Ruletka.h"
#include "BlackJack.h"
#include <vector>

using namespace std;

class Menu : public Gracz {
private:
    Gracz *gracz;
    JednorekiBandyta *jednoreki;
    Ruletka *ruletka;
    BlackJack *black;
    vector<Gracz> dane;


protected:
    int wybor;
    int wczytajWybor();
    void pokazMenu();
    void zapisywaniedoProgramu();
    void sortowanieListyWynikowWedlugSalda();
    void zapisywanieDoPliku();
    void odczyt();

public:
    Menu(Gracz *gracz);
    ~Menu();
    Menu();
    void wyborOpcji();
};

#endif //CASINO_MENU_H
