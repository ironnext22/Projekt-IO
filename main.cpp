#include <iostream>
#include "includes/Okno.h"
#include "includes/Pracownicy.h"
#include "includes/Loging.h"
using namespace sf;
Loging login;
Pracownicy test;
int main()
{
    //test.dodaj_pracownika("Wiktor","Kowalski","X123Y","W123","Administrator","admin@exemp.pl");
    //test.disp();
    std::cout<<login.log_in("X123Y","W123");
    test.zmien_nazwisko("X123Y","Kowalski");
    // initializiing the game

    Okno menu;

    while(menu.get_window_is_open()) {

                menu.update();
                menu.render();

    }
    return 0;
}

