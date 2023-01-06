#include <iostream>
#include "includes/MENU.h"
#include "includes/Pracownicy.h"
using namespace sf;
Pracownicy test;
int main()
{
    //test.dodaj_pracownika("Wiktor","Kowalski","X123Y","W123","Administrator");
    test.disp();
    // initializiing the game
    int current = 0;
    MENU menu;

    while(menu.get_window_is_open()) {

        /// update
        switch(current) {
            case 0: {
                menu.update();
                menu.render();
                break;
            }
            case 1: {
                break;
            }
        }


    }
    return 0;
}

