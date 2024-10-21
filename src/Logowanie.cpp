#include "../headers/Logowanie.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Logowanie::Logowanie() {
    srodki = 0;
    numerGracza = 1;
}

void Logowanie::dodajGracza() {
    srand(time(NULL));
    cout << "Witamy w kasynie" << std::endl;
    srodki = rand() % 1000 + 1;
    cout << "Podaj nazwę gracza: ";
    cin >> nazwa;
    cout << "Twoje dzisiejsze środki to: " << srodki;
    numerGracza++;
}

void Logowanie::logowanie() {
    dodajGracza();
}
