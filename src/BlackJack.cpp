#include "../headers/BlackJack.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

BlackJack::BlackJack() {}

BlackJack::BlackJack(Gracz *gracz) {
    this->gracz = gracz;
}

void BlackJack::stworzTalie() {
    string kolory[4] = {"Kier", "Karo", "Trefl", "Pik"};
    string typy[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10",
                       "Jopek", "Dama", "Krol", "As"};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            Karta karta;
            karta.kolor = kolory[i];
            karta.typ = typy[j];
            if (j < 9)
                karta.wartosc = j + 2;
            else if (j>=9 && j<12)
                karta.wartosc = 10;
            else karta.wartosc = 11;
            talia.push_back(karta);
        }
    }
}

void BlackJack::tasujTalie() {
    random_device rd;
    mt19937 rng(rd());
    shuffle(talia.begin(), talia.end(), rng);
}

void BlackJack::rozdajKarty() {
    rekaGracza.push_back(talia.back());
    talia.pop_back();
    rekaKrupiera.push_back(talia.back());
    talia.pop_back();
    rekaGracza.push_back(talia.back());
    talia.pop_back();
    rekaKrupiera.push_back(talia.back());
    talia.pop_back();
}

void BlackJack::wyswietlKartyGracza() {
    cout << "Karty gracza: " << endl;
    for (int i = 0; i < rekaGracza.size(); i++)
    {
        cout << rekaGracza[i].kolor << " " << rekaGracza[i].typ << endl;
    }
}

void BlackJack::wyswietlKartyKrupiera() {
    cout << "Karty krupiera: " << endl;
    for (int i = 0; i < rekaKrupiera.size(); i++)
    {
        cout << rekaKrupiera[i].kolor << " " << rekaKrupiera[i].typ << endl;
    }
}

void BlackJack::wyswietlWartoscGracza() {
    int suma = 0;
    for (int i = 0; i < rekaGracza.size(); i++)
    {
        suma += rekaGracza[i].wartosc;
    }
    cout << "Wartosc kart gracza: " << suma << endl;
}

void BlackJack::wyswietlWartoscKrupiera() {
    int suma = 0;
    for (int i = 0; i < rekaKrupiera.size(); i++) {
        suma += rekaKrupiera[i].wartosc;
    }
    cout << "Wartosc kart krupiera: " << suma << endl;
}

bool BlackJack::czyWygranaKrupiera() {
    int suma = 0;
    for (int i = 0; i < rekaKrupiera.size(); i++)
    {
        suma += rekaKrupiera[i].wartosc;
    }
    if (suma > 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BlackJack::czyRemisKrupiera() {
    int suma = 0;
    for (int i = 0; i < rekaKrupiera.size(); i++)
    {
        suma += rekaKrupiera[i].wartosc;
    }
    if (suma == 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BlackJack::czyWygranaGracza() {
    int suma = 0;
    for (int i = 0; i < rekaGracza.size(); i++)
    {
        suma += rekaGracza[i].wartosc;
    }
    if (suma == 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BlackJack::czyRemis() {
    int suma = 0;
    for (int i = 0; i < rekaGracza.size(); i++)
    {
        suma += rekaGracza[i].wartosc;
    }
    if (suma == 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BlackJack::czyPrzegrana() {
    int suma = 0;
    for (int i = 0; i < rekaGracza.size(); i++)
    {
        suma += rekaGracza[i].wartosc;
    }
    if (suma > 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BlackJack::graj() {
    cout << "$$$$ BLACKJACK $$$$" << endl;

    do {
        cout << "Podaj stawkę: ";
        cin >> stawka;

        if (stawka > gracz->srodki) {
            cout << "Nie masz tyle pieniędzy" << endl;
        } else if (stawka <= 0) {
            cout << "Nieprawidłowa stawka. Spróbuj jeszcze raz." << endl;
        }
    } while (stawka > gracz->srodki || stawka <= 0);

    stworzTalie();
    tasujTalie();
    rozdajKarty();
    wyswietlKartyGracza();
    wyswietlWartoscGracza();
    cout << endl;
    wyswietlKartyKrupiera();
    wyswietlWartoscKrupiera();

    while (true) {
        cout << "\n1. Dobierz kartę" << endl;
        cout << "2. Nie dobieraj karty" << endl;
        cout << "Wybierz opcję: ";
        cin >> wybor;

        if (wybor == 1) {
            rekaGracza.push_back(talia.back());
            talia.pop_back();
            wyswietlKartyGracza();
            wyswietlWartoscGracza();
            if (czyPrzegrana()) {
                cout << "Przegrałeś" << endl;
                gracz->srodki -= stawka;
                break;
            }
        } else if (wybor == 2) {
            while (true) {
                if (czyRemis()) {
                    cout << "Remis" << endl;
                    break;
                }
                if (czyWygranaKrupiera()) {
                    cout << "Przegrałeś" << endl;
                    gracz->srodki -= stawka;
                    break;
                }
                if (czyRemisKrupiera()) {
                    cout << "Remis" << endl;
                    break;
                }
                if (czyWygranaGracza()) {
                    cout << "Wygrałeś" << endl;
                    gracz->srodki += stawka;
                    break;
                }
                rekaKrupiera.push_back(talia.back());
                talia.pop_back();
                wyswietlKartyKrupiera();
                wyswietlWartoscKrupiera();
            }
            break;
        } else {
            cout << "Nie ma takiej opcji" << endl;
        }
    }

    rekaGracza.clear();
    rekaKrupiera.clear();

    cout << "Twoje środki: " << gracz->srodki << endl;
    cout << "Naciśnij Enter, aby powrócić do menu głównego...";
    cin.get();
    cin.ignore();
}
