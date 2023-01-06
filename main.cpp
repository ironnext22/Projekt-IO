#include <iostream>
#include "includes/Okno.h"
using namespace sf;

int main()
{
    // initializiing the game

    Okno menu;

    while(menu.get_window_is_open()) {



                menu.update();
                menu.render();




    }
    return 0;
}

