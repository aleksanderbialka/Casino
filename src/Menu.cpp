#include "../headers/Menu.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

Menu::Menu(Gracz *gracz) {
    this->gracz = gracz;
    this->jednoreki = new JednorekiBandyta(gracz);
    this->ruletka = new Ruletka(gracz);
    this->black = new BlackJack(gracz);
}

Menu::~Menu() {
    delete jednoreki;
    delete ruletka;
    delete black;
}

int Menu::wczytajWybor() {
    int wybor;
    pokazMenu();
    cin >> wybor;
    cin.ignore();
    return wybor;
}

void Menu::pokazMenu() {
    cout << "\nTwoje saldo to: " << gracz->srodki
         << " \nWybierz w co chcesz zagrać: \n1. Jednoręki bandyta \n2. Ruletka "
            "\n3. BlackJack \n4. Pokaż ranking \n0. Zakończ grę \n>>";
}

void Menu::zapisywaniedoProgramu() {
    ifstream plikOdczyt("../Ranking.txt");
    string linia;

    while (getline(plikOdczyt, linia)) {
        if (linia.find("Nazwa gracza:") != string::npos) {
            Gracz gracz;
            gracz.nazwaGracza = linia.substr(linia.find(":") + 1, (linia.find(",") - (linia.find(":") + 1)));
            gracz.srodki = stoi(linia.substr(linia.find(",") + 8, (linia.find("\n") - (linia.find(",") + 8))));
            dane.push_back(gracz);
        }
    }
    plikOdczyt.close();
    dane.push_back(*gracz);
}

void Menu::sortowanieListyWynikowWedlugSalda() {
    sort(dane.begin(), dane.end(), [](Gracz &a, Gracz &b) {
        return a.srodki > b.srodki;
    });
}

void Menu::zapisywanieDoPliku() {
    zapisywaniedoProgramu();
    sortowanieListyWynikowWedlugSalda();

    ofstream plikZapis("../Ranking.txt", ios::out | ios::trunc);
    plikZapis << "Ranking TOP 100 graczy:\n";

    for (int i = 0; i < dane.size(); i++) {
        plikZapis << "Nazwa gracza: " << dane.at(i).nazwaGracza << ", Saldo: " << dane.at(i).srodki << endl;
    }
    plikZapis.close();
}

void Menu::odczyt() {
    for (const auto &gracz : dane) {
        cout << "Nazwa gracza: "<< gracz.nazwaGracza << "   $ Saldo: " << gracz.srodki << endl;
    }
}

void Menu::wyborOpcji() {
    int nrOpcji;

    do {
        nrOpcji = wczytajWybor();
        if (nrOpcji == 0) {
            cout << "Dziękujemy za wizytę!" << endl;
            cout << "Twoje saldo końcowe to: " << gracz->srodki << endl;
            cout << "Twoje dane zostały zapisane do Rankingu" << endl;
            zapisywanieDoPliku();
            break;
        }
        switch (nrOpcji) {
            case 1:
                jednoreki->graj();
                break;
            case 2:
                ruletka->graj();
                break;
            case 3:
                black->graj();
                break;
            case 4:
                zapisywaniedoProgramu();
                sortowanieListyWynikowWedlugSalda();
                odczyt();
                dane.clear();
                cout << "Naciśnij Enter, aby powrócić do menu głównego...";
                cin.get();
                break;
            default:
                cout << "Nie ma takiej opcji w menu!" << endl;
                cout << "Naciśnij Enter, aby powrócić do menu głównego...";
                cin.get();
                break;
        }
    } while (gracz->srodki > 0);

    if (gracz->srodki <= 0) {
        cout << "Brak dalszych środków do gry. Dziękujemy za wizytę!" << endl;
        exit(0);
    }
}
