#include "../headers/JednorekiBandyta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

JednorekiBandyta::JednorekiBandyta() {}

JednorekiBandyta::JednorekiBandyta(Gracz *gracz) {
    this->gracz = gracz;
}

void JednorekiBandyta::graj() {
    cout << "$$$$$$ Jednoreki Bandyta $$$$$$" << endl;
    cout << "Saldo: " << gracz->srodki << endl;
    sleep(0.5);

    do {
        cout << "Wpisz stawkę, jaką chcesz zagrać: ";
        cin >> stawka;
        if (cin.fail() || stawka > gracz->srodki) {
            cin.clear();
            cin.ignore();
            cout << "Nie masz wystarczającej liczby środków lub podałeś złą stawkę. Podaj stawkę jeszcze raz" << endl;
        }
    } while (cin.fail() || stawka > gracz->srodki);

    cin.get();
    cout << "Naciśnij Enter, aby zagrać...";
    cin.ignore();

    srand(time(NULL));
    char symbole[] = {'@', '#', '$', '%', '*', '&'};
    int liczbaSymboli = sizeof(symbole) / sizeof(symbole[0]);

    char los1 = symbole[rand() % liczbaSymboli];
    char los2 = symbole[rand() % liczbaSymboli];
    char los3 = symbole[rand() % liczbaSymboli];

    cout << "\nLosowanie:      " ;
    cout.flush();
    sleep(1.2);
    cout << los1;
    cout.flush();
    sleep(1.2);
    cout << "     " << los2;
    cout.flush();
    sleep(1.2);
    cout << "    " << los3 << endl;

    if (los1 == los2 && los2 == los3) {
        int wygrana = stawka * 5;
        gracz->srodki += wygrana;
        cout << "\nGratulacje! Wygrałeś " << wygrana << endl;
        cout << "Naciśnij Enter, aby powrócić do menu głównego...";
        cin.get();
    } else {
        gracz->srodki -= stawka;
        cout << "\nNiestety, przegrałeś. Spróbuj jeszcze raz." << endl;
        cout << "Twoje saldo to: " << gracz->srodki << endl;
        cout << "Naciśnij Enter, aby powrócić do menu głównego...";
        cin.get();
    }
}
