#include <iostream>
#include "includes/Okno.h"
#include "includes/Pracownicy.h"
#include "includes/Loging.h"
#include "includes/Kalendarz.h"
#include "includes/Assistant.h"
#include "includes/Magazyn.h"
#include "includes/Finanse.h"
#include "includes/Kartoteka.h"
using namespace sf;
int main()
{

    Okno menu;
    while(menu.get_window_is_open()) {

                menu.update();
                menu.render();

    }
    return 0;
}

