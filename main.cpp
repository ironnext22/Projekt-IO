#include <iostream>
#include "includes/MENU.h"
#include "includes/Button.h"
using namespace sf;
int main()
{
    // initializiing the game
    MENU menu;

    while(menu.get_window_is_open()) {

        /// update
        menu.update();

        /// render
        menu.render();

    }
    return 0;
}

