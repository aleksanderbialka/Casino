#ifndef CASINO_LOGOWANIE_H
#define CASINO_LOGOWANIE_H

#include <iostream>
#include <string>

using namespace std;

class Logowanie {
private:
    void dodajGracza();

public:
    int ileGraczy;
    int numerGracza;
    int srodki;
    string nazwa;

    Logowanie();
    void logowanie();
};

#endif //CASINO_LOGOWANIE_H
