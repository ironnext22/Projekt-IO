#include <iostream>
#include "includes/Okno.h"
#include "includes/Pracownicy.h"
#include "includes/Loging.h"
using namespace sf;
Loging login;
Pracownicy test;
int main()
{


    Okno menu;


    while(menu.get_window_is_open()) {

                menu.update();
                menu.render();

    }
    return 0;
}

