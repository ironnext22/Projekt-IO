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
    auto as = new Assistant("123","123");
    //test.set_godzina("19.22","2222222");
    Okno menu;

    while(menu.get_window_is_open()) {

                menu.update();
                menu.render();

    }
    return 0;
}

