#ifndef CASINO_JEDNOREKIBANDYTA_H
#define CASINO_JEDNOREKIBANDYTA_H

#include "Gracz.h"

using namespace std;

class JednorekiBandyta : public Gracz {
private:
    int stawka;
    Gracz *gracz;

public:
    JednorekiBandyta();
    JednorekiBandyta(Gracz *gracz);
    void graj();
};

#endif //CASINO_JEDNOREKIBANDYTA_H
