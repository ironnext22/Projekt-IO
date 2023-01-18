
#include "includes/Okno.h"
#include "includes/Kartoteka.h"
using namespace sf;
Kartoteka test;
int main()
{
    Okno menu;
    while(menu.get_window_is_open()) {

                menu.update();
                menu.render();

    }
    return 0;
}

