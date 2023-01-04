#include <iostream>
#include "includes/MENU.h"
using namespace sf;

int main()
{
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

