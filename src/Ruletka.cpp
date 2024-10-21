#include "../headers/Ruletka.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

Ruletka::Ruletka() {}

Ruletka::Ruletka(Gracz *gracz) {
    this->gracz = gracz;
}

void Ruletka::graj() {
    cout << "$$$$$$ Ruletka $$$$$$" << endl;
    cout << "Saldo: " << gracz->srodki << endl;
    sleep(0.5);

    if (gracz->srodki <= 0) {
        cout << "Nie masz wystarczających środków do gry. Zakończ program." << endl;
        return;
    }

    do {
        cout << "Wpisz stawkę jaką chcesz postawić: ";
        cin >> stawka;
        cin.ignore();

        if (stawka > gracz->srodki) {
            cout << "Nie masz wystarczającej liczby środków. Podaj stawkę jeszcze raz." << endl;
        }
    } while (stawka > gracz->srodki);

    cout << "Wybierz na co chcesz postawić: " << endl;
    cout << "1. Postaw na kolor \n2. Postaw na parzysta/nieparzysta \n3. Dokładny numer (0-36) \n4. Zakres liczb (1-12) \n5. Zakres liczb (13-24) \n6. Zakres liczb (25-36) \n>>";
    cin >> wybor;

    switch (wybor) {
        case 1:
            postawNaKolory();
            break;
        case 2:
            postawParzystosc();
            break;
        case 3:
            postawLiczbe();
            break;
        case 4:
            wyborZakresu(1);
            break;
        case 5:
            wyborZakresu(2);
            break;
        case 6:
            wyborZakresu(3);
            break;
        default:
            cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
            break;
    }

    cout << "Naciśnij Enter, aby powrócić do menu głównego...";
    cin.get();
    cin.ignore();
}

int Ruletka::losujLiczbe() {
    return wylosowanyNumer = rand() % 37;
}

bool Ruletka::ustalKolor(int liczba, string &nazwaKoloru) {
    if (liczba == 1 || liczba == 3 || liczba == 5 || liczba == 7 || liczba == 9 || liczba == 12 ||
        liczba == 14 || liczba == 16 || liczba == 18 || liczba == 19 || liczba == 21 || liczba == 23 ||
        liczba == 25 || liczba == 27 || liczba == 30 || liczba == 32 || liczba == 34 || liczba == 36) {
        nazwaKoloru = "Czerwony";
        return true;
    } else {
        nazwaKoloru = "Czarny";
        return false;
    }
}

void Ruletka::postawNaKolory() {
    string nazwaKoloru = "";
    char urKolor;
    do {
        cout << "Wybierz kolor (Czerwony - R, Czarny - B): ";
        cin >> urKolor;

        if (urKolor != 'R' && urKolor != 'B') {
            cout << "Nieprawidłowy kolor. Spróbuj jeszcze raz." << endl;
            return;
        }
    } while (urKolor != 'R' && urKolor != 'B');

    int wylosowana = losujLiczbe();
    bool kolor = ustalKolor(wylosowana, nazwaKoloru);

    cout << "Wylosowany kolor: " << nazwaKoloru << endl;

    if ((kolor && urKolor == 'R') || (!kolor && urKolor == 'B')) {
        int wygrana = stawka * 2;
        gracz->srodki += wygrana;
        cout << "Gratulacje! Wygrałeś " << wygrana << endl;
    } else {
        gracz->srodki -= stawka;
        cout << "Niestety, przegrałeś. Spróbuj jeszcze raz. Straciłeś " << stawka << " monet" << endl;
    }
}

void Ruletka::postawLiczbe() {
    int liczba;
    cout << "Podaj liczbę na którą chcesz postawić (0-36): ";
    cin >> liczba;

    if (liczba < 0 || liczba > 36) {
        cout << "Nieprawidłowa liczba. Spróbuj jeszcze raz." << endl;
        return;
    }

    int wylosowana = losujLiczbe();

    cout << "Wylosowana liczba: " << wylosowana << endl;

    if (wylosowana == liczba) {
        int wygrana = stawka * 36;
        gracz->srodki += wygrana;
        cout << "Gratulacje! Wygrałeś " << wygrana << endl;
    } else {
        gracz->srodki -= stawka;
        cout << "Niestety, przegrałeś. Spróbuj jeszcze raz. Straciłeś " << stawka << " monet" << endl;
    }
}

void Ruletka::postawParzystosc() {
    char wybor;

    do {
        cout << "\nWybierz parzyste (P) lub nieparzyste (N): ";
        cin >> wybor;
        if (wybor != 'P' && wybor != 'N')
            cout << "Nieprawidłowy wybór. Spróbuj jeszcze raz." << endl;
    } while (wybor != 'P' && wybor != 'N');

    int wylosowana = losujLiczbe();

    cout << "\nWylosowana liczba: " << wylosowana << endl;

    if ((wylosowana % 2 == 0 && wybor == 'P' && wylosowana != 0) || (wylosowana % 2 != 0 && wybor == 'N')) {
        int wygrana = stawka * 2;
        gracz->srodki += wygrana;
        cout << "\nGratulacje! Wygrałeś " << wygrana << endl;
    } else {
        gracz->srodki -= stawka;
        cout << "\nNiestety, przegrałeś. Spróbuj jeszcze raz. Straciłeś " << stawka << " monet" << endl;
    }
}

void Ruletka::wyborZakresu(int zakres) {
    int wylosowana = losujLiczbe();

    cout << "Wylosowana liczba: " << wylosowana << endl;

    bool wygrana = false;

    if (zakres == 1 && wylosowana > 0 && wylosowana < 13)
        wygrana = true;
    else if (zakres == 2 && wylosowana > 12 && wylosowana < 25)
        wygrana = true;
    else if (zakres == 3 && wylosowana > 24 && wylosowana < 37)
        wygrana = true;

    if (wygrana) {
        int nagroda = stawka * 2;
        gracz->srodki += nagroda;
        cout << "\nGratulacje! Wygrałeś " << nagroda << endl;
    } else {
        gracz->srodki -= stawka;
        cout << "\nNiestety, przegrałeś. Spróbuj jeszcze raz. Straciłeś " << stawka << " monet" << endl;
    }
}
