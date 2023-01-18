
#include "includes/Okno.h"
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

