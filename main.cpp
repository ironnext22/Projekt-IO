#include <iostream>
#include "includes/Okno.h"
#include "includes/Pracownicy.h"
#include "includes/Loging.h"
#include "includes/Kalendarz.h"
#include "includes/Assistant.h"
Kalendarz test;
using namespace sf;
int main()
{
//    test.dodal_wizyte("Wiktor","Kowalski","23412343","19.01.2023","19.00","wiktor.k.2002@icloud.com");
    Okno menu;


    while(menu.get_window_is_open()) {

                menu.update();
                menu.render();

    }
    return 0;
}

