#include <iostream>
#include "MENU.h"
using namespace sf;
int main()
{
    sf::RenderWindow window_menu( sf::VideoMode( 800, 600, 32 ), "NIE DLACZEGO" );
    MENU menu(window_menu.getSize().x, window_menu.getSize().y);
    window_menu.setFramerateLimit(60);

    View view(FloatRect (0.0f, 0.0f, 800, 600)); //view_size.x view_size.y
//
    while( window_menu.isOpen()) {
        Event ev{};

        while (window_menu.pollEvent(ev)) {
            switch (ev.type) {
                case Event::KeyReleased:
                    switch (ev.key.code) {
                        case Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case Keyboard::W:
                            menu.MoveUp();
                            break;

                        case Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case Keyboard::S:
                            menu.MoveDown();
                            break;
                        case Keyboard::Return:
                            window_menu.close();
                            break;
                    }
                    break;
                case Event::Closed:
                    window_menu.close();
                    return 0;

                case Event::Resized:
                   // resize_view(window_menu, view);
                    break;
            }
        }
        window_menu.clear();
        menu.draw(window_menu);
        window_menu.display();

    }
    return 0;
}

