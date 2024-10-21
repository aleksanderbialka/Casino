#include "./headers/Logowanie.h"
#include "./headers/Gracz.h"
#include "./headers/Menu.h"

using namespace std;

int main() {
    Logowanie *logowanie = new Logowanie;
    logowanie->logowanie();
    Gracz *gracz = new Gracz(logowanie);
    Menu menu(gracz);
    menu.wyborOpcji();

    delete gracz;
    delete logowanie;

    return 0;
}
