#include <iostream>
#include <SFML/Graphics.hpp>
int main()
{
    sf::Window oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Kurs SFML - http://cpp0x.pl" );
    while( oknoAplikacji.isOpen() )
    {
        oknoAplikacji.display();
        sf::Event event;
        while (oknoAplikacji.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                oknoAplikacji.close();
        }
    }
std::cout<<"Siema mati lubi natalke"; //XD
    return 0;
}

