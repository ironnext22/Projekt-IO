#include <iostream>
#include "includes/Okno.h"
#include "includes/Pracownicy.h"
#include "includes/Loging.h"
#include "includes/Kalendarz.h"
#include "includes/Pacjeci.h"
using namespace sf;
Loging login;
Kalendarz test;
Pacjeci Xdd;
int main()
{
//    test.dodal_wizyte("Wiktor","Kowalski","2222222","19.09.2022","19.22","wiktor.k.2002@icloud.com","01");

    Okno menu;


    while(menu.get_window_is_open()) {

                menu.update();
                menu.render();

    }
    return 0;
}

