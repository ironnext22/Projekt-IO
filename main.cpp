#include <iostream>
#include "includes/Okno.h"
#include "includes/Pracownicy.h"
using namespace sf;
Pracownicy test;
int main()
{
    
    //test.dodaj_pracownika("Wiktor","Kowalski","X123Y","W123","Administrator","admin@exemp.pl");
    test.disp();
    // initializiing the game

    Okno menu;

    while(menu.get_window_is_open()) {

                menu.update();
                menu.render();

    }
    return 0;
}

